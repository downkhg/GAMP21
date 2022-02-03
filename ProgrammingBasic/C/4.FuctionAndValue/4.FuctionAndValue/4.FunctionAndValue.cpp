#include <stdio.h>

//함수 -> 집
//지역변수 -> 집밥
//전역변수 -> 배달음식
//집밥은 그집사람만 먹을수있다.   
//함수는 지역변수만 사용할수있다.
//배달음식은 어느 집이나 시켜 먹을수있다.
//전역변수는 어느 함수나 사용 할 수 있다.

//메모리가 1g가 있다고 한다면, 모든 변수를 전역변수로 만들면 최대 1g만 사용가능하다.
//메모리가 1g가 있고, 전역변수가 500mb사용하고, 각 함수마다 500mb를 지역변수로 사용하면, 
//함수 호출이 끝난후 다른 함수를 사용 할수 있다.

//전역변수: 모든함수에서 접근가능한 변수.{}안에 생성되지않은 변수. 프로그램이 종료될때까지 유지된다.
int g_nData;

//지역변수: 함수(구문)안에서만 존재하는 변수. 매개변수도 지역변수의 일종이다.
void FuncA(int nParameter)
{
	int nDataA = 10;
	g_nData = 10;
	printf("DataA:%d\n", nDataA);
	printf("GrobalData:%d\n", g_nData);
}

void FuncB()
{
	int nDataB = 20;
	//nDataA = 100; //같은함수에 있는 변수만 접근가능하다.
	//nParameter = 200; //매개변수도 지역변수다.
	g_nData = 20;
	printf("DataB:%d\n", nDataB);
	printf("GrobalData:%d\n", g_nData);
}

int inc(int counter)
{
	counter++;
	return counter;
}

void IncTestMain()
{
	int nData = 10;
	printf("1. Data:%d\n", nData);
	inc(nData);//매개변수로 전달된 값은 함수내부에서 증감되더라도 반영되지않는다.
	nData = inc(nData);//리턴받은값으로 전달해서 다른지역변수에 초기화해야한다.
	printf("2. Data:%d\n", nData);
}
//정적지역변수: 함수가 종료되도 값을 유지하는 변수.
//지역변수: 함수가 호출될때마다 초기화되는 변수.
void Sub()
{
	int nAutoCount = 0;
	static int nStaticCount = 0;
	nAutoCount++;
	nStaticCount++;
	printf("AutoCount:%d\n", nAutoCount);
	printf("StaticCount:%d\n", nStaticCount);
}

void StaticTestMain()
{
	for (int i = 0; i < 3; i++)
		Sub();
}

extern int g_nDataA; //extern: 이러한 전역변수가 있지만 여기에서 생성한 것이 아님.(함수의 선언과 유사)
extern /*static*/int g_nStaticDataB; //extern과 static은 같이 사용할수 없음.

extern void PrintDataA();//exturn함수: 이 함수의 정의는 다른파일에 있다.
//extern void PrintDataB(); //static함수는 해당파일에서만 접근가능하므로 extern을 하더라도 사용이 불가능하다.

void GrobalStaticTestMain()
{
	g_nDataA = 100;
	PrintDataA();
	//static을 붙이면 해당 파일안에서만 사용가능하다.
	//g_nStaticDataB = 200;
	//PrintDataB();
}

void main()
{
	//FuncA(10);
	//FuncB();
	//printf("GrobalData:%d\n", g_nData);
	//IncTestMain();
	//StaticTestMain();
	GrobalStaticTestMain();
}