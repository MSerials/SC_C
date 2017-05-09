#pragma once


// Controller 对话框

class Controller : public CDialogEx
{
	DECLARE_DYNAMIC(Controller)

public:
	Controller(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Controller();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SYSCTRL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonConveyorcw();
	afx_msg void OnBnClickedButtonConveyorccw();
	afx_msg void OnBnClickedButtonConveyorstop();
};
