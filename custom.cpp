#include "custom.h"

QString TEXT::createTextFileFromBook(QString filePath){ // pMain указатель на главную форму, чтобы мог открыть QDialog
    QFile file(filePath); //здесь просто загружаем книгу, которую нужно переработать для дальнейшего использования
    if(!file.exists()){
        qDebug()<<"File is not exists! ";
        return "Error! File is not exists!";
    }

    QString book;
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){

        while(!file.atEnd()){
            book = file.readAll();
        }
    }
    else{
        qDebug()<<"File can't be open!";
        return "Error! File can't be open!";
    }
    file.close();


    QFileInfo fileInfo(filePath);
    if(fileInfo.fileName() == ""){
        qDebug()<<"File haven't created!";          // если отменили сохранение файла
        return "Error! File haven't created!";
    }
    this->nameFileOfTexts = fileInfo.fileName();//берем имя файла, чтобы узнать есть ли уже файл с таким же именем
    this->toSaveBook();                         //если есть, то эта функция его поменяет, чтобы не было перезаписи

    QFile processedFile(QDir::currentPath()+"/Texts/"+ this->nameFileOfTexts); // создаем новый файл, в который запишем обработанный текст
    if (!processedFile.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug()<<"File can't be create!";
        return "Error! File can't be create!";
    }
    QTextStream newFile(&processedFile); // создаем поток, для записи в созданный файл

    int wordsCounter = 0; // счётчик слов (в обычной игре сделаю диапазон слов около allWords,
    int allWords = 30;   //потом ищем точку заканчивающее предложение)
    int textsCounter = 0; // сколько игровых текстов получим из книги
    QString word;
    QString gap = " ", dot = ".", questionMark = "?", exclamationPoint = "!", dash="-"; // ищем пробел, точку, вопрос. зн. и воскл. зн.
    QString n = "\n"; // для пропуска абзацев в тексте, которые мне не нужны
    bool wasN = false;  // поиск перехода на новую строку
    bool wasGap = false; //нужен только тогда, когда в тексте нет ни одного пробела
    for(int ii = 0; ii<book.length(); ++ii){
        if((book[ii].unicode()>=32 && book[ii].unicode() <= 126)|| //латинский алфавит + знаки
          (book[ii].unicode()>=1040 && book[ii].unicode() <= 1071)|| //рус заглавные, снизу маленькие
          (book[ii].unicode()>=1072 && book[ii].unicode() <= 1103)||
           book[ii].unicode()==252 || book[ii].unicode()==10 || book[ii].unicode()==8211 || book[ii].unicode()==8212) //проверяем, чтобы символ был в таблицы кодировки этого диапазона
        {                                                           // 252 = № 10 = абзац
            if (book[ii]!=gap){
                if (book[ii] != n){  // если символ перехода на новую строку, то скипаем его
                     word += book[ii];
                }
                else{
                    if(word!="") wasN = true;
                    wasGap = true;
                    continue;
                }

            }
            else{
                if(wasN){
                    word+="."; // так как нашли символ абзаца, то нужно сделать пробел, чтобы слова не слиплись
                }

                if(word!=""){ // проверка, если вдруг в тексте будет несколько пробелов подряд
                    newFile<<word<<" ";
                    wasN = false;
                    word = "";
                    wordsCounter++;


                    if(wordsCounter >= allWords){ // если мы уже набрали стандартное кол-во слов для создания текста, то ищем конец предложения
                                                // чтобы закончить записать одного текста для игры
                        while(book[ii]!= dot && book[ii]!= questionMark && book[ii]!= exclamationPoint && ii<book.length() ){ //i<book.length() чтобы не выхода за пределы массива
                            if(book[ii] == n){
                                newFile<<" ";
                                ii++;
                                continue;
                            }

                            if (book[ii]!=gap){                                                                          // если вдруг там нет знаков, а строка закончилась
                                word += book[ii];
                                ii++;
                            }
                            else{
                                if(word!=""){ // проверка, если вдруг в тексте будет несколько пробелов подряд
                                    newFile<<word<<" "; // из-за этого в конце каждого текста будет один лишний символ пробела
                                    word = "";              // при игре это надо будет учитывать!!!
                                }
                                ii++;
                            }
                        }
                        wordsCounter = 0; // обнуляем счетчик для записи новой строки файла
                        if(ii<book.length()) newFile<<word<<book[ii];// так как мы ищем конец предложения, то последнее слово и символ точки не записывается, тут это исправляем
                        newFile<<"\n"; // переходим на новую строку файла, так как один текст для игры готов
                        textsCounter++;
                        word="";
                    }
                }
            }
        }
        else continue;
    }

    if(wordsCounter != 0 || !wasGap){ //!wasGap это если не было пробелов в тексте
        newFile<<word;// так как мы ищем конец предложения, то последнее слово  не записывается, тут это исправляем
        newFile<<"\n";// а символ точки записывается как раз, так как не обрабатывается в цикле while(не точка и тп)
        textsCounter++;// значит последний текст будет неполный

    }

    this->textsAmount = textsCounter;
    processedFile.close(); //запись закончена, файл для использования готов

    this->toSaveData();
    return "Text file have processed successfully!";
};

