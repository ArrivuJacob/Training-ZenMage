#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QPlainTextEdit>
#include <QLabel>
#include <QFormLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void addIntoComboBox();
    void insertIntoTextBlock(const QString &text);

private:
    QLineEdit *lineEdit;
    QPushButton *button;
    QComboBox *comboBox;
    QPlainTextEdit *textArea;
    QLabel *label;
    QLabel *output;
    QFormLayout *layout;
};
#endif // MAINWINDOW_H
