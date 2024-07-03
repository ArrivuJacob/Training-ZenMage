#include "qpushybutton.h"

QPushyButton::QPushyButton(QWidget *parent)
    : QPushButton{parent}
{
    QObject::connect(this,&QPushyButton::clicked, this, [=]() { emit gotTrigger(triggerText);});
}

void QPushyButton::setTriggerText(const QString &text)
{
    triggerText = text;
}