QString  TEXT::loadTextFromFile(QString fileName)
{   
    QFile fileText(QDir::currentPath()+"/Texts/"+fileName); // тут открываем файл для выбора игрового текста
    if(!fileText.exists()){
        qDebug()<<"File with text doesn't exists! ";
        return "Error";
    }

    QString line;
    if(fileText.open(QIODevice::ReadOnly | QIODevice::Text)){        
        int currentText = 0;

        while(!fileText.atEnd()){
            line = fileText.readLine();
            if(currentText == this->currentText){
                break;
            }
            else{
                currentText++;
            }
        }
        if(currentText!=this->currentText){
            qDebug()<<"Error! Text haven't founded!";
            return "Error! Text haven't founded!";
        }
    }
    else{
        qDebug()<<"File can't be open!";
        return "Error";
    }

    fileText.close();
    return line;
}

QString TEXT::loadDataFromDataFile(QString bookName)
{
    QFile fileData(QDir::currentPath() + "/Saves/data.txt");//создаем файл для взятия инфы
    if(!fileData.exists()){
        qDebug()<<"Data file doesn't  exists!";
        return "Data file doesn't  exists!";
    }

    bookName = hash.getHash(bookName); // получаем хэш нашей книги для ее поиска в файле

    if(fileData.open(QIODevice::ReadOnly)){
        QTextStream outFile(&fileData);
        QString line;
        QString gap = " ";
        bool nameFounded = true;
        int j = 0;
        int counter = 0;

        while(!outFile.atEnd()){     // здесь ищем строку с нашими игровыми данными по книге
            int x = 0;
            nameFounded = true;
            line = outFile.readLine();

            while(line[x]!=gap){
                if(line[x]!=bookName[x]){
                    nameFounded = false;
                    break;
                }
                x++;
                j = x; // идет сначала, а это лучше не допускать, могут пойти ошибки!!!
            }               // делаем для запоминания i, потому что на последней строке файле она обнуляется, и следущий цикл while
            counter++;
            if(nameFounded) break;
        }
        if(!nameFounded) return "Error! Book data haven't founded!"; // если не нашли, значит ее не существует


        QString data = "";

         // если нашли, то будем выписывать наши данные в класс тест, для сейва

        // обнуляем хранимые данные, для перезаписи
        bool wasTextAmount = false, wasCurrentText = false, wasRecord = false,
             wasAverageSpeed = false, wasMistakes = false, wasTimeHours = false,
             wasTimeMinutes = false;

        ENCRYPTION encryption;
        for(int x = j;x<line.length();x++){
            while(x<line.length()&&line[x] != gap ){ // здесь читаем нашу информаци в том порядке, как и сохраняли
                data += line[x];
                x++;
            }

            if(data != ""){
                    float number = encryption.deEncryptNumber(data);

                        if(number == encryption.getTranslateError()){
                        qDebug()<<"Error! Damaged data!";
                        fileData.close();
                        return "Error! Damaged data!";
                    }
                    else{
                        if(!wasTextAmount){ // заполняем наши данные
                            wasTextAmount = true;
                            this->textsAmount = number;
                        }
                        else if(!wasCurrentText){
                            wasCurrentText = true;
                            this->currentText = number;
                        }
                        else if(!wasRecord){
                            wasRecord = true;
                            this->record = number;
                        }
                        else if(!wasAverageSpeed){
                            wasAverageSpeed = true;
                            this->averageSpeed = number;
                        }
                        else if(!wasMistakes){
                            wasMistakes = true;
                            this->mistakes = number;
                        }
                        else if(!wasTimeHours){
                            wasTimeHours = true;
                            this->playTimeHours = number;
                        }
                        else if(!wasTimeMinutes){
                            wasTimeMinutes = true;
                            this->playTimeMinutes = number;
                        }
                    }
            }
            data = "";
        }
    }
    else{
        qDebug()<<"Data file can't be open!";
        return "Error! Data file can't be open!!";
    }

    fileData.close();
    qDebug()<<"Data have looded successfully!";
    return "Data have looded successfully!";
}

