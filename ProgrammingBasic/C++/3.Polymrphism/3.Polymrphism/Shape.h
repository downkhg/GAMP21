#pragma once

#include <iostream>
#include <list>
using namespace std;
//도형과 같이 공통적인 특징이 속성이 없고 동작만 존재하는 클래스를 굳이 상속관계로 만들필요가 없다.
namespace Inheritance
{
	//1차원이라면 객체로 볼수없다.
	struct Vector//객체: 벡터(2차원 위치)
	{
		//public:
		float x;
		float y;
		Vector(float x = 0, float y = 0)
		{
			this->x = x;
			this->y = y;
		}
		void Print(const char* msg)
		{
			cout << msg << "(" << x << "," << y << ")" << endl;
		}
	};

	class Shape //도형:
	{
	public:
		Shape()
		{
			cout << "Shape[" << this << "]" << endl;
		}
		~Shape()
		{
			cout << "~Shape[" << this << "]" << endl;
		}
		virtual void Draw()//가상함수: 부모와 자식이 같은 함수를 공유할때 사용하는 키워드.
		{
			cout << "Shape[" << this << "]::Draw()" << endl;
		};
	};
	//원과 같이 삼각형,사각형을 클래스로 만들기
	class Circle : public Shape
	{
		Vector vPos;
		float fRadius;
	public:
		Circle(Vector pos = Vector(), float rad = 1)
		{
			cout << "Circle[" << this << "]" << endl;
			vPos = pos;
			fRadius = rad;
			
			cout << "Rad:" << fRadius << endl;
		}
		~Circle()
		{
			cout << "~Circle[" << this << "]()" << endl;
		}
		void Draw()
		{
			cout << "Circle[" << this << "]::Draw()" << endl;
			vPos.Print("Pos");
			cout << "Rad:" << fRadius << endl;
		}
	};
	class TriAngle : public Shape
	{
		Vector vA;
		Vector vB;
		Vector vC;
	public:
		TriAngle(Vector a = Vector(), Vector b = Vector(), Vector c = Vector()) 
		{ 
			cout << "TriAngle[" << this << "]" << endl; 
			vA = a;
			vB = b;
			vC = c;
		}
		~TriAngle() { cout << "TriAngle[" << this << "]" << endl; };
		void Draw()
		{
			cout << "TriAngle[" << this << "]::Draw()" << endl;
			vA.Print("A:");
			vB.Print("B:");
			vC.Print("C:");
		}
	};
	class RectAangle : public Shape
	{
		Vector vTL;
		Vector vTR;
		Vector vBL;
		Vector vBR;
	public:
		RectAangle(Vector tl = Vector(), Vector tr = Vector(), Vector bl = Vector(), Vector br = Vector())
		{
			cout << "RectAangle[" << this << "]" << endl;
			vTL = tl;
			vTR = tr;
			vBL = bl;
			vBR = br;
		}
		~RectAangle()
		{
			cout << "~RectAangle[" << this << "]()" << endl;
		}
		void Draw()
		{
			cout << "RectAangle[" << this << "]::Draw()" << endl;
			vTL.Print("TopLeft:");
			vTR.Print("TopRight:");
			vBL.Print("BottomLeft:");
			vBR.Print("BottomRight:");
		}
	};

	//부모의 부분과 자식의 부분은 메모리가 다르다. 
	//결국 상속을 통해서 두개의 같은이름의 함수를 가진다.
	void ShapeMain()
	{
		Shape cShape;
		Circle cCrilce({ 1,1 }, 1);
		cShape.Draw();
		cShape.Shape::Draw();
		cCrilce.Draw();
		cCrilce.Shape::Draw();
	}
	//프로그램 실행중에 선택하여 모양을 여러개를 그리려면 어떻게해야하는가?//동적으로 메모리를 할당받아야한다.
	void RuntimeShapeDrawMain()
	{
		void** arrShape;
		arrShape = new void*[3];
	
		arrShape[0] = (void*)new Circle();
		arrShape[1] = (void*)new RectAangle();
		arrShape[2] = (void*)new TriAngle();

		//실제로는 자식의 함수에 편리하게 접근하고 싶었으나,
		//for (int i = 0; i < 3; i++)
		//	(Shape*)arrShape[i]->Draw();
		//상속을 받았다하더라도, 자식의 함수를 접근할수는 없다.
		((Circle*)arrShape[0])->Draw();
		((RectAangle*)(arrShape[1]))->Draw();
		((TriAngle*)(arrShape[2]))->Draw();

		for (int i = 0; i < 3; i++)
			delete arrShape[i];
	}
	//부모클래스의 함수에 virtual을 붙이면 가상함수가되고,
	//부모포인터에서도 자식의 같은 이름의함수를 호출가능해진다.
	void PolymrphismShapeDrawMain()
	{
		Shape* arrShape[3];

		arrShape[0] = new Circle();
		arrShape[1] = new RectAangle();
		arrShape[2] = new TriAngle();

		for (int i = 0; i < 3; i++)
			arrShape[i]->Draw();

		for (int i = 0; i < 3; i++)
			delete arrShape[i];
	}

	void PolymrphismShapeListDrawMain()
	{
		list<Shape*> arrShape;

		arrShape.push_back(new Circle(0,0));
		arrShape.push_back(new RectAangle(1,1,2,2));
		arrShape.push_back(new TriAngle(Vector(1,1),Vector(2,2),Vector(3,3)));

		//list<Shape*>::iterator it = arrShape.begin(); //초보자라면 타입을 좀더 명확하게 표시하여 익숙해지도록하자.
		auto it = arrShape.begin();//이때 auto를 이용하면 코드를 좀더 짧게 작성가능하다.
		//downcasting: 부모클래스를 자식 클래스로 변환하는 것.
		cout << "### downcasting ###" << endl;
		((Circle*)*it)->Draw();
		((RectAangle*)*++it)->Draw();
		((TriAngle*)*++it)->Draw();
		cout << "#### iterator ####" << endl;
		//부모의 draw를 가상함수화하면 각각 자식의 함수가 호출된다. //정적할당된 대상에서는 성립되지않는다.
		for (it = arrShape.begin(); it != arrShape.end(); it++)
		{
			Shape* pShape = *it;
			pShape->Draw();
			//((RectAangle*)pShape)->Draw();//실행이된다고해서 정상적으로 작동하는 코드가 아니다. 
		}
		cout << "#############" << endl;
		for (it = arrShape.begin(); it != arrShape.end(); it++)
		{
			delete *it;
		}
	}
}