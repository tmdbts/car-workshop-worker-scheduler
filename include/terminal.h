#ifndef CAR_WORKSHOP_WORKER_SCHEDULER_TERMINAL_H
#define CAR_WORKSHOP_WORKER_SCHEDULER_TERMINAL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "terminal_colors.h"

/**
 * Clears the terminal
 */
void clear();

bool readYesNoInput();

#endif //CAR_WORKSHOP_WORKER_SCHEDULER_TERMINAL_H
