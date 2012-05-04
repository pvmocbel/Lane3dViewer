/********************************************************************************
** Form generated from reading UI file 'getdimcone.ui'
**
** Created: Thu May 3 20:53:44 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETDIMCONE_H
#define UI_GETDIMCONE_H

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

class Ui_getDimCone
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QDoubleSpinBox *position_x;
    QLabel *label_2;
    QDoubleSpinBox *position_y;
    QLabel *label_3;
    QDoubleSpinBox *position_z;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QDoubleSpinBox *altura;
    QLabel *label_5;
    QDoubleSpinBox *raio;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *getDimCone)
    {
        if (getDimCone->objectName().isEmpty())
            getDimCone->setObjectName(QString::fromUtf8("getDimCone"));
        getDimCone->resize(382, 211);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(getDimCone->sizePolicy().hasHeightForWidth());
        getDimCone->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(getDimCone);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox = new QGroupBox(getDimCone);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(121, 151));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        position_x = new QDoubleSpinBox(groupBox);
        position_x->setObjectName(QString::fromUtf8("position_x"));
        position_x->setMaximumSize(QSize(62, 22));
        position_x->setDecimals(1);
        position_x->setMinimum(-100);
        position_x->setMaximum(100);
        position_x->setSingleStep(1);

        gridLayout_2->addWidget(position_x, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        position_y = new QDoubleSpinBox(groupBox);
        position_y->setObjectName(QString::fromUtf8("position_y"));
        position_y->setMaximumSize(QSize(62, 22));
        position_y->setDecimals(1);
        position_y->setMinimum(-100);
        position_y->setMaximum(100);
        position_y->setSingleStep(1);

        gridLayout_2->addWidget(position_y, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        position_z = new QDoubleSpinBox(groupBox);
        position_z->setObjectName(QString::fromUtf8("position_z"));
        position_z->setMaximumSize(QSize(62, 22));
        position_z->setDecimals(1);
        position_z->setMinimum(-100);
        position_z->setMaximum(100);
        position_z->setSingleStep(1);

        gridLayout_2->addWidget(position_z, 2, 1, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(getDimCone);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(121, 151));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 2);

        altura = new QDoubleSpinBox(groupBox_2);
        altura->setObjectName(QString::fromUtf8("altura"));
        altura->setMaximumSize(QSize(62, 22));
        altura->setDecimals(2);
        altura->setMinimum(-100);
        altura->setMaximum(100);
        altura->setSingleStep(1);
        altura->setValue(20);

        gridLayout->addWidget(altura, 0, 2, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        raio = new QDoubleSpinBox(groupBox_2);
        raio->setObjectName(QString::fromUtf8("raio"));
        raio->setMaximumSize(QSize(62, 22));
        raio->setDecimals(1);
        raio->setMinimum(-100);
        raio->setMaximum(100);
        raio->setSingleStep(1);
        raio->setValue(10);

        gridLayout->addWidget(raio, 1, 1, 1, 2);


        gridLayout_3->addWidget(groupBox_2, 0, 1, 1, 1);

        buttonBox = new QDialogButtonBox(getDimCone);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_3->addWidget(buttonBox, 1, 0, 1, 2);


        retranslateUi(getDimCone);
        QObject::connect(buttonBox, SIGNAL(accepted()), getDimCone, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), getDimCone, SLOT(reject()));

        QMetaObject::connectSlotsByName(getDimCone);
    } // setupUi

    void retranslateUi(QDialog *getDimCone)
    {
        getDimCone->setWindowTitle(QApplication::translate("getDimCone", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("getDimCone", "Position", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("getDimCone", "x : ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("getDimCone", "y : ", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("getDimCone", "z :", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("getDimCone", "Dimension", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("getDimCone", "altura : ", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("getDimCone", "raio : ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class getDimCone: public Ui_getDimCone {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETDIMCONE_H
