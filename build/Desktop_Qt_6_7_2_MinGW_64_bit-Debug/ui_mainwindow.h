/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QLineEdit *ip;
    QLabel *label_3;
    QLineEdit *port;
    QLabel *label;
    QLineEdit *message_input;
    QPushButton *btn_send;
    QLabel *label_2;
    QTextEdit *message_display;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(493, 373);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        ip = new QLineEdit(centralwidget);
        ip->setObjectName("ip");

        verticalLayout->addWidget(ip);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        port = new QLineEdit(centralwidget);
        port->setObjectName("port");

        verticalLayout->addWidget(port);

        label = new QLabel(centralwidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        message_input = new QLineEdit(centralwidget);
        message_input->setObjectName("message_input");

        verticalLayout->addWidget(message_input);

        btn_send = new QPushButton(centralwidget);
        btn_send->setObjectName("btn_send");

        verticalLayout->addWidget(btn_send);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        message_display = new QTextEdit(centralwidget);
        message_display->setObjectName("message_display");

        verticalLayout->addWidget(message_display);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 493, 17));
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
        label_4->setText(QCoreApplication::translate("MainWindow", "Entrer l'adresse IP :", nullptr));
        ip->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Entrer le port de destination :", nullptr));
        port->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Entrer votre message ...", nullptr));
        message_input->setText(QString());
        btn_send->setText(QCoreApplication::translate("MainWindow", "Envoyer", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Message re\303\247u :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
