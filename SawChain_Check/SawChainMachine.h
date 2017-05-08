#pragma once



#include "MotionCard.h"
#include "DMC1380Card.h"
#include <vector>

// SawChainMachine 命令目标
//这个机器的类，包含了动作，相机等等

#define MAX_NODE 512						//测试聊条有100节长度


enum
{
	NoError
};

enum
{
	STOP,PAUSE,START
};

class SawChainMachine : public CObject
{
public:
	SawChainMachine();
	virtual ~SawChainMachine();

	virtual void Init();
	//相机静态抓取和动态抓取
	virtual void TopCameraSnap();
	virtual void TopCameraGrap();
	virtual void save_top_camera_image(CString Date);

	virtual void BottomCameraSnap();
	virtual void BottomCameraGrap(); 
	virtual void save_bottom_camera_image(CString Date);

	//附加窗口到halcon
	virtual bool affinateWindow(CWnd * wnd, HWND hwnd);

	//
	virtual int get_id_by_position(int counter, int position, int max_node = MAX_NODE);

	//检测字符,使用hog+svm
	virtual float check_charater();//input parameter and srouce
	virtual float check_charater_train();
	virtual float check_charater_predict();

	//检测连接片装反没有
	virtual int check_inverse(double threshold, double minarea, double maxarea);

	//检测刀片磨了没有
	virtual int check_knife();//

	//action
	virtual void system_start();
	virtual void system_pause();
	virtual void system_stop();
	virtual void system_reset();

	//void Conveyor_running(int ChainNo);
	void Conveyor_running(int ChainNo); 
	static UINT Procedure(LPVOID lParam);
	virtual UINT CheckAllSensorState();

	int get_counter() { return m_counter; }
	std::vector<CMotionCard*> mc_vector;
	
protected:
	DWORD m_TopDoubleKnifeSensor;
	DWORD m_BottomDoubleKnifeSensor;
	DWORD m_TopDaJiSensor;
	DWORD m_BottomDaJiSensor;
	DWORD m_DiedKnodeSensor;
	DWORD m_TopCameraResult; 
	DWORD m_BottomCameraResult;

	CMotionCard * mc;
	
private:
	int m_system_state;
	int m_counter;
	
	int m_ng_counter;
	int stack_index;
	DMC1380Card * dmc1380;

	struct KNODE
	{
		unsigned int TopError; //存储连接片错误类型
		unsigned int BottomError;

		unsigned int TopKnife;  //为了触发相机检测刀口未磨
		unsigned int BottomKnife;

		unsigned int kind; //存储连接片是刀片还是传动片类型
	}*m_knode;
};


