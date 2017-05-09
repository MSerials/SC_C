// SawChainMachine.cpp : 实现文件
//

#include "stdafx.h"
#include "SawChain_Check.h"
#include "SawChainMachine.h"


// SawChainMachine

SawChainMachine::SawChainMachine()
	:m_system_state(0)
	, m_counter(0)
	, stack_index(-1)
	
{
	m_knode = (KNODE*)malloc(MAX_NODE*sizeof(KNODE));
}

SawChainMachine::~SawChainMachine()
{
	free(m_knode);
	delete dmc1380;
	dmc1380 = NULL;
}

void SawChainMachine::Init()
{
	dmc1380 = new DMC1380Card();
	if (0 == dmc1380->Init())
	{
		mc_vector.push_back((CMotionCard*)dmc1380);
		stack_index++;	//当前指向的运动卡
	}
	else
	{
		delete dmc1380;
		dmc1380 = NULL;
	}
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

bool SawChainMachine::affinateWindow(CWnd * wnd, HWND hwnd)
{
	return false;
}



int SawChainMachine::get_id_by_position(int counter, int position, int max_node)
{
	if (counter%max_node < position)
		return max_node + counter%max_node - position;
	else
		return (counter - position) % max_node;// - position;
}

float SawChainMachine::check_charater()
{
	return 0.0f;
}

float SawChainMachine::check_charater_train()
{
	return 0.0f;
}

float SawChainMachine::check_charater_predict()
{
	return 0.0f;
}

int SawChainMachine::check_inverse(double threshold, double minarea, double maxarea)
{
	return 0;
}


// SawChainMachine 成员函数

int SawChainMachine::check_knife()
{
	return 0;
}

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

void SawChainMachine::system_reset()
{
	m_counter = 0;
	m_ng_counter = 0;
	memset(m_knode, 0x0, MAX_NODE * sizeof(KNODE));
}

void SawChainMachine::Conveyor_running(int ChainNo)
{
}

UINT SawChainMachine::Procedure()
{
	if (stack_index < 0) return NOCARD;//NoCard
	CMotionCard * mc = mc_vector[stack_index];
	while (CheckAllSensorState()) {
		PushAllCylinderBack();
		AfxMessageBox(L"气缸上限不亮，请检查");
		Sleep(200);
	}
#if 0

	switch (pMainFrm->ConveyorFlag)
	{
	case STOP:	pMainFrm->ConveyorSTOP();		break;
	case CCW:	pMainFrm->ConveyorCCW();		break;
	case CW:	pMainFrm->ConveyorCW();			break;
	default:	mc->EStopMove(0);	exit(1);	break;//退出程序
	}

	while (WAIT_TIMEOUT == ::WaitForSingleObject(evtEStop, 0))
	{
		if (g_bRun && !MotorRunning) { MotorRunning = TRUE; mc->StartTVMove(0, 500, ini->LVEL, ini->dACC); }

		if (TRUE == StartDetect /*&& MotorRunning*/)
		{
			m_bProductTime = GetTickCount();

			//初始化刚进入导轨的连接片状态
			int l_position = pMainFrm->caculate_position(-50); //初始化放在了-40这个位置
			pMainFrm->m_knode[l_position].TopError = pMainFrm->m_knode[l_position].BottomError = NoError;//这个目的是为了进行初始化，把刚进入的连接片状态清0
			pMainFrm->m_knode[l_position].TopKnife = pMainFrm->m_knode[l_position].BottomKnife = NoActivateCamera;//这个目的是为了进行初始化，把刚进入的连接片状态清0，否则会触发相机去判断刀口未磨
			pMainFrm->ScanAllSensor();						//感应器优先扫描，也就是说先扫描出结果后再进行处理
			pMainFrm->StartBottomCamera();					//因为相机从获取图片到处理图片花费时间长，所以排在最前面
			pMainFrm->StartUpCamera();

			if (0 == pMainFrm->m_KnodeCounter%pMainFrm->m_ChainLength - g_RailLenght%pMainFrm->m_ChainLength) //下面这个语句是判断到了打断的那一节点,pMainFrm->m_KnodeCounter%pMainFrm->m_ChainLength保证了循环 //g_RailLenght%pMainFrm->m_ChainLength计算了偏移，如果链条长度小于48，前面的链条也可以进行打断，而不是要等待49节
			{
				//	if(pMainFrm->ChainOrder >= 0)
				//	{
				//	ini->m_TotalCheck ++; 
				//	ini->SetIniDir("ini");
				//	ini->SetIniFile(ini->prj_CurrentProject+".ini");
				//	ini->SaveToFile(PARA_PRJ);	 //保存总检测数，在正常关闭的时候保存这次的检测总数，否则包含了上一次的
				//	}
				CString str;
				str.Format(_T("%d"), ChainNum);
				ope->ShowError(str);

				txt->recordFile.Flush();		//保存错误情况
												//用来记数在打断25节后判断传送带运输情况
				pMainFrm->m_conveyorcounter = 0;

				//这个是用来计算打断链条这一条是第几条
				pMainFrm->ChainOrder = ((pMainFrm->m_KnodeCounter - g_RailLenght) / pMainFrm->m_ChainLength) % g_MAX_CHAIN;//计算当前打断链条的第几条，为了让传送带统计

																														   //打断链条动作
				pMainFrm->Break_chain_action();
			}

			pMainFrm->Chain_Detection();														//对扫描的结果进行计算和检查

			pMainFrm->showAlertInfo();																	//弹出警告框

			if (pMainFrm->m_KnodeCounter < /*g_RailLenght*/(48 + pMainFrm->m_ChainLength))
				pMainFrm->ConveyorCW(); //当检测还没到达49节的时候，整个传送带会反转

										//在打断25节后再进行判断往回跑
			else if (pMainFrm->m_conveyorcounter >= 20)
				pMainFrm->Conveyor_running(pMainFrm->ChainOrder);

			//检测数量自增
			pMainFrm->m_KnodeCounter++;

			//用来记数在打断25节后判断传送带运输情况
			pMainFrm->m_conveyorcounter++;

			m_bProductEndTime = (GetTickCount() - m_bProductTime) / 1000;
			m_DWTotalTime = m_DWTotalTime + m_bProductEndTime;
			::PostMessage(AfxGetMainWnd()->m_hWnd, MSG_SYS_CYC_TIME, (GetTickCount() - m_bProductTime), m_DWTotalTime);

			StartDetect = FALSE;
		}//if(StartDetect)

		if (pMainFrm->Pause()) break;

		if (m_EStop)
		{
			evtEStop.ResetEvent();
		}
#if TEST
#else
		if (::WaitForSingleObject(evtEStop, 0) == WAIT_OBJECT_0)
		{
			AfxMessageBox("wo cao");
			MotorRunning = FALSE;
			mc->EStopMove(0);
			evtEStop.ResetEvent();
			return 1; //结束线程
		}
#endif

	}//while(WAIT_TIMEOUT == ::WaitForSingleObject(evtEStop,0))
	if (m_EStop)
	{
		evtEStop.ResetEvent();
	}
	return TRUE;
#endif
		return NORMAL;
}

UINT SawChainMachine::CheckAllSensorState()
{
	CMotionCard * mc = mc_vector[stack_index];
	return (mc->ReadInPutBit(IN_CYL_Press_UP_SENSOR)
		&& mc->ReadInPutBit(IN_CYL_Push_UP_SENSOR)
		&& mc->ReadInPutBit(IN_CYL_Magnet_SENSOR)
		);
}

void SawChainMachine::PushAllCylinderBack()
{
	CMotionCard * mc = mc_vector[stack_index];
	mc->WriteOutPutBit(OUT_Mark, 1);
	mc->WriteOutPutBit(OUT_CYL_Press, 1);
	mc->WriteOutPutBit(OUT_CYL_Push, 1);
	mc->WriteOutPutBit(OUT_CYL_Magnet, 1);
	mc->WriteOutPutBit(OUT_Magnet, 1);//磁铁断电
}

CMotionCard * SawChainMachine::CurrentMotionCard()
{
	if (stack_index < 0) return nullptr; 
	return mc_vector[stack_index]; 
}

