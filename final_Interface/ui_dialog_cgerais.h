/********************************************************************************
** Form generated from reading UI file 'dialog_cgerais.ui'
**
** Created: Fri Jun 1 11:37:00 2012
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_CGERAIS_H
#define UI_DIALOG_CGERAIS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_CGerais
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QDoubleSpinBox *dim_regiao_livre_x;
    QFrame *line;
    QLabel *label_2;
    QDoubleSpinBox *dim_regiao_livre_y;
    QFrame *line_2;
    QLabel *label_3;
    QDoubleSpinBox *dim_regiao_livre_z;
    QFrame *line_7;
    QLabel *label_9;
    QDoubleSpinBox *delta_regiao_livre;
    QWidget *widget;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *Dialog_CGerais)
    {
        if (Dialog_CGerais->objectName().isEmpty())
            Dialog_CGerais->setObjectName(QString::fromUtf8("Dialog_CGerais"));
        Dialog_CGerais->resize(600, 194);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog_CGerais->sizePolicy().hasHeightForWidth());
        Dialog_CGerais->setSizePolicy(sizePolicy);
        Dialog_CGerais->setMaximumSize(QSize(600, 270));
        gridLayout_2 = new QGridLayout(Dialog_CGerais);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(Dialog_CGerais);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 120));
        groupBox->setMaximumSize(QSize(582, 120));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        dim_regiao_livre_x = new QDoubleSpinBox(groupBox);
        dim_regiao_livre_x->setObjectName(QString::fromUtf8("dim_regiao_livre_x"));
        dim_regiao_livre_x->setMinimumSize(QSize(40, 0));
        dim_regiao_livre_x->setDecimals(4);
        dim_regiao_livre_x->setMaximum(1000);
        dim_regiao_livre_x->setValue(0.15);

        gridLayout->addWidget(dim_regiao_livre_x, 0, 1, 1, 1);

        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 2, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        dim_regiao_livre_y = new QDoubleSpinBox(groupBox);
        dim_regiao_livre_y->setObjectName(QString::fromUtf8("dim_regiao_livre_y"));
        dim_regiao_livre_y->setMinimumSize(QSize(40, 0));
        dim_regiao_livre_y->setDecimals(4);
        dim_regiao_livre_y->setMaximum(1000);
        dim_regiao_livre_y->setValue(0.075);

        gridLayout->addWidget(dim_regiao_livre_y, 0, 4, 1, 1);

        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 0, 5, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 0, 6, 1, 1);

        dim_regiao_livre_z = new QDoubleSpinBox(groupBox);
        dim_regiao_livre_z->setObjectName(QString::fromUtf8("dim_regiao_livre_z"));
        dim_regiao_livre_z->setMinimumSize(QSize(40, 0));
        dim_regiao_livre_z->setDecimals(4);
        dim_regiao_livre_z->setMaximum(1000);
        dim_regiao_livre_z->setValue(0.15);

        gridLayout->addWidget(dim_regiao_livre_z, 0, 7, 1, 1);

        line_7 = new QFrame(groupBox);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShadow(QFrame::Sunken);
        line_7->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(line_7, 1, 0, 1, 8);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_9, 2, 0, 1, 1);

        delta_regiao_livre = new QDoubleSpinBox(groupBox);
        delta_regiao_livre->setObjectName(QString::fromUtf8("delta_regiao_livre"));
        delta_regiao_livre->setDecimals(4);
        delta_regiao_livre->setValue(0.001);

        gridLayout->addWidget(delta_regiao_livre, 2, 1, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        widget = new QWidget(Dialog_CGerais);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 45));
        widget->setMaximumSize(QSize(582, 45));
        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(420, 0, 160, 26));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(widget, 1, 0, 1, 1);


        retranslateUi(Dialog_CGerais);
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog_CGerais, SLOT(slotRejected()));
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog_CGerais, SLOT(slotAccepted()));
        QObject::connect(dim_regiao_livre_x, SIGNAL(valueChanged(QString)), Dialog_CGerais, SLOT(slotSetValoresAmbiente()));
        QObject::connect(dim_regiao_livre_y, SIGNAL(valueChanged(QString)), Dialog_CGerais, SLOT(slotSetValoresAmbiente()));
        QObject::connect(dim_regiao_livre_z, SIGNAL(valueChanged(QString)), Dialog_CGerais, SLOT(slotSetValoresAmbiente()));
        QObject::connect(delta_regiao_livre, SIGNAL(valueChanged(QString)), Dialog_CGerais, SLOT(slotSetValoresAmbiente()));

        QMetaObject::connectSlotsByName(Dialog_CGerais);
    } // setupUi

    void retranslateUi(QWidget *Dialog_CGerais)
    {
        Dialog_CGerais->setWindowTitle(QApplication::translate("Dialog_CGerais", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Dialog_CGerais", "Regi\303\243o de An\303\241lise", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog_CGerais", "Dimen\303\247\303\243o X:", 0, QApplication::UnicodeUTF8));
        dim_regiao_livre_x->setPrefix(QString());
        dim_regiao_livre_x->setSuffix(QApplication::translate("Dialog_CGerais", " m", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog_CGerais", "Dimen\303\247\303\243o Y:", 0, QApplication::UnicodeUTF8));
        dim_regiao_livre_y->setSuffix(QApplication::translate("Dialog_CGerais", " m", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Dialog_CGerais", "Dimen\303\247\303\243o Z:", 0, QApplication::UnicodeUTF8));
        dim_regiao_livre_z->setSuffix(QApplication::translate("Dialog_CGerais", " m", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Dialog_CGerais", "delt:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog_CGerais: public Ui_Dialog_CGerais {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_CGERAIS_H
