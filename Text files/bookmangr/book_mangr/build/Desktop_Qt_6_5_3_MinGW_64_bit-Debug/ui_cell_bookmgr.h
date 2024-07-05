/********************************************************************************
** Form generated from reading UI file 'cell_bookmgr.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CELL_BOOKMGR_H
#define UI_CELL_BOOKMGR_H

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

class Ui_Cell_BookMgr
{
public:
    QTableView *tableView;
    QWidget *widget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QLabel *label_2;

    void setupUi(QWidget *Cell_BookMgr)
    {
        if (Cell_BookMgr->objectName().isEmpty())
            Cell_BookMgr->setObjectName("Cell_BookMgr");
        Cell_BookMgr->resize(578, 317);
        tableView = new QTableView(Cell_BookMgr);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(30, 91, 521, 211));
        widget = new QWidget(Cell_BookMgr);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 20, 541, 51));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 5, 1, 1);

        label = new QLabel(widget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 0, 2, 1, 1);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout->addWidget(pushButton_2, 0, 3, 1, 1);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName("pushButton_3");

        gridLayout->addWidget(pushButton_3, 0, 4, 1, 1);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName("pushButton_5");

        gridLayout->addWidget(pushButton_5, 1, 2, 1, 1);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName("pushButton_4");

        gridLayout->addWidget(pushButton_4, 1, 3, 1, 1);

        label_2 = new QLabel(Cell_BookMgr);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 10, 40, 12));

        retranslateUi(Cell_BookMgr);

        QMetaObject::connectSlotsByName(Cell_BookMgr);
    } // setupUi

    void retranslateUi(QWidget *Cell_BookMgr)
    {
        Cell_BookMgr->setWindowTitle(QCoreApplication::translate("Cell_BookMgr", "Form", nullptr));
        label->setText(QCoreApplication::translate("Cell_BookMgr", "search", nullptr));
        pushButton->setText(QCoreApplication::translate("Cell_BookMgr", "\345\242\236\345\212\240", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Cell_BookMgr", "\344\277\256\346\224\271", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Cell_BookMgr", "\345\210\252\351\231\244", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Cell_BookMgr", "\345\200\237\351\226\261", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Cell_BookMgr", "\346\255\270\351\202\204", nullptr));
        label_2->setText(QCoreApplication::translate("Cell_BookMgr", "bookMGR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Cell_BookMgr: public Ui_Cell_BookMgr {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CELL_BOOKMGR_H
