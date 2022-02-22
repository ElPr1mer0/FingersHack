#ifndef TRAINING_H
#define TRAINING_H
#include "hash.h"
#include "QString"

class TRAINING{
public:
    void addTraining();
    void loadTraining();



    float record = 0;
    float averageSpeed = 0;
    float mistakes = 0;
    int playTimeHours = 0;
    float playTimeMinutes = 0;
    float playTimeSeconds = 0;

private:
    HASH hash;
};

#endif // TRAINING_H
