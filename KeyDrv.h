/****************************************************************************
* File: KeyDrv.h															*
* Description: �NKeyDrv_FreeRun��m�bRoot, �è̷Ӱ���g����BASIC_T_MS���վ�		  *
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
@brief ��l�ƫ���, �|�w���]�w����Ĳ�o���G��, �קK�u���L����Q�~�{������Ĳ�o
@param 1.FreeRun����g��(ms); 2.����debounce(igrone_time_ms)
*/
void KeyDrv_Initial(TD_UB aBasic_t_ms_ub, TD_UW aSensitivity_ms_uw);

/*
@brief �����i��]�w, �]�w�}�Ҹӫ���Ĳ�o
@param ����W��, �w�q�bKeyHal.h
*/
void KeyDrv_SetKeyEnable(TD_UB);

/*
@brief �����i��]�w, �]�w�����ӫ���Ĳ�o
@param ����W��, �w�q�bKeyHal.h
*/
void KeyDrv_SetKeyDisable(TD_UB);

/*
@brief FreeRun��m�bROOT��, �è̷�ROOT����g���ɶ��]�mKeyDrv����BASIC_T_MS
*/
void KeyDrv_FreeRun();

/*
@brief �����i��]�w, �]�w������U�h�[�|Ĳ�o�����\��
@param 1.����W��, �w�q�bKeyHal.h; 2.�����ɶ��]�w�ȡ]ms�^
*/
void KeyDrv_SetKeyLongPressTrigger(TD_UB, TD_UW);

/*
@brief �^�ǫ�������ɶ�,�Y���䦳�h�ج��Ĳ�o,�ШϥΦ��禡���
@param ����W��, �w�q�bKeyHal.h
@return ���U����ɶ�, ���ms
*/
TD_UDW KeyDrv_GetKeyPressTime(TD_UB);

/*
@brief ���o����Ĳ�o
@param ����W��, �w�q�bKeyHal.h
@return ���A 0.KEY_NON; 1.KEY_CLICK; 2.KEY_LONGPRESS
*/
TD_UB KeyDrv_GetKeyStatus(TD_UB);

/*
@brief �ثe�|�۰ʰ���, ���}��\��, �ݨϥλݧ���Key_scan�ʧ@��z.
@param ����W��, �w�q�bKeyHal.h
*/
void KeyDrv_ClearKeyStatus(TD_UB);


#endif