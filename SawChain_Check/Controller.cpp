// Controller.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SawChain_Check.h"
#include "Controller.h"
#include "afxdialogex.h"
#include "MainFrm.h"


// Controller �Ի���

IMPLEMENT_DYNAMIC(Controller, CDialogEx)

Controller::Controller(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SYSCTRL, pParent)
{

}

Controller::~Controller()
{
}

void Controller::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Controller, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CONVEYORCW, &Controller::OnBnClickedButtonConveyorcw)
	ON_BN_CLICKED(IDC_BUTTON_CONVEYORCCW, &Controller::OnBnClickedButtonConveyorccw)
	ON_BN_CLICKED(IDC_BUTTON_CONVEYORSTOP, &Controller::OnBnClickedButtonConveyorstop)
END_MESSAGE_MAP()


// Controller ��Ϣ�������


void Controller::OnBnClickedButtonConveyorcw()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMainFrame * pMain = (CMainFrame *)AfxGetMainWnd();
	CMotionCard * mc = NULL; mc = pMain->SCM.CurrentMotionCard();
	if ((NULL == mc) || (CONVEYOR_CW == mc->GetConveyorState()))	return;							//���û�а忨����������������
	mc->ConveyorSTOP();
	Sleep(1000);										//���ʹ����ܹ����Ÿı䷽��
	mc->ConveyorCW();
}


void Controller::OnBnClickedButtonConveyorccw()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMainFrame * pMain = (CMainFrame *)AfxGetMainWnd();
	CMotionCard * mc = NULL; mc = pMain->SCM.CurrentMotionCard();
	if ((NULL == mc) ||(CONVEYOR_CCW == mc->GetConveyorState()))	return;
	mc->ConveyorSTOP();
	Sleep(1000);										//���ʹ����ܹ����Ÿı䷽��
	mc->ConveyorCCW();
}


void Controller::OnBnClickedButtonConveyorstop()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMainFrame * pMain = (CMainFrame *)AfxGetMainWnd();
	CMotionCard * mc = pMain->SCM.CurrentMotionCard();
	if (nullptr == mc)	return;
	mc->ConveyorSTOP();
}
