/********************************************************************************
** Form generated from reading UI file 'dlg_login.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLG_LOGIN_H
#define UI_DLG_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DLG_Login
{
public:
    QGridLayout *gridLayout;
    QWidget *bg;
    QGridLayout *gridLayout_2;
    QLineEdit *le_user;
    QLabel *lb_txt2;
    QLineEdit *le_pass;
    QPushButton *btn_login;
    QPushButton *btn_exit;
    QLabel *lb_tittle;
    QLabel *lb_txt1;

    void setupUi(QDialog *DLG_Login)
    {
        if (DLG_Login->objectName().isEmpty())
            DLG_Login->setObjectName("DLG_Login");
        DLG_Login->resize(400, 300);
        gridLayout = new QGridLayout(DLG_Login);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        bg = new QWidget(DLG_Login);
        bg->setObjectName("bg");
        gridLayout_2 = new QGridLayout(bg);
        gridLayout_2->setObjectName("gridLayout_2");
        le_user = new QLineEdit(bg);
        le_user->setObjectName("le_user");

        gridLayout_2->addWidget(le_user, 1, 3, 1, 1);

        lb_txt2 = new QLabel(bg);
        lb_txt2->setObjectName("lb_txt2");

        gridLayout_2->addWidget(lb_txt2, 2, 1, 1, 1);

        le_pass = new QLineEdit(bg);
        le_pass->setObjectName("le_pass");

        gridLayout_2->addWidget(le_pass, 2, 3, 1, 1);

        btn_login = new QPushButton(bg);
        btn_login->setObjectName("btn_login");

        gridLayout_2->addWidget(btn_login, 3, 0, 1, 3);

        btn_exit = new QPushButton(bg);
        btn_exit->setObjectName("btn_exit");

        gridLayout_2->addWidget(btn_exit, 3, 3, 1, 1);

        lb_tittle = new QLabel(bg);
        lb_tittle->setObjectName("lb_tittle");
        lb_tittle->setMaximumSize(QSize(16777215, 60));
        lb_tittle->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lb_tittle, 0, 0, 1, 4);

        lb_txt1 = new QLabel(bg);
        lb_txt1->setObjectName("lb_txt1");

        gridLayout_2->addWidget(lb_txt1, 1, 1, 1, 1);


        gridLayout->addWidget(bg, 0, 0, 1, 1);


        retranslateUi(DLG_Login);

        QMetaObject::connectSlotsByName(DLG_Login);
    } // setupUi

    void retranslateUi(QDialog *DLG_Login)
    {
        DLG_Login->setWindowTitle(QCoreApplication::translate("DLG_Login", "Dialog", nullptr));
        lb_txt2->setText(QCoreApplication::translate("DLG_Login", "\345\257\206\347\242\274", nullptr));
        btn_login->setText(QCoreApplication::translate("DLG_Login", "\347\231\273\351\214\204", nullptr));
        btn_exit->setText(QCoreApplication::translate("DLG_Login", "\351\200\200\345\207\272", nullptr));
        lb_tittle->setText(QCoreApplication::translate("DLG_Login", "\345\234\226\346\233\270\347\256\241\347\220\206\347\263\273\347\265\261", nullptr));
        lb_txt1->setText(QCoreApplication::translate("DLG_Login", "\347\224\250\346\210\266\345\220\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DLG_Login: public Ui_DLG_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLG_LOGIN_H
