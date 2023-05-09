#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "include/schedule.h"

Services *servicesList = NULL;

int main() {
    initServices();

    Service *newService = malloc(sizeof(Service));

    newService->id = 1;
    newService->type = strdup(SERVICE_TYPES[0]);
    setStartDate(newService, "2023-05-08 18:34");
    setEndDate(newService);
    
    addService(&servicesList, newService);

    listServices(servicesList);

    Service *another = createService();

    addService(&servicesList, another);

    listServices(servicesList);

//    removeService(&servicesList, 1);

//    listServices(servicesList);

    return 0;
}
