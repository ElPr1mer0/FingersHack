#include "training.h"



////////////////////////////////////////////////////////////////////////
//////////////////////////ADD_TRAINING//////////////////////////////////
////////////////////////////////////////////////////////////////////////
// Эта функция добавляет words-файл для создания тренировки в каталог,//
// где хранятся остальные words-файлы и откуда они загружаются        //
void TRAINING::addTraining(){}
////////////////////////////////////////////////////////////////////////
//////////////////////////ADD_TRAINING//////////////////////////////////
////////////////////////////////////////////////////////////////////////





////////////////////////////////////////////////////////////////////////
//////////////////////////LOAD_TRAINING/////////////////////////////////
////////////////////////////////////////////////////////////////////////
// Эта функция формирует уровень из слов, находящихся в words-файле.////
QString TRAINING::loadTraining(QString fileName){
    QFile fileText(QDir::currentPath()+"/Words files/"+fileName); // тут открываем файл
    if(!fileText.exists()){
        qDebug()<<"File with text doesn't exists! "<< QDir::currentPath()+"/Words files/"+fileName;
        return "Error. File with text doesn't exists!";
    }

    QString line, level = "";
    if(fileText.open(QIODevice::ReadOnly | QIODevice::Text)){
        int totalWordsInFile = 0;

        while(!fileText.atEnd()){ //подсчитали кол-во слов в words-файле
            ++totalWordsInFile;
            fileText.readLine();
        }

        if (totalWordsInFile == 0){         //если файл пустой
            return "Words have not found in file!";
            qDebug()<<"Words have not found in file!";
        }

        for(int i = 0; i<TOTAL_WORDS_PER_LEVEL;++i){ // собираем уровень из слов
            int randWord = -1;
            fileText.seek(0); // возвращаем указатель на начало файла

            while(randWord>totalWordsInFile || randWord<0){ // генератор рандома для слов
                randWord = rand() % totalWordsInFile + 1;
            }

            for(int j = 0; j<randWord;++j){ // здесь уже выписываем сами слова
                line = fileText.readLine();
                line.chop(1); // удаляем последний элемент, а это символ абзаца
            }

            level += line+" ";
        }
    }
    else{
        qDebug()<<"File can't be open!";
        return "Error. File can't be open!";
    }

    fileText.close();
    return level;

}
////////////////////////////////////////////////////////////////////////
//////////////////////////LOAD_TRAINING/////////////////////////////////
////////////////////////////////////////////////////////////////////////





////////////////////////////////////////////////////////////////////////
/////////////////LOAD_TRAINING_NAMES_FROM_TRAINING_FILE/////////////////
////////////////////////////////////////////////////////////////////////
// Эта функция загружает названия тренировок в комбо бокс где их можно//
// выбрать для игры.                                                  //
void TRAINING::loadTrainingNamesFromTrainingFile()
{
    QFile trainingFile(QDir::currentPath() + "/Saves/training.txt");
    if(!trainingFile.exists()){
        qDebug()<<"Training file doesn't  exists!";
    }
    else if(trainingFile.open(QIODevice::ReadOnly| QIODevice::Text)){
        this->trainingNames.clear();
        QTextStream outFile(&trainingFile);
        while(!outFile.atEnd()){
            this->trainingNames << outFile.readLine(); // помещаем названия наших книг в лист для хранения
        }
    }
    else{
        qDebug()<<"Training data file can't be open!";
    }
}
////////////////////////////////////////////////////////////////////////
/////////////////LOAD_TRAINING_NAMES_FROM_TRAINING_FILE/////////////////
////////////////////////////////////////////////////////////////////////

