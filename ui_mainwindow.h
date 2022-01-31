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
    QLineEdit *lineEdit;
    QPushButton *butLoadtextFromFile;
    QPushButton *butStart;
    QLineEdit *lineNumberOfMistakes;
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
    QLabel *labelSpeed;
    QLineEdit *lineEditSpeed;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelMistakes;
    QLineEdit *lineEditMistakes;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelPlayTime;
    QLineEdit *lineEditPlayTime;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1216, 720);
        MainWindow->setTabShape(QTabWidget::Rounded);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(30, 30, 771, 192));
        QFont font;
        font.setPointSize(12);
        textBrowser->setFont(font);
        textBrowser->setFocusPolicy(Qt::NoFocus);
        textBrowser->setFrameShape(QFrame::NoFrame);
        textBrowser->setFrameShadow(QFrame::Sunken);
        textBrowser->setTextInteractionFlags(Qt::NoTextInteraction);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(30, 260, 771, 22));
        lineEdit->setFont(font);
        butLoadtextFromFile = new QPushButton(centralwidget);
        butLoadtextFromFile->setObjectName(QString::fromUtf8("butLoadtextFromFile"));
        butLoadtextFromFile->setGeometry(QRect(860, 70, 111, 31));
        butStart = new QPushButton(centralwidget);
        butStart->setObjectName(QString::fromUtf8("butStart"));
        butStart->setGeometry(QRect(860, 110, 111, 31));
        lineNumberOfMistakes = new QLineEdit(centralwidget);
        lineNumberOfMistakes->setObjectName(QString::fromUtf8("lineNumberOfMistakes"));
        lineNumberOfMistakes->setGeometry(QRect(30, 300, 21, 31));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        lineNumberOfMistakes->setFont(font1);
        lineNumberOfMistakes->setFocusPolicy(Qt::NoFocus);
        lineNumberOfMistakes->setLayoutDirection(Qt::LeftToRight);
        lineNumberOfMistakes->setReadOnly(true);
        butCreateTextFromFile = new QPushButton(centralwidget);
        butCreateTextFromFile->setObjectName(QString::fromUtf8("butCreateTextFromFile"));
        butCreateTextFromFile->setGeometry(QRect(860, 30, 111, 31));
        comboBoxSelectBook = new QComboBox(centralwidget);
        comboBoxSelectBook->setObjectName(QString::fromUtf8("comboBoxSelectBook"));
        comboBoxSelectBook->setGeometry(QRect(860, 0, 361, 22));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setKerning(false);
        comboBoxSelectBook->setFont(font2);
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
        labelTextsAmount->setFont(font);

        horizontalLayout_2->addWidget(labelTextsAmount);

        lineEditTextsAmount = new QLineEdit(layoutWidget);
        lineEditTextsAmount->setObjectName(QString::fromUtf8("lineEditTextsAmount"));
        lineEditTextsAmount->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEditTextsAmount->sizePolicy().hasHeightForWidth());
        lineEditTextsAmount->setSizePolicy(sizePolicy);
        lineEditTextsAmount->setFont(font);
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
        labelCurrentText->setFont(font);

        horizontalLayout_3->addWidget(labelCurrentText);

        lineEditCurrentText = new QLineEdit(layoutWidget);
        lineEditCurrentText->setObjectName(QString::fromUtf8("lineEditCurrentText"));
        sizePolicy.setHeightForWidth(lineEditCurrentText->sizePolicy().hasHeightForWidth());
        lineEditCurrentText->setSizePolicy(sizePolicy);
        lineEditCurrentText->setFont(font);
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
        labelRecord->setFont(font);

        horizontalLayout->addWidget(labelRecord);

        lineEditRecord = new QLineEdit(layoutWidget);
        lineEditRecord->setObjectName(QString::fromUtf8("lineEditRecord"));
        sizePolicy.setHeightForWidth(lineEditRecord->sizePolicy().hasHeightForWidth());
        lineEditRecord->setSizePolicy(sizePolicy);
        lineEditRecord->setFont(font);
        lineEditRecord->setFocusPolicy(Qt::NoFocus);
        lineEditRecord->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditRecord->setReadOnly(true);

        horizontalLayout->addWidget(lineEditRecord);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        labelSpeed = new QLabel(layoutWidget);
        labelSpeed->setObjectName(QString::fromUtf8("labelSpeed"));
        labelSpeed->setMinimumSize(QSize(90, 0));
        labelSpeed->setFont(font);

        horizontalLayout_5->addWidget(labelSpeed);

        lineEditSpeed = new QLineEdit(layoutWidget);
        lineEditSpeed->setObjectName(QString::fromUtf8("lineEditSpeed"));
        sizePolicy.setHeightForWidth(lineEditSpeed->sizePolicy().hasHeightForWidth());
        lineEditSpeed->setSizePolicy(sizePolicy);
        lineEditSpeed->setFont(font);
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
        labelMistakes->setFont(font);

        horizontalLayout_6->addWidget(labelMistakes);

        lineEditMistakes = new QLineEdit(layoutWidget);
        lineEditMistakes->setObjectName(QString::fromUtf8("lineEditMistakes"));
        sizePolicy.setHeightForWidth(lineEditMistakes->sizePolicy().hasHeightForWidth());
        lineEditMistakes->setSizePolicy(sizePolicy);
        lineEditMistakes->setFont(font);
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
        labelPlayTime->setFont(font);

        horizontalLayout_4->addWidget(labelPlayTime);

        lineEditPlayTime = new QLineEdit(layoutWidget);
        lineEditPlayTime->setObjectName(QString::fromUtf8("lineEditPlayTime"));
        sizePolicy.setHeightForWidth(lineEditPlayTime->sizePolicy().hasHeightForWidth());
        lineEditPlayTime->setSizePolicy(sizePolicy);
        lineEditPlayTime->setFont(font);
        lineEditPlayTime->setFocusPolicy(Qt::NoFocus);
        lineEditPlayTime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditPlayTime->setReadOnly(true);

        horizontalLayout_4->addWidget(lineEditPlayTime);


        verticalLayout->addLayout(horizontalLayout_4);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1216, 22));
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
        lineNumberOfMistakes->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        butCreateTextFromFile->setText(QCoreApplication::translate("MainWindow", "Create text", nullptr));
        comboBoxSelectBook->setCurrentText(QString());
        labelTextsAmount->setText(QCoreApplication::translate("MainWindow", "Texts amount:", nullptr));
        labelCurrentText->setText(QCoreApplication::translate("MainWindow", "Current text:", nullptr));
        labelRecord->setText(QCoreApplication::translate("MainWindow", "Record:", nullptr));
        labelSpeed->setText(QCoreApplication::translate("MainWindow", "Speed:", nullptr));
        labelMistakes->setText(QCoreApplication::translate("MainWindow", "Mistakes:", nullptr));
        labelPlayTime->setText(QCoreApplication::translate("MainWindow", "Play time:", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
