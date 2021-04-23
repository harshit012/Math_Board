#ifndef ELLIPSE_H
#define ELLIPSE_H

#include<QPen>
#include<QPoint>
#include<QPainterPath>
#include<QPainter>
#include<drawablecomponent.h>
class Ellipse : public DrawableComponent
{
private:
    double x1,x2,y1,y2;
    int width,finalX,finalY;
    double centerX,centerY;
    QString *str;
    int isSelected;
    QString name;
    QColor color;

public:
    Ellipse();
    ~Ellipse();
    void draw(QPainter *painter) override;
    int checkSelection(double,double) override;
    QString* toString() override;
    int getX1() override;
    int getY1() override;
    void setX1(int value) override;
    int getY2() override;
    int getX2() override;
    void setX2(int value) override;
    void setY1(int value) override;

    void setY2(int value) override;
    int getWidth() const override;
    void setWidth(int value) override;
    void createCircle(bool check);

    int getFinalX() const;
    void setFinalX(int value);
    int getFinalY() const;
    void setFinalY(int value);
    int getIsSelected() override;
    void setIsSelected(int) override;
    QString getName() const override;
    void setName(const QString &value)override;
    void moveTo(int x,int y) override;
    void resizeUpto(int x,int y,int type) override;
    QColor getColor() const override;
    void setColor(const QColor &value) override;
};

#endif // ELLIPSE_H
