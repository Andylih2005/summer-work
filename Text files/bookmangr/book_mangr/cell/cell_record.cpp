#include "cell_record.h"
#include "ui_cell_record.h"

Cell_Record::Cell_Record(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Cell_Record)
{
    ui->setupUi(this);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//对数据封装，不可更改
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows); //单行选取
}

Cell_Record::~Cell_Record()
{
    delete ui;
}
