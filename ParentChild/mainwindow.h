#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPlainTextDocumentLayout>
#include <QFormLayout>
#include <QVBoxLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void logObjectDestroyed(QObject *obj);
    void removeBox();

private:
    QPlainTextEdit *textArea;
    QFormLayout *layout;
    QVBoxLayout *box;
};
#endif // MAINWINDOW_H
