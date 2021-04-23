#include "freehand.h"

int FreeHand::getX1()
{
    return x1;
}

void FreeHand::setX1(int value)
{
    x1 = value;
}

int FreeHand::getY1()
{
    return y1;
}

void FreeHand::setY1(int value)
{
    y1 = value;
}

int FreeHand::getX2()
{
    return x2;
}

void FreeHand::setX2(int value)
{
    x2 = value;
}

int FreeHand::getY2()
{
    return y2;
}

void FreeHand::setY2(int value)
{
    y2 = value;
}


int FreeHand::getWidth() const
{
    return width;
}

void FreeHand::setWidth(int value)
{
    width = value;
}

int FreeHand::getLast() const
{
    return last;
}

void FreeHand::setLast(int value)
{
    last = value;
}



int FreeHand::getSelectionPosition() const
{
    return SelectionPosition;
}

void FreeHand::setSelectionPosition(int value)
{
    SelectionPosition = value;
}

void FreeHand::resizeUpto(int x, int y, int type)
{
    double r=sqrt((x*x)+(y*y));
    double numerator=this->y2-this->y1;
    double denomenator=this->x2-this->x1;
    double m=numerator/denomenator;
    double theta=atan(m);
    double newX;
    double newY;
    if(x<0||y<0)
    {
        newX=this->x2-(r*cos(theta));
        newY=this->y2-(r*sin(theta));
        this->x2=newX;
        this->y2=newY;
    }
    else
    {
        newX=this->x2+(r*cos(theta));
        newY=this->y2+(r*sin(theta));
        this->x2=newX;
        this->y2=newY;
    }
}


QColor FreeHand::getColor() const
{
    return color;
}

void FreeHand::setColor(const QColor &value)
{
    color = value;
}

FreeHand::FreeHand()
{
    last=0;
    this->SelectionPosition=0;
}

FreeHand::~FreeHand()
{

}

void FreeHand::draw(QPainter *painter)
{
    /*if(this->SelectionPosition==-1)
    {
        QPen pen;
        pen.setColor(this->color);
        pen.setWidth(this->width+10);
        painter->setPen(pen);
        painter->drawPoint(QPoint(this->x1,this->y1));
    }
    if(this->SelectionPosition==1)
    {
        QPen pen;
        pen.setColor(this->color);
        pen.setWidth(this->width+10);
        painter->setPen(pen);
        painter->drawPoint(QPoint(this->x2,this->y2));
    }*/
    QPen pen;
    pen.setColor(this->color);
    pen.setWidth(this->width);
    painter->setPen(pen);
    painter->drawLine(this->x1,this->y1,this->x2,this->y2);
}

QString* FreeHand::toString()
{
    return new QString("freeHand");
}

int FreeHand::checkSelection(int x,int y)
{
    int isSelected=0;
    int AB=sqrt(pow((x-this->x1),2)+pow((y-this->y1),2));
    int BC=sqrt(pow((this->x2-x),2)+pow((this->y2-y),2));
    int AC=sqrt(pow((this->x2-this->x1),2)+pow((this->y2-this->y1),2));
    if(AC==(AB+BC)) isSelected=1;
    else isSelected=0;
    return isSelected;
}
