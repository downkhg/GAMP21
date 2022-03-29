/*##################################
C++ 클래스문법-자동차 추상화(C++ 수업용)
파일명: 1.1.Basic_Interface_CarClass.cpp
작성자 : 김홍규(downkhg@gmail.com)
마지막수정날짜 : 2022.03.16
버전 : 1.00
###################################*/
#include <iostream>
#include <string>

using namespace std;

//자동차 - 추상화
//속성-필드(변수:데이터): 속도,기어,색상
//동작-메서드(함수:알고리즘): 가속하기(가속패달),감속하기(브레이크),기어설정,
//※색상은 차를 주문할때 정할수있다.

//클래스: 추상화된 객체를 클래스로 설계도를 만들수있다.
//구조체 <-> 클래스 : 기본멤버 public / private
class CCar
{
	//접근제어자: 클래스에서 변경될 속성을 제한한다.(만들 대상에 따라 멤버에서 설정은 달라질수있다)
//private: //클래스외부에 접근을 막는다.
	//멤버변수
	int m_nSpeed = 0;
	int m_nGear = 0;
	string m_strColor;
	const int MaxSpeed;
	//정적멤버변수는 모든 객체가 공유하는 변수.
	static int m_nCount;//정적변수의 선언: 이러한 정적변수가 필요하다.
	//멤버함수
public: //클래스외부에서 접근을 가능하게 만든다.
	//생성자: 객체가 생성될때 호출되는 함수.
	//리턴값없음. 매개변수있음. 디폴트매개변수가능. 오버로딩가능.
	/*CCar()
	{
		m_nSpeed = 0;
		m_nGear = 0;
		m_strColor = "gray";
	}*/
	//private: //생성자가 접근이 안되면 메모리를 외부에서 할당할수없다.
	static int GetCount()//정적맴버변수는 정적맴버함수만 접근이 가능하다.
	{
		return m_nCount;
	}

public://초기화 목록: 멤버변수에 초기값을 설정함.
	CCar(string color = "gray") :MaxSpeed(100) //함수의 오버로딩
	{
		m_nSpeed = 0;
		m_nGear = 0;
		m_strColor = color;
		m_nCount++;
		cout << "CCar[" << this << "]:("<< m_nCount <<")" << m_strColor << endl;
	}
	CCar(const CCar& car) :MaxSpeed(100)
	{
		//*this = car;
		//memcpy(this, &car, sizeof(CCar)); //문자열객체는 메모리복사가 불가능하다.
		this->m_nSpeed = car.m_nSpeed;
		this->m_nGear = car.m_nGear;
		this->m_strColor = car.m_strColor;
		m_nCount++;
		cout << "CCar Copy[" << this << "]:(" << m_nCount << ")" << m_strColor << endl;
	}

	//private: //객체가 소멸자에서 
		//소멸자: 객체가 소멸할때 호출되는 함수.
		//리턴값없음. 매개변수X. 오버로딩X
	~CCar()
	{
		m_nGear = 0;
		m_nCount--;
		cout << "~CCar[" << this << "]:(" << m_nCount << ")" << m_strColor << endl;
	}

	//void SetSpeed(int speed) { m_nSpeed = speed; } //물리법칙상 변경이 불가능하다.
	void Accelerator()
	{
		m_nSpeed++;
	}
	void Break()
	{
		m_nSpeed--;
	}
	void SetGear(int nGear) //setter(설정자)
	{
		m_nGear = nGear;
	}
	int GetGear() //getter(접근자)
	{
		return m_nGear;
	}
	void SetColor(string color)
	{
		m_strColor = color;
	}
	void Display() //자동차 계기판
	{
		cout << "Color:" << m_strColor << endl;
		cout << "Speed:" << m_nSpeed << endl;
		cout << "Gear:" << m_nGear << endl;
	}
public:
	enum EGEAR { P, R, N, D }; //기어값
};

//자동차구매 -> 계약서작성(옵션) -> 생산 -> 배달
void CarMain()
{
	//클래스의 이름으로 접근하므로 어떤 객체가 생성되지않더라도 접근가능하다. 그러므로 정적맴버변수는 정적맴버함수만 접근가능하다.
	cout << "CarMain Start:" << CCar::GetCount() << endl;
	//주문자가 생선전에 색상을 지정할수있다.
	CCar cCar("red"); //객체생성(정적할당) //생상자나 소멸자가 외부에서 접근불가면 생성불가.
	CCar cCarA("blue");
	CCar arrCar[3];
	//C++의 경우: 객체 == 인터페이스(동적할당이든 정적할당이든 메모리가 할당되면 객체이며 인스턴스다)
	//Java/C#의 경우
	//객체: 대상을 참조하는 것.
	//인스턴스: 참조된 대상. 
	//객체 = 인스턴스
	CCar* pCar = new CCar("green");//객체: 생성자가 외부에서 접근불가능하면 생성불가.
	CCar& refCar = cCar;
	pCar->Display();
	//cCar.m_strColor = "red"; //지나가던 행인이 색을 바꿀수있다.(이러한 행위는 법에 접촉된다)
	cCar.SetColor("red"); //주인에게 허락받아서 색상을 변경한다.
	cCar.Accelerator();
	cCar.Display();
	cCar.Break();
	cCar.Display();
	delete pCar; //소멸자가 외부에서접근불가능하면 지울수없음.
	//정적멤버는 객체가 소멸되도 접근이 가능하므로 다음과 같이 사용가능하나. 추천하는 문법사용방법은 아님.
	//cout << "CarMain End:"<< pCar->GetCount() << endl;
}

void ClassTestMain()
{
	cout << "ClassTestMain Start:" << CCar::GetCount() << endl;
	CCar cCarA;
	CCar cCarB();//함수의 선언으로 취급
	CCar cCarC("blue");
	CCar cCarD = CCar("red"); //임시객체가 생성되어 복사됨.
	CCar cCarE = cCarA;
	cCarA.Display();
	//cCarB.Display(); //객체가 없음.
	cCarC.Display();
	cCarD.Display();
	cout << "ClassTestMain End:" << CCar::GetCount() << endl;
}

void CarInterfaceMain()//자동차를 조작하는 사용자 인터페이스(UI) 구축하기: 콘솔앱
{
	string strInput;
	cout << "InputCarColor:" << strInput;
	cin >> strInput;
	CCar cCar(strInput);
	cout << "#### Drive Start ####" << endl;
	while (strInput != "exit")
	{
		cout << "Select Car Interface(accel,break,gear(P,R,N,D),exit)";
		cin >> strInput;
		if (strInput == "accel")
			cCar.Accelerator();
		else if (strInput == "break")
			cCar.Break();
		else if (strInput == "P")
			cCar.SetGear(CCar::EGEAR::P);
		else if (strInput == "R")
			cCar.SetGear(CCar::EGEAR::R);
		else if (strInput == "N")
			cCar.SetGear(CCar::EGEAR::N);
		else if (strInput == "D")
			cCar.SetGear(CCar::EGEAR::D);
		cCar.Display();
	}
	cout << "#### Driving End ####" << endl;
}

int g_nData;
int CCar::m_nCount = 0;//정적맴버변수의 정의 //전역변수처럼 선언하여 메모리를 생성한다.

void main()
{
	cout << "Main Start:" << CCar::GetCount() << endl;
	//g_nData++;
	//CarMain();
	ClassTestMain();
	cout << "Main End:" << CCar::GetCount() << endl;
}