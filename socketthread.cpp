#include "socketthread.h"

/*
 * This thread runs in the background separate from the UI thread.
 *
 * */
void SocketThread::run()
{
    int number = 1;

    // infinite loop
    for(;;) {
        //sleep the thread for 5 seconds
        QThread::sleep(5);

        //emite the signal with the new value to set on the qlabel
        emit resetToNumber(number);

        // increment number for the next iteration
        ++number;
    }
}
