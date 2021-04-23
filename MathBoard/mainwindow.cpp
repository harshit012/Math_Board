#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QMainWindow::showFullScreen();
    ui->setupUi(this);
    this->ctrlKeyPressed=0;

    QPixmap pickButtonIcon(":/img/icons/tools/pick.png");
    this->ui->pickButton->setIcon(pickButtonIcon);

    QPixmap freeHandButtonIcon(":/img/icons/tools/freehand3.png");
    this->ui->freeHandButton->setIcon(freeHandButtonIcon);

    QPixmap rectangleButtonIcon(":/img/icons/tools/rectangle.png");
    this->ui->rectangleButton->setIcon(rectangleButtonIcon);
    this->ui->rectangleButton->setIconSize(QSize(21,23));

    QPixmap ellipseButtonIcon(":/img/icons/tools/ellipse.png");
    this->ui->ellipseButton->setIcon(ellipseButtonIcon);
    this->ui->ellipseButton->setIconSize(QSize(20,20));

    QPixmap clearAllButtonIcon(":/img/icons/tools/clear.png");
    this->ui->clearButton->setIcon(clearAllButtonIcon);
    this->ui->clearButton->setIconSize(QSize(65,65));

    QPixmap lineButtonIcon(":/img/icons/tools/line.png");
    this->ui->lineButton->setIcon(lineButtonIcon);


    QPixmap saveButtonIcon(":/img/icons/tools/save.png");
    this->ui->saveButton->setIcon(saveButtonIcon);
    this->ui->saveButton->setIconSize(QSize(65,65));

    QPixmap screenShotButtonIcon(":/img/icons/tools/screenShot.png");
    this->ui->scButton->setIcon(screenShotButtonIcon);
    this->ui->scButton->setIconSize(QSize(65,65));

    QPixmap openButtonIcon(":/img/icons/tools/open.png");
    this->ui->openButton->setIcon(openButtonIcon);
    this->ui->openButton->setIconSize(QSize(65,65));

    QPixmap newButtonIcon(":/img/icons/tools/new.png");
    this->ui->newButton->setIcon(newButtonIcon);
    this->ui->newButton->setIconSize(QSize(65,65));

    QPixmap colorButtonIcon(":/img/icons/tools/color.png");
    this->ui->colorButton->setIcon(colorButtonIcon);
    this->ui->colorButton->setIconSize(QSize(65,65));
    this->ui->pageOptionColor->setIcon(colorButtonIcon);
    this->ui->pageOptionColor->setIconSize(QSize(65,65));

    QPixmap pixmapButtonIcon(":/img/icons/tools/pixmap.png");
    this->ui->pixmapButton->setIcon(pixmapButtonIcon);
    this->ui->pixmapButton->setIconSize(QSize(65,65));

    QPixmap deleteButtonIcon(":/img/icons/tools/delete.png");
    this->ui->deleteButton->setIcon(deleteButtonIcon);
    this->ui->deleteButton->setIconSize(QSize(65,65));

    QPixmap resizeButtonIcon(":/img/icons/tools/resize.png");
    this->ui->resizeButton->setIcon(resizeButtonIcon);
    this->ui->resizeButton->setIconSize(QSize(65,65));

    QPixmap cButtonIcon(":/img/icons/tools/c.png");
    this->ui->cButton->setIcon(cButtonIcon);
    this->ui->cButton->setIconSize(QSize(65,65));

    QPixmap undoButtonIcon(":/img/icons/tools/undo.png");
    this->ui->undoButton->setIcon(undoButtonIcon);
    this->ui->undoButton->setIconSize(QSize(65,65));

    QPixmap redoButtonIcon(":/img/icons/tools/redo.png");
    this->ui->redoButton->setIcon(redoButtonIcon);
    this->ui->redoButton->setIconSize(QSize(65,65));

    QPixmap symbolButtonIcon(":/img/icons/tools/symbols.png");
    this->ui->sButton->setIcon(symbolButtonIcon);
    this->ui->sButton->setIconSize(QSize(75,75));

    setIconOnSymbol();

    this->ui->pickButton->setToolTip("Pick");
    this->ui->lineButton->setToolTip("Line");
    this->ui->freeHandButton->setToolTip("FreeHand");
    this->ui->ellipseButton->setToolTip("Ellipse");
    this->ui->rectangleButton->setToolTip("Rectangle");
    this->ui->clearButton->setToolTip("Clear All");

    this->ui->saveButton->setToolTip("Save");
    this->ui->openButton->setToolTip("Open");
    this->currentDSIndex=0;
    this->lastSize=0;
    this->currentTool="";
    this->activeRadioButtons=1;
    this->isMousePressed=0;

    this->mode=0;
    this->ui->plainRadioButton->setChecked(true);
    list.push_back(new TMView());
    this->mapList.push_back(new QMap<int,DrawableComponent*>);
    currentTMView=list[0];

    this->ui->radioButton1->setVisible(true);
    this->ui->radioButton1->setChecked(true);
    this->ui->radioButton2->setVisible(false);
    this->ui->radioButton3->setVisible(false);
    this->ui->radioButton4->setVisible(false);
    this->ui->radioButton5->setVisible(false);
    this->ui->radioButton6->setVisible(false);
    this->ui->radioButton7->setVisible(false);
    this->ui->radioButton8->setVisible(false);
    this->ui->radioButton9->setVisible(false);
    this->ui->radioButton10->setVisible(false);

    this->ui->temp1->setVisible(false);
    this->ui->temp2->setVisible(false);

    this->ui->nameFrame->setVisible(false);
    this->ui->pageOptionFrame->setVisible(false);
    this->pageOptionFrameVisible=0;
    this->ui->copyButton->setVisible(false);


    this->ui->table->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
    this->ui->table->verticalHeader()->hide();
    this->ui->table->setSelectionBehavior(QAbstractItemView::SelectRows);
    QFont font("georgia",8);
    this->ui->table->setFont(font);

    this->recorder=new Recorder();

    this->wtPixmap=new QPixmap(":/images/background_images/wt2.jpg");
    this->woodenFrame=new QPixmap(":/images/background_images/woodenBoard.png");
    this->width=3;
    this->rectangleFlag=0;
    this->count=0;
    this->oldStartX=0;
    this->oldStartY=0;
    this->shiftKeyPressed=0;
    this->pageWidth=3;
    this->pageColor="#85e0ff";

    this->graph=new Graph();
    this->linedPage=new LinedPage();

    this->cScreenText=QString("");
    this->ui->cScreenLabel->setText("0");
      this->ui->cScreenLabel->setAlignment(Qt::AlignRight);
     this->operatorSelected="";
    this->firstValue=0.0;
    this->calculatorVisible=0;
    this->ui->cFrame->setVisible(false);
    this->ui->clickImageButton->setVisible(false);

    this->symbolVisible=0;
    this->ui->sFrame->setVisible(false);

    QWidget::setWindowTitle("Math Board");
    QPixmap logoIcon(":/img/icons/tools/logo.png");
    QWidget::setWindowIcon(logoIcon);

    QShortcut *shortcut1=new QShortcut(QKeySequence(Qt::CTRL+Qt::Key_C),this);
    QObject::connect(shortcut1,SIGNAL(activated()),this,SLOT(on_copyButton_clicked()));
    QShortcut *shortcut2=new QShortcut(QKeySequence(Qt::CTRL+Qt::Key_Z),this);
    QObject::connect(shortcut2,SIGNAL(activated()),this,SLOT(on_undoButton_clicked()));
    QShortcut *shortcut3=new QShortcut(QKeySequence(Qt::CTRL+Qt::Key_Y),this);
    QObject::connect(shortcut3,SIGNAL(activated()),this,SLOT(on_redoButton_clicked()));
    QShortcut *shortcut4=new QShortcut(QKeySequence(Qt::Key_Delete),this);
    QObject::connect(shortcut4,SIGNAL(activated()),this,SLOT(on_deleteButton_clicked()));
    QShortcut *shortcut5=new QShortcut(QKeySequence(Qt::Key_Print),this);
    QObject::connect(shortcut5,SIGNAL(activated()),this,SLOT(on_scButton_clicked()));
    QShortcut *shortcut6=new QShortcut(QKeySequence(Qt::Key_PageUp),this);
    QObject::connect(shortcut6,SIGNAL(activated()),this,SLOT(on_temp1_clicked()));
    QShortcut *shortcut7=new QShortcut(QKeySequence(Qt::Key_PageDown),this);
    QObject::connect(shortcut7,SIGNAL(activated()),this,SLOT(on_temp2_clicked()));

    populateRadioButtons();
    this->isMousePressed=0;
    setMouseTracking(true);
    setHighlights();
}

