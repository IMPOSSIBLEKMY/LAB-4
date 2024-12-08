/*
 * software_timer.h
 *
 *  Created on: Nov 8, 2024
 *      Author: NTKM
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timerTest_flag;

extern int timerENhorizontal_flag;
extern int timerENvertical_flag;

extern int timer7SEGCountHorizontal_flag;
extern int timer7SEGCountVertical_flag;

extern int timerAuto_flag;

extern int timerBlinking_flag;

void setTimerTest(int duration);

void setTimerENhorizontal(int duration);
void setTimerENvertical(int duration);

void setTimer7SEGCountHorizontal(int duration);

void setTimer7SEGCountVertical(int duration);

void setTimerAuto(int duration);

void setTimerBlinking(int duration);

void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
