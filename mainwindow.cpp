#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "custom.h"
#include "hash.h"

TEXT book; // создаем объект класса текста, для работы с текстами и обработки инфы

///////////////////////on_lineEdit_textChanged////////////////////////////////
QString editText;
QString dash = "-";

int letter = 0; // для подсчёта кол-ва пройденных символов в editBrowser
int lineSize = 0; // для подсчета реального кол-ва символов, которые были в введенной игроком строке
int mistakes = 0;// для подсчета кол-ва ошибок при игре

bool firstTime = true;
bool isMistake = false; // проверка на ошибку
bool wasMinus = false; // если находим символ -.е,Е

///////////////////////on_lineEdit_textChanged////////////////////////////////


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEditField->setEnabled(false);

    ui->comboBoxSelectBook->clear();
    book.loadBookNamesFromBookFile(); // подгружаем названия наших книг в comboBoxSelectBook
    ui->comboBoxSelectBook->addItems(book.bookNames);

    timer = new QTimer(this); //создаем таймер
    connect (timer, SIGNAL(timeout()),this, SLOT(on_time()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_butLoadtextFromFile_clicked()
{
    ui->textBrowser->clear();
    QString fileName = ui->comboBoxSelectBook->currentText();
    if(fileName != ""){               
        book.currentText = 0; // записываем полученные данные для обработки и сейва
        book.averageSpeed = 0;
        book.mistakes = 0;
        book.playTimeMinutes = 0;
        book.playTimeSeconds = 0;
        book.record = 0;
        book.textsAmount = 0;

        book.loadDataFromDataFile(ui->comboBoxSelectBook->currentText());
        on_update_data();
        if(book.currentText>=book.textsAmount){
            ui->butStart->setEnabled(false);
            ui->textBrowser->insertPlainText("The book is over!");
        }
        else{
             ui->textBrowser->insertPlainText(book.loadTextFromFile(fileName));
             editText = ui->textBrowser->toPlainText();

             letter = 0;
             lineSize = 0;
             mistakes = 0;
             isMistake = false;
             ui->lineEditCurrentMistakes->setText(QString::number(mistakes));
             this->sec = 0;
             this->min = 0;
             ui->lineEditMinutes->setText("0");
             ui->lineEditSeconds->setText("0");
             ui->labelCurrentMistakesPercent->setText("");
        }
    }
    else{
        qDebug()<<"Error! Book haven't founded!";
    }

}

void MainWindow::on_lineEditField_textChanged(const QString &arg1)
{

    if(arg1.length()- 1 + lineSize  == letter) { // + lineSize, так как мы обнуляем нашу строку после пробела
                                                // а кол-во символов, которые были помнить надо для правильно проверки на ввод
        if(((editText[letter].unicode()==8211 || editText[letter].unicode()==8212) && arg1[letter - lineSize] == dash[0])||// это условие нужно, чтобы большое и маленькое тире считалось как обычное
          (editText[letter].unicode()==1105 && arg1[letter - lineSize].unicode() == 1077 ) || // е=ё
          (editText[letter].unicode()==1025 && arg1[letter - lineSize].unicode() == 1045 )||//Е=Ё
          (editText[letter].unicode()==171 && arg1[letter - lineSize].unicode() == 34 )|| // ковычки
          (editText[letter].unicode()==187 && arg1[letter - lineSize].unicode() == 34 ))  // ковычки
                wasMinus = true;

        if(arg1[letter - lineSize] != editText[letter] && !wasMinus){   // - lineSize, чтобы не выйти за пределы массива(причина как сверху)

                if(!isMistake && firstTime){    // когда мы стираем текст после ошибки, нам нужно, чтобы оно не посчитало лишний раз
                    mistakes++;                 // firstTime здесь нужно, потому что если поставить после ошибки ещё символы, то при стирании
                    ui->lineEditCurrentMistakes->setText(QString::number(mistakes)); // мы вернемся опять сюда, и будет лишняя ошибка засчитана
                    isMistake = true;
                    firstTime = false;
                }

        }else{    // если правильно ввели букву
//            QFont font;
//            font.setBold(true);
//            font.setStyleName("Romantic");
//            font.setPointSize(12);
//            ui->textBrowser->setCurrentFont(font);

            if(editText.length() - 2 == letter){ //проверка на конец текста, -2 так как в конце каждой строки есть символ перехода на новую
                                     //n, его нам считать не надо, и ещё -1 так как с нуля идет счет
                on_win(); //победа
            }

            wasMinus = false;
            isMistake = false;
            letter++;
            QString gap = " ";
            if(arg1[letter - 1 - lineSize] == gap){
                lineSize = letter;                
                ui->lineEditField->clear();
            }          
        }
    }
    else{
            if(letter>arg1.length() +lineSize && letter>0){ //сюда попадаем, когда стираем символы, которые были правильными
                letter--;
                firstTime = true;
            }
            else{
                isMistake = false;
                if(arg1.length()- 1 + lineSize  == letter-1) firstTime = true;  // когда стираем уже неправильный символ
            }
    }
}

void MainWindow::on_butStart_clicked()
{
    if(ui->textBrowser->toPlainText() == ""){
        ui->textBrowser->insertPlainText("Text not Loaded");
        ui->lineEditField->setEnabled(false);
    }
    else{
        ui->lineEditField->setEnabled(true);
        ui->lineEditCurrentMistakes->setText("0");
        ui->lineEditCurrentSpeed->setText("0");
        timer->start(1000);
        ui->butCreateTextFromFile->setEnabled(false);
        ui->butLoadtextFromFile->setEnabled(false);
        ui->butStart->setEnabled(false);
        ui->comboBoxSelectBook->setEnabled(false);
    }
}

void MainWindow::on_butCreateTextFromFile_clicked()
{
    ui->textBrowser->clear();
    QString filePath;
    QString currentDir = QDir::currentPath();
    filePath = QFileDialog::getOpenFileName(this,"Choose a book to processing:",currentDir,"TXT Files (*.txt);");   
    ui->textBrowser->insertPlainText(book.createTextFileFromBook(filePath));
    ui->comboBoxSelectBook->addItem(book.nameFileOfTexts);  // подгружаем названия нашей книги в comboBoxSelectBook
}

void MainWindow::on_comboBoxSelectBook_currentIndexChanged(int index)
{
   if(index !=-1) book.loadDataFromDataFile(ui->comboBoxSelectBook->currentText());

   ui->butStart->setEnabled(true); // это если кнопка была заблочена, когда книга пройдена
   on_update_data();

}

void MainWindow::on_time()
{
    this->sec++;
    if(this->sec >= 60){
        this->sec = 0;
        this->min++;
    }
    ui->lineEditMinutes->setText(QString::number(this->min));
    ui->lineEditSeconds->setText(QString::number(this->sec));
}

void MainWindow::on_update_data()
{
    ui->lineEditTextsAmount->setText(QString::number(floor(book.textsAmount)));
    ui->lineEditCurrentText->setText(QString::number(floor(book.currentText + 1)));
    ui->lineEditRecord->setText(QString::number(floor(book.record)));
    ui->lineEditSpeed->setText(QString::number(floor(book.averageSpeed)));
    ui->lineEditMistakes->setText(QString::number(book.mistakes)+"%");
    ui->lineEditPlayTime->setText(QString::number(floor(book.playTimeHours)) + " h; " +
                                  QString::number(floor(book.playTimeMinutes)) + " m; "); // floor убирает остаток от числа
}

void MainWindow::on_win()
{
    timer->stop();
    ui->lineEditField->setEnabled(false);
    ui->lineEditField->clear();

    //обрабатываем полученные данные
    float averageCurrentSpeed = editText.length() - 1;
    averageCurrentSpeed = round(round((averageCurrentSpeed /(ui->lineEditMinutes->text().toFloat()*60 + ui->lineEditSeconds->text().toFloat())*60)*100)/100);
    ui->lineEditCurrentSpeed->setText(QString::number(averageCurrentSpeed)); //считаем среднюю скорость за текст
    ui->labelCurrentMistakesPercent->setText("("+ QString::number(round(100*ui->lineEditCurrentMistakes->text().toFloat()*100/(editText.length()-1))/100) +"%)");
    //считаем кол-во ошибок в процентах  // round*100/100 это нужно, чтобы было 2 знака после запятой

    book.currentText++; // записываем полученные данные для обработки и сейва
    book.averageSpeed = averageCurrentSpeed;
    book.mistakes = round(100*ui->lineEditCurrentMistakes->text().toFloat()*100/(editText.length()-1))/100;
            //round(100*ui->lineEditCurrentMistakes->text().toFloat()*100/(editText.length()-1))/100;
    book.playTimeMinutes = this->min;
    book.playTimeSeconds = this->sec;
    if(book.averageSpeed>book.record){ // если новый рекорд
        book.record = book.averageSpeed;
        ui->textBrowser->insertPlainText("New record!!!");
    }

    book.updateDataFile(ui->comboBoxSelectBook->currentText()); // заносим данные со статистикой в файл
    on_update_data();

    ui->butCreateTextFromFile->setEnabled(true);   // делаем доступными на форме
    ui->butLoadtextFromFile->setEnabled(true);
    ui->butStart->setEnabled(true);
    ui->comboBoxSelectBook->setEnabled(true);
}




void MainWindow::on_radioButtonCustom_clicked()
{
    ui->comboBoxSelectBook->clear();
    book.loadBookNamesFromBookFile(); // подгружаем названия наших книг в comboBoxSelectBook
    ui->comboBoxSelectBook->addItems(book.bookNames);
}


void MainWindow::on_radioButtonTraining_clicked()
{

}

