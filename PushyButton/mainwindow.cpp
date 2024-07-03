#include "mainwindow.h"
#include "qpushybutton.h"

#include <QFormLayout>
#include <QPlainTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *widget = new QWidget();

    QFormLayout *layout = new QFormLayout(widget);

    QPushyButton *btn = new QPushyButton();
    btn -> setText("Press Me");
    btn -> setTriggerText(("Don't press me "));

    QPlainTextEdit *textArea = new QPlainTextEdit();

    layout -> addRow(btn);
    layout -> addRow(textArea);

    setCentralWidget(widget);

    QObject::connect(btn,SIGNAL(gotTrigger(QString)),textArea,SLOT(appendPlainText(QString)));
}

MainWindow::~MainWindow() {}
