/*
 * button.c
 *
 *  Created on: Nov 8, 2024
 *      Author: NTKM
 */

#include "button.h"

int keyReg0[4] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int keyReg1[4] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int keyReg2[4] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int keyReg3[4] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int TimerForKeyPress[4] = {300, 50, 50, 300};

int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;
int button4_flag = 0;

int isButton1Pressed()
{
	if(button1_flag == 1)
	{
		button1_flag = 0;
		return 1;
	}

	return 0;
}

int isButton2Pressed()
{
	if(button2_flag == 1)
	{
		button2_flag = 0;
		return 1;
	}

	return 0;
}

int isButton3Pressed()
{
	if(button3_flag == 1)
	{
		button3_flag = 0;
		return 1;
	}

	return 0;
}

int isButton4Pressed()
{
	if(button4_flag == 1)
	{
		button4_flag = 0;
		return 1;
	}

	return 0;
}

void getButton1()
{
	int i = 0;
	keyReg0[i] = keyReg1[i];
	keyReg1[i] = keyReg2[i];
	keyReg2[i] = HAL_GPIO_ReadPin(button1_GPIO_Port, button1_Pin);

	if((keyReg0[i] == keyReg1[i]) && (keyReg1[i] == keyReg2[i]))
	{
		if(keyReg3[i] != keyReg2[i])
		{
			keyReg3[i] = keyReg2[i];
			if(keyReg2[i] == PRESSED_STATE)
			{
				button1_flag = 1;
				TimerForKeyPress[i] = 300;
			}
		}
		else
		{
			if(keyReg2[i] == PRESSED_STATE)
			{
				TimerForKeyPress[i]--;
				if(TimerForKeyPress[i] == 0)
				{
					button1_flag = 1;
					TimerForKeyPress[i] = 300;
				}
			}
		}
	}
}

void getButton2()
{
	int i = 1;
	keyReg0[i] = keyReg1[i];
	keyReg1[i] = keyReg2[i];
	keyReg2[i] = HAL_GPIO_ReadPin(button2_GPIO_Port, button2_Pin);

	if((keyReg0[i] == keyReg1[i]) && (keyReg1[i] == keyReg2[i]))
	{
		if(keyReg3[i] != keyReg2[i])
		{
			keyReg3[i] = keyReg2[i];
			if(keyReg2[i] == PRESSED_STATE)
			{
				button2_flag = 1;
				TimerForKeyPress[i] = 50;
			}
		}
		else
		{
			if(keyReg2[i] == PRESSED_STATE)
			{
				TimerForKeyPress[i]--;
				if(TimerForKeyPress[i] == 0)
				{
					button2_flag = 1;
					TimerForKeyPress[i] = 50;
				}
			}
		}
	}
}

void getButton3()
{
	int i = 2;
	keyReg0[i] = keyReg1[i];
	keyReg1[i] = keyReg2[i];
	keyReg2[i] = HAL_GPIO_ReadPin(button3_GPIO_Port, button3_Pin);

	if((keyReg0[i] == keyReg1[i]) && (keyReg1[i] == keyReg2[i]))
	{
		if(keyReg3[i] != keyReg2[i])
		{
			keyReg3[i] = keyReg2[i];
			if(keyReg2[i] == PRESSED_STATE)
			{
				button3_flag = 1;
				TimerForKeyPress[i] = 50;
			}
		}
		else
		{
			if(keyReg2[i] == PRESSED_STATE)
			{
				TimerForKeyPress[i]--;
				if(TimerForKeyPress[i] == 0)
				{
					button3_flag = 1;
					TimerForKeyPress[i] = 50;
				}
			}
		}
	}
}

void getButton4()
{
	int i = 3;
	keyReg0[i] = keyReg1[i];
	keyReg1[i] = keyReg2[i];
	keyReg2[i] = HAL_GPIO_ReadPin(button4_GPIO_Port, button4_Pin);

	if((keyReg0[i] == keyReg1[i]) && (keyReg1[i] == keyReg2[i]))
	{
		if(keyReg3[i] != keyReg2[i])
		{
			keyReg3[i] = keyReg2[i];
			if(keyReg2[i] == PRESSED_STATE)
			{
				button4_flag = 1;
				TimerForKeyPress[i] = 300;
			}
		}
		else
		{
			if(keyReg2[i] == PRESSED_STATE)
			{
				TimerForKeyPress[i]--;
				if(TimerForKeyPress[i] == 0)
				{
					button4_flag = 1;
					TimerForKeyPress[i] = 300;
				}
			}
		}
	}
}
