#ifndef TMVIEW_H
#define TMVIEW_H

#include<drawablecomponent.h>
#include<QPainter>
#include<QPen>
#include<ellipse.h>
#include<rectangle.h>
#include<line.h>
#include<freehand.h>
#include<freehandlist.h>
class TMView
{
private:
    QList<DrawableComponent *> *list;
    QSet<DrawableComponent*> setOfSelectedComponents;
    DrawableComponent *drLast;
public:
    TMView();
    ~TMView();
    void add(DrawableComponent *dr);
    void remove(DrawableComponent *dr);
    void draw(QPainter *painter);
    int sizeOfList();
    void clearList();
    void undo();
    void redo();
    DrawableComponent* get(int index);
    DrawableComponent* getLast();
    int shouldSelect(int,int);
    void release();
    QList<DrawableComponent*> getSelectedComponents();
    void clearAllSelectedComponents();
    void addToSelectedComponents(DrawableComponent*);
    void deleteFromSelectedComponents(DrawableComponent*);
    int sizeOfSelectedComponents();
    int count;
    QList<DrawableComponent *> *getList() const;
};

#endif // TMVIEW_H
