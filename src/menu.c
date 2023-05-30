#include "../include/menu.h"

void printMainMenu() {
    printHeader();
    printf("│            Main Menu           │ \n");
    printf("├───┬────────────────────────────┤ \n");
    printf("│ 1 │           Make appointment │ \n");
    printf("├───┼────────────────────────────┤ \n");
    printf("│ 2 │         Delete appointment │ \n");
    printf("├───┼────────────────────────────┤ \n");
    printf("│ 3 │  Delete backup appointment │ \n");
    printf("├───┼────────────────────────────┤ \n");
    printf("│ 4 │          List appointments │ \n");
    printf("├───┼────────────────────────────┤ \n");
    printf("│ 5 │   List backup appointments │ \n");
    printf("├───┼────────────────────────────┤ \n");
    printf("│ 6 │                 Finish job │ \n");
    printf("├───┼────────────────────────────┤ \n");
    printf("│ 7 │                  Save data │ \n");
    printf("├───┼────────────────────────────┤ \n");
    printf("│ 8 │                  Load data │ \n");
    printf("├───┼────────────────────────────┤ \n");
    printf("│ 0 │                       Quit │ \n");
    printf("└───┴────────────────────────────┘ \n");
}

void printGoBack() {
    printf("│ 0 │                 <- Go back | \n");
    printf("└───┴────────────────────────────┘ \n");
}

void printHeader() {
    printf("┌────────────────────────────────┐ \n");
    printf("│        WORKSHOP BOOKING        │ \n");
    printf("├────────────────────────────────┤ \n");
}