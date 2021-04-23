#include "freehandlist.h"
#include<QDebug>
#include<QListIterator>
int FreeHandList::getIsSelected()
{
    return isSelected;
}

void FreeHandList::setIsSelected(int value)
{
    isSelected = value;
    this->setMinMax();
}

void FreeHandList::clearList()
{
    FreeHand *freeHand;
    QListIterator<FreeHand*> iter(*(this->list));
    while(iter.hasNext())
    {
        freeHand=iter.next();
        delete freeHand;
    }
}

void FreeHandList::moveTo(int x,int y)
{
    QListIterator<FreeHand*> iter(*(this->list));
    FreeHand *freeHand;

    while(iter.hasNext())
    {
        freeHand=iter.next();
        freeHand->setX1(freeHand->getX1()+x);
        freeHand->setY1(freeHand->getY1()+y);
        freeHand->setX2(freeHand->getX2()+x);
        freeHand->setY2(freeHand->getY2()+y);
    }
    this->setMinMax();
}

void FreeHandList::resizeUpto(int x, int y, int type)
{
    double r=sqrt((x*x)+(y*y));
    QListIterator<FreeHand*> iter(*(this->list));
    FreeHand *freeHand;
    FreeHand *previous=NULL;
    while(iter.hasNext())
    {
        freeHand=iter.next();
        freeHand->resizeUpto(x,y,type);
    }
}


QString FreeHandList::getName() const
{
    return name;
}

void FreeHandList::setName(const QString &value)
{
    name = value;
}

QColor FreeHandList::getColor() const
{
    return color;
}

void FreeHandList::setColor(const QColor &value)
{
    color = value;
}

void FreeHandList::setMinMax()
{
    int x1,x2,y1,y2;
    QListIterator<FreeHand*> iter(*(this->list));
    FreeHand *p;
    p=this->list->at(0);
    x1=p->getX1();
    x2=p->getX2();
    y1=p->getY1();
    y2=p->getY2();
    if(x1>x2)
    {
        xMax=x1;
        xMin=x2;
    }else
    {
        xMin=x1;
        xMax=y1;
    }
    if(y1>y2)
    {
        yMax=y1;
        yMin=y2;
    }else
    {
        yMin=y1;
        yMax=y2;
    }

    while(iter.hasNext())
    {
        p=iter.next();
        x1=p->getX1();
        x2=p->getX2();
        y1=p->getY1();
        y2=p->getY2();
        if(x1>xMax) xMax=x1;
        else if(x1<xMin) xMin=x1;
        if(x2>xMax) xMax=x2;
        else if(x2<xMin) xMin=x2;
        if(y1>yMax) yMax=y1;
        else if(y1<yMin) yMin=y1;
        if(y2>yMax) yMax=y2;
        else if(y2<yMin) yMin=y2;
    }
}

FreeHandList::FreeHandList()
{
    this->name="pen";
    this->list=new QList<FreeHand*>;
    this->isSelected=0;
}

FreeHandList::~FreeHandList()
{ 
    clearList();
}



void FreeHandList::draw(QPainter *painter)
{
    QListIterator<FreeHand*> iter(*(this->list));
    while(iter.hasNext())
    {
        iter.next()->draw(painter);
    }
    if(this->isSelected==1)
    {
        QPen pen;
        pen.setColor("#0080ff");
        pen.setWidth(2);
        pen.setStyle(Qt::DashDotLine);
        painter->setPen(pen);
        painter->drawRect(xMin-1,yMin-1,xMax-xMin+2,yMax-yMin+2);
        pen.setWidth(10);
        painter->setPen(pen);
        painter->drawPoint(xMin-1,yMin-1);
        painter->drawPoint(xMax+1,yMin-1);
        painter->drawPoint(xMin-1,yMax+1);
        painter->drawPoint(xMax+1,yMax+1);


    }
}

QString *FreeHandList::toString()
{
    return new QString("freeHandList");
}

void FreeHandList::add(FreeHand *freehand)
{
    list->push_back(freehand);
}

QList<FreeHand *> *FreeHandList::getList()
{
    return this->list;
}

int FreeHandList::checkSelection(double x,double y)
{
    int flag=0;
    QListIterator<FreeHand*> iter(*(this->list));
    while(iter.hasNext())
    {
        flag=iter.next()->checkSelection(x,y);
        if(flag==1) break;
    }
    this->isSelected=flag;
    return flag;
}
