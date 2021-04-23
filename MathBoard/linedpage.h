#ifndef LINEDPAGE_H
#define LINEDPAGE_H

#include<QString>
#include<QPainter>
#include<QList>
#include<QPen>
#include<QDebug>
#include<line.h>
#include<QColor>
class LinedPage
{
private:
    QColor color;
    int width;
public:
    LinedPage();
        void draw(QPainter *painter);
        QColor getColor() const;
        void setColor(const QColor &value);
        int getWidth() const;
        void setWidth(int value);
};

#endif // LINEDPAGE_H
