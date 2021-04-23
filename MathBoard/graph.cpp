#include "graph.h"
#include<QListIterator>


int Graph::getWidth() const
{
    return width;
}

void Graph::setWidth(int value)
{
    width = value;
}

QColor Graph::getColor() const
{
    return color;
}

void Graph::setColor(const QColor &value)
{
    color = value;
}

Graph::Graph()
{

}

void Graph::draw(QPainter *painter)
{
int count=0;
    for(int i=113,count=0;i<=111+1319;i=i+this->width,count++) //vertical lines
    {
        QPen pen;

        pen.setColor(this->color);
        pen.setWidth(1);
        if(count%10==0) pen.setWidth(2);
        painter->setPen(pen);
        painter->drawLine(i,68,i,68+747);
    }
    for(int i=68,count=0;i<=68+747;i=i+this->width,count++) //horizontal lines
    {
        QPen pen;
        pen.setColor(this->color);
        pen.setWidth(1);
        if(count%10==0) pen.setWidth(2);
        painter->setPen(pen);
        painter->drawLine(113,i,111+1319,i);
    }

}
