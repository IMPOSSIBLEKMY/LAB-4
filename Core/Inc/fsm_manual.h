/*
 * fsm_manual.h
 *
 *  Created on: Nov 12, 2024
 *      Author: NTKM
 */

#ifndef INC_FSM_MANUAL_H_
#define INC_FSM_MANUAL_H_

#include "main.h"
#include "7SEG.h"
#include "button.h"
#include "software_timer.h"
#include "fsm_auto.h"

extern int red_yellow_green_manual_time[3];

void fsm_manual();

void fsm_setting();

#endif /* INC_FSM_MANUAL_H_ */
