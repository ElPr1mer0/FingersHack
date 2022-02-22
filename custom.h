#ifndef CUSTOM_H
#define CUSTOM_H
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
    QString updateDataFile(QString);

    void loadBookNamesFromBookFile();

    float textsAmount = 0;
    float currentText = 0;
    float record = 0;
    float averageSpeed = 0;
    float mistakes = 0;
    int playTimeHours = 0;
    float playTimeMinutes = 0;
    float playTimeSeconds = 0;

    QString nameFileOfTexts;

    QList <QString> bookNames;

private:
    void toSaveBook(); // сохраняет название книги при создании текстов фун. createTextFileFromBook  (butCreateText)
    void toSaveData(); // сохраняет начальные данные при создании текстов фун. createTextFileFromBook (butCreateText)

    HASH hash;
};


#endif // CUSTOM_H
