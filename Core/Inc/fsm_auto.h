/*
 * fsm_auto.h
 *
 *  Created on: Nov 12, 2024
 *      Author: NTKM
 */

#ifndef INC_FSM_AUTO_H_
#define INC_FSM_AUTO_H_

#include "main.h"
#include "7SEG.h"
#include "button.h"
#include "software_timer.h"
#include "fsm_manual.h"

#define INIT_AUTO 0
#define AUTO_RED 1
#define AUTO_YELLOW 2
#define AUTO_GREEN 3
#define INIT_MANUAL 4
#define MANUAL_RED 5
#define MANUAL_YELLOW 6
#define MANUAL_GREEN 7

extern int red_yellow_green_auto_time_vertical[3];
extern int red_yellow_green_auto_time_horizontal[3];

extern int horizontal_counter;
extern int vertical_counter;

extern int status_horizontal;
extern int status_vertical;

void fsm_automatic();

void fsm_auto_horizontal();
void fsm_auto_vertical();

#endif /* INC_FSM_AUTO_H_ */
