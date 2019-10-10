#include "mainwindow.h"
#include "socketthread.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow mainWindow;

    // create the background thread
    SocketThread socketThread;

    // here we connect the threads signal to the UI's slot
    // the QObject::connect function takes the following arguments
    // connect(pointer to object with signal, pointer to the signal function, point to the object with the slot, pointer to the slot function)
    QObject::connect(&socketThread, &SocketThread::resetToNumber, &mainWindow, &MainWindow::resetQLabel);

    // start the thread in the background (it needs to be in the background because waiting for network messages
    // would block the ui thread causing it to freeze
    socketThread.start();

    //show the mainWindow
    mainWindow.show();

    return a.exec();
}
