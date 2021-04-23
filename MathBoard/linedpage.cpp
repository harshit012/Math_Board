#include "linedpage.h"

QColor LinedPage::getColor() const
{
    return color;
}

void LinedPage::setColor(const QColor &value)
{
    color = value;
}

int LinedPage::getWidth() const
{
    return width;
}

void LinedPage::setWidth(int value)
{
    width = value;
}

LinedPage::LinedPage()
{
    this->color=QColor("#b5b6b5");
}

void LinedPage::draw(QPainter *painter)
{
    for(int i=68;i<=68+747;i=i+this->width) //horizontal lines
    {
        QPen pen;
        pen.setColor(this->color);
        pen.setWidth(1);
        painter->setPen(pen);
        painter->drawLine(113,i,111+1319,i);
    }
}
