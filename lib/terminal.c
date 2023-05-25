#include "../include/terminal.h"

void clear() {
#ifdef _WIN32
    system("cls");

    return;
#endif

    system("clear");
}

bool readYesNoInput() {
    char input[2];

    while (true) {
        fgets(input, sizeof(input), stdin);

        if (input[0] == '\n') return true;

        if (input[0] == 'y' || input[0] == 'Y') return true;
        if (input[0] == 'n' || input[0] == 'N') return false;

        printf("%sInvalid input. (Y/n) ", TERMINAL_COLOR_YELLOW);
    }
}