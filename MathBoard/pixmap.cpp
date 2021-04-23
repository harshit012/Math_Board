#include "pixmap.h"
#include<QStyleOptionGraphicsItem>
#include<QImage>
int PixMap::getX1()
{
    return x1;
}

void PixMap::setX1(int value)
{
    x1 = value;
}

int PixMap::getY1()
{
    return y1;
}

void PixMap::setY1(int value)
{
    y1 = value;
}

int PixMap::getX2()
{
    return x2;
}

void PixMap::setX2(int value)
{
    x2 = value;
}

int PixMap::getY2()
{
    return y2;
}

void PixMap::setY2(int value)
{
    y2 = value;
}

int PixMap::getIsSelected()
{
    return isSelected;
}

void PixMap::setIsSelected(int value)
{
    isSelected = value;
}


QString PixMap::getName() const
{
    return name;
}

void PixMap::setName(const QString &value)
{
    name = value;
}



void PixMap::moveTo(int x, int y)
{
    this->setX1(this->getX1()+x);
    this->setY1(this->getY1()+y);
}

void PixMap::resizeUpto(int x, int y, int type)
{
    if(type==0)
    {
    this->setX2(this->getX2()+x);
    this->setY2(this->getY2()+y);
    }
}

QPixmap *PixMap::getPixmap() const
{
    return pixmap;
}

void PixMap::setPixmap(QPixmap *value)
{
    pixmap = value;
}

QString PixMap::getPath() const
{
    return path;
}

void PixMap::setPath(const QString &value)
{
    path = value;
}

PixMap::PixMap()
{
    this->pixmap=new QPixmap();
    this->name="pixmap";
}

PixMap::~PixMap()
{
    delete this->pixmap;
}

void PixMap::draw(QPainter *painter)
{
    this->finalX2=this->x1+this->x2;
    this->finalY2=this->y1+this->y2;
    if(isSelected==1)
    {
        QPen pen;
        pen.setColor("black");
        pen.setWidth(3);
        painter->setPen(pen);
        painter->drawPoint(QPoint(this->x1,this->y1));
        painter->drawPoint(QPoint(this->x1,this->finalY2));
        painter->drawPoint(QPoint(this->finalX2,this->y1));
        painter->drawPoint(QPoint(this->finalX2,this->finalY2));
        pen.setWidth(10);
        painter->drawRect(this->x1,this->y1,this->x2,this->y2);
    }
     painter->drawPixmap(this->x1,this->y1,this->x2,this->y2,*(this->pixmap));
}

int PixMap::checkSelection(double x,double y)
{
    int flag=0;
    this->finalX2=this->x1+this->x2;
    this->finalY2=this->y1+this->y2;
    if(this->x2>0&&this->y2>0)
    {
        if((x>this->x1)&&(x<finalX2)&&(y>this->y1)&&(y<finalY2))
        {
            flag=1;
            isSelected=1;
        }

    }
    if(this->x2>0&&this->y2<0)
    {
            if((x>this->x1)&&(x<finalX2)&&(y<this->y1)&&(y>finalY2))
            {
                flag=1;
                isSelected=1;
            }
    }
    if(this->x2<0&&this->y2<0)
    {
            if((x<this->x1)&&(x>finalX2)&&(y<this->y1)&&(y>finalY2))
            {
                flag=1;
                isSelected=1;
            }
    }
    if(this->x2<0&&this->y2>0)
    {
            if((x<this->x1)&&(x>finalX2)&&(y>this->y1)&&(y<finalY2))
            {
                flag=1;
                isSelected=1;
            }
    }
    if(flag==0) this->isSelected=0;
    return isSelected;
}

QString *PixMap::toString()
{
    return new QString("pixmap");
}
