#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <iostream>
#include <ctime>
#include "gamehandler.h"
#include <QPalette>

using namespace std;
GameHandler gamer;
int iSecret;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
//    ui->centralwidget->setStyleSheet("Background-color: rgb(255,0,0);");
    ui->statusbar->setStyleSheet("background-color: rgb(25, 255, 155);");
    ui->statusbar->showMessage("Hello",10000);
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()),this, SLOT(MyTimerSlot()));

    timer->start(1000);
    ui->lcdNumber->setPalette(QColor(0,0,255));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MyTimerSlot()
{

    int iValue = ui->lcdNumber->intValue();
    iValue++;
    ui->lcdNumber->display(iValue);

}

void MainWindow::on_InitialsButton_clicked()
{
    GameHandler gamer;

    srand(time(NULL));
    iSecret = rand() % 11 + 0;

    string init = this->ui->InitialsTextBox->toPlainText().toStdString();
    gamer.setInitials(init);

    QString qstr = QString::fromStdString(gamer.getInitials());
    this->ui->CurrentInitials->setText(qstr);

    this->ui->GuessPushButton->setEnabled(true);
    this->ui->GuessBox->setEnabled(true);

    gamer.hide(true, iSecret);
}

void MainWindow::on_exitButton_clicked()
{
    exit(0);
}

void MainWindow:: cust_Slot() {

    this->ui->GuessBox->clear();
    this->ui->InitialsTextBox->clear();
    this->ui->CurrentInitials->clear();
    this->ui->WordIs->clear();
    gamer.clearBank();
    gamer.clearScore();
}


void MainWindow::on_GuessPushButton_clicked()
{

    bool guessStatus;
    string guess;

    this->ui->LABELGuessFeedback->setText("Please enter your guess. If you would like a hint, type 'hint' ");




                gamer.bankStore(true,iSecret);

                guess = this->ui->GuessBox->toPlainText().toStdString();

                if (guess == "hint") {

                    string hint = gamer.displayHint();
                    QString qstr = QString::fromStdString(hint);
                    this->ui->WordIs->setText(qstr);

                }

                else {
                    //check if users guess was valid
                    guess = guess.substr(0, 1);
                    guessStatus = gamer.checkGuess(guess);

                    gamer.hide(true, iSecret);
                }

                this->ui->GuessBox->clear();

            if (guessStatus) {
                this->ui->GameWinOrLose->setText("Correct!");
            }
            else {
                this->ui->GameWinOrLose->setText("Incorrect");
            }

            string number = to_string(gamer.getCurrentScore());

            QString score = QString::fromStdString(number);

            this->ui->scoreNumber->setText(score);

            string position = gamer.display(true, iSecret);
            QString qstr = QString::fromStdString(position);

            this->ui->WordIs->setText(qstr);
            (gamer.gameState());

}
