#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QPlainTextEdit>
#include <QLabel>
#include <QFormLayout>
#include <QFileDialog>
#include <QScrollArea>
#include <QListView>
#include <QStandardItemModel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void openFileDialog();
    void loadImage(const QString &filePath);
    void displayImage(const QModelIndex &index);

private:
    QLabel *imgLabel;
    QFormLayout *layout;
    QScrollArea *scrollArea;
    QListView *listView;
    QStandardItemModel *itemModel;
    void setupMenu();
    void setupDock();
};
#endif // MAINWINDOW_H
