#ifndef CAR_WORKSHOP_WORKER_SCHEDULER_SCHEDULE_H
#define CAR_WORKSHOP_WORKER_SCHEDULER_SCHEDULE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

typedef struct Service {
    unsigned int id;
    struct tm *startsAt;
    struct tm *endsAt;
    char *type;
} Service;

typedef struct Services {
    Service *service;
    struct Services *next;
} Services;

Services *servicesList;

unsigned int numberOfServices;

extern const char *SERVICE_TYPES[];

extern const int WASH_SERVICE_TIME;

extern const int REPAIR_SERVICE_TIME;

void initServices();

Service *createService();

void addService(Services **services, Service *service);

void removeService(Services **services, unsigned int id);

void orderAsc();

void orderDesc();

void listServices(Services *services);

void setStartDate(Service *service, const char *datetimeString);

struct tm *addMinutesToTime(const struct tm *time, int minutes);

void setEndDate(Service *service);

#endif //CAR_WORKSHOP_WORKER_SCHEDULER_SCHEDULE_H
