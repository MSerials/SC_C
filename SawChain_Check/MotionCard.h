#pragma once

// CMotionCard 命令目标


#if !defined(AFX_MOTIONCARD_H__FAF08485_1C98_4A40_AA13_7EAAA74DD9B5__INCLUDED_)
#define AFX_MOTIONCARD_H__FAF08485_1C98_4A40_AA13_7EAAA74DD9B5__INCLUDED_




#include <iostream>
#include <string>
#include <math>




#define TOTAL_CARD_NUM           1
#define MAX_AXIS_LEN             5
#define MAX_IO_NUM               16
#define INPUT_NUM				 16
#define OUTPUT_NUM				 16
#define dwPortCount              2
#define dwPortBit                16
#define EXCUTE_OK				 0

#define STATUS_BIT_NUMS          32
#define RUN_STATUS_BIT           10
#define MIN_COMPAREA_VALUE       1E-6
#define MIN_REL_MOVE_MM          0.001

#define RETURN_OK                0
#define RETURN_CYL_ERROR         252
#define RETURN_ESTOP             254

#define POSDIR                   1
#define NEGDIR                   -1

#define MSG_MOTION_CARD          (WM_USER+100)
#define MSG_IO_CARD				 (WM_USER+101)




class CMotionCard : public CObject
{
public:
	CMotionCard();
	virtual ~CMotionCard();

	//纯虚函数，子类必须去实现这个东西
	virtual std::string get_vendor() = 0;

};




#endif