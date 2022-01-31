#ifndef ENCRYPTION_H
#define ENCRYPTION_H
#include <QString>


class ENCRYPTION
{
    public:
        QString encryptNumber (int); // шифровка

        int deEncryptNumber (QString); // расшифровка
        int getTranslateError();
    private:
        int kod = 10; // на это значение изменяем наши символы в кодировке
        int translateError = -1;
};

#endif // ENCRYPTION_H
