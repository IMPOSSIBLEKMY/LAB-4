/*
 * fsm_auto.c
 *
 *  Created on: Nov 12, 2024
 *      Author: NTKM
 */

#include "fsm_auto.h"

int red_yellow_green_auto_time_vertical[3] = {5, 2, 3};
int red_yellow_green_auto_time_horizontal[3] = {5, 2, 3};

int horizontal_counter = -1;
int vertical_counter = -1;

int status_horizontal = AUTO_RED;
int status_vertical = AUTO_GREEN;

void fsm_automatic()
{
	fsm_auto_horizontal();

	fsm_auto_vertical();
}

void fsm_auto_horizontal()
{
	switch(status_horizontal)
	{
	case AUTO_RED:
	{
		HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, GPIO_PIN_RESET);

		horizontal_counter++;

		if(red_yellow_green_auto_time_horizontal[0] == horizontal_counter)
		{
			horizontal_counter = 0;
			status_horizontal = AUTO_GREEN;
		}

		break;
	}
	case AUTO_YELLOW:
	{
		HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, GPIO_PIN_RESET);

		horizontal_counter++;

		if(red_yellow_green_auto_time_horizontal[1] == horizontal_counter)
		{
			horizontal_counter = 0;
			status_horizontal = AUTO_RED;
		}

		break;
	}
	case AUTO_GREEN:
	{
		HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, GPIO_PIN_SET);

		horizontal_counter++;

		if(red_yellow_green_auto_time_horizontal[2] == horizontal_counter)
		{
			horizontal_counter = 0;
			status_horizontal = AUTO_YELLOW;
		}

		break;
	}
	default:
		break;
	}

}

void fsm_auto_vertical()
{

	switch(status_vertical)
	{
	case AUTO_RED:
	{
		HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, GPIO_PIN_RESET);

		vertical_counter++;

		if(red_yellow_green_auto_time_vertical[0] == vertical_counter)
		{
			vertical_counter = 0;
			status_vertical = AUTO_GREEN;
		}

		break;
	}
	case AUTO_YELLOW:
	{
		HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, GPIO_PIN_RESET);

		vertical_counter++;

		if(red_yellow_green_auto_time_vertical[1] == vertical_counter)
		{
			vertical_counter = 0;
			status_vertical = AUTO_RED;
		}

		break;
	}
	case AUTO_GREEN:
	{
		HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, GPIO_PIN_SET);

		vertical_counter++;

		if(red_yellow_green_auto_time_vertical[2] == vertical_counter)
		{
			vertical_counter = 0;
			status_vertical = AUTO_YELLOW;
		}

		break;
	}
	default:
		break;
	}

}
