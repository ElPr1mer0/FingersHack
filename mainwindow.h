#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

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

    void on_lineEditField_textChanged(const QString &arg1);

    void on_butStart_clicked();

    void on_butLoadtextFromFile_clicked();

    void on_butCreateTextFromFile_clicked();

    void on_comboBoxSelectBook_currentIndexChanged(int);

    void on_time();

    void on_update_data();

    void on_win();

    void on_radioButtonCustom_clicked();

    void on_radioButtonTraining_clicked();

private:
    //Ui::MainWindow *ui;
    QTimer *timer;
    int min = 0, sec = 0;
};
#endif // MAINWINDOW_H
