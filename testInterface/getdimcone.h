#ifndef GETDIMCONE_H
#define GETDIMCONE_H
#include "irrviewer.h"
#include <QDialog>

namespace Ui {
    class getDimCone;
}

class getDimCone : public QDialog
{
    Q_OBJECT

public:
    explicit getDimCone(QWidget *parent = 0);
    ~getDimCone();
    Pos3df getPosition();
    Dim3df getDimension();

public slots:
    void parser();
    void abort();

private:
    Ui::getDimCone *ui;
    Pos3df position;
    Dim3df dimension;

};

#endif // GETDIMCONE_H
