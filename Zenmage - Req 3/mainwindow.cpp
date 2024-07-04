#include "mainwindow.h"

#include <QImageReader>
#include <QPixmap>
#include <QMenuBar>
#include <QMenu>
#include <QAction>

#include <QApplication>
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(QGuiApplication::primaryScreen()->availableGeometry().size());
    setupMenu();

    QWidget *centralWidget = new QWidget(this);

    layout = new QFormLayout(centralWidget);
    comboBox = new QComboBox();
    comboBox -> setPlaceholderText("Select an item");

    imgLabel = new QLabel();
    scrollArea = new QScrollArea();
    scrollArea -> setWidget(imgLabel);

    label = new QLabel("Enter new colour box item:");
    output = new QLabel("Selected items:");

    layout -> addRow(label);
    layout -> addRow(comboBox);
    layout -> addRow(output);
    layout -> addRow(scrollArea);

    setCentralWidget(centralWidget);

    QObject::connect(comboBox, SIGNAL(currentTextChanged(QString)),this,SLOT(loadImage(QString)));
}

void MainWindow::setupMenu()
{
    QAction *openAct = new QAction("&Open",this);
    QAction *quitAct = new QAction("&Quit",this);

    QMenu *fileMenu = menuBar()->addMenu("&File");
    fileMenu -> addAction(openAct);
    fileMenu -> addAction(quitAct);

    QObject::connect(openAct, &QAction::triggered, this, &MainWindow::openFileDialog);
    QObject::connect(quitAct, &QAction::triggered, qApp, QApplication::quit);
}

void MainWindow::loadImage(const QString &filePath)
{
    QImageReader reader(filePath);
    reader.setAutoTransform(true);

    const QImage image = reader.read();

    if(!image.isNull())
    {
        imgLabel->setPixmap(QPixmap::fromImage(image));
        imgLabel->adjustSize();
    }
}

void MainWindow::openFileDialog()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::ExistingFiles);
    dialog.setNameFilter("Images (*.jpg *.png *.jpeg)");
    dialog.setViewMode(QFileDialog::Detail);
    QStringList fileNames;
    if(dialog.exec())
    {
        fileNames = dialog.selectedFiles();
        comboBox -> addItems(fileNames);
    }
}

MainWindow::~MainWindow()
{


}
