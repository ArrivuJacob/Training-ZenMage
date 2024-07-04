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
    //resize(QGuiApplication::primaryScreen()->availableGeometry().size());
    resize(1000,600);
    setupMenu();

    QWidget *centralWidget = new QWidget(this);

    layout = new QFormLayout(centralWidget);

    imgLabel = new QLabel();
    scrollArea = new QScrollArea();
    scrollArea -> setWidget(imgLabel);

    layout -> addRow(scrollArea);

    setCentralWidget(centralWidget);

    setupDock();
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

void MainWindow::setupDock()
{
    QWidget *widget = new QWidget;

    QVBoxLayout *boxLayout = new QVBoxLayout();
    widget -> setLayout(boxLayout);

    listView = new QListView();
    itemModel = new QStandardItemModel();

    listView -> setModel(itemModel);

    boxLayout -> addWidget(listView);

    boxLayout -> addStretch();

    QDockWidget *dock = new QDockWidget(this);
    dock -> setFeatures(QDockWidget::DockWidgetMovable);
    dock -> setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    dock -> setWidget(widget);

    addDockWidget(Qt::LeftDockWidgetArea,dock);

    QObject::connect(listView, SIGNAL(doubleClicked(QModelIndex)),this,SLOT(displayImage(QModelIndex)));
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

void MainWindow::displayImage(const QModelIndex &index)
{
    loadImage(itemModel -> item(index.row(), 1)->text());
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

        for(const QString& i : fileNames)
        {
            int row = itemModel -> rowCount();
            const QString fileName = i.split('/').last();
            QStandardItem *nameItem = new QStandardItem(fileName);
            nameItem -> setEditable(false);
            QStandardItem *pathItem = new QStandardItem(i);
            itemModel -> setItem(row,0,nameItem);
            itemModel -> setItem(row,1,pathItem);
        }
    }
}

MainWindow::~MainWindow()
{


}
