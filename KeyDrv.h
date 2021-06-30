/****************************************************************************
* File: KeyDrv.h															*
* Description: 將KeyDrv_FreeRun放置在Root, 並依照執行週期對BASIC_T_MS做調整		  *
*																			*
* (C)Copyright Sakura corp. 2021											*
*																			*
* Author: GUAN U															*
* Created Date: 2021/05/04													*
*																			*
****************************************************************************/
#ifndef KEYDRV_H
#define KEYDRV_H

/****************************************************************************
*								Include File								*
****************************************************************************/
#include "KeyHal.h"

/****************************************************************************
*						Private Constant Definition							*
****************************************************************************/
#define KEY_NON 0
#define KEY_CLICK 1
#define KEY_LONG_PRESS 2

/****************************************************************************
*								Public Function								*
****************************************************************************/
/*
@brief 初始化按鍵, 會預先設定長按觸發為二秒, 避免短按無條件被誤認為長按觸發
@param 1.FreeRun執行週期(ms); 2.按鍵debounce(igrone_time_ms)
*/
void KeyDrv_Initial(TD_UB aBasic_t_ms_ub, TD_UW aSensitivity_ms_uw);

/*
@brief 對按鍵進行設定, 設定開啟該按鍵觸發
@param 按鍵名稱, 定義在KeyHal.h
*/
void KeyDrv_SetKeyEnable(TD_UB);

/*
@brief 對按鍵進行設定, 設定關閉該按鍵觸發
@param 按鍵名稱, 定義在KeyHal.h
*/
void KeyDrv_SetKeyDisable(TD_UB);

/*
@brief FreeRun放置在ROOT內, 並依照ROOT執行週期時間設置KeyDrv中的BASIC_T_MS
*/
void KeyDrv_FreeRun();

/*
@brief 對按鍵進行設定, 設定按鍵按下多久會觸發長按功能
@param 1.按鍵名稱, 定義在KeyHal.h; 2.長按時間設定值（ms）
*/
void KeyDrv_SetKeyLongPressTrigger(TD_UB, TD_UW);

/*
@brief 回傳按鍵按壓時間,若按鍵有多種秒數觸發,請使用此函式抓取
@param 按鍵名稱, 定義在KeyHal.h
@return 按下持續時間, 單位ms
*/
TD_UDW KeyDrv_GetKeyPressTime(TD_UB);

/*
@brief 取得按鍵觸發
@param 按鍵名稱, 定義在KeyHal.h
@return 狀態 0.KEY_NON; 1.KEY_CLICK; 2.KEY_LONGPRESS
*/
TD_UB KeyDrv_GetKeyStatus(TD_UB);

/*
@brief 目前會自動執行, 不開放功能, 需使用需改變Key_scan動作原理.
@param 按鍵名稱, 定義在KeyHal.h
*/
void KeyDrv_ClearKeyStatus(TD_UB);


#endif