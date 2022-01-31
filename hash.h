#ifndef HASH_H
#define HASH_H

#include <QString>

class HASH
{
public:
    QString getHash(QString fileName);

private:
    int receivingExistCodes(int x);
    int getControlSum(QString str);
    int hashSize = 100;
};

#endif // HASH_H
