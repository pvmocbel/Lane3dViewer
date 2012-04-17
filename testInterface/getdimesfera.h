#ifndef GETDIMESFERA_H
#define GETDIMESFERA_H
#include "irrviewer.h"
#include <QDialog>

namespace Ui {
    class getDimEsfera;
}

class getDimEsfera : public QDialog
{
    Q_OBJECT

public:
    explicit getDimEsfera(QWidget *parent = 0);
    ~getDimEsfera();
    Pos3df getPosition();
    double getDimension();

public slots:
    void parser();
    void abort();

private:
    Ui::getDimEsfera *ui;
    Pos3df position;
    double raio;
};

#endif // GETDIMESFERA_H
