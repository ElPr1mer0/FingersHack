#include "encryption.h"
#include <QDebug>


QString ENCRYPTION::encryptNumber(float number)
{
    QString str =  QString::number(number);

    for(int i = 0; i<str.length();i++){ // здесь меняем кодировку
        str[i] = QChar(str[i].unicode() + this->kod);
    }

    return str;
}

float ENCRYPTION::deEncryptNumber(QString str)
{
    for(int j = 0; j<str.length();j++){ // здесь возвращаем исходную кодировку
        str[j] = QChar(str[j].unicode() - this->kod);
    }

    bool isNumber = false;
    if(str.toFloat(&isNumber)||str=="0") {  // проверка на число, если это не число, тогда файл был поврежден, возвращаем 0
                                // п.с. toInt(&isNumber) считает 0 не числом, поэтому возвращает false, поэтому доп проверка на str=="0"
        float number = str.toFloat();
        return number;
    }
    else{
        qDebug()<<"Number translation error! File have damaged!";
        return this->translateError;
    }
}

int ENCRYPTION::getTranslateError()
{
    return this->translateError;
}
