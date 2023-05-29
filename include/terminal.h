#ifndef CAR_WORKSHOP_WORKER_SCHEDULER_TERMINAL_H
#define CAR_WORKSHOP_WORKER_SCHEDULER_TERMINAL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "terminal_colors.h"
#include "error_handler.h"

/**
 * Clears the terminal
 */
void clear();

bool readYesNoInput();

int readInt();

bool isNumber(const char *str);

char *readString(int maxCharacters);

#endif //CAR_WORKSHOP_WORKER_SCHEDULER_TERMINAL_H