MainWindow::~MainWindow()
{
    TMView *tm;
    for(int i=0;i<=9;i++)
    {
        this->currentDSIndex=i;
        this->on_clearButton_clicked();
    }
    delete this->woodenFrame;
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.boundingRect(QRect(111,68,1319,747),1,"");
    painter.fillRect(QRect(0,0,1600,900),QColor("Black"));
    painter.drawPixmap(QRect(0,0,1600,900),*(this->wtPixmap));
    painter.drawPixmap(85,43,1368,795,*(this->woodenFrame));
    painter.fillRect(QRect(111,68,1319,747),QColor("White"));
    painter.setClipRegion(QRegion(111,68,1319,747));
    if(this->mode==1)
    {
        this->graph->setWidth(this->pageWidth);
        this->graph->setColor(this->pageColor);
        this->graph->draw(&painter);
    }
    if(this->mode==2)
    {
        this->linedPage->setWidth(this->pageWidth);
        this->linedPage->setColor(this->pageColor);
        this->linedPage->draw(&painter);
    }
    this->list[this->currentDSIndex]->draw(&painter);
}



void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    setMouseTracking(true);
    int x=event->pos().x();
    int y=event->pos().y();
    int w=this->width/2;
    if(x<(111+w)||y<(68+w)||x>(111+1319-w)||y>(68+747-w)) return;
    if(this->isMousePressed==0) return;
    if(currentTool==QString("freeHand"))
    {
        this->freeHand->setX2(x);
        this->freeHand->setY2(y);
        this->freeHand->setWidth(this->width);
        this->freeHand->setColor(this->color);
        this->freeHandList->add(freeHand);
        this->freeHandList->setColor(this->color);
        if(count==0)this->currentTMView->add(freeHandList);
        update();
        this->freeHand=new FreeHand();
        this->freeHand->setX1(x);
        this->freeHand->setY1(y);
    }
    if(currentTool==QString("rectangle"))
    {
        this->rectangle->setX2(x-this->oldX);
        this->rectangle->setY2(y-this->oldY);
        this->rectangle->setColor(this->color);
                this->rectangle->setWidth(this->width);
        this->rectangle->setName("rectangle");
        if(this->shiftKeyPressed)
        {
            this->rectangle->setName("square");
            this->rectangle->createSquare(true);
        }
        if(count==0) this->currentTMView->add(rectangle);
        update();
    }
    if(this->currentTool==QString("ellipse"))
    {
       this->ellipse->setX2(x-this->oldX);
       this->ellipse->setY2(y-this->oldY);
       this->ellipse->setColor(this->color);
       this->ellipse->setWidth(this->width);
        this->ellipse->setName("ellipse");
       if(this->shiftKeyPressed)
       {
           this->ellipse->setName("circle");
           this->ellipse->createCircle(true);
       }if(count==0) this->currentTMView->add(ellipse);
        update();
    }
    if(this->currentTool==QString("line"))
    {
       this->line->setX2(x);
       this->line->setY2(y);
       this->line->setColor(this->color);
       this->line->setWidth(this->width);
       if(count==0) this->currentTMView->add(line);
       update();
    }

    if(this->currentTool==QString("pick"))
    {
        int difX=x-this->oldStartX;
        int difY=y-this->oldStartY;
        move(difX,difY);
        oldStartX=x;
        oldStartY=y;
        update();
    }
    if(this->currentTool==QString("resize"))
    {
        this->setCursor(Qt::CrossCursor);
        int difX=x-this->oldStartX;
        int difY=y-this->oldStartY;
        resize(difX,difY);
        oldStartX=x;
        oldStartY=y;
        update();
    }
    this->count++;
}

void MainWindow::mousePressEvent(QMouseEvent*event)
{
    setMouseTracking(true);
    int x=event->pos().x();
    int y=event->pos().y();
    this->oldX=x;
    this->oldY=y;
    int w=this->width/2;
    if(x<(111+w)||y<(68+w)||x>(111+1319-w)||y>(68+747-w)) return;
    if(currentTool==QString("freeHand"))
    {
        this->freeHandList=new FreeHandList();
        this->freeHand=new FreeHand();
        this->freeHand->setX1(x);
        this->freeHand->setY1(y);
    }
    if(currentTool==QString("rectangle"))
    {
        this->rectangle=new Rectangle();
        rectangle->setX1(x);
        rectangle->setY1(y);
    }
    if(this->currentTool==QString("ellipse"))
    {
        this->ellipse=new Ellipse();
        ellipse->setX1(x);
        ellipse->setY1(y);
    }
    if(this->currentTool==QString("line"))
    {
        this->line=new Line();
        line->setX1(x);
        line->setY1(y);
    }

    if(this->currentTool==QString("pick"))
    {
        int countOfSelectedComponents=0;
        this->setCursor(Qt::ClosedHandCursor);
        int flag;
        this->oldStartX=x;
        this->oldStartY=y;
        if(this->ctrlKeyPressed==0)
        {
            this->list[currentDSIndex]->clearAllSelectedComponents();
        }
        countOfSelectedComponents=this->list[currentDSIndex]->shouldSelect(x,y);
        this->SelectTheSelectedComponents();
        setHighlights();
        update();
    }
    if(this->currentTool==QString("resize"))
    {
        this->setCursor(Qt::ArrowCursor);
        this->oldStartX=x;
        this->oldStartY=y;
    }
    this->isMousePressed=1;
    this->count=0;
}

void MainWindow::mouseReleaseEvent(QMouseEvent*event)
{
    setMouseTracking(true);
    int x=event->pos().x();
    int y=event->pos().y();
    int w=this->width/2;
    if(x<(111+w)||y<(68+w)||x>(111+1319-w)||y>(68+747-w)) return;
    if(isMousePressed==0) return;
    if(this->currentTool==QString("freeHand"))
    {
        delete this->freeHand;
        populateTable();
    }
    if(this->currentTool==QString("rectangle"))
    {
        populateTable();
    }if(this->currentTool==QString("ellipse"))
    {
        populateTable();
    }
    if(this->currentTool==QString("line"))
    {
        populateTable();
    }
    if(this->currentTool==QString("pick"))
    {
    this->setCursor(Qt::ArrowCursor);
    }
    setHighlights();
    this->count=0;
    this->isMousePressed=0;

}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Control)
    {
        this->ctrlKeyPressed=1;
    }
    if(event->key()==Qt::Key_Shift)
    {
        this->shiftKeyPressed=1;
    }
}
void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Control)
    {
        this->ctrlKeyPressed=0;
    }
    if(event->key()==Qt::Key_Shift)
    {
        this->shiftKeyPressed=0;
    }
}

