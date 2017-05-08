// SawChainMachine.cpp : 实现文件
//

#include "stdafx.h"
#include "SawChain_Check.h"
#include "SawChainMachine.h"


// SawChainMachine

SawChainMachine::SawChainMachine()
:m_system_state(0)
,m_counter(0)
{
}

SawChainMachine::~SawChainMachine()
{
}

void SawChainMachine::Init()
{
}

void SawChainMachine::TopCameraSnap()
{
}

void SawChainMachine::TopCameraGrap()
{
}

void SawChainMachine::save_top_camera_image(CString Date)
{
}

void SawChainMachine::BottomCameraSnap()
{
}

void SawChainMachine::BottomCameraGrap()
{
}

void SawChainMachine::save_bottom_camera_image(CString Date)
{
}

int SawChainMachine::get_id_by_position(int counter, int position, int max_node)
{
	if (counter%max_node < position)
		return max_node + counter%max_node - position;
	else
		return (counter - position) % max_node;// - position;
}


// SawChainMachine 成员函数

void SawChainMachine::system_start()
{
	m_system_state = START;
}

void SawChainMachine::system_pause()
{
	m_system_state = PAUSE;
}

void SawChainMachine::system_stop()
{
	m_system_state = STOP;
}
