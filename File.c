#include <stdio.h>
#include <time.h>

int main() {
    time_t last_update = 0;

    while (1) {
        time_t now = time(NULL);

        // Update only every 2 seconds
        if (now - last_update >= 2) {
            last_update = now;

            struct tm *t = localtime(&now);

            // Clear screen (ANSI escape, works on most terminals)
            printf("\033[H\033[J");

            printf("Current Time: %02d:%02d:%02d\n",
                   t->tm_hour,
                   t->tm_min,
                   t->tm_sec);

            fflush(stdout); // Make sure output appears immediately
        }
    }

    return 0;
}
