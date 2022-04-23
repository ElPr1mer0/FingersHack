/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QPushButton *butLoadtextFromFile;
    QPushButton *butStart;
    QPushButton *butCreateTextFromFile;
    QComboBox *comboBoxSelectBook;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelTextsAmount;
    QLineEdit *lineEditTextsAmount;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelCurrentText;
    QLineEdit *lineEditCurrentText;
    QHBoxLayout *horizontalLayout;
    QLabel *labelRecord;
    QLineEdit *lineEditRecord;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelAverageSpeed;
    QLineEdit *lineEditSpeed;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelMistakes;
    QLineEdit *lineEditMistakes;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelPlayTime;
    QLineEdit *lineEditPlayTime;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEditField;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelCurrentMistakes;
    QLineEdit *lineEditCurrentMistakes;
    QLabel *labelCurrentMistakesPercent;
    QHBoxLayout *horizontalLayout_10;
    QLabel *labelCurrentSpeed;
    QLineEdit *lineEditCurrentSpeed;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_8;
    QLabel *labelCurrentPlayTime;
    QLineEdit *lineEditMinutes;
    QLabel *labelCurrentMinutes;
    QLineEdit *lineEditSeconds;
    QLabel *labelCurrentSec;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButtonCustom;
    QRadioButton *radioButtonTraining;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1267, 720);
        MainWindow->setTabShape(QTabWidget::Rounded);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(30, 30, 771, 192));
        QFont font;
        font.setPointSize(16);
        textBrowser->setFont(font);
        textBrowser->setFocusPolicy(Qt::NoFocus);
        textBrowser->setFrameShape(QFrame::NoFrame);
        textBrowser->setFrameShadow(QFrame::Sunken);
        textBrowser->setTextInteractionFlags(Qt::NoTextInteraction);
        butLoadtextFromFile = new QPushButton(centralwidget);
        butLoadtextFromFile->setObjectName(QString::fromUtf8("butLoadtextFromFile"));
        butLoadtextFromFile->setGeometry(QRect(860, 70, 111, 31));
        butStart = new QPushButton(centralwidget);
        butStart->setObjectName(QString::fromUtf8("butStart"));
        butStart->setGeometry(QRect(860, 110, 111, 31));
        butCreateTextFromFile = new QPushButton(centralwidget);
        butCreateTextFromFile->setObjectName(QString::fromUtf8("butCreateTextFromFile"));
        butCreateTextFromFile->setGeometry(QRect(860, 30, 111, 31));
        comboBoxSelectBook = new QComboBox(centralwidget);
        comboBoxSelectBook->setObjectName(QString::fromUtf8("comboBoxSelectBook"));
        comboBoxSelectBook->setGeometry(QRect(860, 0, 391, 22));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setKerning(false);
        comboBoxSelectBook->setFont(font1);
        comboBoxSelectBook->setMouseTracking(false);
        comboBoxSelectBook->setTabletTracking(false);
        comboBoxSelectBook->setFocusPolicy(Qt::ClickFocus);
        comboBoxSelectBook->setLayoutDirection(Qt::LeftToRight);
        comboBoxSelectBook->setAutoFillBackground(false);
        comboBoxSelectBook->setEditable(false);
        comboBoxSelectBook->setIconSize(QSize(16, 16));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(980, 30, 267, 221));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelTextsAmount = new QLabel(layoutWidget);
        labelTextsAmount->setObjectName(QString::fromUtf8("labelTextsAmount"));
        labelTextsAmount->setMinimumSize(QSize(90, 0));
        QFont font2;
        font2.setPointSize(12);
        labelTextsAmount->setFont(font2);

        horizontalLayout_2->addWidget(labelTextsAmount);

        lineEditTextsAmount = new QLineEdit(layoutWidget);
        lineEditTextsAmount->setObjectName(QString::fromUtf8("lineEditTextsAmount"));
        lineEditTextsAmount->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEditTextsAmount->sizePolicy().hasHeightForWidth());
        lineEditTextsAmount->setSizePolicy(sizePolicy);
        lineEditTextsAmount->setFont(font2);
        lineEditTextsAmount->setFocusPolicy(Qt::NoFocus);
        lineEditTextsAmount->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditTextsAmount->setReadOnly(true);

        horizontalLayout_2->addWidget(lineEditTextsAmount);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelCurrentText = new QLabel(layoutWidget);
        labelCurrentText->setObjectName(QString::fromUtf8("labelCurrentText"));
        labelCurrentText->setMinimumSize(QSize(90, 0));
        labelCurrentText->setFont(font2);

        horizontalLayout_3->addWidget(labelCurrentText);

        lineEditCurrentText = new QLineEdit(layoutWidget);
        lineEditCurrentText->setObjectName(QString::fromUtf8("lineEditCurrentText"));
        sizePolicy.setHeightForWidth(lineEditCurrentText->sizePolicy().hasHeightForWidth());
        lineEditCurrentText->setSizePolicy(sizePolicy);
        lineEditCurrentText->setFont(font2);
        lineEditCurrentText->setFocusPolicy(Qt::NoFocus);
        lineEditCurrentText->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditCurrentText->setReadOnly(true);

        horizontalLayout_3->addWidget(lineEditCurrentText);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelRecord = new QLabel(layoutWidget);
        labelRecord->setObjectName(QString::fromUtf8("labelRecord"));
        labelRecord->setMinimumSize(QSize(90, 0));
        labelRecord->setFont(font2);

        horizontalLayout->addWidget(labelRecord);

        lineEditRecord = new QLineEdit(layoutWidget);
        lineEditRecord->setObjectName(QString::fromUtf8("lineEditRecord"));
        sizePolicy.setHeightForWidth(lineEditRecord->sizePolicy().hasHeightForWidth());
        lineEditRecord->setSizePolicy(sizePolicy);
        lineEditRecord->setFont(font2);
        lineEditRecord->setFocusPolicy(Qt::NoFocus);
        lineEditRecord->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditRecord->setReadOnly(true);

        horizontalLayout->addWidget(lineEditRecord);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        labelAverageSpeed = new QLabel(layoutWidget);
        labelAverageSpeed->setObjectName(QString::fromUtf8("labelAverageSpeed"));
        labelAverageSpeed->setMinimumSize(QSize(90, 0));
        labelAverageSpeed->setFont(font2);

        horizontalLayout_5->addWidget(labelAverageSpeed);

        lineEditSpeed = new QLineEdit(layoutWidget);
        lineEditSpeed->setObjectName(QString::fromUtf8("lineEditSpeed"));
        sizePolicy.setHeightForWidth(lineEditSpeed->sizePolicy().hasHeightForWidth());
        lineEditSpeed->setSizePolicy(sizePolicy);
        lineEditSpeed->setFont(font2);
        lineEditSpeed->setFocusPolicy(Qt::NoFocus);
        lineEditSpeed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditSpeed->setReadOnly(true);

        horizontalLayout_5->addWidget(lineEditSpeed);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        labelMistakes = new QLabel(layoutWidget);
        labelMistakes->setObjectName(QString::fromUtf8("labelMistakes"));
        labelMistakes->setMinimumSize(QSize(90, 0));
        labelMistakes->setFont(font2);

        horizontalLayout_6->addWidget(labelMistakes);

        lineEditMistakes = new QLineEdit(layoutWidget);
        lineEditMistakes->setObjectName(QString::fromUtf8("lineEditMistakes"));
        sizePolicy.setHeightForWidth(lineEditMistakes->sizePolicy().hasHeightForWidth());
        lineEditMistakes->setSizePolicy(sizePolicy);
        lineEditMistakes->setFont(font2);
        lineEditMistakes->setFocusPolicy(Qt::NoFocus);
        lineEditMistakes->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditMistakes->setReadOnly(true);

        horizontalLayout_6->addWidget(lineEditMistakes);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labelPlayTime = new QLabel(layoutWidget);
        labelPlayTime->setObjectName(QString::fromUtf8("labelPlayTime"));
        labelPlayTime->setMinimumSize(QSize(90, 0));
        labelPlayTime->setFont(font2);

        horizontalLayout_4->addWidget(labelPlayTime);

        lineEditPlayTime = new QLineEdit(layoutWidget);
        lineEditPlayTime->setObjectName(QString::fromUtf8("lineEditPlayTime"));
        sizePolicy.setHeightForWidth(lineEditPlayTime->sizePolicy().hasHeightForWidth());
        lineEditPlayTime->setSizePolicy(sizePolicy);
        lineEditPlayTime->setFont(font2);
        lineEditPlayTime->setFocusPolicy(Qt::NoFocus);
        lineEditPlayTime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditPlayTime->setReadOnly(true);

        horizontalLayout_4->addWidget(lineEditPlayTime);


        verticalLayout->addLayout(horizontalLayout_4);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 260, 781, 73));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEditField = new QLineEdit(layoutWidget1);
        lineEditField->setObjectName(QString::fromUtf8("lineEditField"));
        QFont font3;
        font3.setPointSize(14);
        lineEditField->setFont(font3);
        lineEditField->setReadOnly(false);

        verticalLayout_2->addWidget(lineEditField);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        labelCurrentMistakes = new QLabel(layoutWidget1);
        labelCurrentMistakes->setObjectName(QString::fromUtf8("labelCurrentMistakes"));
        labelCurrentMistakes->setMinimumSize(QSize(70, 0));
        labelCurrentMistakes->setFont(font2);

        horizontalLayout_7->addWidget(labelCurrentMistakes);

        lineEditCurrentMistakes = new QLineEdit(layoutWidget1);
        lineEditCurrentMistakes->setObjectName(QString::fromUtf8("lineEditCurrentMistakes"));
        lineEditCurrentMistakes->setEnabled(true);
        lineEditCurrentMistakes->setMinimumSize(QSize(25, 0));
        lineEditCurrentMistakes->setMaximumSize(QSize(2, 16777215));
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setStyleStrategy(QFont::PreferDefault);
        lineEditCurrentMistakes->setFont(font4);
        lineEditCurrentMistakes->setFocusPolicy(Qt::NoFocus);
        lineEditCurrentMistakes->setAcceptDrops(true);
        lineEditCurrentMistakes->setLayoutDirection(Qt::LeftToRight);
        lineEditCurrentMistakes->setAutoFillBackground(false);
        lineEditCurrentMistakes->setFrame(true);
        lineEditCurrentMistakes->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditCurrentMistakes->setReadOnly(true);
        lineEditCurrentMistakes->setClearButtonEnabled(false);

        horizontalLayout_7->addWidget(lineEditCurrentMistakes);

        labelCurrentMistakesPercent = new QLabel(layoutWidget1);
        labelCurrentMistakesPercent->setObjectName(QString::fromUtf8("labelCurrentMistakesPercent"));
        labelCurrentMistakesPercent->setMinimumSize(QSize(90, 0));
        labelCurrentMistakesPercent->setFont(font2);

        horizontalLayout_7->addWidget(labelCurrentMistakesPercent);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        labelCurrentSpeed = new QLabel(layoutWidget1);
        labelCurrentSpeed->setObjectName(QString::fromUtf8("labelCurrentSpeed"));
        labelCurrentSpeed->setMinimumSize(QSize(60, 0));
        labelCurrentSpeed->setFont(font2);

        horizontalLayout_10->addWidget(labelCurrentSpeed);

        lineEditCurrentSpeed = new QLineEdit(layoutWidget1);
        lineEditCurrentSpeed->setObjectName(QString::fromUtf8("lineEditCurrentSpeed"));
        lineEditCurrentSpeed->setMinimumSize(QSize(60, 0));
        lineEditCurrentSpeed->setMaximumSize(QSize(25, 16777215));
        QFont font5;
        font5.setPointSize(12);
        font5.setBold(true);
        lineEditCurrentSpeed->setFont(font5);
        lineEditCurrentSpeed->setFocusPolicy(Qt::NoFocus);
        lineEditCurrentSpeed->setLayoutDirection(Qt::LeftToRight);
        lineEditCurrentSpeed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditCurrentSpeed->setReadOnly(true);

        horizontalLayout_10->addWidget(lineEditCurrentSpeed);


        horizontalLayout_7->addLayout(horizontalLayout_10);

        horizontalSpacer = new QSpacerItem(700, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);


        horizontalLayout_9->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        labelCurrentPlayTime = new QLabel(layoutWidget1);
        labelCurrentPlayTime->setObjectName(QString::fromUtf8("labelCurrentPlayTime"));
        labelCurrentPlayTime->setMinimumSize(QSize(90, 0));
        labelCurrentPlayTime->setFont(font2);

        horizontalLayout_8->addWidget(labelCurrentPlayTime);

        lineEditMinutes = new QLineEdit(layoutWidget1);
        lineEditMinutes->setObjectName(QString::fromUtf8("lineEditMinutes"));
        lineEditMinutes->setMinimumSize(QSize(25, 0));
        lineEditMinutes->setMaximumSize(QSize(25, 16777215));
        lineEditMinutes->setFont(font5);
        lineEditMinutes->setFocusPolicy(Qt::NoFocus);
        lineEditMinutes->setLayoutDirection(Qt::LeftToRight);
        lineEditMinutes->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditMinutes->setReadOnly(true);

        horizontalLayout_8->addWidget(lineEditMinutes);

        labelCurrentMinutes = new QLabel(layoutWidget1);
        labelCurrentMinutes->setObjectName(QString::fromUtf8("labelCurrentMinutes"));
        labelCurrentMinutes->setMinimumSize(QSize(30, 0));
        labelCurrentMinutes->setMaximumSize(QSize(30, 16777215));
        labelCurrentMinutes->setFont(font2);

        horizontalLayout_8->addWidget(labelCurrentMinutes);

        lineEditSeconds = new QLineEdit(layoutWidget1);
        lineEditSeconds->setObjectName(QString::fromUtf8("lineEditSeconds"));
        lineEditSeconds->setMinimumSize(QSize(25, 0));
        lineEditSeconds->setMaximumSize(QSize(25, 16777215));
        lineEditSeconds->setFont(font5);
        lineEditSeconds->setFocusPolicy(Qt::NoFocus);
        lineEditSeconds->setLayoutDirection(Qt::LeftToRight);
        lineEditSeconds->setEchoMode(QLineEdit::Normal);
        lineEditSeconds->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditSeconds->setReadOnly(true);

        horizontalLayout_8->addWidget(lineEditSeconds);

        labelCurrentSec = new QLabel(layoutWidget1);
        labelCurrentSec->setObjectName(QString::fromUtf8("labelCurrentSec"));
        labelCurrentSec->setMinimumSize(QSize(30, 0));
        labelCurrentSec->setMaximumSize(QSize(30, 16777215));
        labelCurrentSec->setFont(font2);

        horizontalLayout_8->addWidget(labelCurrentSec);


        horizontalLayout_9->addLayout(horizontalLayout_8);


        verticalLayout_2->addLayout(horizontalLayout_9);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(860, 150, 111, 48));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        radioButtonCustom = new QRadioButton(layoutWidget2);
        radioButtonCustom->setObjectName(QString::fromUtf8("radioButtonCustom"));
        radioButtonCustom->setChecked(true);

        verticalLayout_3->addWidget(radioButtonCustom);

        radioButtonTraining = new QRadioButton(layoutWidget2);
        radioButtonTraining->setObjectName(QString::fromUtf8("radioButtonTraining"));
        radioButtonTraining->setChecked(false);

        verticalLayout_3->addWidget(radioButtonTraining);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1267, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());

        retranslateUi(MainWindow);

        comboBoxSelectBook->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        butLoadtextFromFile->setText(QCoreApplication::translate("MainWindow", "Load text from file", nullptr));
        butStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        butCreateTextFromFile->setText(QCoreApplication::translate("MainWindow", "Create text", nullptr));
        comboBoxSelectBook->setCurrentText(QString());
        labelTextsAmount->setText(QCoreApplication::translate("MainWindow", "Texts amount:", nullptr));
        labelCurrentText->setText(QCoreApplication::translate("MainWindow", "Current text:", nullptr));
        labelRecord->setText(QCoreApplication::translate("MainWindow", "Record:", nullptr));
        labelAverageSpeed->setText(QCoreApplication::translate("MainWindow", "Average speed:", nullptr));
        labelMistakes->setText(QCoreApplication::translate("MainWindow", "Mistakes:", nullptr));
        labelPlayTime->setText(QCoreApplication::translate("MainWindow", "Play time:", nullptr));
        labelCurrentMistakes->setText(QCoreApplication::translate("MainWindow", "Mistakes:", nullptr));
        lineEditCurrentMistakes->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelCurrentMistakesPercent->setText(QString());
        labelCurrentSpeed->setText(QCoreApplication::translate("MainWindow", "Speed:", nullptr));
        lineEditCurrentSpeed->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelCurrentPlayTime->setText(QCoreApplication::translate("MainWindow", "Play time:", nullptr));
        lineEditMinutes->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelCurrentMinutes->setText(QCoreApplication::translate("MainWindow", "Min", nullptr));
        lineEditSeconds->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelCurrentSec->setText(QCoreApplication::translate("MainWindow", "Sec", nullptr));
        radioButtonCustom->setText(QCoreApplication::translate("MainWindow", "Custom", nullptr));
        radioButtonTraining->setText(QCoreApplication::translate("MainWindow", "Training", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
