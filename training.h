#ifndef TRAINING_H
#define TRAINING_H
#include "hash.h"
#include "QString"
#include <QList>
#include "QDebug"
#include "QFile"
#include "QDir"

#define TOTAL_WORDS_PER_LEVEL 30

class TRAINING{
public:
    void addTraining();
    QString loadTraining(QString fileName);
    void loadTrainingNamesFromTrainingFile();


    float record = 0;
    float averageSpeed = 0;
    float mistakes = 0;
    int playTimeHours = 0;
    float playTimeMinutes = 0;
    float playTimeSeconds = 0;

    QList <QString> trainingNames;
private:
    HASH hash;
};

#endif // TRAINING_H
