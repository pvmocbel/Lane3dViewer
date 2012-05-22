/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue May 22 17:05:07 2012
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStackedWidget>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionNew;
    QAction *actionSave;
    QAction *actionPosicao;
    QAction *actionRotacao;
    QAction *actionPonto;
    QAction *actionLinha;
    QAction *actionCubo;
    QAction *actionEsfera;
    QAction *actionCilindro;
    QAction *actionCone;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGridLayout *grid_Interface;
    QStackedWidget *stackedWidget_Lateral;
    QWidget *page_Ambiente;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_PainelTitulo_0;
    QScrollArea *scrollArea_0;
    QWidget *scrollAreaWidgetContents_pnLateral_0;
    QVBoxLayout *verticalLayout_12;
    QGroupBox *groupBox_15;
    QFormLayout *formLayout_16;
    QLabel *label_45;
    QDoubleSpinBox *doubleSpinBox_XDim_RLIVRE;
    QLabel *label_58;
    QDoubleSpinBox *doubleSpinBox_YDim_RLIVRE;
    QLabel *label_59;
    QDoubleSpinBox *doubleSpinBox_ZDim_RLIVRE;
    QFrame *line_5;
    QLabel *label_65;
    QDoubleSpinBox *doubleSpinBox_deltaX_RLIVRE;
    QSpacerItem *verticalSpacer_5;
    QWidget *page_Objetos;
    QVBoxLayout *verticalLayout_4;
    QScrollArea *scrollArea_1;
    QWidget *scrollAreaWidgetContents_pnLateral_1;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_Identificao;
    QFormLayout *formLayout_10;
    QLabel *label_40;
    QLineEdit *lineEdit_Name;
    QLabel *label_41;
    QSpinBox *spinBox_4;
    QStackedWidget *stackedWidget_pnLateralObj;
    QWidget *page_Ponto;
    QVBoxLayout *verticalLayout_11;
    QWidget *page_Linha;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label_14;
    QDoubleSpinBox *raio_haste;
    QFrame *line_2;
    QLabel *label_6;
    QLabel *label_7;
    QDoubleSpinBox *haste_inicial_x;
    QLabel *label_8;
    QDoubleSpinBox *haste_inicial_y;
    QLabel *label_9;
    QDoubleSpinBox *haste_inicial_z;
    QFrame *line_6;
    QLabel *label_13;
    QLabel *label_11;
    QDoubleSpinBox *haste_final_x;
    QLabel *label_12;
    QDoubleSpinBox *haste_final_y;
    QLabel *label_10;
    QDoubleSpinBox *haste_final_z;
    QWidget *page_Cubo;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_13;
    QGridLayout *gridLayout_4;
    QLabel *label_36;
    QDoubleSpinBox *cube_dim_X;
    QLabel *label_37;
    QDoubleSpinBox *cube_dim_Y;
    QLabel *label_38;
    QDoubleSpinBox *cube_dim_Z;
    QSpacerItem *verticalSpacer;
    QWidget *page_Esfera;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_14;
    QFormLayout *formLayout_15;
    QLabel *label_39;
    QDoubleSpinBox *raio_esfera;
    QSpacerItem *verticalSpacer_2;
    QWidget *page_Cilindro;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox_20;
    QFormLayout *formLayout_19;
    QLabel *label_51;
    QDoubleSpinBox *raio_cilindro;
    QLabel *label_57;
    QDoubleSpinBox *comprimento_cilindro;
    QSpacerItem *verticalSpacer_3;
    QWidget *page_Cone;
    QGroupBox *groupBox_21;
    QGridLayout *gridLayout_5;
    QLabel *label_52;
    QLabel *label_60;
    QDoubleSpinBox *comprimento_cone;
    QDoubleSpinBox *raio_cone;
    QGroupBox *groupBox_Material;
    QFormLayout *formLayout;
    QLabel *label_48;
    QLabel *label_49;
    QDoubleSpinBox *permeabilidade;
    QLabel *label_50;
    QDoubleSpinBox *condutibilidade;
    QLabel *label_5;
    QComboBox *comboBox_Prop;
    QDoubleSpinBox *permissividade;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_PainelTitulo_1;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QToolButton *PositionButton;
    QToolButton *RotationButton;
    QFrame *line;
    QLabel *label;
    QDoubleSpinBox *position_X;
    QLabel *label_2;
    QDoubleSpinBox *position_Y;
    QLabel *label_3;
    QDoubleSpinBox *position_Z;
    QFrame *line_4;
    QPushButton *GerarMalha;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_1;
    QHBoxLayout *horizontalLayout_2;
    QFrame *line_3;
    QLabel *label_4;
    QMenuBar *menuBar;
    QToolBar *ToolBar_File;
    QToolBar *toolBar_Manipulador;
    QStatusBar *statusBar;
    QToolBar *toolBar_GeometBasicas;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(900, 600);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionPosicao = new QAction(MainWindow);
        actionPosicao->setObjectName(QString::fromUtf8("actionPosicao"));
        actionRotacao = new QAction(MainWindow);
        actionRotacao->setObjectName(QString::fromUtf8("actionRotacao"));
        actionPonto = new QAction(MainWindow);
        actionPonto->setObjectName(QString::fromUtf8("actionPonto"));
        actionLinha = new QAction(MainWindow);
        actionLinha->setObjectName(QString::fromUtf8("actionLinha"));
        actionCubo = new QAction(MainWindow);
        actionCubo->setObjectName(QString::fromUtf8("actionCubo"));
        actionEsfera = new QAction(MainWindow);
        actionEsfera->setObjectName(QString::fromUtf8("actionEsfera"));
        actionCilindro = new QAction(MainWindow);
        actionCilindro->setObjectName(QString::fromUtf8("actionCilindro"));
        actionCone = new QAction(MainWindow);
        actionCone->setObjectName(QString::fromUtf8("actionCone"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        grid_Interface = new QGridLayout();
        grid_Interface->setSpacing(6);
        grid_Interface->setObjectName(QString::fromUtf8("grid_Interface"));
        stackedWidget_Lateral = new QStackedWidget(centralWidget);
        stackedWidget_Lateral->setObjectName(QString::fromUtf8("stackedWidget_Lateral"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stackedWidget_Lateral->sizePolicy().hasHeightForWidth());
        stackedWidget_Lateral->setSizePolicy(sizePolicy);
        stackedWidget_Lateral->setMinimumSize(QSize(180, 0));
        stackedWidget_Lateral->setMaximumSize(QSize(180, 451));
        stackedWidget_Lateral->setFrameShape(QFrame::Box);
        stackedWidget_Lateral->setFrameShadow(QFrame::Raised);
        stackedWidget_Lateral->setLineWidth(1);
        stackedWidget_Lateral->setMidLineWidth(0);
        page_Ambiente = new QWidget();
        page_Ambiente->setObjectName(QString::fromUtf8("page_Ambiente"));
        verticalLayout_2 = new QVBoxLayout(page_Ambiente);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(5, -1, 0, -1);
        label_PainelTitulo_0 = new QLabel(page_Ambiente);
        label_PainelTitulo_0->setObjectName(QString::fromUtf8("label_PainelTitulo_0"));
        sizePolicy.setHeightForWidth(label_PainelTitulo_0->sizePolicy().hasHeightForWidth());
        label_PainelTitulo_0->setSizePolicy(sizePolicy);
        label_PainelTitulo_0->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_PainelTitulo_0);

        scrollArea_0 = new QScrollArea(page_Ambiente);
        scrollArea_0->setObjectName(QString::fromUtf8("scrollArea_0"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollArea_0->sizePolicy().hasHeightForWidth());
        scrollArea_0->setSizePolicy(sizePolicy1);
        scrollArea_0->setMinimumSize(QSize(160, 0));
        scrollArea_0->setMaximumSize(QSize(160, 16777215));
        scrollArea_0->setFrameShape(QFrame::NoFrame);
        scrollArea_0->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea_0->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea_0->setWidgetResizable(true);
        scrollAreaWidgetContents_pnLateral_0 = new QWidget();
        scrollAreaWidgetContents_pnLateral_0->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_pnLateral_0"));
        scrollAreaWidgetContents_pnLateral_0->setGeometry(QRect(0, 0, 140, 195));
        verticalLayout_12 = new QVBoxLayout(scrollAreaWidgetContents_pnLateral_0);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(0, 9, 0, -1);
        groupBox_15 = new QGroupBox(scrollAreaWidgetContents_pnLateral_0);
        groupBox_15->setObjectName(QString::fromUtf8("groupBox_15"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_15->sizePolicy().hasHeightForWidth());
        groupBox_15->setSizePolicy(sizePolicy2);
        groupBox_15->setMinimumSize(QSize(140, 0));
        groupBox_15->setMaximumSize(QSize(140, 16777215));
        formLayout_16 = new QFormLayout(groupBox_15);
        formLayout_16->setSpacing(6);
        formLayout_16->setContentsMargins(11, 11, 11, 11);
        formLayout_16->setObjectName(QString::fromUtf8("formLayout_16"));
        formLayout_16->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_45 = new QLabel(groupBox_15);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setMinimumSize(QSize(40, 0));
        label_45->setTextFormat(Qt::AutoText);
        label_45->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_45->setIndent(-1);

        formLayout_16->setWidget(0, QFormLayout::LabelRole, label_45);

        doubleSpinBox_XDim_RLIVRE = new QDoubleSpinBox(groupBox_15);
        doubleSpinBox_XDim_RLIVRE->setObjectName(QString::fromUtf8("doubleSpinBox_XDim_RLIVRE"));
        doubleSpinBox_XDim_RLIVRE->setMinimumSize(QSize(60, 0));
        doubleSpinBox_XDim_RLIVRE->setDecimals(2);
        doubleSpinBox_XDim_RLIVRE->setMaximum(1000);

        formLayout_16->setWidget(0, QFormLayout::FieldRole, doubleSpinBox_XDim_RLIVRE);

        label_58 = new QLabel(groupBox_15);
        label_58->setObjectName(QString::fromUtf8("label_58"));
        label_58->setMinimumSize(QSize(40, 0));
        label_58->setTextFormat(Qt::AutoText);
        label_58->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_58->setIndent(-1);

        formLayout_16->setWidget(1, QFormLayout::LabelRole, label_58);

        doubleSpinBox_YDim_RLIVRE = new QDoubleSpinBox(groupBox_15);
        doubleSpinBox_YDim_RLIVRE->setObjectName(QString::fromUtf8("doubleSpinBox_YDim_RLIVRE"));
        doubleSpinBox_YDim_RLIVRE->setDecimals(2);
        doubleSpinBox_YDim_RLIVRE->setMaximum(1000);

        formLayout_16->setWidget(1, QFormLayout::FieldRole, doubleSpinBox_YDim_RLIVRE);

        label_59 = new QLabel(groupBox_15);
        label_59->setObjectName(QString::fromUtf8("label_59"));
        label_59->setMinimumSize(QSize(40, 0));
        label_59->setTextFormat(Qt::AutoText);
        label_59->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_59->setIndent(-1);

        formLayout_16->setWidget(2, QFormLayout::LabelRole, label_59);

        doubleSpinBox_ZDim_RLIVRE = new QDoubleSpinBox(groupBox_15);
        doubleSpinBox_ZDim_RLIVRE->setObjectName(QString::fromUtf8("doubleSpinBox_ZDim_RLIVRE"));
        doubleSpinBox_ZDim_RLIVRE->setDecimals(2);
        doubleSpinBox_ZDim_RLIVRE->setMaximum(1000);

        formLayout_16->setWidget(2, QFormLayout::FieldRole, doubleSpinBox_ZDim_RLIVRE);

        line_5 = new QFrame(groupBox_15);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        formLayout_16->setWidget(3, QFormLayout::SpanningRole, line_5);

        label_65 = new QLabel(groupBox_15);
        label_65->setObjectName(QString::fromUtf8("label_65"));
        label_65->setMinimumSize(QSize(40, 0));
        label_65->setTextFormat(Qt::AutoText);
        label_65->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_65->setIndent(-1);

        formLayout_16->setWidget(4, QFormLayout::LabelRole, label_65);

        doubleSpinBox_deltaX_RLIVRE = new QDoubleSpinBox(groupBox_15);
        doubleSpinBox_deltaX_RLIVRE->setObjectName(QString::fromUtf8("doubleSpinBox_deltaX_RLIVRE"));
        doubleSpinBox_deltaX_RLIVRE->setDecimals(4);

        formLayout_16->setWidget(4, QFormLayout::FieldRole, doubleSpinBox_deltaX_RLIVRE);


        verticalLayout_12->addWidget(groupBox_15);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_12->addItem(verticalSpacer_5);

        scrollArea_0->setWidget(scrollAreaWidgetContents_pnLateral_0);

        verticalLayout_2->addWidget(scrollArea_0);

        stackedWidget_Lateral->addWidget(page_Ambiente);
        scrollArea_0->raise();
        label_PainelTitulo_0->raise();
        page_Objetos = new QWidget();
        page_Objetos->setObjectName(QString::fromUtf8("page_Objetos"));
        verticalLayout_4 = new QVBoxLayout(page_Objetos);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(5, -1, 0, -1);
        scrollArea_1 = new QScrollArea(page_Objetos);
        scrollArea_1->setObjectName(QString::fromUtf8("scrollArea_1"));
        sizePolicy1.setHeightForWidth(scrollArea_1->sizePolicy().hasHeightForWidth());
        scrollArea_1->setSizePolicy(sizePolicy1);
        scrollArea_1->setMinimumSize(QSize(160, 0));
        scrollArea_1->setMaximumSize(QSize(160, 16777215));
        scrollArea_1->setFrameShape(QFrame::NoFrame);
        scrollArea_1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea_1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea_1->setWidgetResizable(true);
        scrollAreaWidgetContents_pnLateral_1 = new QWidget();
        scrollAreaWidgetContents_pnLateral_1->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_pnLateral_1"));
        scrollAreaWidgetContents_pnLateral_1->setGeometry(QRect(0, 0, 150, 619));
        gridLayout_3 = new QGridLayout(scrollAreaWidgetContents_pnLateral_1);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 9, 0, -1);
        groupBox_Identificao = new QGroupBox(scrollAreaWidgetContents_pnLateral_1);
        groupBox_Identificao->setObjectName(QString::fromUtf8("groupBox_Identificao"));
        sizePolicy2.setHeightForWidth(groupBox_Identificao->sizePolicy().hasHeightForWidth());
        groupBox_Identificao->setSizePolicy(sizePolicy2);
        groupBox_Identificao->setMinimumSize(QSize(140, 0));
        groupBox_Identificao->setMaximumSize(QSize(140, 16777215));
        formLayout_10 = new QFormLayout(groupBox_Identificao);
        formLayout_10->setSpacing(6);
        formLayout_10->setContentsMargins(11, 11, 11, 11);
        formLayout_10->setObjectName(QString::fromUtf8("formLayout_10"));
        label_40 = new QLabel(groupBox_Identificao);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setMinimumSize(QSize(39, 0));
        label_40->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_10->setWidget(0, QFormLayout::LabelRole, label_40);

        lineEdit_Name = new QLineEdit(groupBox_Identificao);
        lineEdit_Name->setObjectName(QString::fromUtf8("lineEdit_Name"));
        sizePolicy2.setHeightForWidth(lineEdit_Name->sizePolicy().hasHeightForWidth());
        lineEdit_Name->setSizePolicy(sizePolicy2);
        lineEdit_Name->setMinimumSize(QSize(60, 0));

        formLayout_10->setWidget(0, QFormLayout::FieldRole, lineEdit_Name);

        label_41 = new QLabel(groupBox_Identificao);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setMinimumSize(QSize(39, 0));
        label_41->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_10->setWidget(1, QFormLayout::LabelRole, label_41);

        spinBox_4 = new QSpinBox(groupBox_Identificao);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        sizePolicy2.setHeightForWidth(spinBox_4->sizePolicy().hasHeightForWidth());
        spinBox_4->setSizePolicy(sizePolicy2);
        spinBox_4->setMinimumSize(QSize(73, 0));

        formLayout_10->setWidget(1, QFormLayout::FieldRole, spinBox_4);


        gridLayout_3->addWidget(groupBox_Identificao, 1, 0, 1, 1);

        stackedWidget_pnLateralObj = new QStackedWidget(scrollAreaWidgetContents_pnLateral_1);
        stackedWidget_pnLateralObj->setObjectName(QString::fromUtf8("stackedWidget_pnLateralObj"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(15);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(stackedWidget_pnLateralObj->sizePolicy().hasHeightForWidth());
        stackedWidget_pnLateralObj->setSizePolicy(sizePolicy3);
        stackedWidget_pnLateralObj->setMinimumSize(QSize(150, 0));
        stackedWidget_pnLateralObj->setMaximumSize(QSize(170, 16777215));
        page_Ponto = new QWidget();
        page_Ponto->setObjectName(QString::fromUtf8("page_Ponto"));
        verticalLayout_11 = new QVBoxLayout(page_Ponto);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        stackedWidget_pnLateralObj->addWidget(page_Ponto);
        page_Linha = new QWidget();
        page_Linha->setObjectName(QString::fromUtf8("page_Linha"));
        verticalLayout_3 = new QVBoxLayout(page_Linha);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox = new QGroupBox(page_Linha);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy4);
        groupBox->setMinimumSize(QSize(100, 100));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_2->addWidget(label_14, 0, 1, 1, 2);

        raio_haste = new QDoubleSpinBox(groupBox);
        raio_haste->setObjectName(QString::fromUtf8("raio_haste"));
        raio_haste->setMinimum(-100);
        raio_haste->setSingleStep(0.01);

        gridLayout_2->addWidget(raio_haste, 0, 3, 1, 1);

        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_2, 1, 0, 1, 4);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 2, 0, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 2, 2, 1, 1);

        haste_inicial_x = new QDoubleSpinBox(groupBox);
        haste_inicial_x->setObjectName(QString::fromUtf8("haste_inicial_x"));
        haste_inicial_x->setDecimals(3);
        haste_inicial_x->setMinimum(-100);
        haste_inicial_x->setSingleStep(0.01);

        gridLayout_2->addWidget(haste_inicial_x, 2, 3, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 3, 2, 1, 1);

        haste_inicial_y = new QDoubleSpinBox(groupBox);
        haste_inicial_y->setObjectName(QString::fromUtf8("haste_inicial_y"));
        haste_inicial_y->setDecimals(3);
        haste_inicial_y->setMinimum(-100);
        haste_inicial_y->setSingleStep(0.01);

        gridLayout_2->addWidget(haste_inicial_y, 3, 3, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_2->addWidget(label_9, 4, 2, 1, 1);

        haste_inicial_z = new QDoubleSpinBox(groupBox);
        haste_inicial_z->setObjectName(QString::fromUtf8("haste_inicial_z"));
        haste_inicial_z->setDecimals(3);
        haste_inicial_z->setMinimum(-100);
        haste_inicial_z->setSingleStep(0.01);

        gridLayout_2->addWidget(haste_inicial_z, 4, 3, 1, 1);

        line_6 = new QFrame(groupBox);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_6, 5, 0, 1, 4);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_2->addWidget(label_13, 6, 0, 1, 1);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_2->addWidget(label_11, 6, 2, 1, 1);

        haste_final_x = new QDoubleSpinBox(groupBox);
        haste_final_x->setObjectName(QString::fromUtf8("haste_final_x"));
        haste_final_x->setDecimals(3);
        haste_final_x->setMinimum(-100);
        haste_final_x->setSingleStep(0.01);
        haste_final_x->setValue(1);

        gridLayout_2->addWidget(haste_final_x, 6, 3, 1, 1);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_2->addWidget(label_12, 7, 2, 1, 1);

        haste_final_y = new QDoubleSpinBox(groupBox);
        haste_final_y->setObjectName(QString::fromUtf8("haste_final_y"));
        haste_final_y->setDecimals(3);
        haste_final_y->setMinimum(-100);
        haste_final_y->setSingleStep(0.01);
        haste_final_y->setValue(0);

        gridLayout_2->addWidget(haste_final_y, 7, 3, 1, 1);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_2->addWidget(label_10, 8, 2, 1, 1);

        haste_final_z = new QDoubleSpinBox(groupBox);
        haste_final_z->setObjectName(QString::fromUtf8("haste_final_z"));
        haste_final_z->setMinimum(-100);
        haste_final_z->setSingleStep(0.01);

        gridLayout_2->addWidget(haste_final_z, 8, 3, 1, 1);


        verticalLayout_3->addWidget(groupBox);

        stackedWidget_pnLateralObj->addWidget(page_Linha);
        page_Cubo = new QWidget();
        page_Cubo->setObjectName(QString::fromUtf8("page_Cubo"));
        verticalLayout_5 = new QVBoxLayout(page_Cubo);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        groupBox_13 = new QGroupBox(page_Cubo);
        groupBox_13->setObjectName(QString::fromUtf8("groupBox_13"));
        sizePolicy2.setHeightForWidth(groupBox_13->sizePolicy().hasHeightForWidth());
        groupBox_13->setSizePolicy(sizePolicy2);
        groupBox_13->setMinimumSize(QSize(140, 259));
        groupBox_13->setMaximumSize(QSize(140, 259));
        gridLayout_4 = new QGridLayout(groupBox_13);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_36 = new QLabel(groupBox_13);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setMinimumSize(QSize(40, 0));
        label_36->setTextFormat(Qt::AutoText);
        label_36->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_36->setIndent(-1);

        gridLayout_4->addWidget(label_36, 0, 0, 1, 1);

        cube_dim_X = new QDoubleSpinBox(groupBox_13);
        cube_dim_X->setObjectName(QString::fromUtf8("cube_dim_X"));
        cube_dim_X->setMinimumSize(QSize(60, 0));
        cube_dim_X->setDecimals(3);
        cube_dim_X->setMinimum(0);
        cube_dim_X->setMaximum(100);
        cube_dim_X->setSingleStep(0.01);
        cube_dim_X->setValue(0.1);

        gridLayout_4->addWidget(cube_dim_X, 0, 1, 1, 1);

        label_37 = new QLabel(groupBox_13);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setMinimumSize(QSize(40, 0));
        label_37->setTextFormat(Qt::AutoText);
        label_37->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_37->setIndent(-1);

        gridLayout_4->addWidget(label_37, 1, 0, 1, 1);

        cube_dim_Y = new QDoubleSpinBox(groupBox_13);
        cube_dim_Y->setObjectName(QString::fromUtf8("cube_dim_Y"));
        cube_dim_Y->setDecimals(3);
        cube_dim_Y->setMinimum(0);
        cube_dim_Y->setMaximum(100);
        cube_dim_Y->setSingleStep(0.01);
        cube_dim_Y->setValue(0.1);

        gridLayout_4->addWidget(cube_dim_Y, 1, 1, 1, 1);

        label_38 = new QLabel(groupBox_13);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setMinimumSize(QSize(40, 0));
        label_38->setTextFormat(Qt::AutoText);
        label_38->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_38->setIndent(-1);

        gridLayout_4->addWidget(label_38, 2, 0, 1, 1);

        cube_dim_Z = new QDoubleSpinBox(groupBox_13);
        cube_dim_Z->setObjectName(QString::fromUtf8("cube_dim_Z"));
        cube_dim_Z->setDecimals(3);
        cube_dim_Z->setMinimum(0);
        cube_dim_Z->setMaximum(100);
        cube_dim_Z->setSingleStep(0.01);
        cube_dim_Z->setValue(0.1);

        gridLayout_4->addWidget(cube_dim_Z, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 121, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 3, 1, 1, 1);


        verticalLayout_5->addWidget(groupBox_13);

        stackedWidget_pnLateralObj->addWidget(page_Cubo);
        page_Esfera = new QWidget();
        page_Esfera->setObjectName(QString::fromUtf8("page_Esfera"));
        verticalLayout = new QVBoxLayout(page_Esfera);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_14 = new QGroupBox(page_Esfera);
        groupBox_14->setObjectName(QString::fromUtf8("groupBox_14"));
        sizePolicy2.setHeightForWidth(groupBox_14->sizePolicy().hasHeightForWidth());
        groupBox_14->setSizePolicy(sizePolicy2);
        groupBox_14->setMinimumSize(QSize(140, 0));
        groupBox_14->setMaximumSize(QSize(140, 16777215));
        formLayout_15 = new QFormLayout(groupBox_14);
        formLayout_15->setSpacing(6);
        formLayout_15->setContentsMargins(11, 11, 11, 11);
        formLayout_15->setObjectName(QString::fromUtf8("formLayout_15"));
        formLayout_15->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_39 = new QLabel(groupBox_14);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setMinimumSize(QSize(40, 0));
        label_39->setTextFormat(Qt::AutoText);
        label_39->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_39->setIndent(-1);

        formLayout_15->setWidget(0, QFormLayout::LabelRole, label_39);

        raio_esfera = new QDoubleSpinBox(groupBox_14);
        raio_esfera->setObjectName(QString::fromUtf8("raio_esfera"));
        raio_esfera->setMinimumSize(QSize(60, 0));
        raio_esfera->setMaximum(100);
        raio_esfera->setSingleStep(0.01);
        raio_esfera->setValue(0.05);

        formLayout_15->setWidget(0, QFormLayout::FieldRole, raio_esfera);


        verticalLayout->addWidget(groupBox_14);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        stackedWidget_pnLateralObj->addWidget(page_Esfera);
        page_Cilindro = new QWidget();
        page_Cilindro->setObjectName(QString::fromUtf8("page_Cilindro"));
        verticalLayout_6 = new QVBoxLayout(page_Cilindro);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        groupBox_20 = new QGroupBox(page_Cilindro);
        groupBox_20->setObjectName(QString::fromUtf8("groupBox_20"));
        sizePolicy2.setHeightForWidth(groupBox_20->sizePolicy().hasHeightForWidth());
        groupBox_20->setSizePolicy(sizePolicy2);
        groupBox_20->setMinimumSize(QSize(140, 0));
        groupBox_20->setMaximumSize(QSize(140, 16777215));
        formLayout_19 = new QFormLayout(groupBox_20);
        formLayout_19->setSpacing(6);
        formLayout_19->setContentsMargins(11, 11, 11, 11);
        formLayout_19->setObjectName(QString::fromUtf8("formLayout_19"));
        formLayout_19->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_51 = new QLabel(groupBox_20);
        label_51->setObjectName(QString::fromUtf8("label_51"));
        label_51->setMinimumSize(QSize(40, 0));
        label_51->setTextFormat(Qt::AutoText);
        label_51->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_51->setIndent(-1);

        formLayout_19->setWidget(0, QFormLayout::LabelRole, label_51);

        raio_cilindro = new QDoubleSpinBox(groupBox_20);
        raio_cilindro->setObjectName(QString::fromUtf8("raio_cilindro"));
        raio_cilindro->setMinimumSize(QSize(60, 0));
        raio_cilindro->setDecimals(3);
        raio_cilindro->setSingleStep(0.01);
        raio_cilindro->setValue(0.05);

        formLayout_19->setWidget(0, QFormLayout::FieldRole, raio_cilindro);

        label_57 = new QLabel(groupBox_20);
        label_57->setObjectName(QString::fromUtf8("label_57"));
        label_57->setMinimumSize(QSize(40, 0));
        label_57->setTextFormat(Qt::AutoText);
        label_57->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_57->setIndent(-1);

        formLayout_19->setWidget(1, QFormLayout::LabelRole, label_57);

        comprimento_cilindro = new QDoubleSpinBox(groupBox_20);
        comprimento_cilindro->setObjectName(QString::fromUtf8("comprimento_cilindro"));
        comprimento_cilindro->setDecimals(3);
        comprimento_cilindro->setSingleStep(0.01);
        comprimento_cilindro->setValue(0.1);

        formLayout_19->setWidget(1, QFormLayout::FieldRole, comprimento_cilindro);


        verticalLayout_6->addWidget(groupBox_20);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_3);

        stackedWidget_pnLateralObj->addWidget(page_Cilindro);
        page_Cone = new QWidget();
        page_Cone->setObjectName(QString::fromUtf8("page_Cone"));
        groupBox_21 = new QGroupBox(page_Cone);
        groupBox_21->setObjectName(QString::fromUtf8("groupBox_21"));
        groupBox_21->setGeometry(QRect(0, 20, 140, 96));
        sizePolicy2.setHeightForWidth(groupBox_21->sizePolicy().hasHeightForWidth());
        groupBox_21->setSizePolicy(sizePolicy2);
        groupBox_21->setMinimumSize(QSize(140, 0));
        groupBox_21->setMaximumSize(QSize(140, 16777215));
        gridLayout_5 = new QGridLayout(groupBox_21);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, -1, -1);
        label_52 = new QLabel(groupBox_21);
        label_52->setObjectName(QString::fromUtf8("label_52"));
        label_52->setMinimumSize(QSize(40, 0));
        label_52->setTextFormat(Qt::AutoText);
        label_52->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_52->setIndent(-1);

        gridLayout_5->addWidget(label_52, 0, 0, 1, 1);

        label_60 = new QLabel(groupBox_21);
        label_60->setObjectName(QString::fromUtf8("label_60"));
        label_60->setMinimumSize(QSize(40, 0));
        label_60->setTextFormat(Qt::AutoText);
        label_60->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_60->setIndent(-1);

        gridLayout_5->addWidget(label_60, 1, 0, 1, 1);

        comprimento_cone = new QDoubleSpinBox(groupBox_21);
        comprimento_cone->setObjectName(QString::fromUtf8("comprimento_cone"));
        comprimento_cone->setDecimals(3);
        comprimento_cone->setSingleStep(0.01);
        comprimento_cone->setValue(0.1);

        gridLayout_5->addWidget(comprimento_cone, 1, 1, 1, 1);

        raio_cone = new QDoubleSpinBox(groupBox_21);
        raio_cone->setObjectName(QString::fromUtf8("raio_cone"));
        raio_cone->setMinimumSize(QSize(60, 0));
        raio_cone->setDecimals(3);
        raio_cone->setMinimum(0);
        raio_cone->setSingleStep(0.01);
        raio_cone->setValue(0.1);

        gridLayout_5->addWidget(raio_cone, 0, 1, 1, 1);

        stackedWidget_pnLateralObj->addWidget(page_Cone);

        gridLayout_3->addWidget(stackedWidget_pnLateralObj, 2, 0, 1, 1);

        groupBox_Material = new QGroupBox(scrollAreaWidgetContents_pnLateral_1);
        groupBox_Material->setObjectName(QString::fromUtf8("groupBox_Material"));
        sizePolicy.setHeightForWidth(groupBox_Material->sizePolicy().hasHeightForWidth());
        groupBox_Material->setSizePolicy(sizePolicy);
        groupBox_Material->setMaximumSize(QSize(140, 16777215));
        groupBox_Material->setLayoutDirection(Qt::LeftToRight);
        groupBox_Material->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout = new QFormLayout(groupBox_Material);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_48 = new QLabel(groupBox_Material);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setMinimumSize(QSize(40, 0));
        label_48->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_48);

        label_49 = new QLabel(groupBox_Material);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        label_49->setMinimumSize(QSize(40, 0));
        label_49->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_49);

        permeabilidade = new QDoubleSpinBox(groupBox_Material);
        permeabilidade->setObjectName(QString::fromUtf8("permeabilidade"));
        permeabilidade->setMaximumSize(QSize(50, 27));
        permeabilidade->setSingleStep(0.01);

        formLayout->setWidget(1, QFormLayout::FieldRole, permeabilidade);

        label_50 = new QLabel(groupBox_Material);
        label_50->setObjectName(QString::fromUtf8("label_50"));
        label_50->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_50);

        condutibilidade = new QDoubleSpinBox(groupBox_Material);
        condutibilidade->setObjectName(QString::fromUtf8("condutibilidade"));
        condutibilidade->setMaximumSize(QSize(50, 27));
        condutibilidade->setSingleStep(0.01);

        formLayout->setWidget(2, QFormLayout::FieldRole, condutibilidade);

        label_5 = new QLabel(groupBox_Material);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(3, QFormLayout::SpanningRole, label_5);

        comboBox_Prop = new QComboBox(groupBox_Material);
        comboBox_Prop->setObjectName(QString::fromUtf8("comboBox_Prop"));

        formLayout->setWidget(4, QFormLayout::SpanningRole, comboBox_Prop);

        permissividade = new QDoubleSpinBox(groupBox_Material);
        permissividade->setObjectName(QString::fromUtf8("permissividade"));
        permissividade->setMaximumSize(QSize(50, 27));
        permissividade->setSingleStep(0.01);

        formLayout->setWidget(0, QFormLayout::FieldRole, permissividade);


        gridLayout_3->addWidget(groupBox_Material, 3, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_4, 4, 0, 1, 1);

        label_PainelTitulo_1 = new QLabel(scrollAreaWidgetContents_pnLateral_1);
        label_PainelTitulo_1->setObjectName(QString::fromUtf8("label_PainelTitulo_1"));
        sizePolicy.setHeightForWidth(label_PainelTitulo_1->sizePolicy().hasHeightForWidth());
        label_PainelTitulo_1->setSizePolicy(sizePolicy);
        label_PainelTitulo_1->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_PainelTitulo_1, 0, 0, 1, 1);

        scrollArea_1->setWidget(scrollAreaWidgetContents_pnLateral_1);

        verticalLayout_4->addWidget(scrollArea_1);

        stackedWidget_Lateral->addWidget(page_Objetos);

        grid_Interface->addWidget(stackedWidget_Lateral, 0, 1, 1, 1);

        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        widget_2->setMinimumSize(QSize(0, 30));
        widget_2->setMaximumSize(QSize(16777215, 30));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(4, 4, 4, 4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        PositionButton = new QToolButton(widget_2);
        PositionButton->setObjectName(QString::fromUtf8("PositionButton"));

        horizontalLayout->addWidget(PositionButton);

        RotationButton = new QToolButton(widget_2);
        RotationButton->setObjectName(QString::fromUtf8("RotationButton"));

        horizontalLayout->addWidget(RotationButton);

        line = new QFrame(widget_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        position_X = new QDoubleSpinBox(widget_2);
        position_X->setObjectName(QString::fromUtf8("position_X"));
        position_X->setEnabled(true);
        position_X->setKeyboardTracking(true);
        position_X->setDecimals(2);
        position_X->setMinimum(-1000);

        horizontalLayout->addWidget(position_X);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        position_Y = new QDoubleSpinBox(widget_2);
        position_Y->setObjectName(QString::fromUtf8("position_Y"));
        position_Y->setMinimum(-1000);

        horizontalLayout->addWidget(position_Y);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        position_Z = new QDoubleSpinBox(widget_2);
        position_Z->setObjectName(QString::fromUtf8("position_Z"));
        position_Z->setAcceptDrops(false);
        position_Z->setMinimum(-1000);

        horizontalLayout->addWidget(position_Z);

        line_4 = new QFrame(widget_2);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_4);

        GerarMalha = new QPushButton(widget_2);
        GerarMalha->setObjectName(QString::fromUtf8("GerarMalha"));

        horizontalLayout->addWidget(GerarMalha);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        grid_Interface->addWidget(widget_2, 1, 0, 1, 1);

        widget_1 = new QWidget(centralWidget);
        widget_1->setObjectName(QString::fromUtf8("widget_1"));
        widget_1->setMaximumSize(QSize(170, 16777215));
        horizontalLayout_2 = new QHBoxLayout(widget_1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, -1, -1, -1);
        line_3 = new QFrame(widget_1);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_3);

        label_4 = new QLabel(widget_1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy5);
        label_4->setMinimumSize(QSize(165, 0));
        label_4->setMaximumSize(QSize(165, 16777215));

        horizontalLayout_2->addWidget(label_4);


        grid_Interface->addWidget(widget_1, 1, 1, 1, 1);


        gridLayout->addLayout(grid_Interface, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 900, 25));
        MainWindow->setMenuBar(menuBar);
        ToolBar_File = new QToolBar(MainWindow);
        ToolBar_File->setObjectName(QString::fromUtf8("ToolBar_File"));
        MainWindow->addToolBar(Qt::TopToolBarArea, ToolBar_File);
        toolBar_Manipulador = new QToolBar(MainWindow);
        toolBar_Manipulador->setObjectName(QString::fromUtf8("toolBar_Manipulador"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_Manipulador);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar_GeometBasicas = new QToolBar(MainWindow);
        toolBar_GeometBasicas->setObjectName(QString::fromUtf8("toolBar_GeometBasicas"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_GeometBasicas);

        ToolBar_File->addAction(actionNew);
        ToolBar_File->addAction(actionOpen);
        ToolBar_File->addAction(actionSave);
        toolBar_Manipulador->addAction(actionPosicao);
        toolBar_Manipulador->addAction(actionRotacao);
        toolBar_GeometBasicas->addAction(actionPonto);
        toolBar_GeometBasicas->addAction(actionLinha);
        toolBar_GeometBasicas->addAction(actionCubo);
        toolBar_GeometBasicas->addAction(actionEsfera);
        toolBar_GeometBasicas->addAction(actionCilindro);
        toolBar_GeometBasicas->addAction(actionCone);

        retranslateUi(MainWindow);
        QObject::connect(GerarMalha, SIGNAL(clicked()), MainWindow, SLOT(gerarMalha()));
        QObject::connect(position_Y, SIGNAL(valueChanged(double)), MainWindow, SLOT(change_position()));
        QObject::connect(position_Z, SIGNAL(valueChanged(double)), MainWindow, SLOT(change_position()));
        QObject::connect(position_X, SIGNAL(valueChanged(double)), MainWindow, SLOT(change_position()));
        QObject::connect(raio_haste, SIGNAL(valueChanged(double)), MainWindow, SLOT(set_haste()));
        QObject::connect(haste_inicial_x, SIGNAL(valueChanged(double)), MainWindow, SLOT(set_haste()));
        QObject::connect(haste_inicial_y, SIGNAL(valueChanged(double)), MainWindow, SLOT(set_haste()));
        QObject::connect(haste_inicial_z, SIGNAL(valueChanged(double)), MainWindow, SLOT(set_haste()));
        QObject::connect(haste_final_x, SIGNAL(valueChanged(double)), MainWindow, SLOT(set_haste()));
        QObject::connect(haste_final_y, SIGNAL(valueChanged(double)), MainWindow, SLOT(set_haste()));
        QObject::connect(haste_final_z, SIGNAL(valueChanged(double)), MainWindow, SLOT(set_haste()));
        QObject::connect(cube_dim_X, SIGNAL(valueChanged(double)), MainWindow, SLOT(set_cube()));
        QObject::connect(cube_dim_Y, SIGNAL(valueChanged(double)), MainWindow, SLOT(set_cube()));
        QObject::connect(cube_dim_Z, SIGNAL(valueChanged(double)), MainWindow, SLOT(set_cube()));
        QObject::connect(raio_esfera, SIGNAL(valueChanged(double)), MainWindow, SLOT(set_esfera()));
        QObject::connect(raio_cilindro, SIGNAL(valueChanged(double)), MainWindow, SLOT(set_cilindro()));
        QObject::connect(comprimento_cilindro, SIGNAL(valueChanged(double)), MainWindow, SLOT(set_cilindro()));
        QObject::connect(comprimento_cone, SIGNAL(valueChanged(double)), MainWindow, SLOT(set_cone()));
        QObject::connect(raio_cone, SIGNAL(valueChanged(double)), MainWindow, SLOT(set_cone()));

        stackedWidget_Lateral->setCurrentIndex(1);
        stackedWidget_pnLateralObj->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("MainWindow", "Open Projeto", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionNew->setText(QApplication::translate("MainWindow", "New", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionNew->setToolTip(QApplication::translate("MainWindow", "New Projeto", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("MainWindow", "Save Projeto", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionPosicao->setText(QApplication::translate("MainWindow", "Pos", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionPosicao->setToolTip(QApplication::translate("MainWindow", "Posicao", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionRotacao->setText(QApplication::translate("MainWindow", "Rot", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionRotacao->setToolTip(QApplication::translate("MainWindow", "Rotacao", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionPonto->setText(QApplication::translate("MainWindow", "Ponto", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionPonto->setToolTip(QApplication::translate("MainWindow", "Cria Ponto", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionLinha->setText(QApplication::translate("MainWindow", "Haste", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionLinha->setToolTip(QApplication::translate("MainWindow", "Cria Haste", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionCubo->setText(QApplication::translate("MainWindow", "Cubo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionCubo->setToolTip(QApplication::translate("MainWindow", "Cria Cubo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionEsfera->setText(QApplication::translate("MainWindow", "Esfera", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionEsfera->setToolTip(QApplication::translate("MainWindow", "Cria Esfera", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionCilindro->setText(QApplication::translate("MainWindow", "Cilindro", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionCilindro->setToolTip(QApplication::translate("MainWindow", "Cria Cilindro", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionCone->setText(QApplication::translate("MainWindow", "Cone", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionCone->setToolTip(QApplication::translate("MainWindow", "Cria Cone", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_PainelTitulo_0->setText(QApplication::translate("MainWindow", "AMBIENTE", 0, QApplication::UnicodeUTF8));
        groupBox_15->setTitle(QApplication::translate("MainWindow", "Regi\303\243o de An\303\241lise", 0, QApplication::UnicodeUTF8));
        label_45->setText(QApplication::translate("MainWindow", "Dim X:", 0, QApplication::UnicodeUTF8));
        doubleSpinBox_XDim_RLIVRE->setSuffix(QApplication::translate("MainWindow", " m", 0, QApplication::UnicodeUTF8));
        label_58->setText(QApplication::translate("MainWindow", "Dim Y:", 0, QApplication::UnicodeUTF8));
        doubleSpinBox_YDim_RLIVRE->setSuffix(QApplication::translate("MainWindow", " m", 0, QApplication::UnicodeUTF8));
        label_59->setText(QApplication::translate("MainWindow", "Dim Z:", 0, QApplication::UnicodeUTF8));
        doubleSpinBox_ZDim_RLIVRE->setSuffix(QApplication::translate("MainWindow", " m", 0, QApplication::UnicodeUTF8));
        label_65->setText(QApplication::translate("MainWindow", "delt Med:", 0, QApplication::UnicodeUTF8));
        doubleSpinBox_deltaX_RLIVRE->setSuffix(QApplication::translate("MainWindow", " m", 0, QApplication::UnicodeUTF8));
        groupBox_Identificao->setTitle(QApplication::translate("MainWindow", "Identifca\303\247\303\243o", 0, QApplication::UnicodeUTF8));
        label_40->setText(QApplication::translate("MainWindow", "Nome:", 0, QApplication::UnicodeUTF8));
        label_41->setText(QApplication::translate("MainWindow", "n\302\272:", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Dimension", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "raio:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Inicial", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "X:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Y:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Z:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "Final", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "X:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "Y:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Z:", 0, QApplication::UnicodeUTF8));
        groupBox_13->setTitle(QApplication::translate("MainWindow", "Dimens\303\265es", 0, QApplication::UnicodeUTF8));
        label_36->setText(QApplication::translate("MainWindow", "X:", 0, QApplication::UnicodeUTF8));
        cube_dim_X->setSuffix(QApplication::translate("MainWindow", " m", 0, QApplication::UnicodeUTF8));
        label_37->setText(QApplication::translate("MainWindow", "Y:", 0, QApplication::UnicodeUTF8));
        cube_dim_Y->setSuffix(QApplication::translate("MainWindow", " m", 0, QApplication::UnicodeUTF8));
        label_38->setText(QApplication::translate("MainWindow", "Z:", 0, QApplication::UnicodeUTF8));
        cube_dim_Z->setSuffix(QApplication::translate("MainWindow", " m", 0, QApplication::UnicodeUTF8));
        groupBox_14->setTitle(QApplication::translate("MainWindow", "Dimension", 0, QApplication::UnicodeUTF8));
        label_39->setText(QApplication::translate("MainWindow", "raio:", 0, QApplication::UnicodeUTF8));
        raio_esfera->setSuffix(QApplication::translate("MainWindow", " m", 0, QApplication::UnicodeUTF8));
        groupBox_20->setTitle(QApplication::translate("MainWindow", "Dimension", 0, QApplication::UnicodeUTF8));
        label_51->setText(QApplication::translate("MainWindow", "raio:", 0, QApplication::UnicodeUTF8));
        raio_cilindro->setSuffix(QApplication::translate("MainWindow", " m", 0, QApplication::UnicodeUTF8));
        label_57->setText(QApplication::translate("MainWindow", "comp:", 0, QApplication::UnicodeUTF8));
        comprimento_cilindro->setSuffix(QApplication::translate("MainWindow", " m", 0, QApplication::UnicodeUTF8));
        groupBox_21->setTitle(QApplication::translate("MainWindow", "Dimension", 0, QApplication::UnicodeUTF8));
        label_52->setText(QApplication::translate("MainWindow", "raio:", 0, QApplication::UnicodeUTF8));
        label_60->setText(QApplication::translate("MainWindow", "comp:", 0, QApplication::UnicodeUTF8));
        comprimento_cone->setSuffix(QApplication::translate("MainWindow", " m", 0, QApplication::UnicodeUTF8));
        raio_cone->setSuffix(QApplication::translate("MainWindow", " m", 0, QApplication::UnicodeUTF8));
        groupBox_Material->setTitle(QApplication::translate("MainWindow", "Materiais", 0, QApplication::UnicodeUTF8));
        label_48->setText(QApplication::translate("MainWindow", "Permissi:", 0, QApplication::UnicodeUTF8));
        label_49->setText(QApplication::translate("MainWindow", "Permea:", 0, QApplication::UnicodeUTF8));
        label_50->setText(QApplication::translate("MainWindow", "Conduc:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Propriedade:", 0, QApplication::UnicodeUTF8));
        comboBox_Prop->clear();
        comboBox_Prop->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "NONE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Metal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Medi\303\247\303\243o", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Fonte", 0, QApplication::UnicodeUTF8)
        );
        label_PainelTitulo_1->setText(QApplication::translate("MainWindow", "OBJETOS", 0, QApplication::UnicodeUTF8));
        PositionButton->setText(QApplication::translate("MainWindow", "Pos", 0, QApplication::UnicodeUTF8));
        RotationButton->setText(QApplication::translate("MainWindow", "Rot", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "X:", 0, QApplication::UnicodeUTF8));
        position_X->setSuffix(QApplication::translate("MainWindow", "m", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Y:", 0, QApplication::UnicodeUTF8));
        position_Y->setSuffix(QApplication::translate("MainWindow", "m", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Z:", 0, QApplication::UnicodeUTF8));
        position_Z->setSuffix(QApplication::translate("MainWindow", "m", 0, QApplication::UnicodeUTF8));
        GerarMalha->setText(QApplication::translate("MainWindow", "Gerar Malha", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", " Manupuladores de Cena", 0, QApplication::UnicodeUTF8));
        toolBar_Manipulador->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
        toolBar_GeometBasicas->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
