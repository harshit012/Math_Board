#include "ellipse.h"

int Ellipse::getX1()
{
    return x1;
}

void Ellipse::setX1(int value)
{
    x1 = value;
}

int Ellipse::getX2()
{
    return x2;
}

void Ellipse::setX2(int value)
{
    x2 = value;
}

int Ellipse::getY1()
{
    return y1;
}

void Ellipse::setY1(int value)
{
    y1 = value;
}

int Ellipse::getY2()
{
    return y2;
}

void Ellipse::setY2(int value)
{
    y2 = value;
}

int Ellipse::getWidth() const
{
    return width;
}

void Ellipse::setWidth(int value)
{
    width = value;
}

void Ellipse::createCircle(bool check)
{
    if(check==true)
    {
        this->y2=this->x2;
    }
}

int Ellipse::getFinalX() const
{
    return finalX;
}

void Ellipse::setFinalX(int value)
{
    finalX = value;
}

int Ellipse::getFinalY() const
{
    return finalY;
}

void Ellipse::setFinalY(int value)
{
    finalY = value;
}

int Ellipse::getIsSelected()
{
    return this->isSelected;
}

void Ellipse::setIsSelected(int value)
{
    this->isSelected=value;
}



QString Ellipse::getName() const
{
    return name;
}

void Ellipse::setName(const QString &value)
{
    name = value;
}

void Ellipse::moveTo(int x, int y)
{
    this->setX1(this->getX1()+x);
    this->setY1(this->getY1()+y);
}

void Ellipse::resizeUpto(int x, int y, int type=0)
{
    if(type==0)
    {
    this->setX2(this->getX2()+x);
    this->setY2(this->getY2()+y);
    }
    else
    {
        if(x<y)
        {
            double oldX=this->x2;
            this->setX2(this->getX2()+x);
            double newY=(this->x2*this->y2)/oldX;
            this->setY2(newY);
        }
        else
        {
            double oldY=this->y2;
            this->setY2(this->getY2()+y);
            double newX=(this->x2*this->y2)/oldY;
            this->setX2(newX);
        }
    }
}



QColor Ellipse::getColor() const
{
    return color;
}

void Ellipse::setColor(const QColor &value)
{
    color = value;
}

Ellipse::Ellipse()
{
    this->isSelected=0;
    this->name="ellipse";
}

Ellipse::~Ellipse()
{

}

void Ellipse::draw(QPainter *painter)
{
    this->centerX=this->x1+(this->x2/2);
    this->centerY=this->y1+(this->y2/2);
    if(isSelected==1)
    {
        QPen pen;
        pen.setColor(this->color);
        pen.setWidth(this->width+10);
        painter->setPen(pen);
        painter->drawPoint(QPoint(this->centerX-(this->x2/2),this->centerY));
        painter->drawPoint(QPoint(this->centerX+(this->x2/2),this->centerY));
        painter->drawPoint(QPoint(this->centerX,this->centerY-(this->y2/2)));
        painter->drawPoint(QPoint(this->centerX,this->centerY+(this->y2/2)));
    }
    QPen pen;
    pen.setColor(this->color);
    pen.setWidth(this->width);
    painter->setPen(pen);
    int tempY2=this->x2;
    painter->drawEllipse(this->x1,this->y1,this->x2,this->y2);
}

int Ellipse::checkSelection(double x,double y)
{
    double x1=(double)this->x1;
    double x2=(double)this->x2;
    double y1=(double)this->y1;
    double y2=(double)this->y2;
    double a,b;
    this->centerX=(x1+x1+x2)/2;
    this->centerY=(y1+y1+y2)/2;
    a=x2/2;
    b=y2/2;

    double part1=pow(((double)x-this->centerX),2);
    double part2=pow(((double)y-this->centerY),2);
    double value=(part1/(a*a))+(part2/(b*b));
    if(value<=(double)1)
    {
        this->isSelected=1;
    }
    else this->isSelected=0;
    return isSelected;
}


QString* Ellipse::toString()
{
    return new QString("ellipse");
}


