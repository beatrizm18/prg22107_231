#ifndef MINEBUTTON_H
#define MINEBUTTON_H

#include <QPushButton>
#include <QMouseEvent>

class MineButton : public QPushButton
{
    Q_OBJECT

public:
    MineButton(QWidget *parent = 0);

protected:
    void mouseReleaseEvent(QMouseEvent *e);

private:
    bool _marked;
};

#endif // MINEBUTTON_H
