#include "../include/error_handler.h"

const char *MEMORY_ALLOCATION_MESSAGE = "Memory allocation error.";

const char *UNAVAILABLE_TIME_SLOT_MESSAGE = "The selected time is unavailable.";

const char *EMPTY_LIST_ON_REMOVE_MESSAGE = "The booking is empty. Couldn't remove appointment.";

const char *APPOINTMENT_NOT_FOUND_MESSAGE = "The appointment you selected does not exist.";

const char *INVALID_DATE_FORMAT_MESSAGE = "Invalid date format (yyyy-mm-dd hh:mm).";

const char *INVALID_INT_MESSAGE = "Invalid input. Please enter a valid number.";

const char *OPEN_FILE_MESSAGE = "Error opening file.";

void printError(const char *message) {
    printf("%s%s\n", TERMINAL_COLOR_RED, message);
    printf("%s", TERMINAL_COLOR_DEFAULT);
}

void printWarning(const char *message) {
    printf("%s%s\n", TERMINAL_COLOR_YELLOW, message);
    printf("%s", TERMINAL_COLOR_DEFAULT);
}
