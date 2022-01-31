#ifndef WORKWITHTEXT_H
#define WORKWITHTEXT_H
#include <QMainWindow>
#include "ui_mainwindow.h"
#include "mainwindow.h"

#include <QWidget>
#include "QDebug"
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QString>
#include <QList>

#include <hash.h>
#include <encryption.h>




class TEXT{
public:
    QString createTextFileFromBook(QString);
    QString loadTextFromFile(QString);       
    QString loadDataFromDataFile(QString);
    QString updateDataFile();

    void loadBookNamesFromBookFile();

    int textsCounter = 0;
    int currentText = 0;
    int record = 0;
    int speed = 0;
    int mistakes = 0;
    int playTimeHours = 0;
    int playTimeMinutes = 0;

    QString nameFileOfTexts;

    QList <QString> bookNames;

private:
    void toSaveBook(); // сохраняет название книги при создании текстов фун. createTextFileFromBook  (butCreateText)
    void toSaveData(); // сохраняет начальные данные при создании текстов фун. createTextFileFromBook (butCreateText)

    HASH hash;
};


#endif // WORKWITHTEXT_H
