#ifndef CAR_WORKSHOP_WORKER_SCHEDULER_ERROR_HANDLER_H
#define CAR_WORKSHOP_WORKER_SCHEDULER_ERROR_HANDLER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "terminal_colors.h"

extern const char *MEMORY_ALLOCATION_MESSAGE;

extern const char *UNAVAILABLE_TIME_SLOT_MESSAGE;

extern const char *EMPTY_LIST_ON_REMOVE_MESSAGE;

extern const char *APPOINTMENT_NOT_FOUND_MESSAGE;

extern const char *INVALID_DATE_FORMAT_MESSAGE;

void printError(const char *message);

void printWarning(const char *message);

#endif //CAR_WORKSHOP_WORKER_SCHEDULER_ERROR_HANDLER_H
