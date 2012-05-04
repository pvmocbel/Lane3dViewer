/********************************************************************************
** Form generated from reading UI file 'getdimcilindro.ui'
**
** Created: Thu May 3 20:53:44 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETDIMCILINDRO_H
#define UI_GETDIMCILINDRO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_getDimCilindro
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QDoubleSpinBox *position_x;
    QLabel *label_2;
    QDoubleSpinBox *position_y;
    QLabel *label_3;
    QDoubleSpinBox *position_z;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QDoubleSpinBox *raio;
    QLabel *label_5;
    QDoubleSpinBox *comprimento;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *getDimCilindro)
    {
        if (getDimCilindro->objectName().isEmpty())
            getDimCilindro->setObjectName(QString::fromUtf8("getDimCilindro"));
        getDimCilindro->resize(344, 195);
        getDimCilindro->setMaximumSize(QSize(344, 195));
        gridLayout_3 = new QGridLayout(getDimCilindro);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox = new QGroupBox(getDimCilindro);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(103, 107));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        position_x = new QDoubleSpinBox(groupBox);
        position_x->setObjectName(QString::fromUtf8("position_x"));
        position_x->setMaximumSize(QSize(62, 22));
        position_x->setMinimum(-100);
        position_x->setMaximum(100);

        gridLayout->addWidget(position_x, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        position_y = new QDoubleSpinBox(groupBox);
        position_y->setObjectName(QString::fromUtf8("position_y"));
        position_y->setMaximumSize(QSize(62, 22));
        position_y->setMinimum(-100);
        position_y->setMaximum(100);

        gridLayout->addWidget(position_y, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        position_z = new QDoubleSpinBox(groupBox);
        position_z->setObjectName(QString::fromUtf8("position_z"));
        position_z->setMaximumSize(QSize(62, 22));
        position_z->setMinimum(-100);
        position_z->setMaximum(100);

        gridLayout->addWidget(position_z, 2, 1, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(getDimCilindro);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(139, 81));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        raio = new QDoubleSpinBox(groupBox_2);
        raio->setObjectName(QString::fromUtf8("raio"));
        raio->setMaximumSize(QSize(62, 22));
        raio->setMinimum(-100);
        raio->setMaximum(100);
        raio->setValue(10);

        gridLayout_2->addWidget(raio, 0, 1, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        comprimento = new QDoubleSpinBox(groupBox_2);
        comprimento->setObjectName(QString::fromUtf8("comprimento"));
        comprimento->setMaximumSize(QSize(62, 22));
        comprimento->setMinimum(-100);
        comprimento->setMaximum(100);
        comprimento->setValue(20);

        gridLayout_2->addWidget(comprimento, 1, 1, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 0, 1, 1, 1);

        buttonBox = new QDialogButtonBox(getDimCilindro);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_3->addWidget(buttonBox, 1, 0, 1, 2);


        retranslateUi(getDimCilindro);
        QObject::connect(buttonBox, SIGNAL(accepted()), getDimCilindro, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), getDimCilindro, SLOT(reject()));

        QMetaObject::connectSlotsByName(getDimCilindro);
    } // setupUi

    void retranslateUi(QDialog *getDimCilindro)
    {
        getDimCilindro->setWindowTitle(QApplication::translate("getDimCilindro", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("getDimCilindro", "Position", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("getDimCilindro", "x :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("getDimCilindro", "y :", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("getDimCilindro", "z :", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("getDimCilindro", "Position", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("getDimCilindro", "raio :", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("getDimCilindro", "comp :", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class getDimCilindro: public Ui_getDimCilindro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETDIMCILINDRO_H
