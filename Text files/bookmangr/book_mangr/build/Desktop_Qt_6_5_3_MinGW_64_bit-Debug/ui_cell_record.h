/********************************************************************************
** Form generated from reading UI file 'cell_record.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CELL_RECORD_H
#define UI_CELL_RECORD_H

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

class Ui_Cell_Record
{
public:
    QWidget *widget;
    QGridLayout *gridLayout_5;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_23;
    QLabel *label_6;
    QTableView *tableView;

    void setupUi(QWidget *Cell_Record)
    {
        if (Cell_Record->objectName().isEmpty())
            Cell_Record->setObjectName("Cell_Record");
        Cell_Record->resize(494, 311);
        widget = new QWidget(Cell_Record);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(50, 30, 321, 51));
        gridLayout_5 = new QGridLayout(widget);
        gridLayout_5->setObjectName("gridLayout_5");
        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");

        gridLayout_5->addWidget(label_5, 0, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_5, 0, 3, 1, 1);

        lineEdit_5 = new QLineEdit(widget);
        lineEdit_5->setObjectName("lineEdit_5");

        gridLayout_5->addWidget(lineEdit_5, 0, 1, 1, 1);

        pushButton_23 = new QPushButton(widget);
        pushButton_23->setObjectName("pushButton_23");

        gridLayout_5->addWidget(pushButton_23, 0, 2, 1, 1);

        label_6 = new QLabel(Cell_Record);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(40, 20, 40, 12));
        tableView = new QTableView(Cell_Record);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(60, 101, 371, 181));

        retranslateUi(Cell_Record);

        QMetaObject::connectSlotsByName(Cell_Record);
    } // setupUi

    void retranslateUi(QWidget *Cell_Record)
    {
        Cell_Record->setWindowTitle(QCoreApplication::translate("Cell_Record", "Form", nullptr));
        label_5->setText(QCoreApplication::translate("Cell_Record", "search", nullptr));
        pushButton_23->setText(QCoreApplication::translate("Cell_Record", "\345\210\252\351\231\244\350\250\230\351\214\204", nullptr));
        label_6->setText(QCoreApplication::translate("Cell_Record", "\345\200\237\351\226\261\350\250\230\351\214\204", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Cell_Record: public Ui_Cell_Record {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CELL_RECORD_H
