/*If you use VSCode for testing/tweaking this, please do not use the 
integrated terminal, it can screw with how it looks for you when testing.*/

#include <stdio.h>
#include <time.h> //gives us time(), localtime(), time_t, and struct tm
#include <stdlib.h> //general-purpose stuff
#include "sleep.c" //my global sleep function (fuck standard sleep functions in C)

int main(void) {
    while (1) {
        time_t now = time(NULL); //get the current time

        struct tm *local = localtime(&now); //convert time to local time

        printf("\033[2J\033[H"); //clears the screen

        printf("%02d:%02d:%02d\n",
            local->tm_hour,
            local->tm_min,
            local->tm_sec);

        fflush(stdout); //flush the metaphorical drain
        gsleep(2);
    }

    return 0;
}