void MainWindow::on_rectangleButton_clicked()
{
        this->setCursor(Qt::ArrowCursor);
        this->currentTool="rectangle";
}

void MainWindow::on_ellipseButton_clicked()
{
      this->setCursor(Qt::ArrowCursor);
      this->currentTool="ellipse";
}

void MainWindow::on_lineButton_clicked()
{
      this->setCursor(Qt::ArrowCursor);
      this->currentTool="line";
}

void MainWindow::on_pickButton_clicked()
{
    if(!(this->currentTool=="pick"))
    {
    this->currentTool="pick";
    }
    else
    {
        this->currentTool="";
        this->setCursor(Qt::ArrowCursor);
    }
}

void MainWindow::on_freeHandButton_clicked()
{

        this->setCursor(Qt::ArrowCursor);
        this->currentTool="freeHand";
}


void MainWindow::on_clearButton_clicked()
{
    this->list[currentDSIndex]->clearAllSelectedComponents();
    this->mapList[currentDSIndex]->clear();
    this->list[currentDSIndex]->clearList();
    this->ui->table->clear();
    update();
}

void MainWindow::on_closeButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(this,"Math Board","Are you sure you want to quit?",QMessageBox::Yes|QMessageBox::No);
    if(reply==QMessageBox::Yes)
    {
        on_clearButton_clicked();
        exit(0);
    }else
    {
        return;
    }
}


void MainWindow::on_widthSlider_valueChanged(int value)
{
    this->width=value;
    updateSelectedComponents();
}

void MainWindow::populateTable()
{
    int flag=0;
    QString *str;
    this->ui->table->clear();
    QList<DrawableComponent*> *list=this->currentTMView->getList();
    this->ui->table->setColumnCount(1);
    this->ui->table->setColumnWidth(0,110);
    this->ui->table->horizontalHeader()->hide();
    if(list->size()==0) return;
    if(list->size()==lastSize) return;
    QString *temp=list->at(list->size()-1)->toString();
    delete temp;
    mapList[currentDSIndex]->insert(mapList[currentDSIndex]->size(),list->at(list->size()-1));
    this->ui->table->setRowCount(mapList[currentDSIndex]->size());
    this->lastSize=list->size();
}

void MainWindow::populateMapList()
{
     this->mapList[currentDSIndex]->clear();
     QList<DrawableComponent*> *list=this->list[currentDSIndex]->getList();
     QListIterator<DrawableComponent*> iter(*list);
     int count=0;
     while(iter.hasNext())
     {
         this->mapList[currentDSIndex]->insert(count,iter.next());
         count++;
     }
}




void MainWindow::on_newButton_clicked()
{
    int size=this->list.size();
    if(size>9) return;
    this->list.push_back(new TMView());
    this->mapList.push_back(new QMap<int,DrawableComponent*>);
    this->radioButtons[size]->setVisible(true);
    this->radioButtons[size]->setChecked(true);
    this->currentTMView=list.last();
    this->currentDSIndex=list.size()-1;
    this->ui->table->clear();
    update();
}

void MainWindow::populateRadioButtons()
{
    radioButtons.push_back(this->ui->radioButton1);
    radioButtons.push_back(this->ui->radioButton2);
    radioButtons.push_back(this->ui->radioButton3);
    radioButtons.push_back(this->ui->radioButton4);
    radioButtons.push_back(this->ui->radioButton5);
    radioButtons.push_back(this->ui->radioButton6);
    radioButtons.push_back(this->ui->radioButton7);
    radioButtons.push_back(this->ui->radioButton8);
    radioButtons.push_back(this->ui->radioButton9);
    radioButtons.push_back(this->ui->radioButton10);
}


void MainWindow::on_radioButton1_clicked()
{
    this->ui->radioButton1->setVisible(true);
    this->currentTMView=this->list[0];
    this->currentDSIndex=0;
    setHighlights();
    update();

}

void MainWindow::on_radioButton2_clicked()
{
    this->ui->radioButton2->setVisible(true);
    this->currentTMView=this->list[1];
    this->currentDSIndex=1;
    setHighlights();
    update();

}

void MainWindow::on_radioButton3_clicked()
{
    this->ui->radioButton3->setVisible(true);
    this->currentTMView=this->list[2];
    this->currentDSIndex=2;
    setHighlights();
    update();

}

void MainWindow::on_radioButton4_clicked()
{
    this->ui->radioButton4->setVisible(true);
    this->currentTMView=this->list[3];
    this->currentDSIndex=3;
    setHighlights();
    update();

}

void MainWindow::on_radioButton5_clicked()
{
    this->ui->radioButton5->setVisible(true);
    this->currentTMView=this->list[4];
    this->currentDSIndex=4;
    setHighlights();
    update();

}

void MainWindow::on_radioButton6_clicked()
{
    this->ui->radioButton6->setVisible(true);
    this->currentTMView=this->list[5];
    this->currentDSIndex=5;
    setHighlights();
    update();

}

void MainWindow::on_radioButton7_clicked()
{
    this->ui->radioButton7->setVisible(true);
    this->currentTMView=this->list[6];
    this->currentDSIndex=6;
    setHighlights();
    update();

}

void MainWindow::on_radioButton8_clicked()
{
    this->ui->radioButton8->setVisible(true);
    this->currentTMView=this->list[7];
    this->currentDSIndex=7;
    setHighlights();
    update();

}

void MainWindow::on_radioButton9_clicked()
{
    this->ui->radioButton9->setVisible(true);
    this->currentTMView=this->list[8];
    this->currentDSIndex=8;
    setHighlights();
    update();

}

void MainWindow::on_radioButton10_clicked()
{
    this->ui->radioButton10->setVisible(true);
    this->currentTMView=this->list[9];
    this->currentDSIndex=9;
    setHighlights();
    update();
}


void MainWindow::on_closeBoardButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(this,"Math Board","Do you want to save file?",QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
    if(reply==QMessageBox::Yes) on_saveButton_clicked();
    if(reply==QMessageBox::Cancel) return;
    if(this->list.size()==1)
    {
        on_clearButton_clicked();
        exit(0);
    }
    this->ui->radioButton1->setChecked(1);
    this->radioButtons[list.size()-1]->setVisible(false);
    on_clearButton_clicked();
    this->list.removeAt(currentDSIndex);
    this->mapList.removeAt(currentDSIndex);
    this->on_radioButton1_clicked();
    setHighlights();
    update();
}

