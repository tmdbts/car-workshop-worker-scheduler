#ifndef CAR_WORKSHOP_WORKER_SCHEDULER_SCHEDULE_H
#define CAR_WORKSHOP_WORKER_SCHEDULER_SCHEDULE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "terminal.h"
#include "terminal_colors.h"
#include "error_handler.h"

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

Services *booking;

Services *backUpBooking;

unsigned int numberOfServices;

unsigned int numberOfBackupServices;

extern const char *SERVICE_TYPES[];

extern const int WASH_SERVICE_TIME;

extern const int REPAIR_SERVICE_TIME;

void initBooking(Services **services, unsigned int *servicesCount);

void fillBooking(Services **services, Services **backupServices);

Service *createService();

bool isTimeBetween8and6(Service *service);

bool isTimeAvailable(Services **services, Service *service);

bool compareDates(const struct tm *date1, const struct tm *date2);

void swapServices(Services *firstService, Services *secondService);

bool addService(Services **services, Service *newService);

bool addBackupService(Services **services, Service *newService);

void removeService(Services **services, Service *service);

void removeServiceById(Services **services, unsigned int id);

void deleteService(Services **services, unsigned int id);

void orderAsc(Services **services);

void orderDesc(Services **services);

void listServices(Services *services);

void setStartDate(Service *service, const char *datetimeString);

char *dateToString(struct tm *date);

struct tm *addMinutesToTime(struct tm *time, int minutes);

void setEndDate(Service *service);

Service *getService(Services *services, unsigned int id);

bool isValidServiceType(char *type);

#endif //CAR_WORKSHOP_WORKER_SCHEDULER_SCHEDULE_H
