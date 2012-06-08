/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Jun 8 00:56:41 2012
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
    QAction *actionEyeAntenna;
    QWidget *centralWidget;
    QGridLayout *gridLayout_15;
    QGridLayout *grid_Interface;
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
    QStackedWidget *painel_lateral;
    QWidget *page_Ambiente;
    QVBoxLayout *verticalLayout_2;
    QLabel *painel_ambiente;
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
    QFormLayout *formLayout_2;
    QLabel *label_PainelTitulo_1;
    QGroupBox *groupBox_Identificao;
    QFormLayout *formLayout_10;
    QLabel *label_40;
    QLineEdit *lineEdit_Name;
    QLabel *label_41;
    QSpinBox *spinBox_4;
    QStackedWidget *painel_objetos;
    QWidget *page_Ponto;
    QVBoxLayout *verticalLayout_11;
    QWidget *page_Linha;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
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
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_11;
    QGroupBox *groupBox_13;
    QGridLayout *gridLayout_4;
    QLabel *label_36;
    QDoubleSpinBox *cube_dim_X;
    QLabel *label_37;
    QDoubleSpinBox *cube_dim_Y;
    QLabel *label_38;
    QDoubleSpinBox *cube_dim_Z;
    QGroupBox *groupBox_Material_3;
    QGridLayout *gridLayout_12;
    QLabel *label_73;
    QLabel *label_74;
    QLabel *label_75;
    QLabel *label_20;
    QComboBox *propriedade_cube;
    QLineEdit *permissividade_cubo;
    QLineEdit *permeabilidade_cubo;
    QLineEdit *condutibilidade_cubo;
    QWidget *page_Esfera;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_5;
    QFormLayout *formLayout_3;
    QGroupBox *groupBox_14;
    QFormLayout *formLayout_15;
    QLabel *label_39;
    QDoubleSpinBox *raio_esfera;
    QGroupBox *groupBox_Material_6;
    QGridLayout *gridLayout_18;
    QLabel *label_82;
    QLabel *label_83;
    QLabel *label_84;
    QLabel *label_23;
    QComboBox *propriedade_esfera;
    QLineEdit *permissividade_esfera;
    QLineEdit *permeabilidade_esfera;
    QLineEdit *condutibilidade_esfera;
    QWidget *page_Cilindro;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox_6;
    QFormLayout *formLayout;
    QGroupBox *groupBox_20;
    QFormLayout *formLayout_19;
    QLabel *label_51;
    QDoubleSpinBox *raio_cilindro;
    QLabel *label_57;
    QDoubleSpinBox *comprimento_cilindro;
    QGroupBox *groupBox_Material_4;
    QGridLayout *gridLayout_13;
    QLabel *label_76;
    QLabel *label_77;
    QLabel *label_78;
    QLabel *label_21;
    QComboBox *propriedade_cilindro;
    QLineEdit *permissividade_cilindro;
    QLineEdit *permeabilidade_cilindro;
    QLineEdit *condutibilidade_cilindro;
    QWidget *page_cone;
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_17;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_8;
    QLabel *label_52;
    QDoubleSpinBox *raio_cone;
    QLabel *label_60;
    QDoubleSpinBox *comprimento_cone;
    QGroupBox *groupBox_Material_5;
    QGridLayout *gridLayout_16;
    QLabel *label_79;
    QLabel *label_80;
    QLabel *label_81;
    QLabel *label_22;
    QComboBox *propriedade_cone;
    QLineEdit *permissividade_cone;
    QLineEdit *permeabilidade_cone;
    QLineEdit *condutibilidade_cone;
    QWidget *page_EyeAntenna;
    QGridLayout *gridLayout_5;
    QSpacerItem *verticalSpacer_4;
    QMenuBar *menuBar;
    QToolBar *ToolBar_File;
    QToolBar *toolBar_Manipulador;
    QStatusBar *statusBar;
    QToolBar *toolBar_GeometBasicas;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(891, 565);
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
        actionEyeAntenna = new QAction(MainWindow);
        actionEyeAntenna->setObjectName(QString::fromUtf8("actionEyeAntenna"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_15 = new QGridLayout(centralWidget);
        gridLayout_15->setSpacing(6);
        gridLayout_15->setContentsMargins(11, 11, 11, 11);
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        grid_Interface = new QGridLayout();
        grid_Interface->setSpacing(6);
        grid_Interface->setObjectName(QString::fromUtf8("grid_Interface"));
        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
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
        position_X->setDecimals(5);
        position_X->setMinimum(-1000);
        position_X->setSingleStep(0.01);

        horizontalLayout->addWidget(position_X);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        position_Y = new QDoubleSpinBox(widget_2);
        position_Y->setObjectName(QString::fromUtf8("position_Y"));
        position_Y->setDecimals(5);
        position_Y->setMinimum(-1000);
        position_Y->setSingleStep(0.01);

        horizontalLayout->addWidget(position_Y);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        position_Z = new QDoubleSpinBox(widget_2);
        position_Z->setObjectName(QString::fromUtf8("position_Z"));
        position_Z->setAcceptDrops(false);
        position_Z->setDecimals(5);
        position_Z->setMinimum(-1000);
        position_Z->setSingleStep(0.01);

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
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setMinimumSize(QSize(165, 0));
        label_4->setMaximumSize(QSize(165, 16777215));

        horizontalLayout_2->addWidget(label_4);


        grid_Interface->addWidget(widget_1, 1, 1, 1, 1);

        painel_lateral = new QStackedWidget(centralWidget);
        painel_lateral->setObjectName(QString::fromUtf8("painel_lateral"));
        sizePolicy.setHeightForWidth(painel_lateral->sizePolicy().hasHeightForWidth());
        painel_lateral->setSizePolicy(sizePolicy);
        painel_lateral->setMinimumSize(QSize(180, 0));
        painel_lateral->setMaximumSize(QSize(180, 451));
        painel_lateral->setFrameShape(QFrame::Box);
        painel_lateral->setFrameShadow(QFrame::Raised);
        painel_lateral->setLineWidth(1);
        painel_lateral->setMidLineWidth(0);
        page_Ambiente = new QWidget();
        page_Ambiente->setObjectName(QString::fromUtf8("page_Ambiente"));
        verticalLayout_2 = new QVBoxLayout(page_Ambiente);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(5, -1, 0, -1);
        painel_ambiente = new QLabel(page_Ambiente);
        painel_ambiente->setObjectName(QString::fromUtf8("painel_ambiente"));
        sizePolicy.setHeightForWidth(painel_ambiente->sizePolicy().hasHeightForWidth());
        painel_ambiente->setSizePolicy(sizePolicy);
        painel_ambiente->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(painel_ambiente);

        scrollArea_0 = new QScrollArea(page_Ambiente);
        scrollArea_0->setObjectName(QString::fromUtf8("scrollArea_0"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scrollArea_0->sizePolicy().hasHeightForWidth());
        scrollArea_0->setSizePolicy(sizePolicy2);
        scrollArea_0->setMinimumSize(QSize(170, 0));
        scrollArea_0->setMaximumSize(QSize(160, 16777215));
        scrollArea_0->setFrameShape(QFrame::NoFrame);
        scrollArea_0->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea_0->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea_0->setWidgetResizable(true);
        scrollAreaWidgetContents_pnLateral_0 = new QWidget();
        scrollAreaWidgetContents_pnLateral_0->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_pnLateral_0"));
        scrollAreaWidgetContents_pnLateral_0->setGeometry(QRect(0, 0, 250, 385));
        scrollAreaWidgetContents_pnLateral_0->setMinimumSize(QSize(250, 0));
        verticalLayout_12 = new QVBoxLayout(scrollAreaWidgetContents_pnLateral_0);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(0, 9, 0, -1);
        groupBox_15 = new QGroupBox(scrollAreaWidgetContents_pnLateral_0);
        groupBox_15->setObjectName(QString::fromUtf8("groupBox_15"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_15->sizePolicy().hasHeightForWidth());
        groupBox_15->setSizePolicy(sizePolicy3);
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

        painel_lateral->addWidget(page_Ambiente);
        scrollArea_0->raise();
        painel_ambiente->raise();
        page_Objetos = new QWidget();
        page_Objetos->setObjectName(QString::fromUtf8("page_Objetos"));
        verticalLayout_4 = new QVBoxLayout(page_Objetos);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(5, -1, 0, -1);
        scrollArea_1 = new QScrollArea(page_Objetos);
        scrollArea_1->setObjectName(QString::fromUtf8("scrollArea_1"));
        sizePolicy2.setHeightForWidth(scrollArea_1->sizePolicy().hasHeightForWidth());
        scrollArea_1->setSizePolicy(sizePolicy2);
        scrollArea_1->setMinimumSize(QSize(170, 400));
        scrollArea_1->setMaximumSize(QSize(180, 16777215));
        scrollArea_1->setFrameShape(QFrame::NoFrame);
        scrollArea_1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea_1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea_1->setWidgetResizable(true);
        scrollAreaWidgetContents_pnLateral_1 = new QWidget();
        scrollAreaWidgetContents_pnLateral_1->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_pnLateral_1"));
        scrollAreaWidgetContents_pnLateral_1->setGeometry(QRect(0, 0, 156, 600));
        scrollAreaWidgetContents_pnLateral_1->setMinimumSize(QSize(0, 600));
        formLayout_2 = new QFormLayout(scrollAreaWidgetContents_pnLateral_1);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_2->setContentsMargins(0, 9, 0, -1);
        label_PainelTitulo_1 = new QLabel(scrollAreaWidgetContents_pnLateral_1);
        label_PainelTitulo_1->setObjectName(QString::fromUtf8("label_PainelTitulo_1"));
        sizePolicy.setHeightForWidth(label_PainelTitulo_1->sizePolicy().hasHeightForWidth());
        label_PainelTitulo_1->setSizePolicy(sizePolicy);
        label_PainelTitulo_1->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_PainelTitulo_1);

        groupBox_Identificao = new QGroupBox(scrollAreaWidgetContents_pnLateral_1);
        groupBox_Identificao->setObjectName(QString::fromUtf8("groupBox_Identificao"));
        sizePolicy3.setHeightForWidth(groupBox_Identificao->sizePolicy().hasHeightForWidth());
        groupBox_Identificao->setSizePolicy(sizePolicy3);
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
        sizePolicy3.setHeightForWidth(lineEdit_Name->sizePolicy().hasHeightForWidth());
        lineEdit_Name->setSizePolicy(sizePolicy3);
        lineEdit_Name->setMinimumSize(QSize(60, 0));

        formLayout_10->setWidget(0, QFormLayout::FieldRole, lineEdit_Name);

        label_41 = new QLabel(groupBox_Identificao);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setMinimumSize(QSize(39, 0));
        label_41->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout_10->setWidget(1, QFormLayout::LabelRole, label_41);

        spinBox_4 = new QSpinBox(groupBox_Identificao);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        sizePolicy3.setHeightForWidth(spinBox_4->sizePolicy().hasHeightForWidth());
        spinBox_4->setSizePolicy(sizePolicy3);
        spinBox_4->setMinimumSize(QSize(73, 0));

        formLayout_10->setWidget(1, QFormLayout::FieldRole, spinBox_4);


        formLayout_2->setWidget(1, QFormLayout::LabelRole, groupBox_Identificao);

        painel_objetos = new QStackedWidget(scrollAreaWidgetContents_pnLateral_1);
        painel_objetos->setObjectName(QString::fromUtf8("painel_objetos"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(15);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(painel_objetos->sizePolicy().hasHeightForWidth());
        painel_objetos->setSizePolicy(sizePolicy4);
        painel_objetos->setMinimumSize(QSize(150, 0));
        painel_objetos->setMaximumSize(QSize(170, 16777215));
        page_Ponto = new QWidget();
        page_Ponto->setObjectName(QString::fromUtf8("page_Ponto"));
        verticalLayout_11 = new QVBoxLayout(page_Ponto);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        painel_objetos->addWidget(page_Ponto);
        page_Linha = new QWidget();
        page_Linha->setObjectName(QString::fromUtf8("page_Linha"));
        verticalLayout_3 = new QVBoxLayout(page_Linha);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox_3 = new QGroupBox(page_Linha);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(150, 300));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox = new QGroupBox(groupBox_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy5);
        groupBox->setMinimumSize(QSize(150, 100));
        groupBox->setMaximumSize(QSize(500, 500));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_2->addWidget(label_14, 0, 0, 1, 1);

        raio_haste = new QDoubleSpinBox(groupBox);
        raio_haste->setObjectName(QString::fromUtf8("raio_haste"));
        raio_haste->setMaximumSize(QSize(91, 19));
        raio_haste->setDecimals(3);
        raio_haste->setMinimum(-100);
        raio_haste->setSingleStep(0.01);
        raio_haste->setValue(7);

        gridLayout_2->addWidget(raio_haste, 0, 1, 1, 3);

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
        haste_final_x->setValue(0);

        gridLayout_2->addWidget(haste_final_x, 6, 3, 1, 1);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_2->addWidget(label_12, 7, 2, 1, 1);

        haste_final_y = new QDoubleSpinBox(groupBox);
        haste_final_y->setObjectName(QString::fromUtf8("haste_final_y"));
        haste_final_y->setDecimals(3);
        haste_final_y->setMinimum(-100);
        haste_final_y->setSingleStep(0.01);
        haste_final_y->setValue(0.1);

        gridLayout_2->addWidget(haste_final_y, 7, 3, 1, 1);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_2->addWidget(label_10, 8, 2, 1, 1);

        haste_final_z = new QDoubleSpinBox(groupBox);
        haste_final_z->setObjectName(QString::fromUtf8("haste_final_z"));
        haste_final_z->setMinimum(-100);
        haste_final_z->setSingleStep(0.01);

        gridLayout_2->addWidget(haste_final_z, 8, 3, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        groupBox->raise();
        groupBox->raise();

        verticalLayout_3->addWidget(groupBox_3);

        painel_objetos->addWidget(page_Linha);
        page_Cubo = new QWidget();
        page_Cubo->setObjectName(QString::fromUtf8("page_Cubo"));
        verticalLayout_5 = new QVBoxLayout(page_Cubo);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        groupBox_4 = new QGroupBox(page_Cubo);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_11 = new QGridLayout(groupBox_4);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        groupBox_13 = new QGroupBox(groupBox_4);
        groupBox_13->setObjectName(QString::fromUtf8("groupBox_13"));
        sizePolicy3.setHeightForWidth(groupBox_13->sizePolicy().hasHeightForWidth());
        groupBox_13->setSizePolicy(sizePolicy3);
        groupBox_13->setMinimumSize(QSize(130, 120));
        groupBox_13->setMaximumSize(QSize(140, 120));
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


        gridLayout_11->addWidget(groupBox_13, 0, 0, 1, 1);

        groupBox_Material_3 = new QGroupBox(groupBox_4);
        groupBox_Material_3->setObjectName(QString::fromUtf8("groupBox_Material_3"));
        sizePolicy.setHeightForWidth(groupBox_Material_3->sizePolicy().hasHeightForWidth());
        groupBox_Material_3->setSizePolicy(sizePolicy);
        groupBox_Material_3->setMinimumSize(QSize(150, 0));
        groupBox_Material_3->setMaximumSize(QSize(150, 180));
        groupBox_Material_3->setLayoutDirection(Qt::LeftToRight);
        groupBox_Material_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        gridLayout_12 = new QGridLayout(groupBox_Material_3);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        label_73 = new QLabel(groupBox_Material_3);
        label_73->setObjectName(QString::fromUtf8("label_73"));
        label_73->setMinimumSize(QSize(40, 0));
        label_73->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_12->addWidget(label_73, 0, 0, 1, 1);

        label_74 = new QLabel(groupBox_Material_3);
        label_74->setObjectName(QString::fromUtf8("label_74"));
        label_74->setMinimumSize(QSize(40, 0));
        label_74->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_12->addWidget(label_74, 1, 0, 1, 1);

        label_75 = new QLabel(groupBox_Material_3);
        label_75->setObjectName(QString::fromUtf8("label_75"));
        label_75->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_12->addWidget(label_75, 2, 0, 1, 1);

        label_20 = new QLabel(groupBox_Material_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_12->addWidget(label_20, 3, 0, 1, 2);

        propriedade_cube = new QComboBox(groupBox_Material_3);
        propriedade_cube->setObjectName(QString::fromUtf8("propriedade_cube"));

        gridLayout_12->addWidget(propriedade_cube, 4, 0, 1, 2);

        permissividade_cubo = new QLineEdit(groupBox_Material_3);
        permissividade_cubo->setObjectName(QString::fromUtf8("permissividade_cubo"));

        gridLayout_12->addWidget(permissividade_cubo, 0, 1, 1, 1);

        permeabilidade_cubo = new QLineEdit(groupBox_Material_3);
        permeabilidade_cubo->setObjectName(QString::fromUtf8("permeabilidade_cubo"));

        gridLayout_12->addWidget(permeabilidade_cubo, 1, 1, 1, 1);

        condutibilidade_cubo = new QLineEdit(groupBox_Material_3);
        condutibilidade_cubo->setObjectName(QString::fromUtf8("condutibilidade_cubo"));

        gridLayout_12->addWidget(condutibilidade_cubo, 2, 1, 1, 1);


        gridLayout_11->addWidget(groupBox_Material_3, 1, 0, 1, 1);


        verticalLayout_5->addWidget(groupBox_4);

        painel_objetos->addWidget(page_Cubo);
        page_Esfera = new QWidget();
        page_Esfera->setObjectName(QString::fromUtf8("page_Esfera"));
        verticalLayout = new QVBoxLayout(page_Esfera);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_5 = new QGroupBox(page_Esfera);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        formLayout_3 = new QFormLayout(groupBox_5);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        groupBox_14 = new QGroupBox(groupBox_5);
        groupBox_14->setObjectName(QString::fromUtf8("groupBox_14"));
        sizePolicy3.setHeightForWidth(groupBox_14->sizePolicy().hasHeightForWidth());
        groupBox_14->setSizePolicy(sizePolicy3);
        groupBox_14->setMinimumSize(QSize(140, 0));
        groupBox_14->setMaximumSize(QSize(140, 63));
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
        raio_esfera->setDecimals(3);
        raio_esfera->setMaximum(100);
        raio_esfera->setSingleStep(0.01);
        raio_esfera->setValue(0.014);

        formLayout_15->setWidget(0, QFormLayout::FieldRole, raio_esfera);


        formLayout_3->setWidget(0, QFormLayout::LabelRole, groupBox_14);

        groupBox_Material_6 = new QGroupBox(groupBox_5);
        groupBox_Material_6->setObjectName(QString::fromUtf8("groupBox_Material_6"));
        sizePolicy.setHeightForWidth(groupBox_Material_6->sizePolicy().hasHeightForWidth());
        groupBox_Material_6->setSizePolicy(sizePolicy);
        groupBox_Material_6->setMinimumSize(QSize(150, 0));
        groupBox_Material_6->setMaximumSize(QSize(150, 180));
        groupBox_Material_6->setLayoutDirection(Qt::LeftToRight);
        groupBox_Material_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        gridLayout_18 = new QGridLayout(groupBox_Material_6);
        gridLayout_18->setSpacing(6);
        gridLayout_18->setContentsMargins(11, 11, 11, 11);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        label_82 = new QLabel(groupBox_Material_6);
        label_82->setObjectName(QString::fromUtf8("label_82"));
        label_82->setMinimumSize(QSize(40, 0));
        label_82->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_18->addWidget(label_82, 0, 0, 1, 1);

        label_83 = new QLabel(groupBox_Material_6);
        label_83->setObjectName(QString::fromUtf8("label_83"));
        label_83->setMinimumSize(QSize(40, 0));
        label_83->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_18->addWidget(label_83, 1, 0, 1, 1);

        label_84 = new QLabel(groupBox_Material_6);
        label_84->setObjectName(QString::fromUtf8("label_84"));
        label_84->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_18->addWidget(label_84, 2, 0, 1, 1);

        label_23 = new QLabel(groupBox_Material_6);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_18->addWidget(label_23, 3, 0, 1, 2);

        propriedade_esfera = new QComboBox(groupBox_Material_6);
        propriedade_esfera->setObjectName(QString::fromUtf8("propriedade_esfera"));

        gridLayout_18->addWidget(propriedade_esfera, 4, 0, 1, 2);

        permissividade_esfera = new QLineEdit(groupBox_Material_6);
        permissividade_esfera->setObjectName(QString::fromUtf8("permissividade_esfera"));

        gridLayout_18->addWidget(permissividade_esfera, 0, 1, 1, 1);

        permeabilidade_esfera = new QLineEdit(groupBox_Material_6);
        permeabilidade_esfera->setObjectName(QString::fromUtf8("permeabilidade_esfera"));

        gridLayout_18->addWidget(permeabilidade_esfera, 1, 1, 1, 1);

        condutibilidade_esfera = new QLineEdit(groupBox_Material_6);
        condutibilidade_esfera->setObjectName(QString::fromUtf8("condutibilidade_esfera"));

        gridLayout_18->addWidget(condutibilidade_esfera, 2, 1, 1, 1);


        formLayout_3->setWidget(1, QFormLayout::LabelRole, groupBox_Material_6);


        verticalLayout->addWidget(groupBox_5);

        painel_objetos->addWidget(page_Esfera);
        page_Cilindro = new QWidget();
        page_Cilindro->setObjectName(QString::fromUtf8("page_Cilindro"));
        verticalLayout_6 = new QVBoxLayout(page_Cilindro);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        groupBox_6 = new QGroupBox(page_Cilindro);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        formLayout = new QFormLayout(groupBox_6);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        groupBox_20 = new QGroupBox(groupBox_6);
        groupBox_20->setObjectName(QString::fromUtf8("groupBox_20"));
        sizePolicy3.setHeightForWidth(groupBox_20->sizePolicy().hasHeightForWidth());
        groupBox_20->setSizePolicy(sizePolicy3);
        groupBox_20->setMinimumSize(QSize(140, 0));
        groupBox_20->setMaximumSize(QSize(140, 96));
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


        formLayout->setWidget(0, QFormLayout::LabelRole, groupBox_20);

        groupBox_Material_4 = new QGroupBox(groupBox_6);
        groupBox_Material_4->setObjectName(QString::fromUtf8("groupBox_Material_4"));
        sizePolicy.setHeightForWidth(groupBox_Material_4->sizePolicy().hasHeightForWidth());
        groupBox_Material_4->setSizePolicy(sizePolicy);
        groupBox_Material_4->setMinimumSize(QSize(150, 0));
        groupBox_Material_4->setMaximumSize(QSize(150, 180));
        groupBox_Material_4->setLayoutDirection(Qt::LeftToRight);
        groupBox_Material_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        gridLayout_13 = new QGridLayout(groupBox_Material_4);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        label_76 = new QLabel(groupBox_Material_4);
        label_76->setObjectName(QString::fromUtf8("label_76"));
        label_76->setMinimumSize(QSize(40, 0));
        label_76->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_13->addWidget(label_76, 0, 0, 1, 1);

        label_77 = new QLabel(groupBox_Material_4);
        label_77->setObjectName(QString::fromUtf8("label_77"));
        label_77->setMinimumSize(QSize(40, 0));
        label_77->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_13->addWidget(label_77, 1, 0, 1, 1);

        label_78 = new QLabel(groupBox_Material_4);
        label_78->setObjectName(QString::fromUtf8("label_78"));
        label_78->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_13->addWidget(label_78, 2, 0, 1, 1);

        label_21 = new QLabel(groupBox_Material_4);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_13->addWidget(label_21, 3, 0, 1, 2);

        propriedade_cilindro = new QComboBox(groupBox_Material_4);
        propriedade_cilindro->setObjectName(QString::fromUtf8("propriedade_cilindro"));

        gridLayout_13->addWidget(propriedade_cilindro, 4, 0, 1, 2);

        permissividade_cilindro = new QLineEdit(groupBox_Material_4);
        permissividade_cilindro->setObjectName(QString::fromUtf8("permissividade_cilindro"));

        gridLayout_13->addWidget(permissividade_cilindro, 0, 1, 1, 1);

        permeabilidade_cilindro = new QLineEdit(groupBox_Material_4);
        permeabilidade_cilindro->setObjectName(QString::fromUtf8("permeabilidade_cilindro"));

        gridLayout_13->addWidget(permeabilidade_cilindro, 1, 1, 1, 1);

        condutibilidade_cilindro = new QLineEdit(groupBox_Material_4);
        condutibilidade_cilindro->setObjectName(QString::fromUtf8("condutibilidade_cilindro"));

        gridLayout_13->addWidget(condutibilidade_cilindro, 2, 1, 1, 1);


        formLayout->setWidget(1, QFormLayout::FieldRole, groupBox_Material_4);


        verticalLayout_6->addWidget(groupBox_6);

        painel_objetos->addWidget(page_Cilindro);
        page_cone = new QWidget();
        page_cone->setObjectName(QString::fromUtf8("page_cone"));
        gridLayout_7 = new QGridLayout(page_cone);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        groupBox_7 = new QGroupBox(page_cone);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setMinimumSize(QSize(150, 200));
        gridLayout_17 = new QGridLayout(groupBox_7);
        gridLayout_17->setSpacing(6);
        gridLayout_17->setContentsMargins(11, 11, 11, 11);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        groupBox_2 = new QGroupBox(groupBox_7);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(151, 100));
        groupBox_2->setMaximumSize(QSize(160, 100));
        gridLayout_8 = new QGridLayout(groupBox_2);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_52 = new QLabel(groupBox_2);
        label_52->setObjectName(QString::fromUtf8("label_52"));
        label_52->setMinimumSize(QSize(40, 0));
        label_52->setTextFormat(Qt::AutoText);
        label_52->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_52->setIndent(-1);

        gridLayout_8->addWidget(label_52, 0, 0, 1, 1);

        raio_cone = new QDoubleSpinBox(groupBox_2);
        raio_cone->setObjectName(QString::fromUtf8("raio_cone"));
        raio_cone->setMinimumSize(QSize(60, 0));
        raio_cone->setDecimals(3);
        raio_cone->setMinimum(0);
        raio_cone->setSingleStep(0.01);
        raio_cone->setValue(0.1);

        gridLayout_8->addWidget(raio_cone, 0, 1, 1, 1);

        label_60 = new QLabel(groupBox_2);
        label_60->setObjectName(QString::fromUtf8("label_60"));
        label_60->setMinimumSize(QSize(40, 0));
        label_60->setTextFormat(Qt::AutoText);
        label_60->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_60->setIndent(-1);

        gridLayout_8->addWidget(label_60, 1, 0, 1, 1);

        comprimento_cone = new QDoubleSpinBox(groupBox_2);
        comprimento_cone->setObjectName(QString::fromUtf8("comprimento_cone"));
        comprimento_cone->setDecimals(3);
        comprimento_cone->setSingleStep(0.01);
        comprimento_cone->setValue(0.1);

        gridLayout_8->addWidget(comprimento_cone, 1, 1, 1, 1);


        gridLayout_17->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox_Material_5 = new QGroupBox(groupBox_7);
        groupBox_Material_5->setObjectName(QString::fromUtf8("groupBox_Material_5"));
        sizePolicy.setHeightForWidth(groupBox_Material_5->sizePolicy().hasHeightForWidth());
        groupBox_Material_5->setSizePolicy(sizePolicy);
        groupBox_Material_5->setMinimumSize(QSize(150, 0));
        groupBox_Material_5->setMaximumSize(QSize(150, 180));
        groupBox_Material_5->setLayoutDirection(Qt::LeftToRight);
        groupBox_Material_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        gridLayout_16 = new QGridLayout(groupBox_Material_5);
        gridLayout_16->setSpacing(6);
        gridLayout_16->setContentsMargins(11, 11, 11, 11);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        label_79 = new QLabel(groupBox_Material_5);
        label_79->setObjectName(QString::fromUtf8("label_79"));
        label_79->setMinimumSize(QSize(40, 0));
        label_79->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(label_79, 0, 0, 1, 1);

        label_80 = new QLabel(groupBox_Material_5);
        label_80->setObjectName(QString::fromUtf8("label_80"));
        label_80->setMinimumSize(QSize(40, 0));
        label_80->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(label_80, 1, 0, 1, 1);

        label_81 = new QLabel(groupBox_Material_5);
        label_81->setObjectName(QString::fromUtf8("label_81"));
        label_81->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_16->addWidget(label_81, 2, 0, 1, 1);

        label_22 = new QLabel(groupBox_Material_5);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout_16->addWidget(label_22, 3, 0, 1, 2);

        propriedade_cone = new QComboBox(groupBox_Material_5);
        propriedade_cone->setObjectName(QString::fromUtf8("propriedade_cone"));

        gridLayout_16->addWidget(propriedade_cone, 4, 0, 1, 2);

        permissividade_cone = new QLineEdit(groupBox_Material_5);
        permissividade_cone->setObjectName(QString::fromUtf8("permissividade_cone"));

        gridLayout_16->addWidget(permissividade_cone, 0, 1, 1, 1);

        permeabilidade_cone = new QLineEdit(groupBox_Material_5);
        permeabilidade_cone->setObjectName(QString::fromUtf8("permeabilidade_cone"));

        gridLayout_16->addWidget(permeabilidade_cone, 1, 1, 1, 1);

        condutibilidade_cone = new QLineEdit(groupBox_Material_5);
        condutibilidade_cone->setObjectName(QString::fromUtf8("condutibilidade_cone"));

        gridLayout_16->addWidget(condutibilidade_cone, 2, 1, 1, 1);


        gridLayout_17->addWidget(groupBox_Material_5, 1, 0, 1, 1);


        gridLayout_7->addWidget(groupBox_7, 0, 0, 1, 1);

        painel_objetos->addWidget(page_cone);
        page_EyeAntenna = new QWidget();
        page_EyeAntenna->setObjectName(QString::fromUtf8("page_EyeAntenna"));
        gridLayout_5 = new QGridLayout(page_EyeAntenna);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        painel_objetos->addWidget(page_EyeAntenna);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, painel_objetos);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_2->setItem(3, QFormLayout::LabelRole, verticalSpacer_4);

        scrollArea_1->setWidget(scrollAreaWidgetContents_pnLateral_1);

        verticalLayout_4->addWidget(scrollArea_1);

        painel_lateral->addWidget(page_Objetos);

        grid_Interface->addWidget(painel_lateral, 0, 1, 1, 1);


        gridLayout_15->addLayout(grid_Interface, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 891, 25));
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
#ifndef QT_NO_SHORTCUT
        label_14->setBuddy(raio_haste);
        label_7->setBuddy(haste_inicial_x);
        label_8->setBuddy(haste_inicial_y);
        label_9->setBuddy(haste_inicial_z);
        label_11->setBuddy(haste_final_x);
        label_12->setBuddy(haste_final_y);
        label_10->setBuddy(haste_final_z);
        label_36->setBuddy(cube_dim_X);
        label_37->setBuddy(cube_dim_Y);
        label_38->setBuddy(cube_dim_Z);
        label_39->setBuddy(raio_esfera);
        label_51->setBuddy(raio_cilindro);
        label_57->setBuddy(comprimento_cilindro);
        label_52->setBuddy(raio_cone);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(raio_haste, haste_inicial_x);
        QWidget::setTabOrder(haste_inicial_x, haste_inicial_y);
        QWidget::setTabOrder(haste_inicial_y, haste_inicial_z);
        QWidget::setTabOrder(haste_inicial_z, haste_final_x);
        QWidget::setTabOrder(haste_final_x, haste_final_y);
        QWidget::setTabOrder(haste_final_y, haste_final_z);
        QWidget::setTabOrder(haste_final_z, position_X);
        QWidget::setTabOrder(position_X, position_Y);
        QWidget::setTabOrder(position_Y, position_Z);
        QWidget::setTabOrder(position_Z, GerarMalha);
        QWidget::setTabOrder(GerarMalha, cube_dim_X);
        QWidget::setTabOrder(cube_dim_X, cube_dim_Y);
        QWidget::setTabOrder(cube_dim_Y, cube_dim_Z);
        QWidget::setTabOrder(cube_dim_Z, raio_esfera);
        QWidget::setTabOrder(raio_esfera, raio_cilindro);
        QWidget::setTabOrder(raio_cilindro, comprimento_cilindro);
        QWidget::setTabOrder(comprimento_cilindro, raio_cone);
        QWidget::setTabOrder(raio_cone, comprimento_cone);
        QWidget::setTabOrder(comprimento_cone, scrollArea_0);
        QWidget::setTabOrder(scrollArea_0, doubleSpinBox_XDim_RLIVRE);
        QWidget::setTabOrder(doubleSpinBox_XDim_RLIVRE, doubleSpinBox_YDim_RLIVRE);
        QWidget::setTabOrder(doubleSpinBox_YDim_RLIVRE, doubleSpinBox_ZDim_RLIVRE);
        QWidget::setTabOrder(doubleSpinBox_ZDim_RLIVRE, doubleSpinBox_deltaX_RLIVRE);
        QWidget::setTabOrder(doubleSpinBox_deltaX_RLIVRE, scrollArea_1);
        QWidget::setTabOrder(scrollArea_1, lineEdit_Name);
        QWidget::setTabOrder(lineEdit_Name, PositionButton);
        QWidget::setTabOrder(PositionButton, RotationButton);
        QWidget::setTabOrder(RotationButton, spinBox_4);

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
        toolBar_GeometBasicas->addAction(actionEyeAntenna);

        retranslateUi(MainWindow);
        QObject::connect(GerarMalha, SIGNAL(clicked()), MainWindow, SLOT(gerarMalha()));
        QObject::connect(position_Y, SIGNAL(valueChanged(double)), MainWindow, SLOT(change_position()));
        QObject::connect(position_Z, SIGNAL(valueChanged(double)), MainWindow, SLOT(change_position()));
        QObject::connect(position_X, SIGNAL(valueChanged(double)), MainWindow, SLOT(change_position()));
        QObject::connect(cube_dim_X, SIGNAL(valueChanged(double)), MainWindow, SLOT(set_cube()));
        QObject::connect(cube_dim_Z, SIGNAL(valueChanged(double)), MainWindow, SLOT(set_cube()));
        QObject::connect(raio_cilindro, SIGNAL(valueChanged(double)), MainWindow, SLOT(set_cilindro()));
        QObject::connect(cube_dim_Y, SIGNAL(valueChanged(double)), MainWindow, SLOT(set_cube()));
        QObject::connect(comprimento_cilindro, SIGNAL(valueChanged(double)), MainWindow, SLOT(set_cilindro()));
        QObject::connect(raio_esfera, SIGNAL(valueChanged(double)), MainWindow, SLOT(set_esfera()));
        QObject::connect(raio_cone, SIGNAL(valueChanged(double)), MainWindow, SLOT(set_cone()));
        QObject::connect(comprimento_cone, SIGNAL(valueChanged(double)), MainWindow, SLOT(set_cone()));
        QObject::connect(raio_haste, SIGNAL(valueChanged(double)), MainWindow, SLOT(set_haste()));
        QObject::connect(haste_inicial_x, SIGNAL(valueChanged(double)), MainWindow, SLOT(set_haste()));
        QObject::connect(haste_final_y, SIGNAL(valueChanged(double)), MainWindow, SLOT(set_haste()));
        QObject::connect(haste_inicial_y, SIGNAL(valueChanged(double)), MainWindow, SLOT(set_haste()));
        QObject::connect(haste_inicial_z, SIGNAL(valueChanged(double)), MainWindow, SLOT(set_haste()));
        QObject::connect(haste_final_x, SIGNAL(valueChanged(double)), MainWindow, SLOT(set_material_parametros()));
        QObject::connect(haste_final_z, SIGNAL(valueChanged(double)), MainWindow, SLOT(set_haste()));
        QObject::connect(permissividade_cone, SIGNAL(textChanged(QString)), MainWindow, SLOT(set_cone()));
        QObject::connect(permeabilidade_cone, SIGNAL(textChanged(QString)), MainWindow, SLOT(set_cone()));
        QObject::connect(condutibilidade_cone, SIGNAL(textChanged(QString)), MainWindow, SLOT(set_cone()));
        QObject::connect(permissividade_cubo, SIGNAL(textChanged(QString)), MainWindow, SLOT(set_cube()));
        QObject::connect(permeabilidade_cubo, SIGNAL(textChanged(QString)), MainWindow, SLOT(set_cube()));
        QObject::connect(condutibilidade_cubo, SIGNAL(textChanged(QString)), MainWindow, SLOT(set_cube()));
        QObject::connect(permissividade_esfera, SIGNAL(textChanged(QString)), MainWindow, SLOT(set_esfera()));
        QObject::connect(permeabilidade_esfera, SIGNAL(textChanged(QString)), MainWindow, SLOT(set_esfera()));
        QObject::connect(condutibilidade_esfera, SIGNAL(textChanged(QString)), MainWindow, SLOT(set_esfera()));
        QObject::connect(permissividade_cilindro, SIGNAL(textChanged(QString)), MainWindow, SLOT(set_cilindro()));
        QObject::connect(permeabilidade_cilindro, SIGNAL(textChanged(QString)), MainWindow, SLOT(set_cilindro()));
        QObject::connect(condutibilidade_cilindro, SIGNAL(textChanged(QString)), MainWindow, SLOT(set_cilindro()));

        painel_lateral->setCurrentIndex(1);
        painel_objetos->setCurrentIndex(2);


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
        actionEyeAntenna->setText(QApplication::translate("MainWindow", "Antenna", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionEyeAntenna->setToolTip(QApplication::translate("MainWindow", "Antenna", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
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
        painel_ambiente->setText(QApplication::translate("MainWindow", "AMBIENTE", 0, QApplication::UnicodeUTF8));
        groupBox_15->setTitle(QApplication::translate("MainWindow", "Regi\303\243o de An\303\241lise", 0, QApplication::UnicodeUTF8));
        label_45->setText(QApplication::translate("MainWindow", "Dim X:", 0, QApplication::UnicodeUTF8));
        doubleSpinBox_XDim_RLIVRE->setSuffix(QApplication::translate("MainWindow", " m", 0, QApplication::UnicodeUTF8));
        label_58->setText(QApplication::translate("MainWindow", "Dim Y:", 0, QApplication::UnicodeUTF8));
        doubleSpinBox_YDim_RLIVRE->setSuffix(QApplication::translate("MainWindow", " m", 0, QApplication::UnicodeUTF8));
        label_59->setText(QApplication::translate("MainWindow", "Dim Z:", 0, QApplication::UnicodeUTF8));
        doubleSpinBox_ZDim_RLIVRE->setSuffix(QApplication::translate("MainWindow", " m", 0, QApplication::UnicodeUTF8));
        label_65->setText(QApplication::translate("MainWindow", "delt Med:", 0, QApplication::UnicodeUTF8));
        doubleSpinBox_deltaX_RLIVRE->setSuffix(QApplication::translate("MainWindow", " m", 0, QApplication::UnicodeUTF8));
        label_PainelTitulo_1->setText(QApplication::translate("MainWindow", "OBJETOS", 0, QApplication::UnicodeUTF8));
        groupBox_Identificao->setTitle(QApplication::translate("MainWindow", "Identifca\303\247\303\243o", 0, QApplication::UnicodeUTF8));
        label_40->setText(QApplication::translate("MainWindow", "Nome:", 0, QApplication::UnicodeUTF8));
        label_41->setText(QApplication::translate("MainWindow", "n\302\272:", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QString());
        groupBox->setTitle(QApplication::translate("MainWindow", "Dimension", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "raio:", 0, QApplication::UnicodeUTF8));
        raio_haste->setSuffix(QApplication::translate("MainWindow", "mm", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Inicial", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "X:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Y:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Z:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "Final", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "X:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "Y:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Z:", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QString());
        groupBox_13->setTitle(QApplication::translate("MainWindow", "Dimens\303\265es", 0, QApplication::UnicodeUTF8));
        label_36->setText(QApplication::translate("MainWindow", "X:", 0, QApplication::UnicodeUTF8));
        cube_dim_X->setSuffix(QApplication::translate("MainWindow", " m", 0, QApplication::UnicodeUTF8));
        label_37->setText(QApplication::translate("MainWindow", "Y:", 0, QApplication::UnicodeUTF8));
        cube_dim_Y->setSuffix(QApplication::translate("MainWindow", " m", 0, QApplication::UnicodeUTF8));
        label_38->setText(QApplication::translate("MainWindow", "Z:", 0, QApplication::UnicodeUTF8));
        cube_dim_Z->setSuffix(QApplication::translate("MainWindow", " m", 0, QApplication::UnicodeUTF8));
        groupBox_Material_3->setTitle(QApplication::translate("MainWindow", "Materiais", 0, QApplication::UnicodeUTF8));
        label_73->setText(QApplication::translate("MainWindow", "P.E:", 0, QApplication::UnicodeUTF8));
        label_74->setText(QApplication::translate("MainWindow", "P.M:", 0, QApplication::UnicodeUTF8));
        label_75->setText(QApplication::translate("MainWindow", "C:", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindow", "Propriedade:", 0, QApplication::UnicodeUTF8));
        propriedade_cube->clear();
        propriedade_cube->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "NONE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Metal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Medi\303\247\303\243o", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Fonte", 0, QApplication::UnicodeUTF8)
        );
        permissividade_cubo->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        permeabilidade_cubo->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        condutibilidade_cubo->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "GroupBox", 0, QApplication::UnicodeUTF8));
        groupBox_14->setTitle(QApplication::translate("MainWindow", "Dimension", 0, QApplication::UnicodeUTF8));
        label_39->setText(QApplication::translate("MainWindow", "raio:", 0, QApplication::UnicodeUTF8));
        raio_esfera->setSuffix(QApplication::translate("MainWindow", " m", 0, QApplication::UnicodeUTF8));
        groupBox_Material_6->setTitle(QApplication::translate("MainWindow", "Materiais", 0, QApplication::UnicodeUTF8));
        label_82->setText(QApplication::translate("MainWindow", "P.E:", 0, QApplication::UnicodeUTF8));
        label_83->setText(QApplication::translate("MainWindow", "P.M:", 0, QApplication::UnicodeUTF8));
        label_84->setText(QApplication::translate("MainWindow", "C:", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("MainWindow", "Propriedade:", 0, QApplication::UnicodeUTF8));
        propriedade_esfera->clear();
        propriedade_esfera->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "NONE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Metal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Medi\303\247\303\243o", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Fonte", 0, QApplication::UnicodeUTF8)
        );
        permissividade_esfera->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        permeabilidade_esfera->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        condutibilidade_esfera->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "GroupBox", 0, QApplication::UnicodeUTF8));
        groupBox_20->setTitle(QApplication::translate("MainWindow", "Dimension", 0, QApplication::UnicodeUTF8));
        label_51->setText(QApplication::translate("MainWindow", "raio:", 0, QApplication::UnicodeUTF8));
        raio_cilindro->setSuffix(QApplication::translate("MainWindow", " m", 0, QApplication::UnicodeUTF8));
        label_57->setText(QApplication::translate("MainWindow", "comp:", 0, QApplication::UnicodeUTF8));
        comprimento_cilindro->setSuffix(QApplication::translate("MainWindow", " m", 0, QApplication::UnicodeUTF8));
        groupBox_Material_4->setTitle(QApplication::translate("MainWindow", "Materiais", 0, QApplication::UnicodeUTF8));
        label_76->setText(QApplication::translate("MainWindow", "P.E:", 0, QApplication::UnicodeUTF8));
        label_77->setText(QApplication::translate("MainWindow", "P.M:", 0, QApplication::UnicodeUTF8));
        label_78->setText(QApplication::translate("MainWindow", "C:", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindow", "Propriedade:", 0, QApplication::UnicodeUTF8));
        propriedade_cilindro->clear();
        propriedade_cilindro->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "NONE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Metal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Medi\303\247\303\243o", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Fonte", 0, QApplication::UnicodeUTF8)
        );
        permissividade_cilindro->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        permeabilidade_cilindro->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        condutibilidade_cilindro->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "GroupBox", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Dimension", 0, QApplication::UnicodeUTF8));
        label_52->setText(QApplication::translate("MainWindow", "raio:", 0, QApplication::UnicodeUTF8));
        raio_cone->setSuffix(QApplication::translate("MainWindow", " m", 0, QApplication::UnicodeUTF8));
        label_60->setText(QApplication::translate("MainWindow", "comp:", 0, QApplication::UnicodeUTF8));
        comprimento_cone->setSuffix(QApplication::translate("MainWindow", " m", 0, QApplication::UnicodeUTF8));
        groupBox_Material_5->setTitle(QApplication::translate("MainWindow", "Materiais", 0, QApplication::UnicodeUTF8));
        label_79->setText(QApplication::translate("MainWindow", "P.E:", 0, QApplication::UnicodeUTF8));
        label_80->setText(QApplication::translate("MainWindow", "P.M:", 0, QApplication::UnicodeUTF8));
        label_81->setText(QApplication::translate("MainWindow", "C:", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MainWindow", "Propriedade:", 0, QApplication::UnicodeUTF8));
        propriedade_cone->clear();
        propriedade_cone->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "NONE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Metal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Medi\303\247\303\243o", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Fonte", 0, QApplication::UnicodeUTF8)
        );
        permissividade_cone->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        permeabilidade_cone->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        condutibilidade_cone->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        toolBar_Manipulador->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
        toolBar_GeometBasicas->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
