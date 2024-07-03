#ifndef QPUSHYBUTTON_H
#define QPUSHYBUTTON_H

#include <QPushButton>

class QPushyButton: public QPushButton
{
    Q_OBJECT
public:
    explicit QPushyButton(QWidget *parent = nullptr);

signals:
    void gotTrigger(const QString &text);

public slots:
    void setTriggerText(const QString &text);

private:
    QString triggerText;
};

#endif // QPUSHYBUTTON_H
