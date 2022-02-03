#include <stdio.h> //라이브러리: 도서관에서 책을 빌리는 것처럼 함수가 필요할때마다 가져와서 사용하는 곳.
//함수: 기능을 만들어서 사용하는 것.
//리턴값: 계산된 결과를 함수밖으로 내보는것. 리턴을 만나면 함수가 종료된다.
//매개변수: 함수밖에서 넣은 값을 전달해주는 변수.
//함수명: 함수를 호출할때 사용하는 이름.
//리턴값 함수명(매개변수.....)
int square(int x)//제곱을 구하는 함수
{
	return x * x; 
}

//제곱을 구하는 함수를 만들어서, 숫자를 넣으면 제곱값을 계산하는 프로그램을 만들기
//변수:숫자-정수
//알고리즘:숫자를 제곱 -> 숫자*숫자
void SquareCalculatorMain()
{
	int nNumber = 5;

	//int nSquare = nNumber* nNumber;
	int nSquare = square(nNumber);//인수: 매개변수에 전달되는 값.

	printf("%d^2 = %d\n", nNumber, nSquare);//라이브러리 함수
}

int Add(int a, int b) //함수의 매개변수는 2개이상 만들수있다.
{
	return a + b;
}

float Add_fi(float a, int b) //함수의 매개변수의 타입은 달라도 상관없다. //리턴값은 계산결과가 문제가 없는 타입을 선택하면된다.
{
	return a + b;
}

int ResutnTest()//함수에서 값을 2개이상 결과로 내고싶을때는 전역변수나 참조를 이용해야한다.(추후 다룸)
{
	printf("ResutnTest 1");
	return 1; //리턴을 만나면 함수가 종료되므로 뒤에 코드는 무의미하다.
	printf("ResutnTest 2");
	return 2;
	printf("ResutnTest 3");
	return 3;
	printf("ResutnTest 4");
}

int Max(int a, int b)//조건에 따라 리턴값이 서로 다른 경우 종료 경로가 다르므로 상관없다.
{
	if (a > b)
		return a;
	else
		return b;
}

void FunctionTestMain()
{
	int nDataA = 10;
	int nDataB = 20;
	float fDataA = 2.5f;
	float fDataB = 4.5f;
	int nResult;
	float fResult;
	nResult = Add(nDataA, nDataB);
	fResult = Add_fi(fDataA, nDataB);
	nResult = Max(nDataA, nDataB);
	printf("Add(%d,%d):%d\n",nDataA,nDataB,nResult);
	printf("Add_fi(%f,%d):%f\n", fDataA, nDataB, fResult);
	printf("Max(%d,%d):%d\n", nDataA, nDataB, nResult);
	ResutnTest();
}
//함수의 선언: 이런 타입의 함수가 있다. 하지만 내용은 알수없다.
int combination(int n, int r);
int factorial(int n);

void CombinationTestMain()
{
	int nDataA;
	int nDataB;
	scanf("%d",&nDataA);
	scanf("%d", &nDataB);
	int nResult = combination(nDataA, nDataB);
	printf("C(%d,%d)= %d\n",nDataA, nDataB,nResult);
}
//함수의 정의: 선언된 함수의 내용을 작성함.
int combination(int n, int r)
{
	return factorial(n) / (factorial(r) * factorial(n - r));
}

int factorial(int n)
{
	long result = 1;
	for (int i = 1; i <= n; i++)
	{
		result = result * i;//result *= i;
	}
	return result;
}

void main()
{
	//SquareCalculatorMain(); 
	//FunctionTestMain();
	CombinationTestMain();
}