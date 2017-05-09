#pragma once





#define _HALCON
#ifdef _HALCON

#include "HalconCpp.h"

#ifdef _TEST
#include <iostream>
#include <vector>
using namespace std;
#endif


#ifdef _WIN64
#pragma comment(lib,"third_party/lib/halcon/x64/halconcpp.lib")
#else
#pragma comment(lib,"third_party/lib/halcon/x86/halconcpp.lib")
#endif

#endif
















#define MAX_COUNTER						128


//输送带继电器
#define OUT_ConveyerCW                  14
#define OUT_ConveyerCCW                 15
//伺服使能
#define	OUT_SV_ON						22		











//触发拍照感应器
#define	IN_Start_Camera_SENSOR			1
//打断检测感应器
#define	IN_CHECK_BREAK					3
//预先筛选向上打击和拱起来的
#define	IN_Check_UP_TIPPEDUP			6
//吸扣气缸上限感应器
#define	IN_CYL_Magnet_SENSOR			7
//预先筛选向上打击和拱起来的
#define	IN_Check_BT_TIPPEDUP			8
//启动按钮
#define	IN_START_BTN					16
//停止按钮
#define	IN_BTN_STOP						17
//底部双刀粒感应器
#define	IN_Check_Double_Sword2			18
//Mark3气缸上限
#define	IN_CYL_Mark3_UP_SENSOR			19
//死结感应器，进
#define	IN_CHECK_SENSOR					25
//桌面死结感应器
#define	IN_DIED_KNOED_SENSOR			25
//顶部双刀粒感应器
#define	IN_Check_Double_Sword1			21
//Mark1气缸感应器
#define	IN_CYL_Mark1_UP_SENSOR			22
//接料按钮或者脚踏开关
#define	IN_Foot_Switch					23
//Mark2气缸上限感应器
#define	IN_CYL_Mark2_UP_SENSOR			24
//死结感应器，出
#define	IN_CHECK_SENSOR1				20
//上压气缸上限感应器
#define	IN_CYL_Press_UP_SENSOR			26
//急停按钮
#define	IN_ESTOP_BTN					27
//顶部打机感应器
#define	IN_Check_UP_DaJi				28
//底部打机感应器
#define	IN_Check_BT_DaJi				29
//推链气缸上限感应器
#define	IN_CYL_Push_UP_SENSOR			30


//OutPut
#define OUT_LAMP_START_BTN               9
#define OUT_LAMP_STOP_BTN                10
#define OUT_LAMP_RED_TOWER               12
#define OUT_LAMP_GREEN_TOWER             13
#define OUT_ConveyerCW                   14
#define OUT_ConveyerCCW                  15

/*#define OUT_LAMP_YELLOW_TOWER            14*/
/*#define OUT_TOWER_BUZZER                 15*/

#define OUT_Mark                         23
#define OUT_CYL_Mark2                    17
#define OUT_CYL_Press                    18
#define OUT_CYL_Press_Side               19
#define OUT_CYL_Push                     20
#define OUT_CYL_METER                    21
#define OUT_SV_ON                        22
#define OUT_CYL_Mark3                    24

//#region global variable use for function autorun
#define uchar unsigned char

#define OUT_Magnet						11
#define OUT_JOINT_INDICATOR				13
#define OUT_CYL_Magnet					19





enum ControllerError
{
	NORMAL,
	NOCARD,
	NOPRESSURE
};