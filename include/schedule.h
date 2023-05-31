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

/**
 * @struct Service Defines the service structure
 * @typedef Defines a type for the Service struct
 */
typedef struct Service {
    unsigned int id;
    struct tm *startsAt;
    struct tm *endsAt;
    char *type;
} Service;

/**
 * @struct Services Defines the service structure
 * @typedef Defines a type for the services structure
 */
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

/**
 * @brief Initializes a services list
 *
 * @param services the services list
 * @param servicesCount the number of services in the list
 */
void initBooking(Services **services, unsigned int *servicesCount);

/**
 * @brief Fills the gaps in the main services list from a backup list
 *
 * @param services the main services list
 * @param backupServices the backup services list
 */
void fillBooking(Services **services, Services **backupServices);

/**
 * @brief Creates a service
 *
 * @return the created service
 */
Service *createService();

/**
 * @brief Checks if the time window for a service is between 8AM and 6PM
 *
 * @param service the service
 *
 * @return 1 if it is between 8AM and 6AM or 0 if it is not
 */
bool isTimeBetween8and6(Service *service);

/**
 * @brief Checks if the time window for a service is available in the services list
 *
 * @param services the services list
 * @param service the service
 *
 * @return 0 if the time window is not available and 1 if it is
 */
bool isTimeAvailable(Services **services, Service *service);

/**
 * @brief Checks if a date is before another
 *
 * @param date1 the date to be checked
 * @param date2 the date to be checked against
 *
 * @return 0 if date1 is not before date2 and 1 if it is
 */
bool isDateBefore(const struct tm *date1, const struct tm *date2);

/**
 * @brief Swaps to services
 *
 * @param firstService the first service
 * @param secondService the second service
 */
void swapServices(Services *firstService, Services *secondService);

/**
 * @brief Adds a service to a services list
 *
 * This function will add a service to the a services list,
 * which means that the service will only be added if the slot
 * is free.
 *
 * @see addBackupService() if you do not want the time slot to be considered
 *
 * @param services the services list
 * @param newService the service
 *
 * @return 0 if the service was not added or 1 if it was
 */
bool addService(Services **services, Service *newService);

/**
 * @brief Adds a service to a backup services list
 *
 * This function will add a service to the a services backup list,
 * which means that the service will always be added regardless of the slot
 * being free or not.
 *
 * @see addService() if you want the time slot to specifically be available
 *
 * @param services the backup services list
 * @param newService the service
 *
 * @return 0 if the was not added or 1 if it was
 */
bool addBackupService(Services **services, Service *newService);

/**
 * @brief Removes a service from a services list
 *
 * This function does not remove the memory space allocated to the
 * service.
 *
 * @see deleteService()
 *
 * @param services
 * @param service
 */
void removeService(Services **services, Service *service);

/**
 * @brief Removes a service from a services list by id
 *
 * @param services the services list
 * @param id the service id
 */
void removeServiceById(Services **services, unsigned int id);

/**
 * @brief Deletes a service from a services list
 *
 * This function does not remove the memory space allocated to the
 * service.
 *
 * @param services the services list
 * @param id the service id
 */
void deleteService(Services **services, unsigned int id);

/**
 * @brief Orders a services list in ascending order
 *
 * @param services the services list
 */
void orderAsc(Services **services);

/**
 * @brief Orders a services list in descending order
 *
 * @param services the services list
 */
void orderDesc(Services **services);

/**
 * @brief prints a services list to the stdout
 *
 * @param services the services list
 */
void listServices(Services *services);

/**
 * @brief Sets a date of a service from a the string date
 *
 * @param service the service
 * @param datetimeString the string date
 */
void setStartDate(Service *service, const char *datetimeString);

/**
 * @brief Converts a date to string
 *
 * @param date the date
 *
 * @return the converted string date
 */
char *dateToString(struct tm *date);

/**
 * @brief Adds minutes to a time
 *
 * @param time the time
 * @param minutes the amount of minutes
 *
 * @return the date with the added minutes
 */
struct tm *addMinutesToTime(struct tm *time, int minutes);

/**
 * @brief Sets a date of a service
 *
 * This function calculates the end date according to the start date
 * and the end date
 *
 * @param service the service
 */
void setEndDate(Service *service);

/**
 * @brief Gets a service from a service list by id
 *
 * @param services the services list
 * @param id the id
 *
 * @return the service
 */
Service *getService(Services *services, unsigned int id);

/**
 * @brief Checks if a service type is valid
 *
 * @param type the service type
 *
 * @return 0 if the service is not valid or 1 if it is
 */
bool isValidServiceType(char *type);

#endif //CAR_WORKSHOP_WORKER_SCHEDULER_SCHEDULE_H
