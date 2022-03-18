#include <iostream>

using namespace std;
//추상화? 어떤 목적에 따라서 대상에 필요한 정보만 남기는것.
//자동차 주행
//1. 시동을 건다.
//2. 기어를 D로 바꾼다.
//3. 액셀을 밟는다.
//4. 감속하거나 멈출때, 브레이크를 밟는다.
//데이터(속성): 시동(bool),기어(enum P,R,D),속도(int)
//알고리즘(동작): 시동걸기/끄기, 기어변경,  액셀-속도증가, 브레이크-속도감소
//5. 차량의 상태를 알수없다 -> 계기판 필요. -> 출력결과 초기화가 안됨.
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

	CCar()//생성자: 객체가 생성될때 호출되는 함수
	{
		cout << "CCar["<< this << "]" << endl;
		m_isOn = false;
		m_eGear = EGEAR::N;
		m_nSpeed = 0;
	}
	~CCar() //소멸자: 객체삭제 시에 호출되는 함수
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
	CCar cCar; //객체생성(=변수선언) -> 정적할당
	CCar* pCar = new CCar(); //동적할당

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