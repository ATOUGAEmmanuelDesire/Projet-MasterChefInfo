/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *table1;
    QLabel *table2;
    QLabel *table3;
    QLabel *client;
    QLabel *serveur;
    QLabel *chef;
    QLabel *comptoir;
    QLabel *frigo;
    QLabel *Plan_de_travail;
    QLabel *Four;
    QLabel *Four2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1473, 748);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        table1 = new QLabel(centralwidget);
        table1->setObjectName("table1");
        table1->setGeometry(QRect(30, 150, 141, 141));
        table1->setPixmap(QPixmap(QString::fromUtf8("Images/table.png")));
        table2 = new QLabel(centralwidget);
        table2->setObjectName("table2");
        table2->setGeometry(QRect(20, 410, 141, 141));
        table2->setPixmap(QPixmap(QString::fromUtf8("Images/table.png")));
        table3 = new QLabel(centralwidget);
        table3->setObjectName("table3");
        table3->setGeometry(QRect(290, 360, 141, 141));
        table3->setPixmap(QPixmap(QString::fromUtf8("Images/tables.png")));
        client = new QLabel(centralwidget);
        client->setObjectName("client");
        client->setGeometry(QRect(430, 160, 90, 90));
        client->setPixmap(QPixmap(QString::fromUtf8("Images/client.png")));
        serveur = new QLabel(centralwidget);
        serveur->setObjectName("serveur");
        serveur->setGeometry(QRect(650, 250, 131, 131));
        serveur->setPixmap(QPixmap(QString::fromUtf8("Images/serve.png")));
        chef = new QLabel(centralwidget);
        chef->setObjectName("chef");
        chef->setGeometry(QRect(1030, 350, 131, 91));
        chef->setPixmap(QPixmap(QString::fromUtf8("Images/chef.png")));
        comptoir = new QLabel(centralwidget);
        comptoir->setObjectName("comptoir");
        comptoir->setGeometry(QRect(810, 20, 101, 481));
        comptoir->setPixmap(QPixmap(QString::fromUtf8("Images/compt.png")));
        frigo = new QLabel(centralwidget);
        frigo->setObjectName("frigo");
        frigo->setGeometry(QRect(920, 20, 331, 151));
        frigo->setPixmap(QPixmap(QString::fromUtf8("Images/frigo.png")));
        Plan_de_travail = new QLabel(centralwidget);
        Plan_de_travail->setObjectName("Plan_de_travail");
        Plan_de_travail->setGeometry(QRect(1270, 30, 191, 611));
        Plan_de_travail->setPixmap(QPixmap(QString::fromUtf8("Images/cuisine.png")));
        Four = new QLabel(centralwidget);
        Four->setObjectName("Four");
        Four->setGeometry(QRect(870, 530, 411, 161));
        Four->setPixmap(QPixmap(QString::fromUtf8("Images/cusine2.png")));
        Four2 = new QLabel(centralwidget);
        Four2->setObjectName("Four2");
        Four2->setGeometry(QRect(890, 630, 131, 51));
        Four2->setPixmap(QPixmap(QString::fromUtf8("Images/cusine3.png")));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1473, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        table1->setText(QString());
        table2->setText(QString());
        table3->setText(QString());
        client->setText(QString());
        serveur->setText(QString());
        chef->setText(QString());
        comptoir->setText(QString());
        frigo->setText(QString());
        Plan_de_travail->setText(QString());
        Four->setText(QString());
        Four2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
