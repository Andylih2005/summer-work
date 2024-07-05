#ifndef CELL_USERMGR_H
#define CELL_USERMGR_H

#include <QWidget>
#include <qstandarditemmodel.h>

namespace Ui {
class Cell_Usermgr;
}

class Cell_Usermgr : public QWidget
{
    Q_OBJECT

public:
    explicit Cell_Usermgr(QWidget *parent = nullptr);
    ~Cell_Usermgr();

private:
    Ui::Cell_Usermgr *ui;
    QStandardItemModel m_model;
};

#endif // CELL_USERMGR_H
