#include "../include/schedule.h"

const char *SERVICE_TYPES[] = {"repair", "wash"};

const int WASH_SERVICE_TIME = 30;

const int REPAIR_SERVICE_TIME = 60;

unsigned int numberOfServices = 0;

void initBooking(Services **services, unsigned int *servicesCount) {
    *services = NULL;
    *servicesCount = 0;
}

void fillBooking(Services **services, Services **backupServices) {
    Services *backUp = *backupServices;

    while (backUp != NULL) {
        Service *currentService = backUp->service;

        if (!isTimeAvailable(services, backUp->service)) {
            backUp = backUp->next;

            continue;
        }

        addService(services, currentService);

        Services *temp = backUp;
        backUp = backUp->next;

        removeService(backupServices, temp->service);
    }
}

Service *createService() {
    Service *newService = malloc(sizeof(Service));
    char datetimeString[20];
    char type[20];

    if (newService == NULL) {
        printError(MEMORY_ALLOCATION_MESSAGE);
        return NULL;
    }

    newService->id = numberOfServices + 1;

    printf("Enter service date and time (YYYY-MM-DD HH:MM): ");
    fgets(datetimeString, 20, stdin);

    if (datetimeString[strlen(datetimeString) - 1] == '\n') {
        datetimeString[strlen(datetimeString) - 1] = '\0';
    }

    setStartDate(newService, datetimeString);
    setEndDate(newService);

    printf("Enter service type: ");
    scanf("%19s", type);
    newService->type = strdup(type);

    return newService;
}

bool isTimeBetween8and6(Service *service) {
    struct tm *startsAt = service->startsAt;
    struct tm *endsAt = service->endsAt;

    return startsAt->tm_hour >= 8 && endsAt->tm_hour < 18;
}

bool compareDates(const struct tm *date1, const struct tm *date2) {
    struct tm copy1 = *date1;
    struct tm copy2 = *date2;

    time_t time1 = mktime(&copy1);
    time_t time2 = mktime(&copy2);

    return time1 < time2;
}

bool isTimeAvailable(Services **services, Service *service) {
    Services *current = *services;

    if (!isTimeBetween8and6(service)) return false;

    while (current != NULL) {
        if (difftime(timegm(current->service->endsAt), timegm(service->startsAt)) >= 0 &&
            difftime(timegm(service->endsAt), timegm(current->service->startsAt)) >= 0)
            return false;


        current = current->next;
    }

    return true;
}


void swapServices(Services *firstService, Services *secondService) {
    Service *temp = firstService->service;

    firstService->service = secondService->service;
    secondService->service = temp;
}

void orderAsc(Services **services) {
    if (*services == NULL || (*services)->next == NULL) {
        return;
    }

    bool swapped;
    Services *curr;
    Services *last = NULL;

    do {
        swapped = false;
        curr = *services;

        while (curr->next != last) {
            if (!compareDates(curr->service->startsAt, curr->next->service->startsAt)) {
                swapServices(curr, curr->next);
                swapped = true;
            }

            curr = curr->next;
        }

        last = curr;

    } while (swapped);
}

void orderDesc(Services **services) {
    if (*services == NULL || (*services)->next == NULL) return;

    bool swapped;
    Services *curr;
    Services *last = NULL;

    do {
        swapped = false;
        curr = *services;

        while (curr->next != last) {
            if (compareDates(curr->service->startsAt, curr->next->service->startsAt)) {
                swapServices(curr, curr->next);
                swapped = true;
            }

            curr = curr->next;
        }

        last = curr;

    } while (swapped);
}

bool addService(Services **services, Service *newService) {
    if (!isTimeAvailable(services, newService)) {
        printError(UNAVAILABLE_TIME_SLOT_MESSAGE);

        return false;
    }

    Services *newNode = malloc(sizeof(Services));

    if (newNode == NULL) {
        printError(MEMORY_ALLOCATION_MESSAGE);

        return false;
    }

    newNode->service = newService;
    newNode->next = NULL;

    if (*services == NULL) {
        *services = newNode;

        numberOfServices++;

        return true;
    }

    Services *lastNode = *services;

    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }

    lastNode->next = newNode;

    numberOfServices++;

    return true;
}

bool addBackupService(Services **services, Service *newService) {
    Services *newNode = malloc(sizeof(Services));

    if (newNode == NULL) {
        printError(MEMORY_ALLOCATION_MESSAGE);

        return false;
    }

    newNode->service = newService;
    newNode->next = NULL;

    if (*services == NULL) {
        *services = newNode;

        numberOfServices++;

        return true;
    }

    Services *lastNode = *services;

    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }

    lastNode->next = newNode;

    numberOfServices++;

    return true;
}

