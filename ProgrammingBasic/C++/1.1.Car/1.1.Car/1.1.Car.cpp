#include <iostream>
#include <stdlib.h> //�޸� �����Ҵ� ���
#include <crtdbg.h> //�޸� ���� Ž�� ���

using namespace std;
//�߻�ȭ? � ������ ���� ��� �ʿ��� ������ ����°�.
//�ڵ��� ����
//1. �õ��� �Ǵ�.
//2. �� D�� �ٲ۴�.
//3. �׼��� ��´�.
//4. �����ϰų� ���⶧, �극��ũ�� ��´�.
//������(�Ӽ�): �õ�(bool),���(enum P,R,D),�ӵ�(int)
//�˰���(����): �õ��ɱ�/����, ����,  �׼�-�ӵ�����, �극��ũ-�ӵ�����
//5. ������ ���¸� �˼����� -> ����� �ʿ�. -> ��°�� �ʱ�ȭ�� �ȵ�. -> �ٸ���ü�� �����ϱ� ����� -> ������ �߰�
class CCar
{
public: //Ŭ���� �ܺο��� ���ٰ����Ѱ�.
	enum EGEAR { P, R, N, D };

	void On() { m_isOn = true; }
	void Off() { m_isOn = false; }
	//Setter/Getter: ��������� �����ϵ��� �����ϴ� �Լ�. �뵵�� ���� ���ѵɼ�������.. ��Ģ�����δ� ��� �߰��ϴ� ���� ����.
	void SetGear(EGEAR gear) { m_eGear = gear; }
	EGEAR GetGear() { return m_eGear; } //????
	//void SetSpeed(int speed) { m_nSpeed = speed; }//���������� �Ұ�����.
	int GetSpeed() { return m_nSpeed; } //�ڵ����� �ӵ��� �ܺο����� ���������ϴ�.
	void SetColor(string color) { m_strColor = color; } //��빮���� �ֱ������� ������. ������ �����Ҽ��� �ִ�(����������)
	string GetColor() { return m_strColor; } //������ ���� ������ �����ִ�.
	void Accel() { m_nSpeed++; }
	void Break() { m_nSpeed--; }
	void DashBoard() 
	{ 
		cout << "###### " << this << " ######" << endl;
		cout << "Color:" << m_strColor << endl;
		cout << "Speed:" << m_nSpeed << endl; 
		cout << "Gear:" << m_eGear << endl;
		cout << "On:" << m_isOn << endl;
	}
	//CCar()//����Ʈ ������: �Ű������� ���� ������ //�����ڵ� �����ε� �����ϴ�.
	//{
	//	cout << "CCar[" << this << "]" << endl;
	//	m_isOn = false;
	//	m_eGear = EGEAR::N;
	//	m_nSpeed = 0;
	//	m_strColor = "white";
	//}
//�����ڰ� private�̸� ��ü�� �����Ҽ������Ƿ�, �Ϲ������� �������ʴ´�.(�̱��濡���� �����)
	//CCar(string color)//����Ʈ�����ڰ� ������ �Ҵ�� �Ű������� �����ؾ��ϹǷ� ��ü������ ���ŷο�����.
	CCar(string color = "white")//������: ��ü�� �����ɶ� ȣ��Ǵ� �Լ� //����Ʈ�Ű������� �̿��Ͽ� �⺻������ó�� ��밡���ϴ�.
	{
		cout << "CCar["<< this << "]:"<< color << endl;
		m_isOn = false;
		m_eGear = EGEAR::N;
		m_nSpeed = 0;
		m_strColor = color;
	}
//private: //�����Ҵ�Ȱ�ü�� ������ ������ ������ �����ʴ� ������ �߻��Ҽ��ִ�.
	//�Ҹ��ڴ� �Ű������� �����Ƿ�, �����ε������ʴ´�. -> �Ҹ�Ǵ� ������ �����ΰ� �� �ʿ䰡 �ִ°�?
	~CCar() //�Ҹ���: ��ü���� �ÿ� ȣ��Ǵ� �Լ�
	{
		cout << "~CCar[" << this << "]:" << m_strColor << endl;
	}
private: //Ŭ�������ο����� ���ٰ����Ѱ�.
	bool m_isOn = false;
	EGEAR m_eGear = EGEAR::N;
	int m_nSpeed = 0;
	string m_strColor = "white";
};

