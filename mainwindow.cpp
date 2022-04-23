#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "custom.h"
#include "training.h"
#include "hash.h"

TEXT text; // создаем объект класса текста, для работы с текстами и обработки инфы
TRAINING  training;
///////////////////////on_lineEdit_textChanged////////////////////////////////
QString editText;
QString dash = "-";

//#define DASH "-"

int letter = 0; // для подсчёта кол-ва пройденных символов в editBrowser
int lineSize = 0; // для подсчета реального кол-ва символов, которые были в введенной игроком строке
int mistakes = 0;// для подсчета кол-ва ошибок при игре

bool firstTime = true;
bool isMistake = false; // проверка на ошибку
bool wasMinus = false; // если находим символ -.е,Е

///////////////////////on_lineEdit_textChanged////////////////////////////////





////////////////////////////////////////////////////////////////////////
////////////////////////////MAIN_WINDOW/////////////////////////////////
////////////////////////////////////////////////////////////////////////
// Эта функция используется для задания значений переменных при старте//
// приложения.                                                        //
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEditField->setEnabled(false);
    ui->butStart->setEnabled(false);

    ui->comboBoxSelectBook->clear();
    text.loadBookNamesFromBookFile(); // подгружаем названия наших книг в comboBoxSelectBook
    ui->comboBoxSelectBook->addItems(text.bookNames);

    timer = new QTimer(this); //создаем таймер
    connect (timer, SIGNAL(timeout()),this, SLOT(on_time()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
////////////////////////////////////////////////////////////////////////
////////////////////////////MAIN_WINDOW/////////////////////////////////
////////////////////////////////////////////////////////////////////////





////////////////////////////////////////////////////////////////////////
//////////////////ON_BUT_LOAD_TEXT_FROM_FILE_CLICKED////////////////////
////////////////////////////////////////////////////////////////////////
// Эта функция обрабатывает событие нажатия на кнопку загрузки текстов//
// из игрового файла.
void MainWindow::on_butLoadtextFromFile_clicked()
{
    ui->textBrowser->clear();
    QString fileName = ui->comboBoxSelectBook->currentText();
    if (ui->radioButtonCustom->isChecked()){
        if(fileName != ""){ // если есть такой файл
            text.currentText = 0; // записываем полученные данные для обработки и сейва
            text.averageSpeed = 0;
            text.mistakes = 0;
            text.playTimeMinutes = 0;
            text.playTimeSeconds = 0;
            text.record = 0;
            text.textsAmount = 0;

            text.loadDataFromDataFile(ui->comboBoxSelectBook->currentText());
            on_update_data();

            if(text.currentText>=text.textsAmount){ // если тексты закончились
                ui->butStart->setEnabled(false);
                ui->textBrowser->insertPlainText("The text is over!");
            }
            else{
                 ui->textBrowser->insertPlainText(text.loadTextFromFile(fileName));
                 editText = ui->textBrowser->toPlainText();
                 ui->butStart->setEnabled(true);

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
            qDebug()<<"Error! text haven't founded!";
        }
    }
    else if(ui->radioButtonTraining->isChecked()){
         ui->textBrowser->insertPlainText(training.loadTraining(fileName));
         editText = ui->textBrowser->toPlainText();
         ui->butStart->setEnabled(true);
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
////////////////////////////////////////////////////////////////////////
//////////////////ON_BUT_LOAD_TEXT_FROM_FILE_CLICKED////////////////////
////////////////////////////////////////////////////////////////////////





////////////////////////////////////////////////////////////////////////
//////////////////ON_LINE_EDIT_FIELD_TEXT_CHANGED///////////////////////
////////////////////////////////////////////////////////////////////////
// Эта функция обрабатывает события изменения вводимого текста в      //
// игровое поле в ходе игры. Проверяет на победу.                     //
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
////////////////////////////////////////////////////////////////////////
//////////////////ON_LINE_EDIT_FIELD_TEXT_CHANGED///////////////////////
////////////////////////////////////////////////////////////////////////





////////////////////////////////////////////////////////////////////////
//////////////////////////ON_BUT_START_CLICKED//////////////////////////
////////////////////////////////////////////////////////////////////////
// Эта функция обрабатывает нажатие на кнопку старта игры             //
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
        ui->butStart->setEnabled(false);
    }
}
////////////////////////////////////////////////////////////////////////
//////////////////////////ON_BUT_START_CLICKED//////////////////////////
////////////////////////////////////////////////////////////////////////





////////////////////////////////////////////////////////////////////////
////////////////ON_BUT_CREATE_TEXT_FROM_FILE_CLICKED////////////////////
////////////////////////////////////////////////////////////////////////
// Эта функция обрабатывает нажатие на кнопку при создании новой      //
// игровой книги с текстами из входящего файла.                       //
void MainWindow::on_butCreateTextFromFile_clicked()
{
    ui->textBrowser->clear();
    QString filePath;
    QString currentDir = QDir::currentPath();
    filePath = QFileDialog::getOpenFileName(this,"Choose a text to processing:",currentDir,"TXT Files (*.txt);");
    ui->textBrowser->insertPlainText(text.createTextFileFromBook(filePath));
    ui->comboBoxSelectBook->addItem(text.nameFileOfTexts);  // подгружаем названия нашей книги в comboBoxSelectBook
}
////////////////////////////////////////////////////////////////////////
////////////////ON_BUT_CREATE_TEXT_FROM_FILE_CLICKED////////////////////
////////////////////////////////////////////////////////////////////////





////////////////////////////////////////////////////////////////////////
////////////ON_COMBO_BOX_SELECT_BOOK_CURRENT_INDEX_CHANGED//////////////
////////////////////////////////////////////////////////////////////////
// Эта функция обрабатывает событие выбора другой книги в комбо боксе //
// и подгружает информацию о игровой книге.                           //
void MainWindow::on_comboBoxSelectBook_currentIndexChanged(int index)
{
   if(index !=-1) text.loadDataFromDataFile(ui->comboBoxSelectBook->currentText());

   //ui->butStart->setEnabled(true); // это если кнопка была заблочена, когда книга пройдена
   on_update_data();
}
////////////////////////////////////////////////////////////////////////
////////////ON_COMBO_BOX_SELECT_BOOK_CURRENT_INDEX_CHANGED//////////////
////////////////////////////////////////////////////////////////////////





////////////////////////////////////////////////////////////////////////
///////////////////////////////ON_TIME//////////////////////////////////
////////////////////////////////////////////////////////////////////////
// Эта функция создана для подсчета времени нахождения в игре, при    //
// при наборе текста, для сохранения этого в статистике.              //
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
////////////////////////////////////////////////////////////////////////
///////////////////////////////ON_TIME//////////////////////////////////
////////////////////////////////////////////////////////////////////////





////////////////////////////////////////////////////////////////////////
////////////////////////////ON_UPDATE_DATE//////////////////////////////
////////////////////////////////////////////////////////////////////////
// Функция обновляет данные после набора текста, или при загрузке     //
// приложения.                                                        //
void MainWindow::on_update_data()
{
    ui->lineEditTextsAmount->setText(QString::number(floor(text.textsAmount)));
    ui->lineEditCurrentText->setText(QString::number(floor(text.currentText + 1)));
    ui->lineEditRecord->setText(QString::number(floor(text.record)));
    ui->lineEditSpeed->setText(QString::number(floor(text.averageSpeed)));
    ui->lineEditMistakes->setText(QString::number(text.mistakes)+"%");
    ui->lineEditPlayTime->setText(QString::number(floor(text.playTimeHours)) + " h; " +
                                  QString::number(floor(text.playTimeMinutes)) + " m; "); // floor убирает остаток от числа
}
////////////////////////////////////////////////////////////////////////
////////////////////////////ON_UPDATE_DATE//////////////////////////////
////////////////////////////////////////////////////////////////////////





////////////////////////////////////////////////////////////////////////
////////////////////////////////////ON_WIN//////////////////////////////
////////////////////////////////////////////////////////////////////////
// Функция вызывается при "победе" (окончании игрового текста), для   //
// подсчета игровых данных, их обработки и сохранения.                //
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

    text.currentText++; // записываем полученные данные для обработки и сейва
    text.averageSpeed = averageCurrentSpeed;
    text.mistakes = round(100*ui->lineEditCurrentMistakes->text().toFloat()*100/(editText.length()-1))/100;
            //round(100*ui->lineEditCurrentMistakes->text().toFloat()*100/(editText.length()-1))/100;
    text.playTimeMinutes = this->min;
    text.playTimeSeconds = this->sec;
    if(text.averageSpeed>text.record){ // если новый рекорд
        text.record = text.averageSpeed;
        ui->textBrowser->insertPlainText("New record!!!");
    }

    text.updateDataFile(ui->comboBoxSelectBook->currentText()); // заносим данные со статистикой в файл
    on_update_data();

    ui->butCreateTextFromFile->setEnabled(true);   // делаем доступными на форме
    ui->butLoadtextFromFile->setEnabled(true);
    ui->comboBoxSelectBook->setEnabled(true);
}
////////////////////////////////////////////////////////////////////////
////////////////////////////////////ON_WIN//////////////////////////////
////////////////////////////////////////////////////////////////////////





////////////////////////////////////////////////////////////////////////
/////////////////////ON_RADIO_BUTTON_CUSTOM_CLICKED/////////////////////
////////////////////////////////////////////////////////////////////////
// Функция обрабатывает переключение в радио-группе и подгружает      //
// данные.                                                            //
void MainWindow::on_radioButtonCustom_clicked()
{
    ui->comboBoxSelectBook->clear();
    text.loadBookNamesFromBookFile(); // подгружаем названия наших книг в comboBoxSelectBook
    ui->comboBoxSelectBook->addItems(text.bookNames);
}
////////////////////////////////////////////////////////////////////////
/////////////////////ON_RADIO_BUTTON_CUSTOM_CLICKED/////////////////////
////////////////////////////////////////////////////////////////////////





////////////////////////////////////////////////////////////////////////
///////////////////ON_RADIO_BUTTON_Training_CLICKED/////////////////////
////////////////////////////////////////////////////////////////////////
// Функция обрабатывает переключение в радио-группе и подгружает      //
// данные.                                                            //
void MainWindow::on_radioButtonTraining_clicked()
{
    ui->comboBoxSelectBook->clear();
    training.loadTrainingNamesFromTrainingFile(); // подгружаем названия наших тренировок в comboBoxSelectBook
    ui->comboBoxSelectBook->addItems(training.trainingNames);
}
////////////////////////////////////////////////////////////////////////
///////////////////ON_RADIO_BUTTON_Training_CLICKED/////////////////////
////////////////////////////////////////////////////////////////////////
