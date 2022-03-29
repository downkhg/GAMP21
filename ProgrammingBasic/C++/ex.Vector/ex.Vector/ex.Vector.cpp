#include <iostream>
#include <string>
using namespace std;

//벡터
//원소: x,y
//연산: +,-,*,평준화(Normalize),스칼라(scala),x,y설정자,생성자(x,y)

class Vector
{
	float x; 
	float y;
public:
	Vector(float x = 0, float y = 0)
	{
		this->x = x;
		this->y = y;
	}
	void Set(float x, float y) { this->x = x; this->y = y;}
	void SetX(float x){ this->x = x; }
	float GetX() { return x; }
	void SetY(float y){ this->y = y; }
	float GetY() { return y; }
	Vector Add(Vector v)
	{
		return Vector(x + v.x, y + v.y);
	}
	Vector operator+(const Vector& v)
	{
		return Vector(x + v.x, y + v.y);
	}
	Vector operator-(const Vector& v)
	{
		return Vector(x - v.x, y - v.y);
	}
	Vector operator*(float scala)
	{
		return Vector(x * scala, y * scala);
	}
	bool operator == (const Vector& v)
	{
		return ((this->x == v.x) && (this->y == v.y));
	}
	//friend: 객체외부에서 해당객체의 멤버를 엑세스할 수 있는 함수. 
	friend Vector operator*(const float scala, const Vector& v)
	{
		return Vector(v.x * scala, v.y * scala);
	}
	friend ostream& operator<<(ostream& os, const Vector v)
	{
		os << "(" << v.x << "," << v.y << ")";
		return os;
	}
	float Magnitude()
	{
		return sqrt(x * x + y * y);
	}
	Vector Normalize()
	{
		float fScala = Magnitude();
		return Vector(x / fScala, y / fScala);
	}
	void Display(const char* msg =  "") const
	{
		cout << msg <<"(" << x << "," << y << ")" << endl;
	}
	const char* GetString()
	{
		char cArray[1024];
		sprintf_s(cArray, "(%f,%f)", x, y);
		static string strTemp(cArray);//모든객체의 함수에서 공유되므로 한줄에 여러객체의 값을 출력할때는 유효하지않다.
		return strTemp.c_str();
	}
	float operator[](int idx)
	{
		if (idx == 0) return x;
		else return y;
	}
	float operator[](char c)
	{
		if (c == 'x') return x;
		else if (c == 'y') return y;
		else return -1;
	}
};

void VecterTestMain()
{
	Vector vA;
	Vector vB(2, 0);
	Vector vResult;
	cout << "vA[" << vA[0] << "," << vA[1] << "]" << endl;
	cout << "vB[" << vB['x'] << "," << vB['y'] << "]" << endl;
	vResult = vA.Add(vB);
	vResult = vA + vB;
	vA.Display("A");
	vB.Display("B");
	vResult.Display("Result=A+B:");
	float fDist = vResult.Magnitude();
	Vector vDir = vResult.Normalize();
	vResult = vDir * fDist;
	cout << "Dist:" << fDist << endl;
	vDir.Display("Dir:");
	vResult.Display("vDir * fDist = vResult");
	//cout << vA.GetString() << "+" << vB.GetString() << "=" << vResult.GetString() << endl;
	cout << vA << "+" << vB << "=" << vResult << endl;

	if (vA == vB)
		printf("A == B");
	else
		printf("A != B");
}

void main()
{
	VecterTestMain();
}