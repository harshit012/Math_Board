#ifndef RECTANGLE_H
#define RECTANGLE_H

#include<QString>
#include<drawablecomponent.h>
#include<QPaintEvent>
#include<QPainter>
#include<QPen>
class Rectangle : public DrawableComponent
{
private:
    double x1,y1,x2,y2;
    int width,finalX2,finalY2;

    QString *str;
    int isSelected;
    QString name;
    QColor color;
public:
    Rectangle();
    ~Rectangle();
    void draw(QPainter *painter) override;
    int checkSelection(double,double) override;
    QString* toString() override;
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

    int getIsSelected() override;
    void setIsSelected(int) override;
    QString getName() const override;
    void setName(const QString &value) override;
    void createSquare(bool check);
    QColor getColor() const override;
    void setColor(const QColor &value) override;
    void moveTo(int x,int y) override;
    void resizeUpto(int x,int y,int type) override;
};


#endif // RECTANGLE_H
