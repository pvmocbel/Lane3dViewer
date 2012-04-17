#ifndef GETDIMCILINDRO_H
#define GETDIMCILINDRO_H
#include "irrviewer.h"
#include <QDialog>

namespace Ui {
    class getDimCilindro;
}

class getDimCilindro : public QDialog
{
    Q_OBJECT

public:
    explicit getDimCilindro(QWidget *parent = 0);
    ~getDimCilindro();
    Pos3df getPosition();
    Dim3df getDimension();

public slots:
    void parser();
    void abort();

private:
    Ui::getDimCilindro *ui;
    Pos3df position;
    Dim3df dimension;

};

#endif // GETDIMCILINDRO_H
