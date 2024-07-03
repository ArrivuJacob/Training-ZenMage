#include "mainwindow.h"
#include <QLabel>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *widget = new QWidget();

    QLabel *lbl1 =new QLabel("Label 1");
    QLabel *lbl2 =new QLabel("Label 2");
    QLabel *lbl3 =new QLabel("Label 3");

    lbl1 -> setObjectName ("Label 1");
    lbl2 -> setObjectName ("Label 2");
    lbl3 -> setObjectName ("Label 3");

    layout = new QFormLayout(widget);
    box = new QVBoxLayout();

    box -> addWidget(lbl1);
    box -> addWidget(lbl2);
    box -> addWidget(lbl3);

    QPushButton *btn = new QPushButton("Remove Box");
    textArea = new QPlainTextEdit();

    layout -> addRow(box);
    layout -> addRow(btn);
    layout -> addRow(textArea);

    setCentralWidget(widget);

    QObject::connect(lbl1, SIGNAL(destroyed(QObject*)),this,SLOT(logObjectDestroyed(QObject*)));
    QObject::connect(lbl2, SIGNAL(destroyed(QObject*)),this,SLOT(logObjectDestroyed(QObject*)));
    QObject::connect(lbl3, SIGNAL(destroyed(QObject*)),this,SLOT(logObjectDestroyed(QObject*)));

    QObject::connect(btn, SIGNAL(clicked()), this, SLOT(removeBox()));
}

void MainWindow::logObjectDestroyed(QObject *obj)
{
    textArea -> appendPlainText(obj -> objectName() + " Destroyed");
}

void MainWindow::removeBox()
{
    layout -> removeRow(box);
}

MainWindow::~MainWindow() {}
