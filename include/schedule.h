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

Services *booking;

Services *backUpBooking;

unsigned int numberOfServices;

unsigned int numberOfBackupServices;

extern const char *SERVICE_TYPES[];

extern const int WASH_SERVICE_TIME;

extern const int REPAIR_SERVICE_TIME;

void initBooking(Services **services, unsigned int *servicesCount);

void initServices();

Service *createService();

bool isTimeBetween8and6(Service *service);

bool isTimeAvailable(Services **services, Service *service);

bool compareDates(const struct tm *date1, const struct tm *date2);

void addService(Services **services, Service *service);

void removeService(Services **services, unsigned int id);

void orderAsc();

void orderDesc();

void listServices(Services *services);

void setStartDate(Service *service, const char *datetimeString);


struct tm *addMinutesToTime(struct tm *time, int minutes);

void setEndDate(Service *service);

#endif //CAR_WORKSHOP_WORKER_SCHEDULER_SCHEDULE_H
