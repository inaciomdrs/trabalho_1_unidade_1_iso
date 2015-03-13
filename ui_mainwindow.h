/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QCustomPlot *customPlot;
    QLineEdit *lineEdit_Iteracoes;
    QLineEdit *lineEdit_Dimensao;
    QProgressBar *progressBar;
    QLabel *label_2;
    QPushButton *pushButton_Executar;
    QCheckBox *checkBox_Quick;
    QCheckBox *checkBox_Bubble;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(624, 391);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        customPlot = new QCustomPlot(centralWidget);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setGeometry(QRect(40, 70, 551, 251));
        lineEdit_Iteracoes = new QLineEdit(centralWidget);
        lineEdit_Iteracoes->setObjectName(QStringLiteral("lineEdit_Iteracoes"));
        lineEdit_Iteracoes->setGeometry(QRect(152, 0, 131, 27));
        lineEdit_Dimensao = new QLineEdit(centralWidget);
        lineEdit_Dimensao->setObjectName(QStringLiteral("lineEdit_Dimensao"));
        lineEdit_Dimensao->setGeometry(QRect(110, 30, 171, 27));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(400, 30, 201, 23));
        progressBar->setValue(0);
        progressBar->setTextVisible(true);
        progressBar->setOrientation(Qt::Horizontal);
        progressBar->setInvertedAppearance(false);
        progressBar->setTextDirection(QProgressBar::TopToBottom);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 30, 71, 20));
        pushButton_Executar = new QPushButton(centralWidget);
        pushButton_Executar->setObjectName(QStringLiteral("pushButton_Executar"));
        pushButton_Executar->setGeometry(QRect(400, 0, 201, 27));
        checkBox_Quick = new QCheckBox(centralWidget);
        checkBox_Quick->setObjectName(QStringLiteral("checkBox_Quick"));
        checkBox_Quick->setGeometry(QRect(290, 10, 91, 22));
        checkBox_Bubble = new QCheckBox(centralWidget);
        checkBox_Bubble->setObjectName(QStringLiteral("checkBox_Bubble"));
        checkBox_Bubble->setGeometry(QRect(290, 30, 111, 22));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 151, 20));
        MainWindow->setCentralWidget(centralWidget);
        lineEdit_Iteracoes->raise();
        lineEdit_Dimensao->raise();
        progressBar->raise();
        label_2->raise();
        pushButton_Executar->raise();
        checkBox_Quick->raise();
        checkBox_Bubble->raise();
        label->raise();
        customPlot->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 624, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_2->setText(QApplication::translate("MainWindow", "Dimens\303\243o", 0));
        pushButton_Executar->setText(QApplication::translate("MainWindow", "Executar", 0));
        checkBox_Quick->setText(QApplication::translate("MainWindow", "QuickSort", 0));
        checkBox_Bubble->setText(QApplication::translate("MainWindow", "BubbleSort", 0));
        label->setText(QApplication::translate("MainWindow", "N\303\272mero de Itera\303\247\303\265es", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
