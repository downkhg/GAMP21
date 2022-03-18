#include <iostream>

using namespace std;
//�߻�ȭ? � ������ ���� ��� �ʿ��� ������ ����°�.
//�ڵ��� ����
//1. �õ��� �Ǵ�.
//2. �� D�� �ٲ۴�.
//3. �׼��� ��´�.
//4. �����ϰų� ���⶧, �극��ũ�� ��´�.
//������(�Ӽ�): �õ�(bool),���(enum P,R,D),�ӵ�(int)
//�˰���(����): �õ��ɱ�/����, ����,  �׼�-�ӵ�����, �극��ũ-�ӵ�����
//5. ������ ���¸� �˼����� -> ����� �ʿ�. -> ��°�� �ʱ�ȭ�� �ȵ�.
class CCar
{
public:
	enum EGEAR { P, R, N, D };

	void On() { m_isOn = true; }
	void Off() { m_isOn = false; }
	void SetGear(EGEAR gear) { m_eGear = gear; }
	void Accel() { m_nSpeed++; }
	void Break() { m_nSpeed--; }
	void DashBoard() 
	{ 
		cout << "Speed:" << m_nSpeed << endl; 
		cout << "Gear:" << m_eGear << endl;
		cout << "On:" << m_isOn << endl;
	}

	CCar()//������: ��ü�� �����ɶ� ȣ��Ǵ� �Լ�
	{
		cout << "CCar["<< this << "]" << endl;
		m_isOn = false;
		m_eGear = EGEAR::N;
		m_nSpeed = 0;
	}
	~CCar() //�Ҹ���: ��ü���� �ÿ� ȣ��Ǵ� �Լ�
	{
		cout << "~CCar[" << this << "]" << endl;
	}
private:
	bool m_isOn;
	EGEAR m_eGear;
	int m_nSpeed;
};

void ClassTestMain()
{
	CCar cCar; //��ü����(=��������) -> �����Ҵ�
	CCar* pCar = new CCar(); //�����Ҵ�

	cCar.On();
	cCar.SetGear(CCar::EGEAR::D);
	cCar.Accel(); cCar.Accel(); cCar.Accel(); cCar.Accel(); cCar.Accel(); cCar.Accel();
	cCar.DashBoard();
	cCar.Break(); cCar.Break(); cCar.Break(); cCar.Break(); cCar.Break(); cCar.Break();
	cCar.DashBoard();
}

void main()
{
	ClassTestMain();
}