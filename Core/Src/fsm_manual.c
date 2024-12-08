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

int auto_count = 20;

void fsm_manual()
{
	switch(status_horizontal)
	{
	case AUTO_RED:
	{
		if(isButton1Pressed() == 1)
		{
			for(int i = 0; i < 3; i++)
			{
				red_yellow_green_manual_time[i] = red_yellow_green_auto_time_horizontal[i];
			}

			check_sync_red = 0;
			check_sync_yellow = 0;
			check_sync_green = 0;

			check_button2_red = 0;
			check_button2_yellow = 0;
			check_button2_green = 0;

			check_button3_red = 0;
			check_button3_yellow = 0;
			check_button3_green = 0;

			status_horizontal = MANUAL_RED;
			status_vertical = MANUAL_RED;
		}
		break;
	}
	case AUTO_YELLOW:
	{
		if(isButton1Pressed() == 1)
		{
			for(int i = 0; i < 3; i++)
			{
				red_yellow_green_manual_time[i] = red_yellow_green_auto_time_horizontal[i];
			}

			check_sync_red = 0;
			check_sync_yellow = 0;
			check_sync_green = 0;

			check_button2_red = 0;
			check_button2_yellow = 0;
			check_button2_green = 0;

			check_button3_red = 0;
			check_button3_yellow = 0;
			check_button3_green = 0;

			status_horizontal = MANUAL_RED;
			status_vertical = MANUAL_RED;
		}
		break;
	}
	case AUTO_GREEN:
	{
		if(isButton1Pressed() == 1)
		{
			for(int i = 0; i < 3; i++)
			{
				red_yellow_green_manual_time[i] = red_yellow_green_auto_time_horizontal[i];
			}

			check_sync_red = 0;
			check_sync_yellow = 0;
			check_sync_green = 0;

			check_button2_red = 0;
			check_button2_yellow = 0;
			check_button2_green = 0;

			check_button3_red = 0;
			check_button3_yellow = 0;
			check_button3_green = 0;

			status_horizontal = MANUAL_RED;
			status_vertical = MANUAL_RED;
		}
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

		HAL_GPIO_TogglePin(red1_GPIO_Port, red1_Pin);
		HAL_GPIO_TogglePin(red2_GPIO_Port, red2_Pin);

		HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, GPIO_PIN_RESET);

		if(isButton1Pressed() == 1)
		{
			status_horizontal = MANUAL_YELLOW;
			status_vertical = MANUAL_YELLOW;

			auto_count = 20;
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

			auto_count = 20;
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

			auto_count = 20;
		}

		if(isButton4Pressed() == 1)
		{
			status_horizontal = AUTO_RED;
			status_vertical = AUTO_GREEN;
		}

		if(auto_count > 0)
		{
			auto_count--;
		}
		else
		{
			status_horizontal = AUTO_RED;
			status_vertical = AUTO_GREEN;
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

		HAL_GPIO_TogglePin(yellow1_GPIO_Port, yellow1_Pin);
		HAL_GPIO_TogglePin(yellow2_GPIO_Port, yellow2_Pin);


		HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, GPIO_PIN_RESET);

		if(isButton1Pressed() == 1)
		{
			status_horizontal = MANUAL_GREEN;
			status_vertical = MANUAL_GREEN;

			auto_count = 20;
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

			auto_count = 20;
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

			auto_count = 20;
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

			status_horizontal = AUTO_RED;
			status_vertical = AUTO_GREEN;
		}

		if(auto_count > 0)
		{
			auto_count--;
		}
		else
		{
			status_horizontal = AUTO_RED;
			status_vertical = AUTO_GREEN;
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

		HAL_GPIO_TogglePin(green1_GPIO_Port, green1_Pin);
		HAL_GPIO_TogglePin(green2_GPIO_Port, green2_Pin);


		HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, GPIO_PIN_RESET);

		if(isButton1Pressed() == 1)
		{
			status_horizontal = AUTO_RED;
			status_vertical = AUTO_GREEN;
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

			auto_count = 20;
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

			auto_count = 20;
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

			status_horizontal = AUTO_RED;
			status_vertical = AUTO_GREEN;
		}

		if(auto_count > 0)
		{
			auto_count--;
		}
		else
		{
			status_horizontal = AUTO_RED;
			status_vertical = AUTO_GREEN;
		}

		break;
	}

	}

}
