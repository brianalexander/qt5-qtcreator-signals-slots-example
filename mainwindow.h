#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

// slot definitions
public slots:
    void resetQLabel(int value);
    void incrementQLabel();

// signal definitions
// see note about signals in socketthread.h
signals:
    void increment();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
