#include "../include/error_handler.h"

const char *MEMORY_ALLOCATION_MESSAGE = "Memory allocation error.";

const char *UNAVAILABLE_TIME_SLOT_MESSAGE = "The selected time is unavailable.";

const char *EMPTY_LIST_ON_REMOVE_MESSAGE = "The booking is empty. Couldn't remove appointment.";

const char *APPOINTMENT_NOT_FOUND_MESSAGE = "The appointment you selected does not exist.";

const char *INVALID_DATE_FORMAT_MESSAGE = "Invalid date format (yyyy-mm-dd hh:mm).";

void printError(const char *message) {
    char *error = malloc(strlen(message) + strlen(TERMINAL_COLOR_RED));

    sprintf(error, "%s%s\n", TERMINAL_COLOR_RED, message);

    perror(error);
    printf("%s", TERMINAL_COLOR_DEFAULT);
}

void printWarning(const char *message) {
    char *error = malloc(strlen(message) + strlen(TERMINAL_COLOR_RED));

    sprintf(error, "%s%s\n", TERMINAL_COLOR_YELLOW, message);

    perror(error);
    printf("%s", TERMINAL_COLOR_DEFAULT);
}
