#include "mainwindow.h"
#include <QFileInfo>
#include <QStandardPaths>
#include <QApplication>
#include <QAudioRecorder>

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    w.hide();

    return a.exec();
}
