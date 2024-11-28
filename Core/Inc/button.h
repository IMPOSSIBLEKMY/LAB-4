/*
 * button.h
 *
 *  Created on: Nov 8, 2024
 *      Author: NTKM
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

int isButton1Pressed();

int isButton2Pressed();

int isButton3Pressed();

int isButton4Pressed();

void getButton1();

void getButton2();

void getButton3();

void getButton4();
#endif /* INC_BUTTON_H_ */
