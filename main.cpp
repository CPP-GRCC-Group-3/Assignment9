#include "mainwindow.h"
#include "gamehandler.h"
#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>
#include <QTimer>
#include <iostream>
#include <ctime>
#include <vector>
#include <QFile>
#include <QIODevice>
#include <QTextStream>

QTimer timer;
using namespace std;

int main(int argc, char *argv[])
{

        srand(time(NULL));

    //    int totalLines = 0;
    //    string quote;
    //    vector<string> textCatch;
    //    ifstream myQuote;
    //    myQuote.open("quotes.txt")

    //    while(getline(myQuote,quote)) {

    //      textCatch.push_back(quote);
    //    }

    //    short int quoteSelect = rand()% 11 + 0;
    //    QString quoteOutput = QString::fromStdString(textCatch[quoteSelect]);

        QApplication a(argc, argv);
        MainWindow w;

        QPixmap SplashIMage(250,250);
        SplashIMage.fill(Qt::white);
        SplashIMage.fill(Qt::red);

        QSplashScreen HangmanSplashScreen(SplashIMage, Qt::WindowStaysOnTopHint);
        HangmanSplashScreen.show();



        HangmanSplashScreen.showMessage("Loading Hangman Program...\n"
    "Developers: Caleb M, Amanuel F, Caleb B\n"
    "Version 3.1\n");

    //HangmanSplashScreen.showMessage(quoteOutput);

        QTimer::singleShot(5000, &HangmanSplashScreen, SLOT(close()));
        QTimer::singleShot(5000, &w,SLOT(show()));

        return a.exec();
}

