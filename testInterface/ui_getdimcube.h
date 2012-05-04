/********************************************************************************
** Form generated from reading UI file 'getdimcube.ui'
**
** Created: Thu May 3 20:53:44 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETDIMCUBE_H
#define UI_GETDIMCUBE_H

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

class Ui_getDimCube
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QDoubleSpinBox *position_x;
    QDoubleSpinBox *position_y;
    QDoubleSpinBox *position_z;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QDoubleSpinBox *dimension_x;
    QDoubleSpinBox *dimension_y;
    QDoubleSpinBox *dimension_z;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *getDimCube)
    {
        if (getDimCube->objectName().isEmpty())
            getDimCube->setObjectName(QString::fromUtf8("getDimCube"));
        getDimCube->resize(266, 171);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(getDimCube->sizePolicy().hasHeightForWidth());
        getDimCube->setSizePolicy(sizePolicy);
        getDimCube->setMaximumSize(QSize(266, 171));
        gridLayout = new QGridLayout(getDimCube);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_3 = new QGroupBox(getDimCube);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(108, 108));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 1, 0, 1, 1);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 2, 0, 1, 1);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_3->addWidget(label_9, 3, 0, 1, 1);

        position_x = new QDoubleSpinBox(groupBox_3);
        position_x->setObjectName(QString::fromUtf8("position_x"));
        position_x->setDecimals(1);
        position_x->setMinimum(-70);
        position_x->setMaximum(70);
        position_x->setSingleStep(1);

        gridLayout_3->addWidget(position_x, 1, 1, 1, 1);

        position_y = new QDoubleSpinBox(groupBox_3);
        position_y->setObjectName(QString::fromUtf8("position_y"));
        position_y->setDecimals(1);
        position_y->setMinimum(-70);
        position_y->setMaximum(70);

        gridLayout_3->addWidget(position_y, 2, 1, 1, 1);

        position_z = new QDoubleSpinBox(groupBox_3);
        position_z->setObjectName(QString::fromUtf8("position_z"));
        position_z->setDecimals(1);
        position_z->setMinimum(-70);
        position_z->setMaximum(70);

        gridLayout_3->addWidget(position_z, 3, 1, 1, 1);


        gridLayout->addWidget(groupBox_3, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(getDimCube);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(108, 108));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 2, 0, 1, 1);

        dimension_x = new QDoubleSpinBox(groupBox_2);
        dimension_x->setObjectName(QString::fromUtf8("dimension_x"));
        dimension_x->setDecimals(1);
        dimension_x->setMaximum(40);
        dimension_x->setValue(10);

        gridLayout_2->addWidget(dimension_x, 0, 1, 1, 1);

        dimension_y = new QDoubleSpinBox(groupBox_2);
        dimension_y->setObjectName(QString::fromUtf8("dimension_y"));
        dimension_y->setDecimals(1);
        dimension_y->setMaximum(40);
        dimension_y->setValue(10);

        gridLayout_2->addWidget(dimension_y, 1, 1, 1, 1);

        dimension_z = new QDoubleSpinBox(groupBox_2);
        dimension_z->setObjectName(QString::fromUtf8("dimension_z"));
        dimension_z->setDecimals(1);
        dimension_z->setMaximum(40);
        dimension_z->setValue(10);

        gridLayout_2->addWidget(dimension_z, 2, 1, 1, 1);


        gridLayout->addWidget(groupBox_2, 0, 1, 1, 1);

        buttonBox = new QDialogButtonBox(getDimCube);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 2);


        retranslateUi(getDimCube);

        QMetaObject::connectSlotsByName(getDimCube);
    } // setupUi

    void retranslateUi(QDialog *getDimCube)
    {
        getDimCube->setWindowTitle(QApplication::translate("getDimCube", "New Cube", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("getDimCube", "Position", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("getDimCube", "x :", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("getDimCube", "y :", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("getDimCube", "z :", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("getDimCube", "Dimension", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("getDimCube", "Lx :", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("getDimCube", "Ly :", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("getDimCube", "Lz :", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class getDimCube: public Ui_getDimCube {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETDIMCUBE_H
