#include "hash.h"



int HASH::receivingExistCodes(int x)
{
    x+=256;  // здесь мы из произведения двух прошлых чисел получаем новый символ из след диапазон:
    while(!(((x<=57)&&(x>=48))||((x<=90)&&(x>=65))||((x<=122)&&(x>=97)))){
        if(x<48)x+=24;
        else x-=47;
    }
    return x;
}

int HASH::getControlSum(QString fileName)
{
    int sault = 0;  // здесь просто считаем сумму символов из входящей строки

    for(int i = 0; i<fileName.length();i++){
        sault += fileName[i].unicode();
    }
    return sault;
}

QString HASH::getHash(QString fileName)
{
    QString hash = "";
    int controlSum = getControlSum(fileName);   //получим контрольную сумму имени файла, запишем в конец хэша
    int mult, div;

    while(hash.length()<this->hashSize){  // делаем цикл, чтобы hash был не меньше hashSize (сейчас 16)
        for(int i = 0; i<fileName.length();i++){
           mult = fileName[i].unicode()*i; // просто рандомные преобразования, чтобы получить часть хэша
           div = fileName[i].unicode()/(i+1);
           hash+=QChar(receivingExistCodes(div)); //QChar здесь нужен для перевода чисел в буквы
           hash+=QChar(receivingExistCodes(mult));
        }
        hash += QString::number(controlSum);
        fileName = hash;
    }

    hash = ""; // обнуляем строку, чтобы туда переписать хэш размером hashSize
    for(int i = 0; i<hashSize;i++){
        hash += fileName[i];
    }
    return hash;
}
