#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include<drawablecomponent.h>
#include<tmview.h>
#include<QMouseEvent>
#include<line.h>
#include<freehand.h>
#include<rectangle.h>
#include<ellipse.h>
#include<QKeyEvent>
#include<QCursor>
#include<QTableWidget>
#include<QLabel>
#include<QIcon>
#include<QMessageBox>
#include<QFont>
#include<QAbstractItemView>
#include<QPalette>
#include<QJsonArray>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonValue>
#include<QFileDialog>
#include<QMessageBox>
#include<QDebug>
#include<QShortcut>
#include<QRadioButton>
#include<qradiobutton.h>
#include<freehandlist.h>
#include<pixmap.h>
#include<graph.h>
#include<linedpage.h>
#include<QListIterator>
#include<QDebug>
#include<QRadioButton>
#include<QMessageBox>
#include<QColorDialog>
#include<QPixmap>
#include<QScreen>
#include<QGuiApplication>
#include<QDesktopWidget>
#include<QTimer>
#include<QBuffer>
#include<QProcess>
#include<QStringList>
#include<recorder.h>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent*event) override;
    void mouseReleaseEvent(QMouseEvent*event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;


private slots:
    void on_rectangleButton_clicked();

    void on_ellipseButton_clicked();

    void on_lineButton_clicked();

    void on_pickButton_clicked();

    void on_freeHandButton_clicked();

    void on_clearButton_clicked();

    void on_closeButton_clicked();


    void on_widthSlider_valueChanged(int value);

    void on_newButton_clicked();

    void on_radioButton1_clicked();

    void on_radioButton2_clicked();

    void on_radioButton3_clicked();

    void on_radioButton4_clicked();

    void on_radioButton5_clicked();

    void on_radioButton6_clicked();

    void on_radioButton7_clicked();

    void on_radioButton8_clicked();

    void on_radioButton9_clicked();

    void on_radioButton10_clicked();



    void on_closeBoardButton_clicked();

    void on_saveButton_clicked();

    void on_openButton_clicked();

    void on_table_cellClicked(int row, int column);

    void on_copyButton_clicked();

    void on_resizeButton_clicked();

    void on_table_cellDoubleClicked(int row, int column);

    void on_colorButton_clicked();

    void on_deleteButton_clicked();


    void on_nameCancelButton_clicked();

    void on_pushButton_clicked();

    void on_nameSaveButton_clicked();

    void on_pixmapButton_clicked();

    void on_graphRadioButton_clicked();

    void on_pageRadioButton_clicked();

    void on_pageOptionColor_clicked();

    void on_pageOptionSlider_valueChanged(int value);

    void on_pageOptionButton_clicked();

    void on_pageOptionCloseButton_clicked();

    void on_plainRadioButton_clicked();

    void on_c1Button_clicked();

    void on_c2Button_clicked();

    void on_c3Button_clicked();


    void on_c4Button_clicked();

    void on_c5Button_clicked();

    void on_c6Button_clicked();

    void on_c7Button_clicked();

    void on_c8Button_clicked();

    void on_c9Button_clicked();

    void on_c0Button_clicked();

    void on_cClearAllButton_clicked();

    void on_cBackSpaceButton_clicked();

    void on_cAddButton_clicked();

    void on_cSubtractButton_clicked();

    void on_cMultiplyButton_clicked();

    void on_cDivideButton_clicked();

    void on_cDecimalButton_clicked();

    void on_cEqualsToButton_clicked();

    void on_cCrossButton_clicked();

    void on_cButton_clicked();

    void on_undoButton_clicked();

    void on_redoButton_clicked();

    void on_sButton_clicked();

    void on_sPlusButton_clicked();

    void on_sMinusButton_clicked();

    void on_sMultiplyButton_clicked();

    void on_sDivideButton_clicked();

    void on_sInfinityButton_clicked();

    void on_sPlusMinusButton_clicked();

    void on_sPercentageButton_clicked();

    void on_sRoundBracesOpen_clicked();

    void on_sRoundBracesClose_clicked();

    void on_sSquareBracesOpen_clicked();

    void on_sSquareBracesClose_clicked();

    void on_sLessThan_clicked();

    void on_sGreaterThan_clicked();

    void on_sOne_clicked();

    void on_sTwo_clicked();

    void on_sThree_clicked();

    void on_sFour_clicked();

    void on_sFive_clicked();

    void on_sSix_clicked();

    void on_sSeven_clicked();

    void on_sEight_clicked();

    void on_sNine_clicked();

    void on_sZero_clicked();

    void on_sDecimal_clicked();

    void on_sHalf_clicked();

    void on_sDifferentiation_clicked();

    void on_sIntegration_clicked();

    void on_sIntegral_clicked();

    void on_sApproximately_clicked();

    void on_sApproximation_clicked();

    void on_sCongruent_clicked();

    void on_sEqualTo_clicked();

    void on_sNotEqualsTo_clicked();

    void on_sAlpha_clicked();

    void on_sBeta_clicked();

    void on_sMu_clicked();

    void on_sOmega_clicked();

    void on_sPie_clicked();

    void on_sAvg_clicked();

    void on_sFactorial_clicked();

    void on_sRoot_clicked();

    void on_sCubeRoot_clicked();

    void on_sElement_clicked();

    void on_sEmptySet_clicked();

    void on_sIntersectionSet_clicked();

    void on_sNotElement_clicked();

    void on_sProportionality_clicked();

    void on_sRealNumber_clicked();

    void on_sSigma_clicked();

    void on_sSubset_clicked();

    void on_sUnionSet_clicked();

    void on_scButton_clicked();

    void on_clickImageButton_clicked();




    void on_temp1_clicked();

    void on_temp2_clicked();

private:
    Ui::MainWindow *ui;
    QProcess *process;
    QList<TMView*> list;
    int ctrlKeyPressed;
    int currentDSIndex;
    QList<QMap<int,DrawableComponent*>*> mapList;
    TMView *currentTMView;
    QString currentTool;
    FreeHand *freeHand;
    Line *line;
    Rectangle *rectangle;
    Ellipse *ellipse;
    FreeHandList *freeHandList;
    PixMap *pixmap;
    Graph *graph;
    LinedPage *linedPage;
    QString cScreenText;

    Recorder *recorder;

    QByteArray plscArray;
    void *gwavi;
    double firstValue;
    int symbolVisible;
    int rectangleFlag;
    int count;
    int scCount;
    int oldX;
    int oldY;
    int width;
    int lastSize;
    int activeRadioButtons;
    int isMousePressed;
    int pageOptionFrameVisible;
    int rowIndex;
    int columnIndex;
    int calculatorVisible;
    int oldStartX;
    int oldStartY;
    int mode;
    int shiftKeyPressed;
    QList<QRadioButton*> radioButtons;
    QColor color;
    QColor pageColor;
    QList<QPixmap*> scList;
    int pageWidth;
    QString operatorSelected;
    QPixmap *wtPixmap;
    QPixmap *woodenFrame;
    QTimer *captureTimer;
    QByteArray scArray;
    unsigned char *data;
    void updateSelectedComponents();
    void populateRadioButtons();
    void populateTable();
    void populateMapList();
    void setHighlights();
    void SelectTheSelectedComponents();
    void setIconOnSymbol();
    void move(int,int);
    void resize(int,int);
    void clickImage();
    void pageUp();
    void pageDown();

};
#endif // MAINWINDOW_H
