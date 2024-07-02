#include "mainwindow.h"
#include <QImageReader>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    layout = new QFormLayout(centralWidget);
    lineEdit = new QLineEdit();
    addButton = new QPushButton("Add");
    chooseFileButton = new QPushButton("Choose Image File");
    comboBox = new QComboBox();
    comboBox -> setPlaceholderText("Select an item");
    imgLabel = new QLabel();

    //textArea = new QPlainTextEdit();
    //textArea -> setReadOnly(true);

    label = new QLabel("Enter new colour box item:");
    output = new QLabel("Selected items:");


    layout -> addRow(label);
    layout -> addRow(lineEdit);
    layout -> addRow(chooseFileButton);
    layout -> addRow(addButton);
    layout -> addRow(comboBox);
    layout -> addRow(output);
    layout -> addRow(imgLabel);

    setCentralWidget(centralWidget);

    QObject::connect(chooseFileButton, SIGNAL(clicked(bool)),this,SLOT(openFileDialog()));
    QObject::connect(addButton, SIGNAL(clicked(bool)),this,SLOT(addIntoComboBox()));
    QObject::connect(comboBox, SIGNAL(currentTextChanged(QString)),this,SLOT(loadImage(QString)));
}

void MainWindow::addIntoComboBox()
{

    comboBox -> addItem(lineEdit -> text());
}

void MainWindow::loadImage(const QString &filePath)
{
    QImageReader reader(filePath);
    reader.setAutoTransform(true);

    const QImage image = reader.read();

    if(!image.isNull())
    {
        imgLabel->setPixmap(QPixmap::fromImage(image));
    }
}

void MainWindow::openFileDialog()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setNameFilter("Images (*.jpg *.png *.jpeg)");
    dialog.setViewMode(QFileDialog::Detail);
    QStringList fileName;
    if(dialog.exec())
    {
        fileName = dialog.selectedFiles();
        lineEdit -> setText(fileName.join(", "));
    }
}

MainWindow::~MainWindow()
{


}
