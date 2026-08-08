/*You must include these files in the same directory as the program.
 *In order to use the program, you must type a header:
    '#include "sleep.c"*/



#include "sleep.h"

#ifdef _WIN32
#include <windows.h> //WINDOWS

#else
#include <time.h> //UNIX/LINUX/MAC(?)/BSD(?) [POSIX]
#endif

void gsleep(double seconds) { //creates function name
#ifdef _WIN32
    //Windows Sleep takes milliseconds
    Sleep((DWORD)(seconds * 1000.0));
#else
    //POSIX nanosleep takes seconds and nanoseconds
    struct timespec ts;
    ts.tv_sec = (time_t)seconds;
                //WHOLE SECONDS
    ts.tv_nsec = (long)((seconds - (double)ts.tv_sec) * 1e9);
    //REMAINDING NANOSECONDS

    nanosleep(&ts, NULL);
#endif
}
