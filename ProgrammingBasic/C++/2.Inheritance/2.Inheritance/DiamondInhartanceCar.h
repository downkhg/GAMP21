#pragma once

#include <iostream>
using namespace std;
//계층상속: 부모를 가진클래스를 상속받는것.
namespace DiamondInhartance
{
	class Vihicle
	{
	protected: //자식은 접근가능하고 외부에서 접근불가.
		int m_nGear = 0;
		int m_nSpeed = 0;
		int m_nSeats = 1;
	public:
		Vihicle(int seat = 1)
		{
			cout << "Vihicle[" << this << "]" << endl;
			m_nSeats = seat;
		}
		~Vihicle() { cout << "~Vihicle[" << this << "]" << endl; }

		void Accel() { m_nSpeed++; }
		void Break() { m_nSpeed--; }
		void SetGear(int gear) { m_nGear = gear; }
		void SetSeats(int seat) { m_nSeats = seat; }
	};

	class Bike : public Vihicle
	{
	public:
		Bike() { cout << "Bike[" << this << "]" << endl; }
		~Bike() { cout << "~Bike[" << this << "]" << endl; }
	};

	class Enginer : public Vihicle
	{
	protected:
		int m_nEngine;
	public:
		Enginer(int engine = 300)
		{
			cout << "Enginer[" << this << "]" << endl;
			m_nEngine = engine;
		}
		~Enginer()
		{
			cout << "~Enginer[" << this << "]" << endl;
		}
	};

	class AutoBike : public Bike, public Enginer
	{
	public:
		AutoBike(int engine = 300) : Enginer(engine)
		{
			cout << "AutoBike[" << this << "]" << endl;
		}
		~AutoBike() { cout << "~AutoBike[" << this << "]" << endl; }
	};

	class Track : public Enginer
	{
		int m_nMaxWight;
	public:
		Track(int engine = 3000, int wight = 1000)
		{
			cout << "Track[" << this << "]" << endl;
			m_nEngine = engine;
			m_nMaxWight = wight;
		}
		~Track() { cout << "~Track[" << this << "]" << endl; }
	};

	class Bus : public Enginer
	{
	public:
		Bus(int engine = 7000, int seat = 30):Enginer(engine)//부모생성자의 호출: 생성자를 통해 호출하면 부모멤버의 접근제어자와 상관없이 사용가능.
		{
			//Vihicle(seat); //다음과같이 처리하면 임시객체만들기때문에 초기화가 아니다.
			//m_nSeats = seat; //기능적으로 같지만 초기화가 부모에서 이미 이루어졌다,
			cout << "Bus[" << this << "]" << endl;
			m_nEngine = engine;
			///m_nSeats = seat; //부모멤버가 private가 아니여야 접근가능.
		}
		~Bus() { cout << "~Bus[" << this << "]" << endl; }
	};
	//다이아몬드상속: 같은부모를 가진 자식을 다중상속받아서 구현한경우.
	//C#이나 Java에서는 다음과 같은 다중상속을 막기위해서 다중상속이 불가능하다.
	//(단, 인터페이스는 다중상속가능하나 클래스랑은 용어가 다르므로 추후 설명함)
	void DiamondInhartanceCarMain()
	{
		AutoBike cAutoBike;
		
		cout << "#### Size #####" << endl;
		cout << "Engener:" << sizeof(cAutoBike) << endl;
		//다중상속을 할때는 상속구조를 제대로 파악해야한다.
		//cAutoBike.SetGear(0);
		cAutoBike.Bike::SetGear(0);
		cAutoBike.Enginer::SetGear(0);
	}
}