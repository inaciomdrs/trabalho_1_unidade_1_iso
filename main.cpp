#include "mainwindow.h"
#include "controller.h"

#include <QApplication>
#include <string>

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();

    Input_Interface I;
    I.algorithm_selected = 3;
    I.iteracoes = 10;
    I.range = "100:100:1000";

    process(&I);

}