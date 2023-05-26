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

int readInt() {
    char buffer[100];

    fflush(stdin);

    fgets(buffer, sizeof(buffer), stdin);

    if (buffer[strlen(buffer) - 1] == '\n')
        buffer[strlen(buffer) - 1] = '\0';

    if (!isNumber(buffer)) {
        printWarning(INVALID_INT_MESSAGE);

        return readInt();
    }

    int value = atoi(buffer);

    return value;
}

bool isNumber(const char *str) {
    if (str == NULL || *str == '\0') return false;

    while (*str != '\0') {
        if (!isdigit(*str)) return false;

        str++;
    }

    return true;
}