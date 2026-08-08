#include <stdio.h>
#include <time.h>

int main() {
    time_t t = time(NULL);
    struct tm *today = localtime(&t);

    printf("DIGITAL DATE DISPLAY\n");
    printf("DATE: %04d-%02d-%02d\n",
            today->tm_year + 1900,
            today->tm_mon + 1,
            today->tm_mday);
    return 0;
}