QString TEXT::updateDataFile(QString bookName)
{
    QFile fileData(QDir::currentPath() + "/Saves/data.txt");//создаем файл для взятия инфы
    if(!fileData.exists()){
        qDebug()<<"Data file doesn't  exists!";
        return "Data file doesn't  exists!";
    }

    int lineCounter = 0;
    QList <QString>listFileData;
    bookName = hash.getHash(bookName);
    QString newDataLine = bookName; //тут мы начинаем создавать строку с новыми данными для замены в файле

    if(!fileData.open(QIODevice::Text |QIODevice::ReadOnly)){
        qDebug()<<"Data file doesn't  exists!";
        return "Data file doesn't  exists!";
    }
    else{       
        QTextStream inFile(&fileData);

        QString line;
        QString gap = " ";
        bool nameFounded = true;
        int j = 0;

        while(!inFile.atEnd()){     // здесь записываем данный из файла в список
            listFileData<<inFile.readLine();
       }


        inFile.seek(0);
        while(!inFile.atEnd()){     // здесь ищем строку с нашими игровыми данными по книге
            int x = 0;                  //возможно в дальнейшем надо написать функцию, а то я этот код использую второй раз
            nameFounded = true;
            line = inFile.readLine();

            while(line[x]!=gap){
                if(line[x]!=bookName[x]){
                    nameFounded = false;
                    lineCounter++;
                    break;
                }
                x++;
                j = x;
            }
            // ищем строку, в которую занесем изменения
            if(nameFounded) break;
        }
        if(!nameFounded){
            qDebug()<<"Error! Book data haven't found!";
            return "Error! Book data haven't found!"; // если не нашли, значит ее не существует
        }


        // если нашли, то будем записывать наши данные из класса в файл, для сейва
       // обнуляем хранимые данные, для перезаписи

       QString data = "";
       ENCRYPTION encryption;
       bool wasTextAmount = false, wasCurrentText = false, wasRecord = false,
            wasAverageSpeed = false, wasMistakes = false, wasTimeHours = false,
            wasTimeMinutes = false; //для сохранения данных по порядку, по другому не придумал как сделать, при чтении из файла

       for(int x = j;x<line.length();x++){
           while(x<line.length()&&line[x] != gap ){ // здесь читаем нашу информаци в том порядке, как и сохраняли
               data += line[x];
               x++;
           }

           if(data != ""){
               float number = encryption.deEncryptNumber(data);

               if(number == encryption.getTranslateError()){
                   qDebug()<<"Error! Damaged data!";
                   fileData.close();
                   return "Error! Damaged data!";
               }
               else if(!wasTextAmount){
                   wasTextAmount = true; // тут мы замен не делаем, тут постоянное значение
                   newDataLine += " " + encryption.encryptNumber(this->textsAmount);
               }
               else if(!wasCurrentText){
                   wasCurrentText = true;
                   newDataLine += " " + encryption.encryptNumber(this->currentText); //тут тоже значение всегда на 1 изменяется
               }
               else if(!wasRecord){
                   wasRecord = true;
                   newDataLine += " " + encryption.encryptNumber(this->record);
               }  // считаем среднюю скорость по всем текстам, this->currentText-1 так как мы увеличиваем кол-во текстов сразу после прохода, а начинаем с 1
               else if(!wasAverageSpeed){
                   wasAverageSpeed = true;
                   this->averageSpeed = round((number*(this->currentText-1)+this->averageSpeed)/this->currentText);
                   newDataLine += " " + encryption.encryptNumber(this->averageSpeed);
               }
               else if(!wasMistakes){
                   wasMistakes = true;
                   this->mistakes = round((number*(this->currentText-1)+this->mistakes)/this->currentText*100)/100;
                   newDataLine += " " + encryption.encryptNumber(this->mistakes);
               }
               else if(!wasTimeHours){
                   wasTimeHours = true;
                   this->playTimeHours = number;
               }
               else if(!wasTimeMinutes){
                   wasTimeMinutes = true;
                   this->playTimeMinutes += number + this->playTimeSeconds/60; // считаем время с секундами
                   if(this->playTimeMinutes>=60){
                       this->playTimeHours+=60;
                       this->playTimeMinutes-=60;
                   }
                   newDataLine += " " + encryption.encryptNumber(playTimeHours) + " " + encryption.encryptNumber(playTimeMinutes);
               }
          }
          data = "";
      }
       // теперь нужно перезаписать наш файл    
   }
    fileData.close();

    if(fileData.open(QIODevice::WriteOnly)){ // перезаписываем файл
        QTextStream inFile(&fileData);
        listFileData[lineCounter] = newDataLine; // изменяем строку в Qlist, чтобы переписать файл
        for(int i = 0; i<listFileData.size();i++)
            inFile<<listFileData[i]<<"\n";
    }
    fileData.close();

   return "Data updated!";
}

