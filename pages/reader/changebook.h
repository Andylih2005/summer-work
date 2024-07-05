#ifndef CHANGEBOOK_H
#define CHANGEBOOK_H

#include <QWidget>

namespace Ui {
class changebook;
}

class changebook : public QWidget
{
    Q_OBJECT

public:
    explicit changebook(QWidget *parent = nullptr);
    ~changebook();

private:
    Ui::changebook *ui;
};

#endif // CHANGEBOOK_H
