#ifndef FREEHANDLIST_H
#define FREEHANDLIST_H
#include<QPainter>
#include<drawablecomponent.h>
#include<QPaintEvent>
#include<QPainter>
#include<drawablecomponent.h>
#include<freehand.h>


class FreeHandList:public DrawableComponent
{
private:
    QList<FreeHand*> *list;
    int isSelected;
    QColor color;
    QString name;
    int xMin;
    int xMax;
    int yMin;
    int yMax;
    void setMinMax();
public:
    FreeHandList();
    ~FreeHandList();

    void draw(QPainter *painter) override;
    QString* toString() override;
    void add(FreeHand*);
    QList<FreeHand*>* getList();
    int checkSelection(double,double) override;
    int getIsSelected() override;
    void setIsSelected(int value) override;
    void clearList();
    void moveTo(int x,int y) override;
    void resizeUpto(int x,int y,int type) override;
    QString getName() const override;
    void setName(const QString &value) override;
    QColor getColor() const override;
    void setColor(const QColor &value)override;

};

#endif // FREEHANDLIST_H
