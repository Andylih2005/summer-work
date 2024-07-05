/********************************************************************************
** Form generated from reading UI file 'cell_usermgr.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CELL_USERMGR_H
#define UI_CELL_USERMGR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Cell_Usermgr
{
public:
    QTableView *tableView;
    QWidget *widget;
    QLabel *label_2;
    QWidget *widget1;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *Cell_Usermgr)
    {
        if (Cell_Usermgr->objectName().isEmpty())
            Cell_Usermgr->setObjectName("Cell_Usermgr");
        Cell_Usermgr->resize(528, 326);
        tableView = new QTableView(Cell_Usermgr);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(40, 100, 421, 192));
        widget = new QWidget(Cell_Usermgr);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 10, 451, 80));
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 0, 40, 12));
        widget1 = new QWidget(widget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(10, 30, 391, 48));
        gridLayout = new QGridLayout(widget1);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget1);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 0, 2, 1, 1);

        label = new QLabel(widget1);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(widget1);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout->addWidget(pushButton_2, 0, 3, 1, 1);

        lineEdit = new QLineEdit(widget1);
        lineEdit->setObjectName("lineEdit");

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 4, 1, 1);


        retranslateUi(Cell_Usermgr);

        QMetaObject::connectSlotsByName(Cell_Usermgr);
    } // setupUi

    void retranslateUi(QWidget *Cell_Usermgr)
    {
        Cell_Usermgr->setWindowTitle(QCoreApplication::translate("Cell_Usermgr", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("Cell_Usermgr", "userMgr", nullptr));
        pushButton->setText(QCoreApplication::translate("Cell_Usermgr", "\347\224\250\346\210\266\345\260\216\345\205\245", nullptr));
        label->setText(QCoreApplication::translate("Cell_Usermgr", "\346\220\234\347\264\242", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Cell_Usermgr", "\345\210\252\351\231\244\347\224\250\346\210\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Cell_Usermgr: public Ui_Cell_Usermgr {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CELL_USERMGR_H
