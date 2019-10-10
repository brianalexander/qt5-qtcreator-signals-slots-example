#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // get a reference to the increment button
    QPushButton *incrementButton = ui->incrementButton;

    // connect the incrementButton's "clicked" signal to the mainWindow's "incrementQLabel" slot
    // note that "this" refers to the current object, which is the instantiated mainWindow object
    QObject::connect(incrementButton, &QPushButton::clicked, this, &MainWindow::incrementQLabel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resetQLabel(int value) {
    //convert int value into a QString
    QString numString = QString::number(value);

    // set the text of the countLabel QLabel item to the value of numString
    ui->countLabel->setText(numString);
}

void MainWindow::incrementQLabel() {
    // get the current value of hte label
    QString currentValue = ui->countLabel->text();

    //create a new QString for the new value and increment the current value by one
    QString newValue = QString::number(currentValue.toInt() + 1);

    // set the new value and update the ui
    ui->countLabel->setText(newValue);
}

