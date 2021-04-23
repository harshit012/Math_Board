#ifndef GRAPH_H
#define GRAPH_H

#include<QString>
#include<QPainter>
#include<QList>
#include<QPen>
#include<QDebug>
#include<line.h>
#include<QColor>
class Graph
{
private:
    QColor color;
    int width;
public:
    Graph();
    void draw(QPainter *painter);

    int getWidth() const;
    void setWidth(int value);
    QColor getColor() const;
    void setColor(const QColor &value);
};

#endif // GRAPH_H
