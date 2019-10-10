#ifndef SOCKETTHREAD_H
#define SOCKETTHREAD_H

#include <QThread>

class SocketThread : public QThread
{
    //this line is a macro, necessary in all QObjects
    Q_OBJECT

public:
    void run(void);

// NOTE: signals are NOT written by you.  They are compiled by Qt and only need
// a function declaration that includes the value that they will be sending
// which are the values following the "emit" keyword
// example: emit resetToNumber(5);
signals:
    void resetToNumber(int value);
};

#endif // SOCKETTHREAD_H
