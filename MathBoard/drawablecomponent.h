#ifndef DRAWABLECOMPONENT_H
#define DRAWABLECOMPONENT_H

#include<QPaintEvent>
#include<QPainter>
#include<QPen>
#include<math.h>
class DrawableComponent
{
public:
    DrawableComponent();
    virtual void draw(QPainter *painter)=0;
    virtual QString* toString()=0;
    virtual QString getName() const;
    virtual void setName(const QString &value);
    virtual int getIsSelected();
    virtual void setIsSelected(int);
    virtual void setX1(int);
    virtual void setY1(int);
    virtual void setX2(int value);
    virtual void setY2(int value);
    virtual int getY1();
    virtual int getX1();
    virtual int getY2();
    virtual int getX2();

    virtual int getWidth() const;
    virtual void setWidth(int value);

    virtual void setLast(int value);
    virtual int getLast() const;
    virtual void moveTo(int x,int y);
    virtual void resizeUpto(int x,int y,int type);
    virtual  int checkSelection(double,double);

    virtual QColor getColor() const;
    virtual void setColor(const QColor &value);
};


#endif // DRAWABLECOMPONENT_H
