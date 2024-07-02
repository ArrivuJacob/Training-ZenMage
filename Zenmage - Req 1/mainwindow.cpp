#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    layout = new QFormLayout(centralWidget);
    lineEdit = new QLineEdit();
    button = new QPushButton("Add");
    comboBox = new QComboBox();
    comboBox -> setPlaceholderText("Select an item");

    textArea = new QPlainTextEdit();
    textArea -> setReadOnly(true);

    label = new QLabel("Enter new colour box item:");
    output = new QLabel("Selected items:");



    layout -> addRow(label);
    layout -> addRow(lineEdit);
    layout -> addRow(button);
    layout -> addRow(comboBox);
    layout -> addRow(output);
    layout -> addRow(textArea);

    setCentralWidget(centralWidget);

    QObject::connect(button, SIGNAL(clicked(bool)),this,SLOT(addIntoComboBox()));
    QObject::connect(comboBox, SIGNAL(currentTextChanged(QString)),this,SLOT(insertIntoTextBlock(QString)));
}

void MainWindow::addIntoComboBox()
{
    comboBox -> addItem(lineEdit -> text());
}

void MainWindow::insertIntoTextBlock(const QString &text)
{
    textArea -> appendPlainText(text);
}

MainWindow::~MainWindow()
{


}