void MainWindow::on_saveButton_clicked()
{
    FreeHand *fr;
    FreeHandList *freeHandList;
     QString *str;
    QString fileName=QFileDialog::getSaveFileName(this,tr("Save file"),"G:\\Drawings","Painting (*.pnt)");
    if(fileName.size()==0) return;
    QFile file(fileName);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QList<DrawableComponent*> *list=this->list[currentDSIndex]->getList();
    QJsonArray jsonArray;
    for(int i=0;i<list->size();i++)
    {
        QJsonObject jsonObject;
        QString name=*(list->at(i)->toString());
        if(name==QString("freeHandList"))
        {
            freeHandList=((FreeHandList*)list->at(i));
            QList<FreeHand*> *tmpList=freeHandList->getList();
            jsonObject.insert("name",name);
            jsonObject.insert("sizeOfFreeHandList",tmpList->size());
            for(int i=0;i<tmpList->size();i++)
            {
                QJsonObject freeHandObject;
                fr=tmpList->at(i);
                str=fr->toString();
                freeHandObject.insert("name",*str);
                freeHandObject.insert("x1",fr->getX1());
                freeHandObject.insert("x2",fr->getX2());
                freeHandObject.insert("y1",fr->getY1());
                freeHandObject.insert("y2",fr->getY2());
                freeHandObject.insert("width",fr->getWidth());
                freeHandObject.insert("color",fr->getColor().name());
                jsonObject.insert(QString("index")+QString::number(i),freeHandObject);
                delete str;
            }
            jsonArray.append(jsonObject);
            continue;
        }
        if(name==QString("pixmap"))
        {
            jsonObject.insert("name",name);
            jsonObject.insert("name",name);
            jsonObject.insert("x1",list->at(i)->getX1());
            jsonObject.insert("x2",list->at(i)->getX2());
            jsonObject.insert("y1",list->at(i)->getY1());
            jsonObject.insert("y2",list->at(i)->getY2());
            jsonObject.insert("path",((PixMap*)list->at(i))->getPath());
            continue;
        }
        jsonObject.insert("name",name);
        jsonObject.insert("x1",list->at(i)->getX1());
        jsonObject.insert("x2",list->at(i)->getX2());
        jsonObject.insert("y1",list->at(i)->getY1());
        jsonObject.insert("y2",list->at(i)->getY2());
        jsonObject.insert("width",list->at(i)->getWidth());
        jsonObject.insert("color",list->at(i)->getColor().name());
        jsonArray.append(jsonObject);
    }
    QJsonDocument document;
    document.setArray(jsonArray);
    file.write(document.toJson());
    file.close();
}