void ClassDynamicAllocMain()
{
	CCar* pArrCar[3];
	pArrCar[0] = new  CCar("red");
	pArrCar[1] = new  CCar("yellow");
	pArrCar[2] = new  CCar("red");
	//for (int i = 0; i < 3; i++)
	//	delete pArrCar[i];
}

//void ClassTestMain()
//{
//	cout << "ClassTestMain Start" << endl;
//	CCar cCar("blue"); //��ü����(=��������) -> �����Ҵ� -> �ν��Ͻ�
//	CCar* pCar = new CCar("green"); //�����Ҵ� -> �ν��Ͻ�
//	CCar arrCar[3] = {CCar("red"),CCar("yellow"),CCar("black")};
//	CCar* pArrCar[3];
//	//CCar cCarA();//�Լ��� ���� ��ü�� ������������. cCarA��� �Լ��� ����
//	CCar cCarB = CCar("pink");
//	pArrCar[0] = new  CCar("red");
//	pArrCar[1] = new  CCar("yellow");
//	pArrCar[2] = new  CCar("red");
//	for (int i = 0; i < 3; i++)
//		delete pArrCar[i];
//	cCar.On();
//	cCar.SetGear(CCar::EGEAR::D);
//	cCar.Accel(); cCar.Accel(); cCar.Accel(); cCar.Accel(); cCar.Accel(); cCar.Accel();
//	cCar.DashBoard();
//	cCar.Break(); cCar.Break(); cCar.Break(); cCar.Break(); cCar.Break(); cCar.Break();
//	cCar.DashBoard();
//
//	pCar->On();
//	pCar->SetGear(CCar::EGEAR::D);
//	pCar->Accel(); 
//	pCar->DashBoard();
//	pCar->Break();
//	pCar->DashBoard();
//
//	delete pCar;
//	cout << "ClassTestMain End" << endl;
//}
//�⺻����
//�ڵ����� ������ �����ؼ� �ֹ��ް�,
//���忡�� ����Ǹ� ����Ͽ� �μ��޴´�.
//�μ����� �ڵ����� �����Ѵ�.

//������: ����, �ڵ���
// 
//��ȭ����
//�ڵ����� �뵵�� �°� �����ϰ� Ȱ���ϴ� �ó������� �ڵ�� �ۼ��ϱ�
//void CarSimulatorMain()
//{
//	string strOderColor;
//	cout << "Color?: ";
//	cin >> strOderColor;
//	CCar cCar(strOderColor);
//	while (true)
//	{
//		int nSelectInterface;
//	
//		cout << "Accel:1 / Break:2 / Gear:0";
//		cin >> nSelectInterface;
//		switch (nSelectInterface)
//		{
//		case 0:
//			cout << "SetGear(P:" << CCar::EGEAR::P << ", R:" << CCar::EGEAR::R << ", N:" << CCar::EGEAR::N << ", D:" << CCar::EGEAR::D << ")";
//			cin >> nSelectInterface;
//			cCar.SetGear((CCar::EGEAR)nSelectInterface);
//			break;
//		case 1:
//			if (cCar.GetGear() == CCar::EGEAR::D)
//				cCar.Accel();
//			else
//				cout << "SetGear chage D" << endl;
//			break;
//		case 2:
//			if (cCar.GetGear() == CCar::EGEAR::D)
//				cCar.Break();
//			else
//				cout << "SetGear chage D" << endl;
//			break;
//		default:
//			break;
//		}
//		cCar.DashBoard();
//		if (cCar.GetGear() == CCar::P) break;
//	}
//}

void main()
{
	_CrtSetBreakAlloc(204); //�޸� ������ ��ȣ�� ������ �Ҵ��ϴ� ��ġ�� �극��ũ ����Ʈ�� �Ǵ�.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //�޸� ���� �˻�
	cout << "Main Start" << endl;
	ClassDynamicAllocMain();
	//ClassTestMain();
	//CarSimulatorMain();
	cout << "Main End" << endl;
}