#include "cell_bookmgr.h"
#include "ui_cell_bookmgr.h"

Cell_BookMgr::Cell_BookMgr(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Cell_BookMgr)
{
    ui->setupUi(this);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//对数据封装，不可更改
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows); //单行选取
}

Cell_BookMgr::~Cell_BookMgr()
{
    delete ui;
}
