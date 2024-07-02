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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void addIntoComboBox();
    void openFileDialog();
    void loadImage(const QString &filePath);

private:
    QLineEdit *lineEdit;
    QPushButton *chooseFileButton;
    QPushButton *addButton;
    QComboBox *comboBox;
    QLabel *label;
    QLabel *output;
    QLabel *imgLabel;
    QFormLayout *layout;
};
#endif // MAINWINDOW_H
