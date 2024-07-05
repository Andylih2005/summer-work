#ifndef CELL_BOOKMGR_H
#define CELL_BOOKMGR_H

#include <QWidget>

namespace Ui {
class Cell_BookMgr;
}

class Cell_BookMgr : public QWidget
{
    Q_OBJECT

public:
    explicit Cell_BookMgr(QWidget *parent = nullptr);
    ~Cell_BookMgr();

private:
    Ui::Cell_BookMgr *ui;
};

#endif // CELL_BOOKMGR_H
