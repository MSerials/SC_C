// SawChainMachine.cpp : ʵ���ļ�
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
		stack_index++;	//��ǰָ����˶���
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


// SawChainMachine ��Ա����

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
		AfxMessageBox(L"�������޲���������");
		Sleep(200);
	}
#if 0

	switch (pMainFrm->ConveyorFlag)
	{
	case STOP:	pMainFrm->ConveyorSTOP();		break;
	case CCW:	pMainFrm->ConveyorCCW();		break;
	case CW:	pMainFrm->ConveyorCW();			break;
	default:	mc->EStopMove(0);	exit(1);	break;//�˳�����
	}

	while (WAIT_TIMEOUT == ::WaitForSingleObject(evtEStop, 0))
	{
		if (g_bRun && !MotorRunning) { MotorRunning = TRUE; mc->StartTVMove(0, 500, ini->LVEL, ini->dACC); }

		if (TRUE == StartDetect /*&& MotorRunning*/)
		{
			m_bProductTime = GetTickCount();

			//��ʼ���ս��뵼�������Ƭ״̬
			int l_position = pMainFrm->caculate_position(-50); //��ʼ��������-40���λ��
			pMainFrm->m_knode[l_position].TopError = pMainFrm->m_knode[l_position].BottomError = NoError;//���Ŀ����Ϊ�˽��г�ʼ�����Ѹս��������Ƭ״̬��0
			pMainFrm->m_knode[l_position].TopKnife = pMainFrm->m_knode[l_position].BottomKnife = NoActivateCamera;//���Ŀ����Ϊ�˽��г�ʼ�����Ѹս��������Ƭ״̬��0������ᴥ�����ȥ�жϵ���δĥ
			pMainFrm->ScanAllSensor();						//��Ӧ������ɨ�裬Ҳ����˵��ɨ���������ٽ��д���
			pMainFrm->StartBottomCamera();					//��Ϊ����ӻ�ȡͼƬ������ͼƬ����ʱ�䳤������������ǰ��
			pMainFrm->StartUpCamera();

			if (0 == pMainFrm->m_KnodeCounter%pMainFrm->m_ChainLength - g_RailLenght%pMainFrm->m_ChainLength) //�������������жϵ��˴�ϵ���һ�ڵ�,pMainFrm->m_KnodeCounter%pMainFrm->m_ChainLength��֤��ѭ�� //g_RailLenght%pMainFrm->m_ChainLength������ƫ�ƣ������������С��48��ǰ�������Ҳ���Խ��д�ϣ�������Ҫ�ȴ�49��
			{
				//	if(pMainFrm->ChainOrder >= 0)
				//	{
				//	ini->m_TotalCheck ++; 
				//	ini->SetIniDir("ini");
				//	ini->SetIniFile(ini->prj_CurrentProject+".ini");
				//	ini->SaveToFile(PARA_PRJ);	 //�����ܼ�������������رյ�ʱ�򱣴���εļ�������������������һ�ε�
				//	}
				CString str;
				str.Format(_T("%d"), ChainNum);
				ope->ShowError(str);

				txt->recordFile.Flush();		//����������
												//���������ڴ��25�ں��жϴ��ʹ��������
				pMainFrm->m_conveyorcounter = 0;

				//���������������������һ���ǵڼ���
				pMainFrm->ChainOrder = ((pMainFrm->m_KnodeCounter - g_RailLenght) / pMainFrm->m_ChainLength) % g_MAX_CHAIN;//���㵱ǰ��������ĵڼ�����Ϊ���ô��ʹ�ͳ��

																														   //�����������
				pMainFrm->Break_chain_action();
			}

			pMainFrm->Chain_Detection();														//��ɨ��Ľ�����м���ͼ��

			pMainFrm->showAlertInfo();																	//���������

			if (pMainFrm->m_KnodeCounter < /*g_RailLenght*/(48 + pMainFrm->m_ChainLength))
				pMainFrm->ConveyorCW(); //����⻹û����49�ڵ�ʱ���������ʹ��ᷴת

										//�ڴ��25�ں��ٽ����ж�������
			else if (pMainFrm->m_conveyorcounter >= 20)
				pMainFrm->Conveyor_running(pMainFrm->ChainOrder);

			//�����������
			pMainFrm->m_KnodeCounter++;

			//���������ڴ��25�ں��жϴ��ʹ��������
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
			return 1; //�����߳�
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
	mc->WriteOutPutBit(OUT_Magnet, 1);//�����ϵ�
}

CMotionCard * SawChainMachine::CurrentMotionCard()
{
	if (stack_index < 0) return nullptr; 
	return mc_vector[stack_index]; 
}

