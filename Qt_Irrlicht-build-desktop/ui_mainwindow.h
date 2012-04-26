/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Apr 25 13:43:17 2012
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
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *start;
    QPushButton *cubo;
    QPushButton *linha;
    QPushButton *esfera;
    QPushButton *cone;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(900, 400);
        MainWindow->setMinimumSize(QSize(800, 400));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        start = new QPushButton(centralWidget);
        start->setObjectName(QString::fromUtf8("start"));
        start->setMaximumSize(QSize(92, 27));

        gridLayout->addWidget(start, 0, 0, 1, 1);

        cubo = new QPushButton(centralWidget);
        cubo->setObjectName(QString::fromUtf8("cubo"));
        cubo->setMaximumSize(QSize(85, 27));

        gridLayout->addWidget(cubo, 1, 0, 1, 1);

        linha = new QPushButton(centralWidget);
        linha->setObjectName(QString::fromUtf8("linha"));
        linha->setMaximumSize(QSize(92, 27));

        gridLayout->addWidget(linha, 2, 0, 1, 1);

        esfera = new QPushButton(centralWidget);
        esfera->setObjectName(QString::fromUtf8("esfera"));
        esfera->setMaximumSize(QSize(92, 27));

        gridLayout->addWidget(esfera, 3, 0, 1, 1);

        cone = new QPushButton(centralWidget);
        cone->setObjectName(QString::fromUtf8("cone"));
        cone->setMaximumSize(QSize(92, 27));

        gridLayout->addWidget(cone, 4, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        start->setText(QApplication::translate("MainWindow", "start", 0, QApplication::UnicodeUTF8));
        cubo->setText(QApplication::translate("MainWindow", "cubo", 0, QApplication::UnicodeUTF8));
        linha->setText(QApplication::translate("MainWindow", "linha", 0, QApplication::UnicodeUTF8));
        esfera->setText(QApplication::translate("MainWindow", "esfera", 0, QApplication::UnicodeUTF8));
        cone->setText(QApplication::translate("MainWindow", "cone", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
