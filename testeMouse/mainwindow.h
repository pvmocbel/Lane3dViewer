#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "irrqwidget.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
     void init();

protected:
    void changeEvent(QEvent *e);
    
private:
    Ui::MainWindow *ui;
    IrrQWidget *irrwindows;
};

#endif // MAINWINDOW_H