void TEXT::toSaveData()
{
    this->currentText = 0;
    this->record = 0;
    this->averageSpeed = 0;
    this->mistakes = 0;
    this->playTimeHours = 0;
    this->playTimeMinutes = 0;

    QFile file(QDir::currentPath() + "/Saves/data.txt");
    QTextStream inFile(&file);  // создаем поток, для записи в созданный файл
    if(!file.exists()){
        if(file.open(QIODevice::WriteOnly)){
            ENCRYPTION encryption;

            inFile<<hash.getHash(this->nameFileOfTexts)<<" " //записываем данные и шифруем их
            <<encryption.encryptNumber(this->textsAmount)<<" "
            <<encryption.encryptNumber(this->currentText)<<" "
            <<encryption.encryptNumber(this->record)<<" "
            <<encryption.encryptNumber(this->averageSpeed)<<" "
            <<encryption.encryptNumber(this->mistakes)<<" "
            <<encryption.encryptNumber(this->playTimeHours)<<" "
            <<encryption.encryptNumber(this->playTimeMinutes)<<"\n";
        }
    }
    else{
        if(file.open(QIODevice::Append| QIODevice::Text)){
            ENCRYPTION encryption;
            inFile<<hash.getHash(this->nameFileOfTexts)<<" " //записываем данные и шифруем их
            <<encryption.encryptNumber(this->textsAmount)<<" "
            <<encryption.encryptNumber(this->currentText)<<" "
            <<encryption.encryptNumber(this->record)<<" "
            <<encryption.encryptNumber(this->averageSpeed)<<" "
            <<encryption.encryptNumber(this->mistakes)<<" "
            <<encryption.encryptNumber(this->playTimeHours)<<" "
            <<encryption.encryptNumber(this->playTimeMinutes)<<"\n";
        }   // путь к игровому тексту, кол-во текстов, текущий уровень прохождения и тп
        else{
            qDebug()<<"File can't be open!";
        }
    }

    file.close();
    qDebug()<<"toSaveData successfully!";
}

void TEXT::toSaveBook()
{
    QString currentDir = QDir::currentPath(); // узнаем путь к текущему бинарнику я так понимаю, а от него уже идем к нашему файлу
    QFile fileBook(currentDir + "/Saves/books.txt");
    QTextStream inFileBook(&fileBook);
    if(!fileBook.exists()){
        if(fileBook.open(QIODevice::WriteOnly)){
            inFileBook<<this->nameFileOfTexts<<"\n";
        }
    }
    else{
        if(fileBook.open(QIODevice::Append | QIODevice::Text|QIODevice::ReadOnly)){
            QString thisNameIsExists = this->nameFileOfTexts;
            QString buf;
            bool copyFound = true;
            bool doWhileCopy = true;    // для того, что если опять есть копия, то идём сначало
            int copyConter = 1;

            if(fileBook.size() != 0){ // если файл не пустой, то ищем копии
                while(doWhileCopy){
                    copyConter++;
                    inFileBook.seek(0); // ставим позицию на начало считывающего файла

                    while(!fileBook.atEnd()){ // этот цикл создаем для проверки есть ли у нас в файле book такое же название книги
                        copyFound = true;
                        buf = fileBook.readLine();

                        if(buf.length()-1!=thisNameIsExists.length()){ // если разная длина, то это не копия, -1 так как
                            doWhileCopy = false;                       // читается ещё символ новой строки /n                             copyFound = false;
                            continue;
                        }else{
                            for(int i = 0; i<thisNameIsExists.length();i++){
                                if(buf[i]!=thisNameIsExists[i]){
                                    copyFound = false; // если совпадений в названиях нет, переходим на другую строку
                                    doWhileCopy = false;
                                    break;
                                }
                            }
                        }

                        if(copyFound){ // если такое назв есть, то создается копия
                            thisNameIsExists = this->nameFileOfTexts;
                            thisNameIsExists.insert(thisNameIsExists.length()-4,"("+QString::number(copyConter)+")");
                            doWhileCopy = true;  // если копия, то добавляем (1),(2) и тп length()-4, так как .txt
                            qDebug()<<"Book's copy have founded!";
                            break;
                        }
                    }
                }
            }

            inFileBook<<thisNameIsExists<<"\n";
            this->nameFileOfTexts = thisNameIsExists; // изменяем на новое имя
        }
        else{
            qDebug()<<"File can't be open!";
        }
    }
    qDebug()<<"toSaveBook successfully!"; ////////////даже при ошибке  будет написан!!!!!!!

    fileBook.close();
}

void TEXT::loadBookNamesFromBookFile()
{
    QFile BooksFile(QDir::currentPath() + "/Saves/books.txt");
    if(!BooksFile.exists()){
        qDebug()<<"Books file doesn't  exists!";
    }
    else if(BooksFile.open(QIODevice::ReadOnly| QIODevice::Text)){
        QTextStream outFile(&BooksFile);
        while(!outFile.atEnd()){
            this->bookNames << outFile.readLine(); // помещаем названия наших книг в лист для хранения
        }
    }
    else{
        qDebug()<<"Data file can't be open!";
    }
}

