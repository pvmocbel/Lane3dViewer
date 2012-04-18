/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Apr 18 14:27:34 2012
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *start;
    QPushButton *cubo;
    QPushButton *esfera;
    QPushButton *cone;
    QPushButton *cilindro;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(514, 326);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        start = new QPushButton(centralWidget);
        start->setObjectName(QString::fromUtf8("start"));

        gridLayout->addWidget(start, 0, 0, 1, 1);

        cubo = new QPushButton(centralWidget);
        cubo->setObjectName(QString::fromUtf8("cubo"));

        gridLayout->addWidget(cubo, 0, 1, 1, 1);

        esfera = new QPushButton(centralWidget);
        esfera->setObjectName(QString::fromUtf8("esfera"));

        gridLayout->addWidget(esfera, 0, 2, 1, 1);

        cone = new QPushButton(centralWidget);
        cone->setObjectName(QString::fromUtf8("cone"));

        gridLayout->addWidget(cone, 0, 3, 1, 1);

        cilindro = new QPushButton(centralWidget);
        cilindro->setObjectName(QString::fromUtf8("cilindro"));

        gridLayout->addWidget(cilindro, 0, 4, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 514, 24));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        start->setText(QApplication::translate("MainWindow", "start", 0, QApplication::UnicodeUTF8));
        cubo->setText(QApplication::translate("MainWindow", "cubo", 0, QApplication::UnicodeUTF8));
        esfera->setText(QApplication::translate("MainWindow", "esfera", 0, QApplication::UnicodeUTF8));
        cone->setText(QApplication::translate("MainWindow", "cone", 0, QApplication::UnicodeUTF8));
        cilindro->setText(QApplication::translate("MainWindow", "cilindro", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
