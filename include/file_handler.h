#ifndef CAR_WORKSHOP_WORKER_SCHEDULER_FILE_HANDLER_H
#define CAR_WORKSHOP_WORKER_SCHEDULER_FILE_HANDLER_H

#include "schedule.h"

extern const char *BASE_PATH;

extern const char SEPARATOR;

void saveData(Services *services, char *fileName);

Services *loadData(char *fileName);

#endif //CAR_WORKSHOP_WORKER_SCHEDULER_FILE_HANDLER_H
