/*
 * software_timer.c
 *
 *  Created on: Nov 8, 2024
 *      Author: NTKM
 */

#include "software_timer.h"

int TIMER_CYCLE = 10;

int timerTest_flag = 0;
int timerTest_counter = 0;


int timerENhorizontal_flag = 0;
int timerENhorizontal_counter = 0;

int timerENvertical_flag = 0;
int timerENvertical_counter = 0;


int timer7SEGCountHorizontal_flag = 0;
int timer7SEGCountHorizontal_counter = 0;

int timer7SEGCountVertical_flag = 0;
int timer7SEGCountVertical_counter = 0;


int timerAuto_flag = 0;
int timerAuto_counter = 0;


int timerBlinking_flag = 0;
int timerBlinking_counter = 0;


void setTimerTest(int duration)
{
    timerTest_counter = duration / TIMER_CYCLE;
    timerTest_flag = 0;
}

void setTimerENhorizontal(int duration)
{
    timerENhorizontal_counter = duration / TIMER_CYCLE;
    timerENhorizontal_flag = 0;
}

void setTimerENvertical(int duration)
{
    timerENvertical_counter = duration / TIMER_CYCLE;
    timerENvertical_flag = 0;
}


void setTimer7SEGCountHorizontal(int duration)
{
    timer7SEGCountHorizontal_counter = duration / TIMER_CYCLE;
    timer7SEGCountHorizontal_flag = 0;
}


void setTimer7SEGCountVertical(int duration)
{
    timer7SEGCountVertical_counter = duration / TIMER_CYCLE;
    timer7SEGCountVertical_flag = 0;
}


void setTimerAuto(int duration)
{
    timerAuto_counter = duration / TIMER_CYCLE;
    timerAuto_flag = 0;
}


void setTimerBlinking(int duration)
{
	timerBlinking_counter = duration / TIMER_CYCLE;
	timerBlinking_flag = 0;
}


void timerRun()
{
    if (timerTest_counter > 0)
    {
        timerTest_counter--;
        if (timerTest_counter <= 0)
        {
            timerTest_flag = 1;
        }
    }


    if (timerENhorizontal_counter > 0)
    {
        timerENhorizontal_counter--;
        if (timerENhorizontal_counter <= 0)
        {
            timerENhorizontal_flag = 1;
        }
    }

    if (timerENvertical_counter > 0)
    {
        timerENvertical_counter--;
        if (timerENvertical_counter <= 0)
        {
            timerENvertical_flag = 1;
        }
    }


    if (timer7SEGCountHorizontal_counter > 0)
    {
        timer7SEGCountHorizontal_counter--;
        if (timer7SEGCountHorizontal_counter <= 0)
        {
            timer7SEGCountHorizontal_flag = 1;
        }
    }


    if (timer7SEGCountVertical_counter > 0)
    {
        timer7SEGCountVertical_counter--;
        if (timer7SEGCountVertical_counter <= 0)
        {
            timer7SEGCountVertical_flag = 1;
        }
    }


    if (timerAuto_counter > 0)
    {
        timerAuto_counter--;
        if (timerAuto_counter <= 0)
        {
            timerAuto_flag = 1;
        }
    }


    if (timerBlinking_counter > 0)
    {
    	timerBlinking_counter--;
    	if (timerBlinking_counter <= 0)
    	{
    		timerBlinking_flag = 1;
    	}
    }
}


