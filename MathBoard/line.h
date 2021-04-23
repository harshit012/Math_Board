#ifndef LINE_H
#define LINE_H

#include<QPainter>
#include<drawablecomponent.h>
#include<QPaintEvent>
#include<QPainter>
#include<math.h>
class Line:public DrawableComponent
{
private:
    double x1,y1,x2,y2,width;
    double slopeAngle;
    QString *str;
    int isSelected;
    QString name;
    QColor color;
public:
    Line();
    ~Line();
    void draw(QPainter *painter) override;
    int checkSelection(double,double) override;
    QString* toString() override;
    void setX1(int value) override;
    int getX1() override;
    int getY1() override;
    void setY1(int value) override;
    int getY2() override;
    int getX2() override;
    void setX2(int value) override;

    void setY2(int value) override;
    int getWidth() const override;
    void setWidth(int value) override;
    int getIsSelected() override;
    void setIsSelected(int) override;
    QString getName() const override;
    void setName(const QString &value) override;
    QColor getColor() const override;
    void setColor(const QColor &value) override;
    void moveTo(int x,int y) override;
     void resizeUpto(int x,int y,int type) override;
};

#endif // LINE_H
