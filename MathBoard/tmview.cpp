#include "tmview.h"


QList<DrawableComponent *> *TMView::getList() const
{
    return list;
}


TMView::TMView()
{
    this->drLast=NULL;
    this->list=new QList<DrawableComponent*>();
    this->count=0;
}

TMView::~TMView()
{
    delete this->list;
    if(this->drLast!=NULL) delete this->drLast;
}
void TMView::add(DrawableComponent *dr)
{
    this->list->push_back(dr);
}

void TMView::remove(DrawableComponent *dr)
{
    this->list->removeOne(dr);
}

void TMView::draw(QPainter *painter)
{
    QListIterator<DrawableComponent*> iter(*list);
    while(iter.hasNext())
    {
        iter.next()->draw(painter);
    }
}

int TMView::sizeOfList()
{
    return this->list->size();
}


void TMView::clearList()
{
    DrawableComponent *p;
    QString *str;
    for(int i=0;i<this->list->size();i++)
    {
        p=list->at(i);
        str=p->toString();
        if(str==QString("freeHandList"))
        {
            ((FreeHandList*)p)->clearList();
        }
        delete p;
        delete str;
    }
    list->clear();
}

void TMView::undo()
{
    if(this->list->size()==0) return;
    DrawableComponent *dr=list->at(list->size()-1);
    list->removeLast();
    if(this->drLast!=NULL) delete this->drLast;
    this->drLast=dr;
}

void TMView::redo()
{
    if(this->drLast!=NULL)
    {
        this->add(this->drLast);
        this->drLast=NULL;
    }
}

DrawableComponent *TMView::get(int index)
{
   if(index==0) return NULL;
   return list->at(index);
}

DrawableComponent* TMView::getLast()
{
    if(this->list->size()!=0) return this->list->at(this->list->size()-1);
    return NULL;
}

int TMView::shouldSelect(int x,int y)
{
    int flag=0;
    DrawableComponent *dr;
    QString *str;
    for(int i=0;i<this->list->size();i++)
    {
        dr=list->at(i);
        flag=flag+dr->checkSelection(x,y);
        if(dr->checkSelection(x,y)) this->setOfSelectedComponents.insert(dr);
        /*str=list->at(i)->toString();
        if(*str==QString("ellipse"))
        {
            Ellipse  *el;
            el=(Ellipse*)dr;
            flag=flag+el->checkSelection(x,y);
            if(el->checkSelection(x,y)) this->setOfSelectedComponents.insert(dr);
        }
        if(*str==QString("rectangle"))
        {
            Rectangle  *rl;
            rl=(Rectangle*)dr;
            flag=flag+rl->checkSelection(x,y);
            if(rl->checkSelection(x,y)) this->setOfSelectedComponents.insert(dr);
        }
        if(*str==QString("line"))
        {
            Line  *l;
            l=(Line*)dr;
            flag=flag+l->checkSelection(x,y);
            if(l->checkSelection(x,y)) this->setOfSelectedComponents.insert(dr);
        }
        if(*str==QString("freeHandList"))
        {
            FreeHandList *freeHandList;
            freeHandList=(FreeHandList*)dr;
            flag=flag+freeHandList->checkSelection(x,y);
            if(freeHandList->checkSelection(x,y)) this->setOfSelectedComponents.insert(dr);
        }
        delete str;*/

    }
        return flag;
}


void TMView::release()
{
    DrawableComponent *dr;
    for(int i=0;i<this->list->size();i++)
    {
        dr=this->list->last();
        list->removeLast();
        delete dr;
    }
}

QList<DrawableComponent *> TMView::getSelectedComponents()
{
    return this->setOfSelectedComponents.values();
}

void TMView::clearAllSelectedComponents()
{
    QList<DrawableComponent*> tmpList=this->setOfSelectedComponents.values();
    QListIterator<DrawableComponent*> iter(tmpList);
    while(iter.hasNext()) iter.next()->setIsSelected(0);
    this->setOfSelectedComponents.clear();
}

void TMView::addToSelectedComponents(DrawableComponent *dr)
{
    this->setOfSelectedComponents.insert(dr);
}

void TMView::deleteFromSelectedComponents(DrawableComponent *dr)
{
    dr->setIsSelected(0);
    this->setOfSelectedComponents.remove(dr);
}

int TMView::sizeOfSelectedComponents()
{
    return this->setOfSelectedComponents.size();
}
