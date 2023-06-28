#include "minebutton.h"

MineButton::MineButton(QWidget *parent): QPushButton(parent)
{
    _marked = false;
}

void MineButton::mouseReleaseEvent(QMouseEvent *e) {
    if (e->button() == Qt::RightButton) {
        if(_marked){
            this->setText("");
            _marked = false;
        } else {
            this->setText("*");
            _marked = true;
        }
    }
    else if (e->button() == Qt::LeftButton) emit clicked();
}
