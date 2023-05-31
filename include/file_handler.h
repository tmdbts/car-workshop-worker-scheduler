#ifndef CAR_WORKSHOP_WORKER_SCHEDULER_FILE_HANDLER_H
#define CAR_WORKSHOP_WORKER_SCHEDULER_FILE_HANDLER_H

#include "schedule.h"

extern const char *BASE_PATH;

extern const char SEPARATOR;

extern const int MAX_LINE_LENGTH;

/**
 * @brief Saves a services list to a file
 *
 * @param services the services list
 * @param fileName the name of the file
 */
void saveData(Services *services, char *fileName);

/**
 * @brief Loads a services list from a file
 *
 * @param fileName the name of the file
 *
 * @return the services list
 */
Services *loadData(char *fileName);

#endif //CAR_WORKSHOP_WORKER_SCHEDULER_FILE_HANDLER_H
