#include "recorder.h"

QString Recorder::getPath() const
{
    return path;
}

void Recorder::setPath(const QString &value)
{
    path = value;
}

Recorder::Recorder()
{
    this->arguments<<"-f gdigrab -framerate 30 -i desktop output99.mkv";
    process=new QProcess;
    process->setProgram("D:\ffmpeg.exe");
    process->setArguments(this->arguments);
}

void Recorder::run()
{
    this->process->open();
}

void Recorder::stopThread()
{
    this->process->write("^c");
    this->process->close();
}
