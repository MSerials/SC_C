// MotionCard.cpp : 实现文件
//

#include "stdafx.h"
#include "SawChain_Check.h"
#include "MotionCard.h"


// CMotionCard

CMotionCard::CMotionCard()
{
}

CMotionCard::~CMotionCard()
{
}


// CMotionCard 成员函数

UINT CMotionCard::StartOrigin()
{
	return 0;
}

BOOL CMotionCard::InitMotionCard(short iCardNum)
{
	return 0;
}

BOOL CMotionCard::ScanMotionCard(HWND hWnd, UINT iMsg)
{
	return 0;
}

BOOL CMotionCard::ResumeScanThread()
{
	return 0;
}

BOOL CMotionCard::SuspendScanThread()
{
	return 0;
}

BOOL CMotionCard::WaitMoveDone(short iAxis)
{
	return 0;
}

BOOL CMotionCard::CheckEStop(DWORD dwOverTime, short iCardID, short iAxis)
{
	return 0;
}

long CMotionCard::UnitToPulse(short iAxis, const double dValue)
{
	return 0;
}

double CMotionCard::PulseToUnit(short iAxis, const long dValue)
{
	return 0.0;
}

std::string CMotionCard::get_vendor()
{
	return "none";
}

BOOL CMotionCard::WriteOutPutBit(short BitNo, short BitData)
{
	return 0;
}

void CMotionCard::EStopMove(short axis)
{
}

void CMotionCard::StartTMove(short axis, long Dist, long Vel, long MaxVel, double Tacc)
{
}

void CMotionCard::StartTVMove(short axis, long strVel, long MaxVel, double Tacc)
{
}

long CMotionCard::ReadPosition(short axis)
{
	return 0;
}

DWORD CMotionCard::ReadOutPutBit(short BitNo)
{
	return 0;
}

DWORD CMotionCard::ReadInPutBit(short BitNo)
{
	return 0;
}

UINT CMotionCard::WaitSensorTimeOutPos(short ibit, DWORD dwSensorTime, DWORD dwOverTime)
{
	return 0;
}

UINT CMotionCard::WaitSensorTimeOutNeg(short iPort, UINT iChanIN, DWORD dwSensorTime, DWORD dwOverTime)
{
	return 0;
}

UINT CMotionCard::WaitMotorDoneTimeOut(short Axis, DWORD dwOverTime)
{
	return 0;
}
