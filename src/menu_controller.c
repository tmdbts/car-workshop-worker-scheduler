#include "../include/menu_controller.h"

int readMenuOption(int max) {
    int menuChoice;

    printf("%sSelect an option from the menu: ", TERMINAL_COLOR_DEFAULT);
    scanf("%d", &menuChoice);

    fflush(stdin);

    if (menuChoice < 0 || menuChoice > max) {
        printf("%sInvalid option. Select an option from 0 to %i.\n", TERMINAL_COLOR_RED, max);

        menuChoice = readMenuOption(max);
    }

    return menuChoice;
}

void mainMenuController() {
    int menuChoice;

    clear();

    do {
        printMainMenu();

        menuChoice = readMenuOption(8);

        switch (menuChoice) {
            case 1:
                createAppointment();

                break;

            case 2:
                deleteAppointment();

                break;

            case 3:
                deleteBackupAppointment();

                break;

            case 4:
                listBooking();

                break;

            case 5:
                listBackupBooking();

                break;

            case 6:
                deleteAppointment();

                break;

            case 7:
                save();

                break;

            case 8:
                read();

                break;

            default:
                break;
        }
    } while (menuChoice != 0);
}

void createAppointment() {
    clear();

    Service *appointment = createService();

    if (!addService(&booking, appointment)) {
        printf("%sDo you want to add you appointment to the backup booking? (Y/n) ", TERMINAL_COLOR_DEFAULT);

        if (!readYesNoInput()) return;

        addBackupService(&backUpBooking, appointment);
    }
}

void listBooking() {
    clear();

    listServices(booking);

    fflush(stdin);

    char opt = getchar();

    if (opt == 'A' || opt == 'a') {
        orderAsc(&booking);

        listBooking();

        return;
    }

    if (opt == 'D' || opt == 'd') {
        orderDesc(&booking);

        listBooking();

        return;
    }

    clear();
}

void listBackupBooking() {
    clear();

    listServices(backUpBooking);

    fflush(stdin);

    char opt = getchar();

    if (opt == 'A' || opt == 'a') {
        orderAsc(&backUpBooking);

        listBackupBooking();

        return;
    }

    if (opt == 'D' || opt == 'd') {
        orderDesc(&backUpBooking);

        listBackupBooking();

        return;
    }

    clear();
}

void deleteAppointment() {
    listServices(booking);

    printf("Insert the id of the appointment to delete: ");

    int id = readInt();

    clear();

    deleteService(&booking, id);

    fillBooking(&booking, &backUpBooking);
}

void deleteBackupAppointment() {
    listServices(backUpBooking);

    printf("Insert the id of the appointment to delete: ");

    int id = readInt();

    clear();

    deleteService(&backUpBooking, id);
}

void save() {
    saveData(booking, "booking.txt");
    saveData(backUpBooking, "backup_booking.txt");
}

void read() {
    booking = loadData("booking.txt");
    backUpBooking = loadData("backup_booking.txt");
}