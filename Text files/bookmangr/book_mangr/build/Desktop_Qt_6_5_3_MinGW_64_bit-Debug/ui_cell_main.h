/********************************************************************************
** Form generated from reading UI file 'cell_main.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CELL_MAIN_H
#define UI_CELL_MAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Cell_Main
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QWidget *tool;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QToolButton *btn_record;
    QToolButton *btn_his;
    QToolButton *btn_book;
    QToolButton *btn_user;
    QStackedWidget *stackedWidget;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *Cell_Main)
    {
        if (Cell_Main->objectName().isEmpty())
            Cell_Main->setObjectName("Cell_Main");
        Cell_Main->resize(800, 600);
        centralwidget = new QWidget(Cell_Main);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        tool = new QWidget(centralwidget);
        tool->setObjectName("tool");
        tool->setMaximumSize(QSize(120, 16777215));
        gridLayout = new QGridLayout(tool);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 0, 1, 1);

        btn_record = new QToolButton(tool);
        buttonGroup = new QButtonGroup(Cell_Main);
        buttonGroup->setObjectName("buttonGroup");
        buttonGroup->addButton(btn_record);
        btn_record->setObjectName("btn_record");

        gridLayout->addWidget(btn_record, 3, 0, 1, 1);

        btn_his = new QToolButton(tool);
        buttonGroup->addButton(btn_his);
        btn_his->setObjectName("btn_his");

        gridLayout->addWidget(btn_his, 2, 0, 1, 1);

        btn_book = new QToolButton(tool);
        buttonGroup->addButton(btn_book);
        btn_book->setObjectName("btn_book");

        gridLayout->addWidget(btn_book, 1, 0, 1, 1);

        btn_user = new QToolButton(tool);
        buttonGroup->addButton(btn_user);
        btn_user->setObjectName("btn_user");

        gridLayout->addWidget(btn_user, 0, 0, 1, 1);


        gridLayout_2->addWidget(tool, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");

        gridLayout_2->addWidget(stackedWidget, 0, 1, 1, 1);

        Cell_Main->setCentralWidget(centralwidget);

        retranslateUi(Cell_Main);

        QMetaObject::connectSlotsByName(Cell_Main);
    } // setupUi

    void retranslateUi(QMainWindow *Cell_Main)
    {
        Cell_Main->setWindowTitle(QCoreApplication::translate("Cell_Main", "Cell_Main", nullptr));
        btn_record->setText(QCoreApplication::translate("Cell_Main", "\345\200\237\351\226\261\350\250\230\351\214\204", nullptr));
        btn_his->setText(QCoreApplication::translate("Cell_Main", "\345\200\237\351\226\261\347\256\241\347\220\206", nullptr));
        btn_book->setText(QCoreApplication::translate("Cell_Main", "\345\234\226\346\233\270\347\256\241\347\220\206", nullptr));
        btn_user->setText(QCoreApplication::translate("Cell_Main", "\347\224\250\346\210\266\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Cell_Main: public Ui_Cell_Main {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CELL_MAIN_H
