/*
 * scheduler.c
 *
 *  Created on: Nov 28, 2024
 *      Author: NTKM
 */
#include "scheduler.h"

sTask SCH_tasks_G[SCH_MAX_TASKS];
unsigned char Error_code_G = 0;

//SCH_Init function
void SCH_Init(void)
{
	unsigned char i;

	for (i = 0; i < SCH_MAX_TASKS; i++)
	{
		SCH_Delete_Task(i);
	}

	Error_code_G = 0;
}


//SCH_Update function
void SCH_Update(void)
{
    unsigned char Index;

    for (Index = 0; Index < SCH_MAX_TASKS; Index++)
    {
        if (SCH_tasks_G[Index].pTask)
        {
            if (SCH_tasks_G[Index].Delay == 0)
            {
                SCH_tasks_G[Index].RunMe += 1;

                if (SCH_tasks_G[Index].Period)
                {
                    SCH_tasks_G[Index].Delay = SCH_tasks_G[Index].Period;
                }
            }
            else
            {
                SCH_tasks_G[Index].Delay -= 10;
            }
        }
    }
}

//SCH_Dispatch_Tasks function
void SCH_Dispatch_Tasks(void)
{
    unsigned char Index;

    for (Index = 0; Index < SCH_MAX_TASKS; Index++)
    {
        if (SCH_tasks_G[Index].RunMe > 0)
        {
            (*SCH_tasks_G[Index].pTask)();
            SCH_tasks_G[Index].RunMe -= 1;

            if (SCH_tasks_G[Index].Period == 0)
            {
                SCH_Delete_Task(Index);
            }
        }
    }
}

//SCH_Add_Task function
unsigned char SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD)
{
    unsigned char Index = 0;

    while ((SCH_tasks_G[Index].pTask != 0) && (Index < SCH_MAX_TASKS))
    {
        Index++;
    }

    if (Index == SCH_MAX_TASKS)
    {
        Error_code_G = ERROR_SCH_TOO_MANY_TASKS;
        return SCH_MAX_TASKS;
    }

    SCH_tasks_G[Index].pTask = pFunction;
    SCH_tasks_G[Index].Delay = DELAY;
    SCH_tasks_G[Index].Period = PERIOD;
    SCH_tasks_G[Index].RunMe = 0;

    return Index;
}


//SCH_Delete_Task function
uint8_t SCH_Delete_Task(uint32_t taskID)
{
    uint8_t Return_code;

    if (SCH_tasks_G[taskID].pTask == 0)
    {
        Error_code_G = ERROR_SCH_CANNOT_DELETE_TASK;
        Return_code = RETURN_ERROR;
    }
    else
    {
        Return_code = RETURN_NORMAL;
    }

    SCH_tasks_G[taskID].pTask = 0x0000;
    SCH_tasks_G[taskID].Delay = 0;
    SCH_tasks_G[taskID].Period = 0;
    SCH_tasks_G[taskID].RunMe = 0;

    return Return_code;
}



//SCH_Report_Status function
void SCH_Report_Status(void)
{
#ifdef SCH_REPORT_ERRORS
    if (Error_code_G!= Last_error_code_G)
    {
        Error_port = 255 - Error_code_G;
        Last_error_code_G = Error_code_G;

        if (Error_code_G!= 0)
        {
            Error_tick_count_G = 60000;
        }
        else
        {
            Error_tick_count_G = 0;
        }
    }
    else
    {
        if (Error_tick_count_G!= 0)
        {
            if (--Error_tick_count_G == 0)
            {
                Error_code_G = 0;
            }
        }
    }
#endif
}
