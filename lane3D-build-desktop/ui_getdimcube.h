/********************************************************************************
** Form generated from reading UI file 'getdimcube.ui'
**
** Created: Mon Apr 9 15:19:46 2012
**      by: Qt User Interface Compiler version 4.7.0
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
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_getDimCube
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QLabel *label_7;
    QLineEdit *text_x_position;
    QLabel *label_8;
    QLineEdit *text_y_position;
    QLabel *label_9;
    QLineEdit *text_z_position;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QLineEdit *text_x_dimension;
    QLabel *label_5;
    QLineEdit *text_y_dimension;
    QLabel *label_6;
    QLineEdit *text_z_dimension;
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

        gridLayout_3->addWidget(label_7, 0, 0, 1, 1);

        text_x_position = new QLineEdit(groupBox_3);
        text_x_position->setObjectName(QString::fromUtf8("text_x_position"));
        sizePolicy.setHeightForWidth(text_x_position->sizePolicy().hasHeightForWidth());
        text_x_position->setSizePolicy(sizePolicy);
        text_x_position->setMaximumSize(QSize(61, 20));

        gridLayout_3->addWidget(text_x_position, 0, 1, 1, 1);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 1, 0, 1, 1);

        text_y_position = new QLineEdit(groupBox_3);
        text_y_position->setObjectName(QString::fromUtf8("text_y_position"));
        sizePolicy.setHeightForWidth(text_y_position->sizePolicy().hasHeightForWidth());
        text_y_position->setSizePolicy(sizePolicy);
        text_y_position->setMaximumSize(QSize(61, 20));

        gridLayout_3->addWidget(text_y_position, 1, 1, 1, 1);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_3->addWidget(label_9, 2, 0, 1, 1);

        text_z_position = new QLineEdit(groupBox_3);
        text_z_position->setObjectName(QString::fromUtf8("text_z_position"));
        sizePolicy.setHeightForWidth(text_z_position->sizePolicy().hasHeightForWidth());
        text_z_position->setSizePolicy(sizePolicy);
        text_z_position->setMaximumSize(QSize(61, 20));

        gridLayout_3->addWidget(text_z_position, 2, 1, 1, 1);


        gridLayout->addWidget(groupBox_3, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(getDimCube);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(108, 108));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        text_x_dimension = new QLineEdit(groupBox_2);
        text_x_dimension->setObjectName(QString::fromUtf8("text_x_dimension"));
        sizePolicy.setHeightForWidth(text_x_dimension->sizePolicy().hasHeightForWidth());
        text_x_dimension->setSizePolicy(sizePolicy);
        text_x_dimension->setMaximumSize(QSize(61, 20));

        gridLayout_2->addWidget(text_x_dimension, 0, 1, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        text_y_dimension = new QLineEdit(groupBox_2);
        text_y_dimension->setObjectName(QString::fromUtf8("text_y_dimension"));
        sizePolicy.setHeightForWidth(text_y_dimension->sizePolicy().hasHeightForWidth());
        text_y_dimension->setSizePolicy(sizePolicy);
        text_y_dimension->setMaximumSize(QSize(61, 20));

        gridLayout_2->addWidget(text_y_dimension, 1, 1, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 2, 0, 1, 1);

        text_z_dimension = new QLineEdit(groupBox_2);
        text_z_dimension->setObjectName(QString::fromUtf8("text_z_dimension"));
        sizePolicy.setHeightForWidth(text_z_dimension->sizePolicy().hasHeightForWidth());
        text_z_dimension->setSizePolicy(sizePolicy);
        text_z_dimension->setMaximumSize(QSize(61, 20));

        gridLayout_2->addWidget(text_z_dimension, 2, 1, 1, 1);


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
