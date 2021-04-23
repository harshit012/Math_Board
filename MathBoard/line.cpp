#include "line.h"

int Line::getX1()
{
    return x1;
}

void Line::setX1(int value)
{
    x1 = value;
}

int Line::getY1()
{
    return y1;
}

void Line::setY1(int value)
{
    y1 = value;
}

int Line::getX2()
{
    return x2;
}

void Line::setX2(int value)
{
    x2 = value;
}

int Line::getY2()
{
    return y2;
}

void Line::setY2(int value)
{
    y2 = value;
}

int Line::getWidth() const
{
    return width;
}

void Line::setWidth(int value)
{
    width = value;
}


QString Line::getName() const
{
    return name;
}

void Line::setName(const QString &value)
{
    name = value;
}

QColor Line::getColor() const
{
    return color;
}

void Line::setColor(const QColor &value)
{
    color = value;
}

void Line::moveTo(int x, int y)
{
    this->setX1(this->getX1()+x);
    this->setY1(this->getY1()+y);
    this->setX2(this->getX2()+x);
    this->setY2(this->getY2()+y);
}

void Line::resizeUpto(int x, int y, int type=0)
{
    if(type==0)
    {
        this->setX2(this->getX2()+x);
        this->setY2(this->getY2()+y);
    }
    else
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
}

Line::Line()
{
    this->name="line";
    this->slopeAngle=0.0;
    this->isSelected=0;
}

Line::~Line()
{

}


int Line::getIsSelected()
{
    return this->isSelected;
}

void Line::setIsSelected(int value)
{
    this->isSelected=value;
}

void Line::draw(QPainter *painter)
{
    if(isSelected==1)
    {
        QPen pen;

        pen.setColor(this->color);
        pen.setWidth(this->width+10);
        painter->setPen(pen);
        painter->drawPoint(QPoint(this->x1,this->y1));
        painter->drawPoint(QPoint(this->x2,this->y2));
    }
    QPen pen;

    pen.setColor(this->color);
    pen.setWidth(this->width);
    painter->setPen(pen);
    painter->drawLine(this->x1,this->y1,this->x2,this->y2);
}

int Line::checkSelection(double x,double y)
{

        int AB=sqrt(pow((x-this->x1),2)+pow((y-this->y1),2));
        int BC=sqrt(pow((this->x2-x),2)+pow((this->y2-y),2));
        int AC=sqrt(pow((this->x2-this->x1),2)+pow((this->y2-this->y1),2));
        if(AC==(AB+BC)) this->isSelected=1;
        else this->isSelected=0;
        return isSelected;
}

QString* Line::toString()
{
    return new QString("line");
}
