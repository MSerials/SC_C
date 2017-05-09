// Controller.cpp : 实现文件
//

#include "stdafx.h"
#include "SawChain_Check.h"
#include "Controller.h"
#include "afxdialogex.h"
#include "MainFrm.h"


// Controller 对话框

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


// Controller 消息处理程序


void Controller::OnBnClickedButtonConveyorcw()
{
	// TODO: 在此添加控件通知处理程序代码
	CMainFrame * pMain = (CMainFrame *)AfxGetMainWnd();
	CMotionCard * mc = NULL; mc = pMain->SCM.CurrentMotionCard();
	if ((NULL == mc) || (CONVEYOR_CW == mc->GetConveyorState()))	return;							//如果没有板卡，则尽量不发生错误
	mc->ConveyorSTOP();
	Sleep(1000);										//输送带不能够急着改变方向
	mc->ConveyorCW();
}


void Controller::OnBnClickedButtonConveyorccw()
{
	// TODO: 在此添加控件通知处理程序代码
	CMainFrame * pMain = (CMainFrame *)AfxGetMainWnd();
	CMotionCard * mc = NULL; mc = pMain->SCM.CurrentMotionCard();
	if ((NULL == mc) ||(CONVEYOR_CCW == mc->GetConveyorState()))	return;
	mc->ConveyorSTOP();
	Sleep(1000);										//输送带不能够急着改变方向
	mc->ConveyorCCW();
}


void Controller::OnBnClickedButtonConveyorstop()
{
	// TODO: 在此添加控件通知处理程序代码
	CMainFrame * pMain = (CMainFrame *)AfxGetMainWnd();
	CMotionCard * mc = pMain->SCM.CurrentMotionCard();
	if (nullptr == mc)	return;
	mc->ConveyorSTOP();
}
