#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <string>
#include <QMainWindow>
#include <iostream>
#include <QTimer>

using namespace std;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTimer *timer;

public slots:
    void MyTimerSlot();

private slots:
    void on_InitialsButton_clicked();

    void on_exitButton_clicked();

    void on_GuessPushButton_clicked();

    void cust_Slot();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
