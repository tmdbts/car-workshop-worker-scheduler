#ifndef CAR_WORKSHOP_WORKER_SCHEDULER_MENU_CONTROLLER_H
#define CAR_WORKSHOP_WORKER_SCHEDULER_MENU_CONTROLLER_H

#include <stdio.h>
#include <stdlib.h>

#include "terminal.h"
#include "terminal_colors.h"
#include "menu.h"
#include "schedule.h"
#include "file_handler.h"

/**
 * @brief Reads a menu option from the user
 *
 * @param max the maximum option in the menu
 *
 * @return the option
 */
int readMenuOption(int max);

/**
 * @brief The menu controller
 */
void mainMenuController();

/**
 * @brief Implements the appointment creation
 */
void createAppointment();

/**
 * @brief Implements the listing of the booking
 */
void listBooking();

/**
 * @brief Implements the listing of the backup booking
 */
void listBackupBooking();

/**
 * @brief Implements an appointment deletion
 */
void deleteAppointment();

/**
 * @brief Implements a backup appointment deletion
 */
void deleteBackupAppointment();

/**
 * @brief Implements the save action to the files
 */
void save();

/**
 * @brief Implements the read action from the saved files
 */
void read();

#endif //CAR_WORKSHOP_WORKER_SCHEDULER_MENU_CONTROLLER_H
