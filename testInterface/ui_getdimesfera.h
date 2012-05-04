/********************************************************************************
** Form generated from reading UI file 'getdimesfera.ui'
**
** Created: Thu May 3 20:53:44 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETDIMESFERA_H
#define UI_GETDIMESFERA_H

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

class Ui_getDimEsfera
{
public:
    QDialogButtonBox *buttonBox;
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

    void setupUi(QDialog *getDimEsfera)
    {
        if (getDimEsfera->objectName().isEmpty())
            getDimEsfera->setObjectName(QString::fromUtf8("getDimEsfera"));
        getDimEsfera->resize(357, 159);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(getDimEsfera->sizePolicy().hasHeightForWidth());
        getDimEsfera->setSizePolicy(sizePolicy);
        getDimEsfera->setMaximumSize(QSize(357, 159));
        buttonBox = new QDialogButtonBox(getDimEsfera);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 120, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(getDimEsfera);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(19, 10, 103, 107));
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

        groupBox_2 = new QGroupBox(getDimEsfera);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(150, 10, 121, 55));
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


        retranslateUi(getDimEsfera);
        QObject::connect(buttonBox, SIGNAL(accepted()), getDimEsfera, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), getDimEsfera, SLOT(reject()));

        QMetaObject::connectSlotsByName(getDimEsfera);
    } // setupUi

    void retranslateUi(QDialog *getDimEsfera)
    {
        getDimEsfera->setWindowTitle(QApplication::translate("getDimEsfera", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("getDimEsfera", "Position", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("getDimEsfera", "x :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("getDimEsfera", "y :", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("getDimEsfera", "z :", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("getDimEsfera", "Dimesion", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("getDimEsfera", "raio :", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class getDimEsfera: public Ui_getDimEsfera {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETDIMESFERA_H
