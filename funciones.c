#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int obtener_anio_actual() {
    time_t seconds=time(NULL);
    struct tm* current_time=localtime(&seconds);
    return current_time->tm_year + 1900;
}
