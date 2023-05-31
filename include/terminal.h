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

/**
 * @brief Reads a "yes" or "no" input
 *
 * @return 1 if it reads "yes" or 0 if it reads "no"
 */
bool readYesNoInput();

/**
 * @brief Reads and integer from stdin
 *
 * @return the read integer
 */
int readInt();

/**
 * Checks if a string is a number
 *
 * @param str the string
 *
 * @return 1 if str is an integer or 0 if str is not an integer
 */
bool isNumber(const char *str);

/**
 * @brief Reads a string from stdin
 *
 * @param maxCharacters the maximum number of characters
 *
 * @return the read string
 */
char *readString(int maxCharacters);

#endif //CAR_WORKSHOP_WORKER_SCHEDULER_TERMINAL_H