void MainWindow::on_openButton_clicked()
{
    FreeHandList *freeHandList;
    PixMap *pixmap;
    FreeHand *freeHand;
    int sizeOfFreeHandList=0;
    int x1,x2,y1,y2,width,last;
    DrawableComponent *dr;
    QString fileName=QFileDialog::getOpenFileName(this,tr("open file"),"G:\\Drawings","Painting (*.pnt)");
    if(fileName.size()==0) return;
    QFile file(fileName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    //QString data=file.readAll();
    QJsonDocument document=QJsonDocument::fromJson(file.readAll());
    QJsonArray jsonArray=document.array();
    for(int i=0;i<jsonArray.size();i++)
    {
        QJsonValue value=jsonArray[i];
        QJsonObject jsonObject=value.toObject();
        QString name=jsonObject.value("name").toString();
        x1=jsonObject.value("x1").toInt();
        x2=jsonObject.value("x2").toInt();
        y1=jsonObject.value("y1").toInt();
        y2=jsonObject.value("y2").toInt();
        width=jsonObject.value("width").toInt();
        last=jsonObject.value("last").toInt();
        QColor color;
        color.setNamedColor(jsonObject.value("color").toString());

        if(name==QString("line")) dr=new Line();
        if(name==QString("ellipse")) dr=new Ellipse();
        if(name==QString("rectangle")) dr=new Rectangle();
        if(name==QString("freeHandList"))
         {
            dr=new FreeHandList();
            freeHandList=(FreeHandList*)dr;
            sizeOfFreeHandList=jsonObject.value("sizeOfFreeHandList").toInt();
            for(int i=0;i<sizeOfFreeHandList;i++)
            {

                freeHand=new FreeHand();
                QJsonObject tmpObj=jsonObject.value(QString("index")+QString::number(i)).toObject();
                x1=tmpObj.value("x1").toInt();
                x2=tmpObj.value("x2").toInt();
                y1=tmpObj.value("y1").toInt();
                y2=tmpObj.value("y2").toInt();
                color.setNamedColor(tmpObj.value("color").toString());
                width=tmpObj.value("width").toInt();
                freeHand->setX1(x1);
                freeHand->setX2(x2);
                freeHand->setY1(y1);
                freeHand->setY2(y2);
                freeHand->setWidth(width);
                freeHand->setColor(color);
                freeHandList->add(freeHand);
            }
            this->list[currentDSIndex]->add(freeHandList);
            populateTable();
            continue;
          }
        if(name==QString("pixmap"))
        {
            QString path=jsonObject.value("path").toString();
            pixmap=new PixMap();
             pixmap->setX1(x1);
             pixmap->setX2(x2);
             pixmap->setY1(y1);
             pixmap->setY2(y2);
            pixmap->setPixmap(new QPixmap(path));
            pixmap->setPath(path);
        }


        dr->setX1(x1);
        dr->setX2(x2);
        dr->setY1(y1);
        dr->setY2(y2);
        dr->setWidth(width);
        dr->setColor(color);
        this->list[currentDSIndex]->add(dr);
        populateTable();
    }
    setHighlights();
    update();
    file.close();
}

void MainWindow::on_table_cellClicked(int row, int column)
{
    int indexOfMap=this->mapList[currentDSIndex]->size()-row-1;
    DrawableComponent *dr=(*(this->mapList[currentDSIndex]))[indexOfMap];
    QString *str=dr->toString();

    if(!dr->getIsSelected())
    {
               dr->setIsSelected(1);
               this->list[currentDSIndex]->addToSelectedComponents(dr);
    }
    else
    {
                 dr->setIsSelected(0);
                 this->list[currentDSIndex]->deleteFromSelectedComponents(dr);
    }

    setHighlights();
    update();
    delete str;
}

void MainWindow::setHighlights()
{
    this->ui->table->clear();
    int flag=0;
    QLabel *label;
    this->ui->table->setRowCount(this->mapList[currentDSIndex]->size());
    QList<DrawableComponent*> tmpList=this->mapList[currentDSIndex]->values();
    for(int i=tmpList.size()-1;i>-1;i--)
    {
        label=new QLabel(tmpList[i]->getName());
        label->setAlignment(Qt::AlignCenter);
        if(tmpList[i]->getIsSelected()) label->setFont(QFont("Time New Roman",14,QFont::Bold));
        this->ui->table->setCellWidget(flag,0,label);
        flag++;
    }
}

void MainWindow::SelectTheSelectedComponents()
{
    QList<DrawableComponent*> tmplist=this->list[currentDSIndex]->getSelectedComponents();
    for(int i=0;i<tmplist.size();i++)
    {
        tmplist[i]->setIsSelected(1);
    }
    update();
}










void MainWindow::setIconOnSymbol()
{
    QPixmap plusButtonIcon(":/iconImage/icons/basic/plus.png");
    this->ui->sPlusButton->setIcon(plusButtonIcon);
    this->ui->sPlusButton->setIconSize(QSize(65,65));

    QPixmap minusButtonIcon(":/iconImage/icons/basic/minus.png");
    this->ui->sMinusButton->setIcon(minusButtonIcon);
    this->ui->sMinusButton->setIconSize(QSize(65,65));

    QPixmap multiplyButtonIcon(":/iconImage/icons/basic/multiply.png");
    this->ui->sMultiplyButton->setIcon(multiplyButtonIcon);
    this->ui->sMultiplyButton->setIconSize(QSize(65,65));

    QPixmap divideButtonIcon(":/iconImage/icons/basic/divide.png");
    this->ui->sDivideButton->setIcon(divideButtonIcon);
    this->ui->sDivideButton->setIconSize(QSize(65,65));

    QPixmap infinityButtonIcon(":/iconImage/icons/basic/infinity.png");
    this->ui->sInfinityButton->setIcon(infinityButtonIcon);
    this->ui->sInfinityButton->setIconSize(QSize(65,65));

    QPixmap percentageButtonIcon(":/iconImage/icons/basic/percentage.png");
    this->ui->sPercentageButton->setIcon(percentageButtonIcon);
    this->ui->sPercentageButton->setIconSize(QSize(65,65));

    QPixmap plusMinusButtonIcon(":/iconImage/icons/basic/plusMinus.png");
    this->ui->sPlusMinusButton->setIcon(plusMinusButtonIcon);
    this->ui->sPlusMinusButton->setIconSize(QSize(65,65));

    //sBracesFrame

    QPixmap roundBracesOpenButtonIcon(":/symbols/icons/braces/roundBracketOpen.PNG");
    this->ui->sRoundBracesOpen->setIcon(roundBracesOpenButtonIcon);

    QPixmap roundBracesCloseButtonIcon(":/symbols/icons/braces/roundBracketClose.PNG");
    this->ui->sRoundBracesClose->setIcon(roundBracesCloseButtonIcon);

    QPixmap squareOpenButtonIcon(":/symbols/icons/braces/squareBracesOpen.PNG");
    this->ui->sSquareBracesOpen->setIcon(squareOpenButtonIcon);

    QPixmap squareBracesCloseButtonIcon(":/symbols/icons/braces/squareBracesClose.PNG");
    this->ui->sSquareBracesClose->setIcon(squareBracesCloseButtonIcon);

   QPixmap lessThanButtonIcon(":/symbols/icons/braces/lessThan.PNG");
    this->ui->sLessThan->setIcon(lessThanButtonIcon);

    QPixmap greaterThanButtonIcon(":/symbols/icons/braces/greaterThan.PNG");
    this->ui->sGreaterThan->setIcon(greaterThanButtonIcon);

    QPixmap oneIcon(":/symbols/icons/count/one.PNG");
    this->ui->sOne->setIcon(oneIcon);

    QPixmap twoIcon(":/symbols/icons/count/two.PNG");
    this->ui->sTwo->setIcon(twoIcon);

    QPixmap threeIcon(":/symbols/icons/count/three.PNG");
    this->ui->sThree->setIcon(threeIcon);

    QPixmap fourIcon(":/symbols/icons/count/four.PNG");
    this->ui->sFour->setIcon(fourIcon);

    QPixmap fiveIcon(":/symbols/icons/count/five.PNG");
    this->ui->sFive->setIcon(fiveIcon);

    QPixmap sixIcon(":/symbols/icons/count/six.PNG");
    this->ui->sSix->setIcon(sixIcon);

    QPixmap sevenIcon(":/symbols/icons/count/seven.PNG");
    this->ui->sSeven->setIcon(sevenIcon);

    QPixmap eightIcon(":/symbols/icons/count/eight.PNG");
    this->ui->sEight->setIcon(eightIcon);

    QPixmap nineIcon(":/symbols/icons/count/nine.PNG");
    this->ui->sNine->setIcon(nineIcon);

    QPixmap zeroIcon(":/symbols/icons/count/zero.PNG");
    this->ui->sZero->setIcon(zeroIcon);

    QPixmap decimalIcon(":/symbols/icons/count/decimal.PNG");
    this->ui->sDecimal->setIcon(decimalIcon);

    QPixmap halfIcon(":/symbols/icons/count/half.PNG");
    this->ui->sHalf->setIcon(halfIcon);

    QPixmap differentiationIcon(":/symbols/icons/dif/differentiation.PNG");
    this->ui->sDifferentiation->setIcon(differentiationIcon);
    this->ui->sDifferentiation->setIconSize(QSize(25,25));

    QPixmap integralIcon(":/symbols/icons/dif/integral.PNG");
    this->ui->sIntegral->setIcon(integralIcon);
    this->ui->sIntegral->setIconSize(QSize(25,25));

    QPixmap integrationIcon(":/symbols/icons/dif/integration.PNG");
    this->ui->sIntegration->setIcon(integrationIcon);
    this->ui->sIntegration->setIconSize(QSize(25,25));

    QPixmap approximatelyIcon(":/symbols/icons/equalto/approximately.PNG");
    this->ui->sApproximately->setIcon(approximatelyIcon);

    QPixmap approximationIcon(":/symbols/icons/equalto/approximation.png");
    this->ui->sApproximation->setIcon(approximationIcon);

    QPixmap congruentIcon(":/symbols/icons/equalto/congruent.png");
    this->ui->sCongruent->setIcon(congruentIcon);

    QPixmap equalsToIcon(":/symbols/icons/equalto/equalsTo.png");
    this->ui->sEqualTo->setIcon(equalsToIcon);

    QPixmap notEqualToIcon(":/symbols/icons/equalto/notEqualTo.png");
    this->ui->sNotEqualsTo->setIcon(notEqualToIcon);

    QPixmap alphaIcon(":/symbols/icons/notation/alpha.png");
    this->ui->sAlpha->setIcon(alphaIcon);

    QPixmap betaIcon(":/symbols/icons/notation/beta.png");
    this->ui->sBeta->setIcon(betaIcon);

    QPixmap muIcon(":/symbols/icons/notation/mu.png");
    this->ui->sMu->setIcon(muIcon);

    QPixmap omegaIcon(":/symbols/icons/notation/omega.png");
    this->ui->sOmega->setIcon(omegaIcon);

    QPixmap piIcon(":/symbols/icons/notation/pie.png");
    this->ui->sPie->setIcon(piIcon);

    QPixmap avgIcon(":/symbols/icons/root/avg.png");
    this->ui->sAvg->setIcon(avgIcon);


    QPixmap cubeRootIcon(":/symbols/icons/root/cubeRoot.PNG");
    this->ui->sCubeRoot->setIcon(cubeRootIcon);
    this->ui->sCubeRoot->setIconSize(QSize(25,25));


    QPixmap factorialIcon(":/symbols/icons/root/factorial.PNG");
    this->ui->sFactorial->setIcon(factorialIcon);


    QPixmap rootIcon(":/symbols/icons/root/root.png");
    this->ui->sRoot->setIcon(rootIcon);

    QPixmap elementIcon(":/symbols/icons/set/element.PNG");
    this->ui->sElement->setIcon(elementIcon);

    QPixmap emptySetIcon(":/symbols/icons/set/emptySet.PNG");
    this->ui->sEmptySet->setIcon(emptySetIcon);

    QPixmap intersectionSetIcon(":/symbols/icons/set/intersectionSet.PNG");
    this->ui->sIntersectionSet->setIcon(intersectionSetIcon);

    QPixmap notElementIcon(":/symbols/icons/set/notElement.PNG");
    this->ui->sNotElement->setIcon(notElementIcon);

    QPixmap proportionalityIcon(":/symbols/icons/set/proportionality.PNG");
    this->ui->sProportionality->setIcon(proportionalityIcon);
    this->ui->sProportionality->setIconSize(QSize(25,25));


    QPixmap realNumberIcon(":/symbols/icons/set/realNumber.PNG");
    this->ui->sRealNumber->setIcon(realNumberIcon);
    this->ui->sRealNumber->setIconSize(QSize(25,25));


    QPixmap sigmaIcon(":/symbols/icons/set/sigma.png");
    this->ui->sSigma->setIcon(sigmaIcon);

    QPixmap subsetIcon(":/symbols/icons/set/subset.PNG");
    this->ui->sSubset->setIcon(subsetIcon);

    QPixmap unionSetIcon(":/symbols/icons/set/unionSet.PNG");
    this->ui->sUnionSet->setIcon(unionSetIcon);







}















void MainWindow::move(int finalX, int finalY)
{
    QList<DrawableComponent*> tmplist=this->list[currentDSIndex]->getSelectedComponents();


    for(int i=0;i<tmplist.size();i++)
    {
        tmplist[i]->moveTo(finalX,finalY);
    }

}

void MainWindow::resize(int finalX, int finalY)
{
    DrawableComponent *dr;
    QList<DrawableComponent*> tmplist=this->list[currentDSIndex]->getSelectedComponents();

    for(int i=0;i<tmplist.size();i++)
    {
        dr=tmplist[i];
        dr->resizeUpto(finalX,finalY,this->shiftKeyPressed);
    }
}

void MainWindow::clickImage()
{
     QPixmap screenShot(QGuiApplication::primaryScreen()->grabWindow(0));
     this->scCount=this->scCount+1;
}

void MainWindow::pageUp()
{
    if(this->currentDSIndex==0) this->currentDSIndex=this->list.size()-1;
    else this->currentDSIndex=this->currentDSIndex-1;
    this->radioButtons[currentDSIndex]->setVisible(true);
    this->radioButtons[currentDSIndex]->setChecked(true);
    this->currentTMView=this->list[currentDSIndex];
    setHighlights();
    update();
}

void MainWindow::pageDown()
{
    if(this->currentDSIndex==this->list.size()-1) this->currentDSIndex=0;
    else this->currentDSIndex=this->currentDSIndex+1;
    this->radioButtons[currentDSIndex]->setVisible(true);
    this->radioButtons[currentDSIndex]->setChecked(true);
    this->currentTMView=this->list[currentDSIndex];
    setHighlights();
    update();
}




void MainWindow::on_copyButton_clicked()
{
    int x1,x2,y1,y2,width;
    QList<DrawableComponent*> tmpList=this->list[currentDSIndex]->getSelectedComponents();
    this->list[currentDSIndex]->clearAllSelectedComponents();
    DrawableComponent *dr,*drCopy;
    QString *str;
    QColor color;
    for(int i=0;i<tmpList.size();i++)
    {
        dr=tmpList[i];
        str=dr->toString();
        if(*str==QString("ellipse")) drCopy=new Ellipse();
        if(*str==QString("rectangle")) drCopy=new Rectangle();
        if(*str==QString("line")) drCopy=new Line();
        if(*str==QString("freeHandList"))
        {
            return;
        }
        x1=dr->getX1();
        y1=dr->getY1();
        x2=dr->getX2();
        y2=dr->getY2();
        width=dr->getWidth();
        color=dr->getColor();
        if(*str==QString("line"))
        {
            drCopy->setX1(x1+10);
            drCopy->setX2(x2+10);
            drCopy->setY1(y1+10);
            drCopy->setY2(y2+10);
        }
        else
        {
        drCopy->setX1(x1+10);
        drCopy->setX2(x2);
        drCopy->setY1(y1+10);
        drCopy->setY2(y2);
        }
        drCopy->setWidth(width);
        drCopy->setColor(color);
        this->list[currentDSIndex]->addToSelectedComponents(drCopy);
        this->list[currentDSIndex]->add(drCopy);
        populateTable();
    }
    SelectTheSelectedComponents();
    setHighlights();
    update();
}

void MainWindow::on_resizeButton_clicked()
{
    this->currentTool="resize";
}

void MainWindow::on_table_cellDoubleClicked(int row, int column)
{
    this->rowIndex=row;
    this->columnIndex=column;
    this->ui->nameFrame->setVisible(true);
}

void MainWindow::on_colorButton_clicked()
{
    this->color=QColorDialog::getColor(Qt::black,this);
    updateSelectedComponents();
}

void MainWindow::on_deleteButton_clicked()
{
    int key;
     DrawableComponent *dr;
     QList<DrawableComponent*> tmplist=this->list[currentDSIndex]->getSelectedComponents();
     if(tmplist.size()==0) return;

     QListIterator<DrawableComponent*> iter1(tmplist);
     while(iter1.hasNext())
     {
         dr=iter1.next();
         this->list[currentDSIndex]->remove(dr);
         //delete dr;
     }
     this->list[currentDSIndex]->clearAllSelectedComponents();
     this->populateMapList();
     this->setHighlights();
     QListIterator<DrawableComponent*> iter(tmplist);
     while(iter.hasNext()) delete iter.next();
     update();
}

void MainWindow::on_nameCancelButton_clicked()
{
    this->ui->nameFrame->setVisible(false);
}

void MainWindow::on_pushButton_clicked()
{
    this->ui->nameFrame->setVisible(false);
}

void MainWindow::on_nameSaveButton_clicked()
{
    QString name=this->ui->namelineEdit->text();
    if(name.size()==0)  return;
    this->mapList[currentDSIndex]->value(this->mapList[currentDSIndex]->size()-this->rowIndex-1)->setName(name);
    this->ui->nameFrame->setVisible(false);
    setHighlights();
}

void MainWindow::on_pixmapButton_clicked()
{
    QString fileName=QFileDialog::getOpenFileName(this,tr("open file"),"G:\\","All files (*.*)");
    if(fileName.size()==0) return;
    this->pixmap=new PixMap();
    this->pixmap->setX1(300);
    this->pixmap->setY1(300);
    this->pixmap->setX2(400);
    this->pixmap->setY2(200);
    this->pixmap->setPath(fileName);
    this->pixmap->setPixmap(new QPixmap(fileName));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    update();
}

void MainWindow::on_graphRadioButton_clicked()
{
    this->mode=1;
    update();
}

void MainWindow::on_pageRadioButton_clicked()
{
    this->mode=2;
    update();
}

void MainWindow::on_pageOptionColor_clicked()
{
    this->pageColor=QColorDialog::getColor(Qt::green,this);
    update();
}

void MainWindow::on_pageOptionSlider_valueChanged(int value)
{
    this->pageWidth=value;
    update();
}

void MainWindow::on_pageOptionButton_clicked()
{
    if(this->pageOptionFrameVisible==0)
    {
        this->ui->pageOptionFrame->setVisible(true);
        this->pageOptionFrameVisible=1;
        return;
    }
    this->ui->pageOptionFrame->setVisible(false);
    this->pageOptionFrameVisible=0;
}
void MainWindow::on_pageOptionCloseButton_clicked()
{
    this->ui->pageOptionFrame->setVisible(false);
    this->pageOptionFrameVisible=0;
}

void MainWindow::on_plainRadioButton_clicked()
{
    this->mode=0;
    update();
}

void MainWindow::on_c1Button_clicked()
{
  this->cScreenText.append("1");
  this->ui->cScreenLabel->setText(this->cScreenText);
  this->ui->cScreenLabel->setAlignment(Qt::AlignRight);
}

void MainWindow::on_c2Button_clicked()
{
    this->cScreenText.append("2");
    this->ui->cScreenLabel->setText(this->cScreenText);
    this->ui->cScreenLabel->setAlignment(Qt::AlignRight);
}

void MainWindow::on_c3Button_clicked()
{
    this->cScreenText.append("3");
    this->ui->cScreenLabel->setText(this->cScreenText);
    this->ui->cScreenLabel->setAlignment(Qt::AlignRight);
}



void MainWindow::on_c4Button_clicked()
{
    this->cScreenText.append("4");
    this->ui->cScreenLabel->setText(this->cScreenText);
    this->ui->cScreenLabel->setAlignment(Qt::AlignRight);
}

void MainWindow::on_c5Button_clicked()
{
    this->cScreenText.append("5");
    this->ui->cScreenLabel->setText(this->cScreenText);
    this->ui->cScreenLabel->setAlignment(Qt::AlignRight);
}

void MainWindow::on_c6Button_clicked()
{
    this->cScreenText.append("6");
    this->ui->cScreenLabel->setText(this->cScreenText);
    this->ui->cScreenLabel->setAlignment(Qt::AlignRight);
}

void MainWindow::on_c7Button_clicked()
{
    this->cScreenText.append("7");
    this->ui->cScreenLabel->setText(this->cScreenText);
    this->ui->cScreenLabel->setAlignment(Qt::AlignRight);
}

void MainWindow::on_c8Button_clicked()
{
    this->cScreenText.append("8");
    this->ui->cScreenLabel->setText(this->cScreenText);
    this->ui->cScreenLabel->setAlignment(Qt::AlignRight);
}

void MainWindow::on_c9Button_clicked()
{
    this->cScreenText.append("9");
    this->ui->cScreenLabel->setText(this->cScreenText);
    this->ui->cScreenLabel->setAlignment(Qt::AlignRight);
}

void MainWindow::on_c0Button_clicked()
{
    this->cScreenText.append("0");
    this->ui->cScreenLabel->setText(this->cScreenText);
    this->ui->cScreenLabel->setAlignment(Qt::AlignRight);
}

void MainWindow::on_cDecimalButton_clicked()
{
    this->cScreenText.append(".");
    this->ui->cScreenLabel->setText(this->cScreenText);
    this->ui->cScreenLabel->setAlignment(Qt::AlignRight);
}

void MainWindow::on_cClearAllButton_clicked()
{
    this->cScreenText.clear();
    this->ui->cScreenLabel->setText("0");
    this->operatorSelected="";
    this->firstValue=0.0;
}

void MainWindow::on_cBackSpaceButton_clicked()
{
    if(this->cScreenText.size()==1)
    {
        this->cScreenText="";
        this->ui->cScreenLabel->setText("0");
        return;
    }
    this->cScreenText=this->cScreenText.mid(0,this->cScreenText.size()-1);
    this->ui->cScreenLabel->setText(this->cScreenText);
}

void MainWindow::on_cAddButton_clicked()
{
    this->firstValue=this->cScreenText.toDouble();
    this->operatorSelected="A";
    this->cScreenText.clear();
    this->ui->cScreenLabel->setText("");
}

void MainWindow::on_cSubtractButton_clicked()
{
    this->firstValue=this->cScreenText.toDouble();
    this->operatorSelected="S";
    this->cScreenText.clear();
    this->ui->cScreenLabel->setText("");
}

void MainWindow::on_cMultiplyButton_clicked()
{
    this->firstValue=this->cScreenText.toDouble();
    this->operatorSelected="M";
    this->cScreenText.clear();
    this->ui->cScreenLabel->setText("");
}

void MainWindow::on_cDivideButton_clicked()
{
    this->firstValue=this->cScreenText.toDouble();
    this->operatorSelected="D";
    this->cScreenText.clear();
    this->ui->cScreenLabel->setText("");
}



void MainWindow::on_cEqualsToButton_clicked()
{
    if(this->operatorSelected.length()==0) return;
    if(this->operatorSelected==QString("A"))
    {
        double total=this->firstValue+this->cScreenText.toDouble();
        this->cScreenText=QString::number(total);
        this->ui->cScreenLabel->setText(this->cScreenText);
        this->firstValue=0.0;
    }
    if(this->operatorSelected==QString("S"))
    {
        double total=this->firstValue-this->cScreenText.toDouble();
        this->cScreenText=QString::number(total);
        this->ui->cScreenLabel->setText(this->cScreenText);
        this->firstValue=0.0;
    }
    if(this->operatorSelected==QString("D"))
    {
        double total=this->firstValue/this->cScreenText.toDouble();
        this->cScreenText=QString::number(total);
        this->ui->cScreenLabel->setText(this->cScreenText);
        this->firstValue=0.0;
    }
    if(this->operatorSelected==QString("M"))
    {
        double total=this->firstValue*this->cScreenText.toDouble();
        this->cScreenText=QString::number(total);
        this->ui->cScreenLabel->setText(this->cScreenText);
        this->firstValue=0.0;
    }
}

void MainWindow::on_cCrossButton_clicked()
{
    this->ui->cFrame->setVisible(false);
}

void MainWindow::on_cButton_clicked()
{
    if(this->calculatorVisible==0)
    {
        this->ui->cFrame->setVisible(true);
        this->calculatorVisible=1;
        return;
    }
    this->ui->cFrame->setVisible(false);
    this->calculatorVisible=0;
    this->cScreenText="";
    this->ui->cScreenLabel->setText("0");
}

void MainWindow::updateSelectedComponents()
{
    DrawableComponent* dr;
    QList<DrawableComponent*> tmpList=this->list[currentDSIndex]->getSelectedComponents();
    if(tmpList.size()==0) return;
    QListIterator<DrawableComponent*> iter(tmpList);
    while(iter.hasNext())
    {
        dr=iter.next();
        dr->setWidth(this->width);
        dr->setColor(this->color);
    }
    update();
}

void MainWindow::on_undoButton_clicked()
{
    this->list[currentDSIndex]->undo();
    populateMapList();
    setHighlights();
    update();
}

void MainWindow::on_redoButton_clicked()
{
    this->list[currentDSIndex]->redo();
    populateMapList();
    setHighlights();
    update();
}

void MainWindow::on_sButton_clicked()
{
    if(this->symbolVisible==0)
    {
        this->symbolVisible=1;
        this->ui->sFrame->setVisible(true);
    }else
    {
         this->symbolVisible=0;
        this->ui->sFrame->setVisible(false);
    }

}

void MainWindow::on_sPlusButton_clicked()
{
    //(750,420,100,100)
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/iconImage/icons/basic/plus.png");
    this->pixmap->setName("plus");
    this->pixmap->setPixmap(new QPixmap(":/iconImage/icons/basic/plus.png"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sMinusButton_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/iconImage/icons/basic/minus.png");
    this->pixmap->setName("minus");
    this->pixmap->setPixmap(new QPixmap(":/iconImage/icons/basic/minus.png"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();

}

void MainWindow::on_sMultiplyButton_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/iconImage/icons/basic/multiply.png");
    this->pixmap->setName("multiply");
    this->pixmap->setPixmap(new QPixmap(":/iconImage/icons/basic/multiply.png"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sDivideButton_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/iconImage/icons/basic/divide.png");
    this->pixmap->setName("divide");
    this->pixmap->setPixmap(new QPixmap(":/iconImage/icons/basic/divide.png"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();

}

void MainWindow::on_sInfinityButton_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/iconImage/icons/basic/infinity.png");
    this->pixmap->setName("infinity");
    this->pixmap->setPixmap(new QPixmap(":/iconImage/icons/basic/infinity.png"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sPlusMinusButton_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/iconImage/icons/basic/plusMinus.png");
    this->pixmap->setName("plus/minus");
    this->pixmap->setPixmap(new QPixmap(":/iconImage/icons/basic/plusMinus.png"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}


void MainWindow::on_sPercentageButton_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/iconImage/icons/basic/percentage.png");
    this->pixmap->setName("percentage");
    this->pixmap->setPixmap(new QPixmap(":/iconImage/icons/basic/percentage.png"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sRoundBracesOpen_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/braces/roundBracketOpen.PNG");
    this->pixmap->setName("round braces open");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/braces/roundBracketOpen.PNG"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sRoundBracesClose_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/braces/roundBracketClose.PNG");
    this->pixmap->setName("round braces close");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/braces/roundBracketClose.PNG"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sSquareBracesOpen_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/braces/squareBracesOpen.PNG");
    this->pixmap->setName("square braces open");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/braces/squareBracesOpen.PNG"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sSquareBracesClose_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/braces/squareBracesClose.PNG");
    this->pixmap->setName("square braces close");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/braces/squareBracesClose.PNG"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sLessThan_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/braces/lessThan.PNG");
    this->pixmap->setName("less than");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/braces/lessThan.PNG"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sGreaterThan_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/bracesgreaterThan.PNG");
    this->pixmap->setName("greater than");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/braces/greaterThan.PNG"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sOne_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/count/one.PNG");
    this->pixmap->setName("one");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/count/one.PNG"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sTwo_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/count/two.PNG");
    this->pixmap->setName("two");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/count/two.PNG"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sThree_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/count/three.PNG");
    this->pixmap->setName("three");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/count/three.PNG"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sFour_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/count/four.PNG");
    this->pixmap->setName("four");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/count/four.PNG"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sFive_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/count/five.PNG");
    this->pixmap->setName("five");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/count/five.PNG"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sSix_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/count/six.PNG");
    this->pixmap->setName("six");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/count/six.PNG"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sSeven_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/count/seven.PNG");
    this->pixmap->setName("seven");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/count/seven.PNG"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sEight_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/count/eight.PNG");
    this->pixmap->setName("eight");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/count/eight.PNG"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sNine_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/count/nine.PNG");
    this->pixmap->setName("nine");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/count/nine.PNG"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sZero_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/count/zero.PNG");
    this->pixmap->setName("zero");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/count/zero.PNG"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sDecimal_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/count/decimal.PNG");
    this->pixmap->setName("decimal");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/count/decimal.PNG"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sHalf_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/count/half.PNG");
    this->pixmap->setName("half");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/count/half.PNG"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sDifferentiation_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/dif/differentiation.PNG");
    this->pixmap->setName("differentiation");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/dif/differentiation.PNG"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sIntegration_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/dif/integration.PNG");
    this->pixmap->setName("integration");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/dif/integration.PNG"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sIntegral_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/dif/integral.PNG");
    this->pixmap->setName("integration");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/dif/integral.PNG"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sApproximately_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/equalto/approximately.PNG");
    this->pixmap->setName("similar");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/equalto/approximately.PNG"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sApproximation_clicked()
{
  this->pixmap=new PixMap();
  this->pixmap->setX1(750);
  this->pixmap->setY1(420);
  this->pixmap->setX2(25);
  this->pixmap->setY2(25);
  this->pixmap->setPath(":/symbols/icons/equalto/approximation.png");
  this->pixmap->setName("approx");
  this->pixmap->setPixmap(new QPixmap(":/symbols/icons/equalto/approximation.png"));
  this->list[currentDSIndex]->add(this->pixmap);
  populateTable();
  setHighlights();
  this->ui->sFrame->setVisible(false);
  this->currentTool="pick";
  update();

}
void MainWindow::on_sCongruent_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/equalto/congruent.png");
    this->pixmap->setName("congruent");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/equalto/congruent.png"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sEqualTo_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/equalto/equalsTo.png");
    this->pixmap->setName("equal to");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/equalto/equalsTo.png"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sNotEqualsTo_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/equalto/notEqualTo.png");
    this->pixmap->setName("not equal");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/equalto/notEqualTo.png"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sAlpha_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/notation/alpha.png");
    this->pixmap->setName("alpha");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/notation/alpha.png"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sBeta_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/notation/beta.png");
    this->pixmap->setName("beta");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/notation/beta.png"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sMu_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/notation/mu.png");
    this->pixmap->setName("mu");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/notation/mu.png"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sOmega_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/notation/omega.png");
    this->pixmap->setName("omega");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/notation/omega.png"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sPie_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/notation/pie.png");
    this->pixmap->setName("pi");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/notation/pie.png"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sAvg_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/root/avg.png");
    this->pixmap->setName("average");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/root/avg.png"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sFactorial_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/root/factorial.PNG");
    this->pixmap->setName("factorial");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/root/factorial.PNG"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sRoot_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/root/root.png");
    this->pixmap->setName("root");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/root/root.png"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sCubeRoot_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/root/cubeRoot.PNG");
    this->pixmap->setName("cube root");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/root/cubeRoot.PNG"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sElement_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/set/element.PNG");
    this->pixmap->setName("belong to");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/set/element.PNG"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sEmptySet_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/set/emptySet.PNG");
    this->pixmap->setName("phie");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/set/emptySet.PNG"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sIntersectionSet_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/set/intersectionSet.PNG");
    this->pixmap->setName("intersection");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/set/intersectionSet.PNG"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sNotElement_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/set/notElement.PNG");
    this->pixmap->setName("notElement");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/set/notElement.PNG"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sProportionality_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/set/proportionality.PNG");
    this->pixmap->setName("proportional");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/set/proportionality.PNG"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sRealNumber_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/set/realNumber.PNG");
    this->pixmap->setName("real number");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/set/realNumber.PNG"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sSigma_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/set/sigma.png");
    this->pixmap->setName("sigma");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/set/sigma.png"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sSubset_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/set/subset.PNG");
    this->pixmap->setName("subset");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/set/subset.PNG"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_sUnionSet_clicked()
{
    this->pixmap=new PixMap();
    this->pixmap->setX1(750);
    this->pixmap->setY1(420);
    this->pixmap->setX2(25);
    this->pixmap->setY2(25);
    this->pixmap->setPath(":/symbols/icons/set/unionSet.PNG");
    this->pixmap->setName("union");
    this->pixmap->setPixmap(new QPixmap(":/symbols/icons/set/unionSet.PNG"));
    this->list[currentDSIndex]->add(this->pixmap);
    populateTable();
    setHighlights();
    this->ui->sFrame->setVisible(false);
    this->currentTool="pick";
    update();
}

void MainWindow::on_scButton_clicked()
{
    QPixmap sc=QGuiApplication::primaryScreen()->grabWindow(0,85,43,1368,795);
    QString fileName=QFileDialog::getSaveFileName(this,tr("Save file"),"G:\\temp","Painting (*.PNG)");
    if(fileName.size()==0) return;
    QFile file(fileName);
     sc.save(&file,"PNG");
}


void MainWindow::on_clickImageButton_clicked()
{
    clickImage();
}

void MainWindow::on_temp1_clicked()
{
    pageUp();
}

void MainWindow::on_temp2_clicked()
{
    pageDown();
}
