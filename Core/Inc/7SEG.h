/*
 * 7SEG.h
 *
 *  Created on: Nov 11, 2024
 *      Author: NTKM
 */

#ifndef INC_7SEG_H_
#define INC_7SEG_H_

#include "main.h"
#include "button.h"
#include "software_timer.h"
#include "fsm_auto.h"
#include "fsm_manual.h"

extern int buffer_7SEG_vertical[2];
extern int buffer_7SEG_horizontal[2];

extern int EN_horizontal;
extern int EN_vertical;

void display7SEGFinal();

void display7SEGvertical(int num);
void display7SEGhorizontal(int num);

void display7SEGBuffervertical(int num);
void display7SEGBufferhorizontal(int num);

void display7SEGFinalvertical();
void display7SEGFinalhorizontal();

#endif /* INC_7SEG_H_ */
