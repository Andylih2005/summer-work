#ifndef INPUTBOOK_H
#define INPUTBOOK_H

#include <QWidget>

namespace Ui {
class inputbook;
}

class inputbook : public QWidget
{
    Q_OBJECT

public:
    explicit inputbook(QWidget *parent = nullptr);
    ~inputbook();

private:
    Ui::inputbook *ui;
};

#endif // INPUTBOOK_H
