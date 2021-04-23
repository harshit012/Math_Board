#include "eraser.h"

int Eraser::getX1()
{
    return x1;
}

void Eraser::setX1(int value)
{
    x1 = value;
}

int Eraser::getY1()
{
    return y1;
}

void Eraser::setY1(int value)
{
    y1 = value;
}

int Eraser::getX2()
{
    return x2;
}

void Eraser::setX2(int value)
{
    x2 = value;
}

int Eraser::getY2()
{
    return y2;
}

void Eraser::setY2(int value)
{
    y2 = value;
}

int Eraser::getWidth() const
{
    return width;
}

void Eraser::setWidth(int value)
{
    width = value;
}

int Eraser::getLast() const
{
    return last;
}

void Eraser::setLast(int value)
{
    last = value;
}


Eraser::Eraser()
{
    this->last=0;
}

void Eraser::draw(QPainter *painter)
{
    QPen pen;
    QColor color("white");
    pen.setColor(color);
    pen.setWidth(this->width);
    painter->setPen(pen);
    painter->drawLine(this->x1,this->y1,this->x2,this->y2);
}

QString* Eraser::toString()
{
    return new QString("eraser");
}
