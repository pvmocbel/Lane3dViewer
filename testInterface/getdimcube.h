#ifndef getDimCube_H
#define getDimCube_H
#include "irrviewer.h"
#include <QDialog>

namespace Ui {
    class getDimCube;
}

class getDimCube : public QDialog
{
    Q_OBJECT

public:
    explicit getDimCube(QWidget *parent = 0);
    ~getDimCube();
    Pos3df getPosition();
    Dim3df getDimension();
    bool isOk();

public slots:
    void parser();
    void abort();

private:
    Pos3df position;
    Dim3df dimension;
    bool ok;
    Ui::getDimCube *ui;
};

#endif // getDimCube_H
