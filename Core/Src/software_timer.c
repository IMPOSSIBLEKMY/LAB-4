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


int timer7SEGCountRedhorizontal_flag = 0;
int timer7SEGCountRedhorizontal_counter = 0;

int timer7SEGCountYellowhorizontal_flag = 0;
int timer7SEGCountYellowhorizontal_counter = 0;

int timer7SEGCountGreenhorizontal_flag = 0;
int timer7SEGCountGreenhorizontal_counter = 0;

int timer7SEGCountRedvertical_flag = 0;
int timer7SEGCountRedvertical_counter = 0;

int timer7SEGCountYellowvertical_flag = 0;
int timer7SEGCountYellowvertical_counter = 0;

int timer7SEGCountGreenvertical_flag = 0;
int timer7SEGCountGreenvertical_counter = 0;


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


void setTimer7SEGCountRedhorizontal(int duration)
{
    timer7SEGCountRedhorizontal_counter = duration / TIMER_CYCLE;
    timer7SEGCountRedhorizontal_flag = 0;
}

void setTimer7SEGCountYellowhorizontal(int duration)
{
    timer7SEGCountYellowhorizontal_counter = duration / TIMER_CYCLE;
    timer7SEGCountYellowhorizontal_flag = 0;
}

void setTimer7SEGCountGreenhorizontal(int duration)
{
    timer7SEGCountGreenhorizontal_counter = duration / TIMER_CYCLE;
    timer7SEGCountGreenhorizontal_flag = 0;
}


void setTimer7SEGCountRedvertical(int duration)
{
    timer7SEGCountRedvertical_counter = duration / TIMER_CYCLE;
    timer7SEGCountRedvertical_flag = 0;
}

void setTimer7SEGCountYellowvertical(int duration)
{
    timer7SEGCountYellowvertical_counter = duration / TIMER_CYCLE;
    timer7SEGCountYellowvertical_flag = 0;
}

void setTimer7SEGCountGreenvertical(int duration)
{
    timer7SEGCountGreenvertical_counter = duration / TIMER_CYCLE;
    timer7SEGCountGreenvertical_flag = 0;
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


    if (timer7SEGCountRedhorizontal_counter > 0)
    {
        timer7SEGCountRedhorizontal_counter--;
        if (timer7SEGCountRedhorizontal_counter <= 0)
        {
            timer7SEGCountRedhorizontal_flag = 1;
        }
    }

    if (timer7SEGCountYellowhorizontal_counter > 0)
    {
        timer7SEGCountYellowhorizontal_counter--;
        if (timer7SEGCountYellowhorizontal_counter <= 0)
        {
            timer7SEGCountYellowhorizontal_flag = 1;
        }
    }

    if (timer7SEGCountGreenhorizontal_counter > 0)
    {
        timer7SEGCountGreenhorizontal_counter--;
        if (timer7SEGCountGreenhorizontal_counter <= 0)
        {
            timer7SEGCountGreenhorizontal_flag = 1;
        }
    }


    if (timer7SEGCountRedvertical_counter > 0)
    {
        timer7SEGCountRedvertical_counter--;
        if (timer7SEGCountRedvertical_counter <= 0)
        {
            timer7SEGCountRedvertical_flag = 1;
        }
    }

    if (timer7SEGCountYellowvertical_counter > 0)
    {
        timer7SEGCountYellowvertical_counter--;
        if (timer7SEGCountYellowvertical_counter <= 0)
        {
            timer7SEGCountYellowvertical_flag = 1;
        }
    }

    if (timer7SEGCountGreenvertical_counter > 0)
    {
        timer7SEGCountGreenvertical_counter--;
        if (timer7SEGCountGreenvertical_counter <= 0)
        {
            timer7SEGCountGreenvertical_flag = 1;
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


