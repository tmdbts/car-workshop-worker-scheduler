#include "../include/terminal.h"

void clear() {
#ifdef _WIN32
    system("cls");

    return;
#endif

    system("clear");
}