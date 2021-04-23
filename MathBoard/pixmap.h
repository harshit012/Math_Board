#ifndef PIXMAP_H
#define PIXMAP_H

#include<drawablecomponent.h>
class PixMap:public DrawableComponent
{
private:
    int x1,y1,x2,y2;
    QString *str;
    int isSelected,finalX2,finalY2;
    QString name,path;
    QPixmap *pixmap;
public:
    PixMap();
    ~PixMap();
    void draw(QPainter *painter) override;
    int checkSelection(double,double) override;
    QString* toString() override;
    int getX1() override;
    void setX1(int value) override;
    int getY1() override;
    void setY1(int value) override;
    int getX2() override;
    void setX2(int value) override;
    int getY2() override;
    void setY2(int value) override;
    int getIsSelected() override;
    void setIsSelected(int value) override;
    QString getName() const override;
    void setName(const QString &value) override;

    void moveTo(int x,int y) override;
    void resizeUpto(int x,int y,int type) override;
    QPixmap *getPixmap() const;
    void setPixmap(QPixmap *value);
    QString getPath() const;
    void setPath(const QString &value);
};

#endif // PIXMAP_H
