#ifndef CAR_WORKSHOP_WORKER_SCHEDULER_MENU_CONTROLLER_H
#define CAR_WORKSHOP_WORKER_SCHEDULER_MENU_CONTROLLER_H

#include <stdio.h>
#include <stdlib.h>

#include "terminal.h"
#include "terminal_colors.h"
#include "menu.h"
#include "schedule.h"
#include "file_handler.h"

int readMenuOption(int max);

void mainMenuController();

void createAppointment();

void listBooking();

void listBackupBooking();

void deleteAppointment();

void deleteBackupAppointment();

void save();

void read();

#endif //CAR_WORKSHOP_WORKER_SCHEDULER_MENU_CONTROLLER_H
