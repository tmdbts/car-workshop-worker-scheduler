#include "../include/file_handler.h"

const char *BASE_PATH = "../persistence/";

const char SEPARATOR = '^';

const int MAX_LINE_LENGTH = 100;

void saveData(Services *services, char *fileName) {
    if (services == NULL) {
        printf("No services to write!\n");

        return;
    }

    char *filePath = malloc(sizeof(char) * MAX_LINE_LENGTH);

    strcpy(filePath, BASE_PATH);

    strcat(filePath, fileName);

    FILE *file = fopen(filePath, "w");

    if (file == NULL) {
        printError(OPEN_FILE_MESSAGE);

        return;
    }

    Services *current = services;

    while (current != NULL) {
        fprintf(file, "%u%c%s%c%s%c%s\n",
                current->service->id, SEPARATOR,
                dateToString(current->service->startsAt), SEPARATOR,
                dateToString(current->service->endsAt), SEPARATOR,
                current->service->type);

        current = current->next;
    }

    fclose(file);

    printf("%sData successfully saved. \n%s", TERMINAL_COLOR_GREEN, TERMINAL_COLOR_DEFAULT);
}

Services *loadData(char *fileName) {
    char *filePath = malloc(sizeof(char) * MAX_LINE_LENGTH);

    strcpy(filePath, BASE_PATH);

    strcat(filePath, fileName);

    FILE *file = fopen(filePath, "r");

    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open file '%s' for reading.\n", fileName);

        return NULL;
    }

    Services *services = NULL;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file) != NULL) {
        Service *newService = malloc(sizeof(Service));

        if (newService == NULL) {
            printError(MEMORY_ALLOCATION_MESSAGE);

            fclose(file);

            return NULL;
        }

        char *idStr = strtok(line, &SEPARATOR);
        char *startsAtStr = strtok(NULL, &SEPARATOR);
        char *endsAtStr = strtok(NULL, &SEPARATOR);
        char *type = strtok(NULL, &SEPARATOR);

        if (type[strlen(type) - 1] == '\n') type[strlen(type) - 1] = '\0';

        struct tm *startsAt = malloc(sizeof(struct tm)), *endsAt = malloc(sizeof(struct tm));
        strptime(startsAtStr, "%Y-%m-%d %H:%M", startsAt);
        strptime(endsAtStr, "%Y-%m-%d %H:%M", endsAt);

        newService->id = strtol(idStr, NULL, 10);
        newService->startsAt = startsAt;
        newService->endsAt = endsAt;
        newService->type = malloc(strlen(type));
        strcpy(newService->type, type);
//        newService->type = type;

        addService(&services, newService);
    }

    fclose(file);
    return services;
}