/*
 * scheduler.h
 *
 *  Created on: Nov 28, 2024
 *      Author: NTKM
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>

// Task structure
typedef struct {
	void (*pTask)(void);
	uint32_t Delay;
	uint32_t Period;
	uint8_t RunMe;
	uint32_t TaskID;
} sTask;

//MUST BE ADJUSTED FOR EACH NEW PROJECT
#define SCH_MAX_TASKS 40
#define NO_TASK_ID 0

//Error codes
#define ERROR_SCH_TOO_MANY_TASKS 1
#define ERROR_SCH_CANNOT_DELETE_TASK 2
#define RETURN_ERROR 0
#define RETURN_NORMAL 1

void SCH_Init(void);

void SCH_Update(void);

unsigned char SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD);

uint8_t SCH_Delete_Task(uint32_t taskID);

void SCH_Dispatch_Tasks(void);

void SCH_Report_Status(void);

void SCH_Go_To_Sleep(void);

#endif /* INC_SCHEDULER_H_ */
