/****************************************************************************
* File: KeyDrv.c															*
* Description:																*
*																			*
* (C)Copyright Sakura corp. 2021											*
*																			*
* Author: GUAN U															*
* Created Date: 2021/05/04													*
*																			*
****************************************************************************/

/****************************************************************************
*								Include File								*
****************************************************************************/
#include "KeyDrv.h"

/****************************************************************************
*						Private Constant Definition							*
****************************************************************************/
typedef struct _Key_st
{
	TD_UB Enable;
	TD_UB Status; // 0 = non; 1 = Click; 2 = LongPress
	TD_UW LongPressTrigger;
	TD_UDW PressCounter;

} Key_st;

/****************************************************************************
*							Private Global Variable							*
****************************************************************************/
TD_UB BASIC_T_MS_UB;
TD_UW SENSITIVITY_MS_UW;

TD_UB KeyDrv_counter;

//define keys
Key_st sKeys[NUMBER_OF_KEYS];

/****************************************************************************
*								Private Function							*
****************************************************************************/
/*
@brief FreeRun執行時使用 掃描底層按鍵觸發
@param 在FreeRun,或者對NUMBER_OF_KEYS參數做調整
@return 傳遞指標,對傳入做直接更改
*/
void KeyScan(Key_st *aKey, TD_UB aKeyNumber)
{
	if (aKey->Enable)
	{
		aKey->Status = KEY_NON;
		if (KeyHal_KeyStateRead(aKeyNumber) == 1)
		{
			aKey->PressCounter++;
			if (aKey->PressCounter >= aKey->LongPressTrigger)
			{
				aKey->Status = KEY_LONG_PRESS;
			}
		}
		else
		{
			if (aKey->PressCounter > 5 && aKey->PressCounter < SENSITIVITY_MS_UW / BASIC_T_MS_UB)
			{
				aKey->Status = KEY_CLICK;
			}

			aKey->PressCounter = 0;
		}
	}
}

/****************************************************************************
*								Public Function								*
****************************************************************************/
void KeyDrv_Initial(TD_UB aBasic_t_ms_ub, TD_UW aSensitivity_ms_uw)
{
	BASIC_T_MS_UB = aBasic_t_ms_ub;
	SENSITIVITY_MS_UW = aSensitivity_ms_uw;

	for (KeyDrv_counter = 0; KeyDrv_counter < NUMBER_OF_KEYS; KeyDrv_counter++)
	{
		KeyDrv_SetKeyEnable(KeyDrv_counter);

		if (sKeys[KeyDrv_counter].LongPressTrigger == 0)
			sKeys[KeyDrv_counter].LongPressTrigger = 2000 / BASIC_T_MS_UB;
	}
}

void KeyDrv_SetKeyEnable(TD_UB aKeyNumber)
{
	sKeys[aKeyNumber].Enable = 1;
}

void KeyDrv_SetKeyDisable(TD_UB aKeyNumber)
{
	sKeys[aKeyNumber].Enable = 0;
}

void KeyDrv_FreeRun()
{
	for (KeyDrv_counter = 0; KeyDrv_counter < NUMBER_OF_KEYS; KeyDrv_counter++)
		KeyScan(&sKeys[KeyDrv_counter], KeyDrv_counter);
}

void KeyDrv_SetKeyLongPressTrigger(TD_UB aKeyNumber, TD_UW aTime)
{
	sKeys[aKeyNumber].LongPressTrigger = aTime / BASIC_T_MS_UB;
}

TD_UDW KeyDrv_GetKeyPressTime(TD_UB aKeyNumber)
{
	return sKeys[aKeyNumber].PressCounter;
}

TD_UB KeyDrv_GetKeyStatus(TD_UB aKeyNumber)
{
	return sKeys[aKeyNumber].Status;
}

void KeyDrv_ClearKeyStatus(TD_UB aKeyNumber)
{
	sKeys[aKeyNumber].Status = 0;
}