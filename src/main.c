#include <stdio.h>
#include <stdlib.h>

#include "../include/schedule.h"
#include "../include/menu_controller.h"

void bootstrap() {
    Service *newService = malloc(sizeof(Service));

    newService->id = 1;
    newService->type = strdup(SERVICE_TYPES[0]);
    setStartDate(newService, "2023-05-08 14:34");
    setEndDate(newService);

    addService(&booking, newService);

    Service *another = malloc(sizeof(Service));

    another->id = 2;
    another->type = strdup(SERVICE_TYPES[1]);
    setStartDate(another, "2023-05-08 09:00");
    setEndDate(another);

    addService(&booking, another);

    Service *anotherOne = malloc(sizeof(Service));

    anotherOne->id = 3;
    anotherOne->type = strdup(SERVICE_TYPES[1]);
    setStartDate(anotherOne, "2023-05-08 12:00");
    setEndDate(anotherOne);

    addService(&booking, anotherOne);

    Service *oneBackup = malloc(sizeof(Service));

    oneBackup->id = 44;
    oneBackup->type = strdup(SERVICE_TYPES[1]);
    setStartDate(oneBackup, "2023-05-08 17:00");
    setEndDate(oneBackup);

    addService(&backUpBooking, oneBackup);

    Service *anotherBackup = malloc(sizeof(Service));

    anotherBackup->id = 32;
    anotherBackup->type = strdup(SERVICE_TYPES[0]);
    setStartDate(anotherBackup, "2023-05-08 14:00");
    setEndDate(anotherBackup);

    addService(&backUpBooking, anotherBackup);

    fillBooking(&booking, &backUpBooking);
}

int main() {
    initBooking(&booking, &numberOfServices);
    initBooking(&backUpBooking, &numberOfBackupServices);

    bootstrap();

    mainMenuController();

    return 0;
}
