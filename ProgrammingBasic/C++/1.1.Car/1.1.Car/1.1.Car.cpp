#include <iostream>
#include <stdlib.h> //메모리 동적할당 헤더
#include <crtdbg.h> //메모리 누수 탐지 헤더

using namespace std;
//추상화? 어떤 목적에 따라서 대상에 필요한 정보만 남기는것.
//자동차 주행
//1. 시동을 건다.
//2. 기어를 D로 바꾼다.
//3. 액셀을 밟는다.
//4. 감속하거나 멈출때, 브레이크를 밟는다.
//데이터(속성): 시동(bool),기어(enum P,R,D),속도(int)
//알고리즘(동작): 시동걸기/끄기, 기어변경,  액셀-속도증가, 브레이크-속도감소
//5. 차량의 상태를 알수없다 -> 계기판 필요. -> 출력결과 초기화가 안됨. -> 다른객체와 구별하기 어려움 -> 색상을 추가
class CCar
{
public: //클래스 외부에서 접근가능한것.
	enum EGEAR { P, R, N, D };

	void On() { m_isOn = true; }
	void Off() { m_isOn = false; }
	//Setter/Getter: 멤버변수에 접근하도록 제공하는 함수. 용도에 따라 제한될수있으나.. 원칙적으로는 모두 추가하는 것이 좋음.
	void SetGear(EGEAR gear) { m_eGear = gear; }
	EGEAR GetGear() { return m_eGear; } //????
	//void SetSpeed(int speed) { m_nSpeed = speed; }//물리적으로 불가능함.
	int GetSpeed() { return m_nSpeed; } //자동차의 속도는 외부에서도 측정가능하다.
	void SetColor(string color) { m_strColor = color; } //비용문제가 있긴하지만 가능함. 누구나 변경할수도 있다(범법행위임)
	string GetColor() { return m_strColor; } //누구나 차의 색상을 볼수있다.
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
	//CCar()//디폴트 생성자: 매개변수가 없는 생성자 //생성자도 오버로딩 가능하다.
	//{
	//	cout << "CCar[" << this << "]" << endl;
	//	m_isOn = false;
	//	m_eGear = EGEAR::N;
	//	m_nSpeed = 0;
	//	m_strColor = "white";
	//}
//생성자가 private이면 객체를 생성할수없으므로, 일반적으로 사용되지않는다.(싱글톤에서는 사용함)
	//CCar(string color)//디폴트생성자가 없으면 할당시 매개변수를 전달해야하므로 객체생성이 번거로워진다.
	CCar(string color = "white")//생성자: 객체가 생성될때 호출되는 함수 //디폴트매개변수를 이용하여 기본생성자처럼 사용가능하다.
	{
		cout << "CCar["<< this << "]:"<< color << endl;
		m_isOn = false;
		m_eGear = EGEAR::N;
		m_nSpeed = 0;
		m_strColor = color;
	}
//private: //동적할당된객체는 생성은 되지만 삭제가 되지않는 문제가 발생할수있다.
	//소멸자는 매개변수가 없으므로, 오버로딩되지않는다. -> 소멸되는 시점에 무엇인가 할 필요가 있는가?
	~CCar() //소멸자: 객체삭제 시에 호출되는 함수
	{
		cout << "~CCar[" << this << "]:" << m_strColor << endl;
	}
private: //클래스내부에서만 접근가능한것.
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
//	CCar cCar("blue"); //객체생성(=변수선언) -> 정적할당 -> 인스턴스
//	CCar* pCar = new CCar("green"); //동적할당 -> 인스턴스
//	CCar arrCar[3] = {CCar("red"),CCar("yellow"),CCar("black")};
//	CCar* pArrCar[3];
//	//CCar cCarA();//함수의 선언 객체가 생성되지않음. cCarA라는 함수의 선언
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
//기본문제
//자동차를 색상을 선택해서 주문받고,
//공장에서 생산되면 출고하여 인수받는다.
//인수받은 자동차를 주행한다.

//데이터: 색상, 자동차
// 
//심화문제
//자동차를 용도에 맞게 설계하고 활용하는 시나리오를 코드로 작성하기
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
	_CrtSetBreakAlloc(204); //메모리 누수시 번호를 넣으면 할당하는 위치에 브레이크 포인트를 건다.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //메모리 누수 검사
	cout << "Main Start" << endl;
	ClassDynamicAllocMain();
	//ClassTestMain();
	//CarSimulatorMain();
	cout << "Main End" << endl;
}