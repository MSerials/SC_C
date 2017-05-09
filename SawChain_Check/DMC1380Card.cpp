#include "stdafx.h"
#include "DMC1380Card.h"
#include "third_party\DMC1380\Dmc1380.h"

#ifdef _WIN64
#pragma comment(lib,"third_party/DMC1380/x64/Dmc1380.lib")
#else
#pragma comment(lib,"third_party/DMC1380/x86/Dmc1380.lib")
#endif

DMC1380Card::DMC1380Card()
{
}


DMC1380Card::~DMC1380Card()
{
}

UINT DMC1380Card::Init()
{
	if (!d1000_board_init()) return 1;
	d1000_set_pls_outmode(0, 0);
	WriteOutPutBit(OUT_SV_ON, 0);
	ConveyorSTOP();
	return 0;
}

std::string DMC1380Card::get_vendor()
{
	return "dmc1380";
}

BOOL DMC1380Card::WriteOutPutBit(short BitNo, short BitData)
{
	return !d1000_out_bit(BitNo, BitData);
}

void DMC1380Card::EStopMove(short axis)
{
	d1000_immediate_stop(axis);
}

void DMC1380Card::StartTMove(short axis, long Dist, long Vel, long MaxVel, double Tacc)
{
	d1000_start_t_move(axis, Dist, Vel, MaxVel, Tacc);
}

void DMC1380Card::StartTVMove(short axis, long strVel, long MaxVel, double Tacc)
{
	d1000_start_tv_move(axis, strVel,MaxVel,Tacc);
}

long DMC1380Card::ReadPosition(short axis)
{
	return d1000_get_command_pos(axis);
}

DWORD DMC1380Card::ReadOutPutBit(short BitNo)
{
	return d1000_get_outbit(BitNo);
}

DWORD DMC1380Card::ReadInPutBit(short BitNo)
{
	return !d1000_in_bit(BitNo);;
}

bool DMC1380Card::WaitSensor(short Bits, long TimeOut)
{
	DWORD tk = GetTickCount();
	for (; d1000_in_bit(Bits);)		
	{
		Sleep(1);
		if ((GetTickCount() - tk) > TimeOut)
			return false;
	}
	return true;
}

bool DMC1380Card::WaitSensorInv(short Bits, long TimeOut)
{
	DWORD tk = GetTickCount();
	for (; !d1000_in_bit(Bits);)		//高电平状态
	{
		Sleep(1);
		if ((GetTickCount() - tk) > TimeOut)
			return false;
	}
	return true;
}

UINT DMC1380Card::WaitSensorTimeOutPos(short ibit, DWORD dwSensorTime, DWORD dwOverTime)
{
	return 0;
}

UINT DMC1380Card::WaitSensorTimeOutNeg(short iPort, UINT iChanIN, DWORD dwSensorTime, DWORD dwOverTime)
{
	return 0;
}

UINT DMC1380Card::WaitMotorDoneTimeOut(short Axis, DWORD dwOverTime)
{
	DWORD tk = GetTickCount();
	for (; !d1000_check_done(Axis);)		//高电平状态
	{
		Sleep(1);
		if ((GetTickCount() - tk) > dwOverTime)
			return false;
	}
	return true;
}

UINT DMC1380Card::StartOrigin()
{
	return 0;
}

void DMC1380Card::ConveyorSTOP()
{
	for(int  i = 0;i<MAX_COUNTER;i++)
	{
	d1000_out_bit(OUT_ConveyerCCW, 1);
	d1000_out_bit(OUT_ConveyerCW, 1);
	}
	SetConveyorState(CONVEYOR_STOP);		
}

void DMC1380Card::ConveyorCCW()
{
	for (int i = 0; i < MAX_COUNTER; i++)
	{
		d1000_out_bit(OUT_ConveyerCCW, 1);
		d1000_out_bit(OUT_ConveyerCW, 0);
	}
	SetConveyorState(CONVEYOR_CCW);
}

void DMC1380Card::ConveyorCW()
{
	for (int i = 0; i < MAX_COUNTER; i++)
	{
		d1000_out_bit(OUT_ConveyerCW, 1);
		d1000_out_bit(OUT_ConveyerCCW, 0);
	}
	SetConveyorState(CONVEYOR_CW);
}
