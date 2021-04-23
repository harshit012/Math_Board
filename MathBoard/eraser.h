#ifndef ERASER_H
#define ERASER_H
#include<QPainter>
#include<drawablecomponent.h>
#include<QPaintEvent>
#include<QPainter>
#include<drawablecomponent.h>
class Eraser:public DrawableComponent
{
private:
        int x1,y1,x2,y2,width,last;
        QString *str;
public:
    Eraser();
    void draw(QPainter *painter) override;
    QString* toString() override;
    void setX1(int value) override;
    int getX1() override;
    int getY1() override;
    void setY1(int value) override ;
    void setX2(int value) override;
    int getY2() override;
    int getX2() override;
    void setY2(int value) override;
    int getWidth() const override;
    void setWidth(int value) override;
    int getLast() const override;
    void setLast(int value) override;
};
#endif // ERASER_H
