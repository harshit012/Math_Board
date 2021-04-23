#include "mainwindow.h"
#include <QApplication>
#include<QMouseEvent>
#include<QPaintEvent>
#include<QSplashScreen>
#include<QTimer>
#include<QThread>

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    QSplashScreen *splash=new QSplashScreen;
    splash->setPixmap(QPixmap(":/img/background_images/spl1.jpg"));
    splash->show();
    QTimer::singleShot(5000,splash,SLOT(close()));
    MainWindow w;
    QTimer::singleShot(5000,&w,SLOT(show()));
    return a.exec();
}
