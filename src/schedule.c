#include "../include/schedule.h"

const char *SERVICE_TYPES[] = {"repair", "wash"};

const int WASH_SERVICE_TIME = 30;

const int REPAIR_SERVICE_TIME = 60;

unsigned int numberOfServices = 0;

void initServices() {
    servicesList = NULL;
    numberOfServices = 0;
}

Service *createService() {
    Service *newService = malloc(sizeof(Service));
    char datetimeString[20];
    char type[20];

    if (newService == NULL) {
        fprintf(stderr, "Memory allocation error!\n");
        return NULL;
    }

    newService->id = numberOfServices + 1;

    printf("Enter service date and time (YYYY-MM-DD HH:MM:SS): ");
    fgets(datetimeString, 20, stdin);

    if (datetimeString[strlen(datetimeString) - 1] == '\n') {
        datetimeString[strlen(datetimeString) - 1] = '\0';
    }

    printf("[INFO] Inserted date: %s\n", datetimeString);

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

void addService(Services **services, Service *newService) {
    if (!isTimeAvailable(newService)) {
        fprintf(stderr, "Time is not available.\n");

        return;
    }

    Services *newNode = malloc(sizeof(Services));

    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation error!\n");

        return;
    }

    newNode->service = newService;
    newNode->next = NULL;

    if (*services == NULL) {
        *services = newNode;

        numberOfServices++;

        return;
    }

    Services *lastNode = *services;

    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }

    lastNode->next = newNode;

    numberOfServices++;
}

//void addService(Services **services, Service *service) {
//    Services *newNode = malloc(sizeof(Services));
//    newNode->service = malloc(sizeof(Service));
//
//    if (newNode == NULL && newNode->service == NULL) {
//        perror("MEMORY ALLOCATION");
//
//        return;
//    }
//
//    memcpy(newNode->service, service, sizeof(Service));
//
//    newNode->next = *services;
//
//    numberOfServices++;
//    *services = newNode;
//}

void removeService(Services **services, unsigned int id) {
    if (*services == NULL) {
        fprintf(stderr, "Error: services list is empty!\n");
        return;
    }

    Services *curr = *services;
    Services *prev = NULL;

    while (curr != NULL && curr->service->id != id) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        fprintf(stderr, "Error: service with id %u not found!\n", id);
        return;
    }

    if (prev == NULL) {
        // Service is first node in list
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

    strftime(string, stringSize, "%Y-%m-%d %H:%M", date);

    return string;
}

void listServices(Services *services) {
    Services *current = services;

    while (current != NULL) {
        printf("Service ID: %u\n", current->service->id);
        printf("Starts at: %s", asctime(current->service->startsAt));
        printf("Ends at: %s", asctime(current->service->endsAt));
        printf("Type: %s\n", current->service->type);
        printf("\n");

        current = current->next;
    }
}

void setStartDate(Service *service, const char *datetimeString) {
    struct tm datetime = {0};

    if (strptime(datetimeString, "%Y-%m-%d %H:%M", &datetime) == NULL) {
        fprintf(stderr, "Invalid startsAt string format!\n");

        return;
    }

    struct tm *datetimePtr = malloc(sizeof(struct tm));

    if (datetimePtr == NULL) {
        fprintf(stderr, "Memory allocation error!\n");
        return;
    }

    memcpy(datetimePtr, &datetime, sizeof(struct tm));
    service->startsAt = datetimePtr;
}

struct tm *addMinutesToTime(struct tm *time, int minutes) {
    time_t timeInSeconds = timegm((struct tm *) time);
    time_t endTimeInSeconds = timeInSeconds + minutes * 60;

    struct tm *endTime = malloc(sizeof(struct tm));

    if (endTime == NULL) {
        fprintf(stderr, "Memory allocation error!\n");

        return NULL;
    }

    gmtime_r(&endTimeInSeconds, endTime);

    return endTime;
}

void setEndDate(Service *service) {
    if (!strcmp(service->type, SERVICE_TYPES[0])) {  // Repair service
        service->endsAt = addMinutesToTime(service->startsAt, REPAIR_SERVICE_TIME);

        return;
    }

    service->endsAt = addMinutesToTime(service->startsAt, WASH_SERVICE_TIME);
}