#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "irrqwidget.h"
#include<Qt/qstackedwidget.h>

namespace Ui { class MainWindow;}

class MainWindow : public QMainWindow
{
    Q_OBJECT
protected:
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void init();
    void cria_cubo();
    void cria_linha();
    void cria_cone();
    void cria_esfera();

    virtual void paintEvent( QPaintEvent *event );
    virtual void resizeEvent(QResizeEvent *event);
private:
    Ui::MainWindow *ui;
    IrrQWidget *irrwindows;
    QVBoxLayout layout;
    QPaintEvent *evento;
    int n;
};
#endif // MAINWINDOW_H
