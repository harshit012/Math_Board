#ifndef FREEHAND_H
#define FREEHAND_H


#include<QPainter>
#include<drawablecomponent.h>
#include<QPaintEvent>
#include<QPainter>
#include<drawablecomponent.h>
#include<math.h>
class FreeHand:public DrawableComponent
{
private:
    int x1,y1,x2,y2,width,last;
    double slopeAngle;
    QString *str;
    QColor color;
    int SelectionPosition;
public:
    FreeHand();
    ~FreeHand();
    void draw(QPainter *painter) override;
    QString* toString() override;
    int checkSelection(int,int);
    void setX1(int value) override;
    int getX1() override;
    int getY1() override;
    void setY1(int value) override;

    void setX2(int value) override;
    int getY2() override;
    int getX2() override;
    void setY2(int value) override;

    int getWidth() const override;
    void setWidth(int value) override;
    int getLast() const override;
    void setLast(int value) override;

    int getSelectionPosition() const;
    void setSelectionPosition(int value);
    void resizeUpto(int x,int y,int type) override;
    QColor getColor() const override;
    void setColor(const QColor &value) override;
};

#endif // FREEHAND_H
