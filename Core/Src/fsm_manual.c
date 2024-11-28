/*
 * fsm_manual.c
 *
 *  Created on: Nov 12, 2024
 *      Author: NTKM
 */

#include "fsm_manual.h"

int red_yellow_green_manual_time[3] = {0, 0, 0};

int check_sync_red = 0;
int check_sync_yellow = 0;
int check_sync_green = 0;

int check_button2_red = 0;
int check_button2_yellow = 0;
int check_button2_green = 0;

int check_button3_red = 0;
int check_button3_yellow = 0;
int check_button3_green = 0;

void fsm_setting()
{

	switch(status_horizontal)
	{
	case INIT_AUTO:
	{
		if(isButton1Pressed() == 1)
		{
			status_horizontal = INIT_MANUAL;
			status_vertical = INIT_MANUAL;
		}
		break;
	}
	case AUTO_RED:
	{
		if(isButton1Pressed() == 1)
		{
			status_horizontal = INIT_MANUAL;
			status_vertical = INIT_MANUAL;
		}
		break;
	}
	case AUTO_YELLOW:
	{
		if(isButton1Pressed() == 1)
		{
			status_horizontal = INIT_MANUAL;
			status_vertical = INIT_MANUAL;
		}
		break;
	}
	case AUTO_GREEN:
	{
		if(isButton1Pressed() == 1)
		{
			status_horizontal = INIT_MANUAL;
			status_vertical = INIT_MANUAL;
		}
		break;
	}
	case MANUAL_RED:
	{
		if(isButton1Pressed() == 1)
		{
			status_horizontal = MANUAL_YELLOW;
			status_vertical = MANUAL_YELLOW;
			setTimerAuto(10000);
			setTimerBlinking(500);
		}

		if(isButton2Pressed() == 1)
		{
			check_button2_red = 1;

			if(red_yellow_green_manual_time[0] <= 99 && red_yellow_green_manual_time[0] >= 1)
			{
				red_yellow_green_manual_time[0]++;
			}
			else
			{
				red_yellow_green_manual_time[0] = 1;
			}
			setTimerAuto(10000);
		}

		if(isButton3Pressed() == 1)
		{
			check_button3_red = 1;

			if(red_yellow_green_manual_time[0] <= 99 && red_yellow_green_manual_time[0] >= 1)
			{
				red_yellow_green_manual_time[0]--;
			}
			else
			{
				red_yellow_green_manual_time[0] = 1;
			}
			setTimerAuto(10000);
		}

		if(isButton4Pressed() == 1)
		{
			status_horizontal = INIT_AUTO;
			status_vertical = INIT_AUTO;
			timerAuto_flag = 0;
		}
		break;
	}
	case MANUAL_YELLOW:
	{
		if(isButton1Pressed() == 1)
		{
			status_horizontal = MANUAL_GREEN;
			status_vertical = MANUAL_GREEN;
			setTimerAuto(10000);
			setTimerBlinking(500);
		}

		if(isButton2Pressed() == 1)
		{
			check_button2_yellow = 1;

			if(red_yellow_green_manual_time[1] <= 99 && red_yellow_green_manual_time[1] >= 1)
			{
				red_yellow_green_manual_time[1]++;
			}
			else
			{
				red_yellow_green_manual_time[1] = 1;
			}
			setTimerAuto(10000);
		}

		if(isButton3Pressed() == 1)
		{
			check_button3_yellow = 1;

			if(red_yellow_green_manual_time[1] <= 99 && red_yellow_green_manual_time[1] >= 1)
			{
				red_yellow_green_manual_time[1]--;
			}
			else
			{
				red_yellow_green_manual_time[1] = 1;
			}
			setTimerAuto(10000);
		}

		if(isButton4Pressed() == 1)
		{
			if((check_button2_red == 1 || check_button3_red == 1) && (check_button2_yellow == 1 || check_button3_yellow == 1))
			{
				red_yellow_green_manual_time[2] = red_yellow_green_manual_time[0] - red_yellow_green_manual_time[1];

				if(red_yellow_green_manual_time[1] < red_yellow_green_manual_time[2]
				&& red_yellow_green_manual_time[1] < red_yellow_green_manual_time[0])
				{
					red_yellow_green_auto_time_horizontal[0] = red_yellow_green_manual_time[0];
					red_yellow_green_auto_time_vertical[0] = red_yellow_green_manual_time[0];

					red_yellow_green_auto_time_horizontal[1] = red_yellow_green_manual_time[1];
					red_yellow_green_auto_time_vertical[1] = red_yellow_green_manual_time[1];

					red_yellow_green_auto_time_horizontal[2] = red_yellow_green_manual_time[2];
					red_yellow_green_auto_time_vertical[2] = red_yellow_green_manual_time[2];
				}

			}

			status_horizontal = INIT_AUTO;
			status_vertical = INIT_AUTO;
			timerAuto_flag = 0;
		}
		break;
	}
	case MANUAL_GREEN:
	{
		if(isButton1Pressed() == 1)
		{
			status_horizontal = INIT_AUTO;
			status_vertical = INIT_AUTO;
		}

		if(isButton2Pressed() == 1)
		{
			check_button2_green = 1;

			if(red_yellow_green_manual_time[2] <= 99 && red_yellow_green_manual_time[2] >= 1)
			{
				red_yellow_green_manual_time[2]++;
			}
			else
			{
				red_yellow_green_manual_time[2] = 1;
			}
			setTimerAuto(10000);
		}

		if(isButton3Pressed() == 1)
		{
			check_button3_green = 1;

			if(red_yellow_green_manual_time[2] <= 99 && red_yellow_green_manual_time[2] >= 1)
			{
				red_yellow_green_manual_time[2]--;
			}
			else
			{
				red_yellow_green_manual_time[2] = 1;
			}
			setTimerAuto(10000);
		}

		if(isButton4Pressed() == 1)
		{
			if((check_button2_red == 1 || check_button3_red == 1) && (check_button2_yellow == 1 || check_button3_yellow == 1))
			{
				red_yellow_green_manual_time[2] = red_yellow_green_manual_time[0] - red_yellow_green_manual_time[1];

				if(red_yellow_green_manual_time[1] < red_yellow_green_manual_time[2]
				&& red_yellow_green_manual_time[1] < red_yellow_green_manual_time[0])
				{
					red_yellow_green_auto_time_horizontal[0] = red_yellow_green_manual_time[0];
					red_yellow_green_auto_time_vertical[0] = red_yellow_green_manual_time[0];

					red_yellow_green_auto_time_horizontal[1] = red_yellow_green_manual_time[1];
					red_yellow_green_auto_time_vertical[1] = red_yellow_green_manual_time[1];

					red_yellow_green_auto_time_horizontal[2] = red_yellow_green_manual_time[2];
					red_yellow_green_auto_time_vertical[2] = red_yellow_green_manual_time[2];
				}

			}
			else if((check_button2_red == 1 || check_button3_red == 1) && (check_button2_green == 1 || check_button3_green == 1))
			{
				red_yellow_green_manual_time[1] = red_yellow_green_manual_time[0] - red_yellow_green_manual_time[2];

				if(red_yellow_green_manual_time[1] < red_yellow_green_manual_time[2]
				&& red_yellow_green_manual_time[1] < red_yellow_green_manual_time[0])
				{
					red_yellow_green_auto_time_horizontal[0] = red_yellow_green_manual_time[0];
					red_yellow_green_auto_time_vertical[0] = red_yellow_green_manual_time[0];

					red_yellow_green_auto_time_horizontal[1] = red_yellow_green_manual_time[1];
					red_yellow_green_auto_time_vertical[1] = red_yellow_green_manual_time[1];

					red_yellow_green_auto_time_horizontal[2] = red_yellow_green_manual_time[2];
					red_yellow_green_auto_time_vertical[2] = red_yellow_green_manual_time[2];
				}

			}
			else if((check_button2_yellow == 1 || check_button3_yellow == 1) && (check_button2_green == 1 || check_button3_green == 1))
			{
				red_yellow_green_manual_time[0] = red_yellow_green_manual_time[1] + red_yellow_green_manual_time[2];

				if(red_yellow_green_manual_time[1] < red_yellow_green_manual_time[2]
				&& red_yellow_green_manual_time[1] < red_yellow_green_manual_time[0])
				{
					red_yellow_green_auto_time_horizontal[0] = red_yellow_green_manual_time[0];
					red_yellow_green_auto_time_vertical[0] = red_yellow_green_manual_time[0];

					red_yellow_green_auto_time_horizontal[1] = red_yellow_green_manual_time[1];
					red_yellow_green_auto_time_vertical[1] = red_yellow_green_manual_time[1];

					red_yellow_green_auto_time_horizontal[2] = red_yellow_green_manual_time[2];
					red_yellow_green_auto_time_vertical[2] = red_yellow_green_manual_time[2];
				}

			}
			else if((check_button2_red == 1 || check_button3_red == 1) && (check_button2_yellow == 1 || check_button3_yellow == 1) && (check_button2_green == 1 || check_button3_green == 1))
			{

				if(red_yellow_green_manual_time[1] < red_yellow_green_manual_time[2]
				&& red_yellow_green_manual_time[1] < red_yellow_green_manual_time[0]
				&& red_yellow_green_manual_time[0] == red_yellow_green_manual_time[1] + red_yellow_green_manual_time[2])
				{
					red_yellow_green_auto_time_horizontal[0] = red_yellow_green_manual_time[0];
					red_yellow_green_auto_time_vertical[0] = red_yellow_green_manual_time[0];

					red_yellow_green_auto_time_horizontal[1] = red_yellow_green_manual_time[1];
					red_yellow_green_auto_time_vertical[1] = red_yellow_green_manual_time[1];

					red_yellow_green_auto_time_horizontal[2] = red_yellow_green_manual_time[2];
					red_yellow_green_auto_time_vertical[2] = red_yellow_green_manual_time[2];
				}

			}

			status_horizontal = INIT_AUTO;
			status_vertical = INIT_AUTO;
			timerAuto_flag = 0;
		}
		break;
	}
	}

}

