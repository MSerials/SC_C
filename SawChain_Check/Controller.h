#pragma once


// Controller �Ի���

class Controller : public CDialogEx
{
	DECLARE_DYNAMIC(Controller)

public:
	Controller(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Controller();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SYSCTRL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonConveyorcw();
	afx_msg void OnBnClickedButtonConveyorccw();
	afx_msg void OnBnClickedButtonConveyorstop();
};
