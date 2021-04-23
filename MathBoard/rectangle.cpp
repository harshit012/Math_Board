#include "rectangle.h"

int Rectangle::getX1()
{
    return x1;
}

void Rectangle::setX1(int value)
{
    x1 = value;
}

int Rectangle::getY1()
{
    return y1;
}

void Rectangle::setY1(int value)
{
    y1 = value;
}

int Rectangle::getX2()
{
    return x2;
}

void Rectangle::setX2(int value)
{
    x2 = value;
}

int Rectangle::getY2()
{
    return y2;
}

void Rectangle::setY2(int value)
{
    y2 = value;
}

int Rectangle::getWidth() const
{
    return width;
}

void Rectangle::setWidth(int value)
{
    width = value;
}




QString Rectangle::getName() const
{
    return name;
}

void Rectangle::setName(const QString &value)
{
    name = value;
}

void Rectangle::createSquare(bool check)
{
    if(check==1)
    {
        this->y2=this->x2;
    }
}

void Rectangle::moveTo(int x, int y)
{
    this->setX1(this->getX1()+x);
    this->setY1(this->getY1()+y);
}


QColor Rectangle::getColor() const
{
    return color;
}

void Rectangle::setColor(const QColor &value)
{
    color = value;
}

void Rectangle::resizeUpto(int x, int y, int type=0)
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
            int oldX=this->x2;
            this->setX2(this->getX2()+x);
            int newY=(this->x2*this->y2)/oldX;
            this->setY2(newY);
        }
        else
        {
            int oldY=this->y2;
            this->setY2(this->getY2()+y);
            int newX=(this->x2*this->y2)/oldY;
            this->setX2(newX);

        }
    }
}

Rectangle::Rectangle()
{
    this->name="rectangle";
    this->isSelected=0;
}

Rectangle::~Rectangle()
{

}

int Rectangle::getIsSelected()
{
    return this->isSelected;
}

void Rectangle::setIsSelected(int value)
{
    this->isSelected=value;
}

void Rectangle::draw(QPainter *painter)
{
    this->finalX2=this->x1+this->x2;
    this->finalY2=this->y1+this->y2;
    if(isSelected==1)
    {
        QPen pen;

        pen.setColor(this->color);
        pen.setWidth(this->width+10);
        painter->setPen(pen);
        painter->drawPoint(QPoint(this->x1,this->y1));
        painter->drawPoint(QPoint(this->x1,this->finalY2));
        painter->drawPoint(QPoint(this->finalX2,this->y1));
        painter->drawPoint(QPoint(this->finalX2,this->finalY2));
    }
    QPen pen;

    pen.setColor(this->color);
    pen.setWidth(this->width);
    painter->setPen(pen);
    painter->drawRect(this->x1,this->y1,this->x2,this->y2);
}

int Rectangle::checkSelection(double x,double y)
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

QString* Rectangle::toString()
{
    return new QString("rectangle");
}
