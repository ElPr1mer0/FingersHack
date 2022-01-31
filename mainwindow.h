#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    Ui::MainWindow *ui; // перенёс сюда, чтобы вызывать из своего класса

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_lineEdit_textChanged(const QString &arg1);

    void on_butStart_clicked();

    void on_butLoadtextFromFile_clicked();

    void on_butCreateTextFromFile_clicked();

    void on_comboBoxSelectBook_currentIndexChanged(int);

private:
    //Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
