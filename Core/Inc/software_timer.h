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

extern int timer7SEGCountRedhorizontal_flag;
extern int timer7SEGCountYellowhorizontal_flag;
extern int timer7SEGCountGreenhorizontal_flag;

extern int timer7SEGCountRedvertical_flag;
extern int timer7SEGCountYellowvertical_flag;
extern int timer7SEGCountGreenvertical_flag;

extern int timerAuto_flag;

extern int timerBlinking_flag;

void setTimerTest(int duration);

void setTimerENhorizontal(int duration);
void setTimerENvertical(int duration);

void setTimer7SEGCountRedhorizontal(int duration);
void setTimer7SEGCountYellowhorizontal(int duration);
void setTimer7SEGCountGreenhorizontal(int duration);

void setTimer7SEGCountRedvertical(int duration);
void setTimer7SEGCountYellowvertical(int duration);
void setTimer7SEGCountGreenvertical(int duration);

void setTimerAuto(int duration);

void setTimerBlinking(int duration);

void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