void removeService(Services **services, Service *service) {
    if (*services == NULL) {
        printError(EMPTY_LIST_ON_REMOVE_MESSAGE);

        return;
    }

    Services *current = *services;
    Services *prev = NULL;

    while (current != NULL && current->service != service) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printError(APPOINTMENT_NOT_FOUND_MESSAGE);

        return;
    }

    if (prev == NULL) {
        *services = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

void removeServiceById(Services **services, unsigned int id) {
    if (*services == NULL) {
        printError(EMPTY_LIST_ON_REMOVE_MESSAGE);

        return;
    }

    Services *current = *services;
    Services *prev = NULL;

    while (current != NULL && current->service->id != id) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printError(APPOINTMENT_NOT_FOUND_MESSAGE);

        return;
    }

    if (prev == NULL) {
        *services = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

void deleteService(Services **services, unsigned int id) {
    if (*services == NULL) {
        printError(EMPTY_LIST_ON_REMOVE_MESSAGE);

        return;
    }

    Services *curr = *services;
    Services *prev = NULL;

    while (curr != NULL && curr->service->id != id) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printError(APPOINTMENT_NOT_FOUND_MESSAGE);

        return;
    }

    if (prev == NULL) {
        *services = curr->next;
    } else {
        prev->next = curr->next;
    }

    free(curr->service->type);
    free(curr->service->startsAt);
    free(curr->service);
    free(curr);
}

char *dateToString(struct tm *date) {
    int stringSize = 20;
    char *string = malloc(stringSize);

    strftime(string, stringSize, "%Y-%m-%d %H:%Mh", date);

    return string;
}

void listServices(Services *services) {
    Services *current = services;

    printf("┌────────────────────────────────┐\n");
    printf("│          Appointments          │\n");
    printf("├────────────────────────────────┤\n");

    while (current != NULL) {
        printf("│ %-10s │ %-17u │\n", "Service ID", current->service->id);
        printf("│ %-10s │ %-17s │\n", "Starts at", dateToString(current->service->startsAt));
        printf("│ %-10s │ %-17s │\n", "Ends at", dateToString(current->service->endsAt));
        printf("│ %-10s │ %-17s │\n", "Type", current->service->type);

        current = current->next;

        if (current == NULL) {
            printf("└────────────────────────────────┘\n");

            continue;
        }

        printf("├────────────────────────────────┤\n");
    }
}

void setStartDate(Service *service, const char *datetimeString) {
    struct tm *datetimePtr = malloc(sizeof(struct tm));

    if (datetimePtr == NULL) {
        printError(MEMORY_ALLOCATION_MESSAGE);

        return;
    }

    if (strptime(datetimeString, "%Y-%m-%d %H:%M", datetimePtr) == NULL) {
        printWarning(INVALID_DATE_FORMAT_MESSAGE);

        free(datetimePtr);

        return;
    }

    service->startsAt = datetimePtr;
}

struct tm *addMinutesToTime(struct tm *time, int minutes) {
    time_t timeInSeconds = timegm((struct tm *) time);
    time_t endTimeInSeconds = timeInSeconds + minutes * 60;

    struct tm *endTime = malloc(sizeof(struct tm));

    if (endTime == NULL) {
        printError(MEMORY_ALLOCATION_MESSAGE);

        return NULL;
    }

    gmtime_r(&endTimeInSeconds, endTime);

    return endTime;
}

void setEndDate(Service *service) {
    if (!strcmp(service->type, SERVICE_TYPES[0])) {
        service->endsAt = addMinutesToTime(service->startsAt, REPAIR_SERVICE_TIME);

        return;
    }

    service->endsAt = addMinutesToTime(service->startsAt, WASH_SERVICE_TIME);
}

Service *getService(Services *services, unsigned int id) {
    Services *current = services;

    while (current != NULL) {
        if (current->service->id == id) {
            return current->service;
        }

        current = current->next;
    }

    return NULL;
}

bool isValidServiceType(char *type) {
    int numberOfServiceTypes = sizeof(SERVICE_TYPES) / sizeof(SERVICE_TYPES[0]);

    for (int i = 0; i < numberOfServiceTypes; ++i) {
        if (!strcmp(SERVICE_TYPES[i], type)) return true;
    }

    return false;
}