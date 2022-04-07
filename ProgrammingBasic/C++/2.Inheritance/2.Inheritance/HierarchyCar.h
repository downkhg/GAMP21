#pragma once

#include <iostream>
using namespace std;
//계층상속: 부모를 가진클래스를 상속받는것.
namespace HierarchyInheritance
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

	class Eneginer : public Vihicle
	{
	protected:
		int m_nEngine;
	public:
		Eneginer(int engine = 300)
		{
			cout << "Eneginer[" << this << "]" << endl;
			m_nEngine = engine;
		}
		~Eneginer()
		{
			cout << "~Eneginer[" << this << "]" << endl;
		}
	};

	class Bike : public Vihicle
	{
	public:
		Bike() { cout << "Bike[" << this << "]" << endl; }
		~Bike() { cout << "~Bike[" << this << "]" << endl; }
	};

	class AutoBike : public Eneginer,Bike
	{
	public:
		AutoBike(int engine = 300) : Eneginer(engine)
		{
			cout << "AutoBike[" << this << "]" << endl;
		}
		~AutoBike() { cout << "~AutoBike[" << this << "]" << endl; }
	};

	class Track : public Eneginer
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

	class Bus : public Eneginer
	{
	public:
		Bus(int engine = 7000, int seat = 30):Eneginer(engine)//부모생성자의 호출: 생성자를 통해 호출하면 부모멤버의 접근제어자와 상관없이 사용가능.
		{
			//Vihicle(seat); //다음과같이 처리하면 임시객체만들기때문에 초기화가 아니다.
			//m_nSeats = seat; //기능적으로 같지만 초기화가 부모에서 이미 이루어졌다,
			cout << "Bus[" << this << "]" << endl;
			m_nEngine = engine;
			///m_nSeats = seat; //부모멤버가 private가 아니여야 접근가능.
		}
		~Bus() { cout << "~Bus[" << this << "]" << endl; }
	};
	
	void HierachyCarMain()
	{
		//Vihicle cVihicle;
		//Bike cBike; //멤버가 추가되지않으므로 굳이 클래스로 만들필요가없다.
		//만약 자전거를 만든다면 객체를 다르게 표현하는것이 방법일수있다.
		//Vihicle cBike;
		//Eneginer cAutoBike;
		AutoBike cAutoBike;
		//Track cTrack;
		//Bus cBus;
		//cout << "#### Size #####" << endl;
		//cout << "Vihicle:" << sizeof(cVihicle) << endl;
		//cout << "Engener:" << sizeof(cAutoBike) << endl;
		//cout << "Track:" << sizeof(cTrack) << endl;
		//cout << "Bus:" << sizeof(cBus) << endl;
	}
}