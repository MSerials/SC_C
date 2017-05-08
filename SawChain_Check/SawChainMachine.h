#pragma once

// SawChainMachine ����Ŀ��
//����������࣬�����˶���������ȵ�

#define MAX_NODE 512						//����������100�ڳ���


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
	//�����̬ץȡ�Ͷ�̬ץȡ
	virtual void TopCameraSnap();
	virtual void TopCameraGrap();
	virtual void save_top_camera_image(CString Date);

	virtual void BottomCameraSnap();
	virtual void BottomCameraGrap(); 
	virtual void save_bottom_camera_image(CString Date);

	//���Ӵ��ڵ�halcon
	virtual bool affinateWindow(CWnd * wnd, HWND hwnd);

	//
	virtual int get_id_by_position(int counter, int position, int max_node = MAX_NODE);

	//����ַ�,ʹ��hog+svm
	virtual float check_charater();//input parameter and srouce
	virtual float check_charater_train();
	virtual float check_charater_predict();

	//�������Ƭװ��û��
	virtual int check_inverse(double threshold, double minarea, double maxarea);

	//��⵶Ƭĥ��û��
	virtual int check_knife();//

	virtual void system_start();
	virtual void system_pause();
	virtual void system_stop();

	int get_counter() { return m_counter; }

protected:
	DWORD m_TopDoubleKnifeSensor;
	DWORD m_BottomDoubleKnifeSensor;
	DWORD m_TopDaJiSensor;
	DWORD m_BottomDaJiSensor;
	DWORD m_DiedKnodeSensor;
	DWORD m_TopCameraResult; 
	DWORD m_BottomCameraResult;

private:
	int m_system_state;
	int m_counter;
};


