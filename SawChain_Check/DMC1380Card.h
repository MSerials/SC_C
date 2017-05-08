
#if !defined(AFX_DMC1380_)
#define AFX_DMC1380_
#pragma once

#include "MotionCard.h"



class DMC1380Card : CMotionCard
{
public:
	DMC1380Card();
	~DMC1380Card();

	//override
	UINT Init();
	//override
	std::string get_vendor();
	//override
	BOOL WriteOutPutBit(short BitNo, short BitData);
	//override
	void EStopMove(short axis);
	//override
	void StartTMove(short axis, long Dist, long Vel, long MaxVel, double Tacc);
	//override
	void StartTVMove(short axis, long strVel, long MaxVel, double Tacc);
	//override
	long ReadPosition(short axis);
	//override
	DWORD ReadOutPutBit(short BitNo);
	//override
	DWORD ReadInPutBit(short BitNo);

	bool WaitSensor(short Bits, long TimeOut = 1000);

	bool WaitSensorInv(short Bits, long TimeOut = 1000);

	//override
	UINT WaitSensorTimeOutPos(short ibit, DWORD dwSensorTime, DWORD dwOverTime = 1000);
	//override
	UINT WaitSensorTimeOutNeg(short iPort, UINT iChanIN, DWORD dwSensorTime, DWORD dwOverTime = 1000);
	//override
	UINT WaitMotorDoneTimeOut(short Axis, DWORD dwOverTime = 1000);
	//override
	UINT StartOrigin();
	//���ʹ�ֹͣ
	//override
	void ConveyorSTOP();
	//���ʹ���ת
	//override
	void ConveyorCCW();
	//���ʹ���ת
	//override
	void ConveyorCW();

};


#endif
