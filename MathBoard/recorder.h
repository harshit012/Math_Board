#ifndef RECORDER_H
#define RECORDER_H

#include<QThread>
#include<QProcess>
#include<QStringList>
#include<QString>
#include<QDebug>

class Recorder:public QThread
{
    QProcess *process;
    QString path;
    QStringList arguments;
public:
    Recorder();
    void run() override;
    void stopThread();

    QString getPath() const;
    void setPath(const QString &value);
};

#endif // RECORDER_H
