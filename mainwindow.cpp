#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "workWithText.h"
#include "hash.h"

TEXT book; // создаем объект класса текста, для работы с текстами и обработки инфы

///////////////////////on_lineEdit_textChanged////////////////////////////////
QString editText;
int letter = 0; // для подсчёта кол-ва пройденных символов в editBrowser
int lineSize = 0; // для подсчета реального кол-ва символов, которые были в введенной игроком строке
int mistakes = 0;// для подсчета кол-ва ошибок при игре
bool firstTime = true;
bool isMistake = false; // проверка на ошибку

///////////////////////on_lineEdit_textChanged////////////////////////////////


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setEnabled(false);

    ui->comboBoxSelectBook->clear();
    book.loadBookNamesFromBookFile(); // подгружаем названия наших книг в comboBoxSelectBook
    ui->comboBoxSelectBook->addItems(book.bookNames);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_butLoadtextFromFile_clicked()
{
    letter = 0;
    lineSize = 0;
    mistakes = 0;
    isMistake = false;
    ui->lineNumberOfMistakes->setText(QString::number(mistakes));
    ui->textBrowser->clear();
    QString fileName = ui->comboBoxSelectBook->currentText();
    if(fileName != ""){
        ui->textBrowser->insertPlainText(book.loadTextFromFile(fileName));
    }
    else{
        qDebug()<<"Error! Book haven't founded!";
    }
    editText = ui->textBrowser->toPlainText();
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    if(editText.length() - 2 == letter){ //проверка на конец текста
        ui->lineEdit->setEnabled(false);
        ui->lineEdit->clear();
        ui->textBrowser->insertPlainText("WINNER"); // -2 вычитаем пробел в конце строки + длина всегда больше на 1 чем есть (от 0)
    }

    if(arg1.length()- 1 + lineSize  == letter) { // + lineSize, так как мы обнуляем нашу строку после пробела
                                                // а кол-во символов, которые были помнить надо для правильно проверки на ввод
        if(arg1[letter - lineSize] != editText[letter]){// - lineSize, чтобы не выйти за пределы массива(причина как сверху)

            if(!isMistake && firstTime){    // когда мы стираем текст после ошибки, нам нужно, чтобы оно не посчитало лишний раз
                mistakes++;                 // firstTime здесь нужно, потому что если поставить после ошибки ещё символы, то при стирании
                ui->lineNumberOfMistakes->setText(QString::number(mistakes)); // мы вернемся опять сюда, и будет лишняя ошибка засчитана
                isMistake = true;
                firstTime = false;
           }
        }else{           // а то здесь эти позиции снова совпадают
//            QFont font;
//            font.setBold(true);
//            font.setStyleName("Romantic");
//            font.setPointSize(12);
//            ui->textBrowser->setCurrentFont(font);
            isMistake = false;
            letter++;
            QString gap = " ";
            if(arg1[letter - 1 - lineSize] == gap){
                lineSize = letter;                
                ui->lineEdit->clear();
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
        ui->lineEdit->setEnabled(false);
    }
    else{
        ui->lineEdit->setEnabled(true);
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
    ui->lineEditTextsAmount->setText(QString::number(book.textsCounter));
    ui->lineEditCurrentText->setText(QString::number(book.currentText));
    ui->lineEditRecord->setText(QString::number(book.record));
    ui->lineEditSpeed->setText(QString::number(book.speed));
    ui->lineEditMistakes->setText(QString::number(book.mistakes));
    ui->lineEditPlayTime->setText(QString::number(book.playTimeHours) + " h; " +
                                  QString::number(book.playTimeHours) + " m; ");

}




