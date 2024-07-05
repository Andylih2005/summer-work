#include "cell_usermgr.h"
#include "ui_cell_usermgr.h"

Cell_Usermgr::Cell_Usermgr(QWidget *parent)
    : QWidget(parent)
    ,ui(new Ui::Cell_Usermgr)
{
    ui->setupUi(this);
    ui->tableView->setModel(&m_model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//对数据封装，不可更改
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows); //单行选取
    m_model.setHorizontalHeaderLabels(QStringList{"用户id","密码","昵称","权限","信用"});

#if 1
    for(int i=0;i<10;i++)
    {
        QList<QStandardItem*>items;
        items.append(new QStandardItem("1"));
        items.append(new QStandardItem("123"));
        items.append(new QStandardItem("你妈s"));
        items.append(new QStandardItem("学生"));
        items.append(new QStandardItem("1"));
        m_model.appendRow(items);
    }
#endif  
}

Cell_Usermgr::~Cell_Usermgr()
{
    delete ui;
}



