#ifndef CHECKBOOK_H
#define CHECKBOOK_H

#include <QWidget>

namespace Ui {
class checkbook;
}

class checkbook : public QWidget
{
    Q_OBJECT

public:
    explicit checkbook(QWidget *parent = nullptr);
    ~checkbook();

private:
    Ui::checkbook *ui;
};

#endif // CHECKBOOK_H