void fsm_manual()
{
	switch(status_horizontal)
	{
	case INIT_MANUAL:
	{
		for(int i = 0; i < 3; i++)
		{
			red_yellow_green_manual_time[i] = red_yellow_green_auto_time_horizontal[i];
		}

		setTimerAuto(10000);
		setTimerBlinking(500);

		check_button2_red = 0;
		check_button2_yellow = 0;
		check_button2_green = 0;

		check_button3_red = 0;
		check_button3_yellow = 0;
		check_button3_green = 0;

		check_sync_red = 0;
		check_sync_yellow = 0;
		check_sync_green = 0;

		EN_horizontal = 1;
		EN_vertical = 1;
		status_horizontal = MANUAL_RED;
		break;
	}
	case MANUAL_RED:
	{

		if(check_sync_red == 0)
		{
			check_sync_red = 1;
			HAL_GPIO_WritePin(yellow1_GPIO_Port, red1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(yellow2_GPIO_Port, red2_Pin, GPIO_PIN_SET);
		}

		if(timerBlinking_flag == 1)
		{
			HAL_GPIO_TogglePin(red1_GPIO_Port, red1_Pin);
			HAL_GPIO_TogglePin(red2_GPIO_Port, red2_Pin);

			setTimerBlinking(500);
		}

		HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, GPIO_PIN_RESET);

		if(timerAuto_flag == 1)
		{
			status_horizontal = INIT_AUTO;
			status_vertical = INIT_AUTO;
		}

		break;
	}
	case MANUAL_YELLOW:
	{

		if(check_sync_yellow == 0)
		{
			check_sync_yellow = 1;
			HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, GPIO_PIN_SET);
		}

		if(timerBlinking_flag == 1)
		{
			HAL_GPIO_TogglePin(yellow1_GPIO_Port, yellow1_Pin);
			HAL_GPIO_TogglePin(yellow2_GPIO_Port, yellow2_Pin);

			setTimerBlinking(500);
		}

		HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, GPIO_PIN_RESET);

		if(timerAuto_flag == 1)
		{
			status_horizontal = INIT_AUTO;
			status_vertical = INIT_AUTO;
		}

		break;
	}
	case MANUAL_GREEN:
	{

		if(check_sync_green == 0)
		{
			check_sync_green = 1;
			HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, GPIO_PIN_SET);
		}

		if(timerBlinking_flag == 1)
		{
			HAL_GPIO_TogglePin(green1_GPIO_Port, green1_Pin);
			HAL_GPIO_TogglePin(green2_GPIO_Port, green2_Pin);

			setTimerBlinking(500);
		}

		HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, GPIO_PIN_RESET);

		if(timerAuto_flag == 1)
		{
			status_horizontal = INIT_AUTO;
			status_vertical = INIT_AUTO;
		}

		break;
	}

	}

}
