#include <stdio.h>
#include <string.h>
//데이터의 값이 전위 연산자와 후위연산자의 차이점을 확인하는 프로그램.
void ValueAndOperatorMain();
//정수와 실수의 데이터를 선언하고, 각 선언된 데이터를 각각의 실수와 포인터에 저장하여,
//모든 변수들에서 연산할 수있는 모든 결과를 출력하여라.
void PointerMain();

void SwapVal(int a, int b);
void SwapPtr(int* a, int* b);
void SwapRef(int& a, int& b);

void FunctionAndPointerMain();
void ArrayMain();

void main() 
{
	//ValueAndOperatorMain();
	//PointerMain();
	//FunctionAndPointerMain();
	ArrayMain();
}

void ValueAndOperatorMain()
{
	int nDataA = 10;
	int nDataB = nDataA;
	printf("1.DataA:%d\n", nDataA);
	printf("1.DataB:%d\n", nDataB);
	nDataB = nDataA++;
	printf("2.DataA:%d\n", nDataA);
	printf("2.DataB:%d\n", nDataB);
	nDataB = --nDataA;
	printf("3.DataA:%d\n", nDataA);
	printf("3.DataB:%d\n", nDataB);
}
//정수와 실수의 데이터를 선언하고, 각 선언된 데이터를 각각의 실수와 포인터에 저장하여,
//모든 변수들에서 연산할 수있는 모든 결과를 출력하여라.
void PointerMain()
{
	int nData = 10;
	float fData = 3.14f;
	int* pIntData = &nData;//포인터: 주소값을 저장하는 변수
	float* pFloatData = &fData;

	printf("nData[%d]:%d\n", &nData, nData);
	printf("fData[%d]:%f\n", &fData, fData);
	//*(참조):포인터가 가진 주소값이 가르키는 변수의 값.
	printf("IntData[%d]:%d\n", *pIntData, pIntData);
	printf("FloatData[%f]:%d\n", *pFloatData, pFloatData);
}

void SwapVal(int a, int b)//값에의한 호출
{
	printf("SwapVal[%d]%d<->[%d]%d\n", &a, a, &b, b);
	int temp = a;
	a = b;
	b = temp;
}

void SwapPtr(int* a, int* b)//주소값에의한 호울
{
	printf("SwapPtr[%d]%d<->[%d]%d\n", *a, a, *b, b);
	int temp = *a;
	*a = *b;
	*b = temp;
}

void SwapRef(int& a, int& b)//참조에의한 호출
{
	printf("SwapRef[%d]%d<->[%d]%d\n", &a, a, &b, b);
	int temp = a;
	a = b;
	b = temp;
}

void FunctionAndPointerMain()
{
	int nDataA = 10;
	int nDataB = 20;
	printf("1.Origin[%d]%d<->[%d]%d\n", &nDataA, nDataA, &nDataB, nDataB);
	SwapVal(nDataA, nDataB);
	printf("2.SwapVal[%d]%d<->[%d]%d\n", &nDataA, nDataA, &nDataB, nDataB);
	SwapPtr(&nDataA, &nDataB);
	printf("3.SwapPtr[%d]%d<->[%d]%d\n", &nDataA, nDataA, &nDataB, nDataB);
	SwapRef(nDataA, nDataB);
	printf("4.SwapRef[%d]%d<->[%d]%d\n", &nDataA, nDataA, &nDataB, nDataB);
}

void ArrayMain()//배열은 메모리의 주소값을 활용하여 렌덤엑세스가 가능하다.
{
	const int nSize = 3;
	int arrScore[nSize];//컴파일러가 배열의 크기를 알아야만 할당할수있다.
	int arrSize = sizeof(arrScore) / sizeof(int);
	for (int i = 0; i < nSize; i++)
		arrScore[i] = 100 - i * 10;
	printf("arrScore[%d]:%d\n", &arrScore, arrScore);
	for (int i = 0; i < nSize; i++)
		printf("[%d/%d]:%d,",&arrScore[i],i,arrScore[i]);//인덱스를 이용한 접근
	printf("\n");
	for (int i = 0; i < nSize; i++)
		printf("[%d/%d]:%d,", (arrScore+i), i, *(arrScore+i)); //포인터의 값에 +n하여 계산
	printf("\n");
	int* pArrScore = arrScore;
	for (int i = 0; i < nSize; i++)
	{
		printf("[%d/%d]:%d,", pArrScore, i, *pArrScore);
		pArrScore++;//포인터연산 값을 1씩 증가해서 연산
	}
	printf("\n");
	int arrCopyArray[nSize];
	memcpy(arrCopyArray, arrScore, sizeof(arrScore));
	for (int i = 0; i < nSize; i++)
		arrCopyArray[i] = arrScore[i];
	printf("\n");
}

void Array2DTestMain() 
{
	const int nSizeX = 3;
	const int nSizeY = 4;
	const int nMaxSize = nSizeX * nSizeY;
	int arr2DArray[nSizeY][nSizeX];
	int arr2DFakeArray[nMaxSize];

	for (int y = 0; y < nSizeY; y++)
	{
		for (int x = 0; x < nSizeX; x++)
		{
			printf("%d[%d,%d]%d,",&arr2DArray[y][x],y,x,arr2DArray[y][x]);
		}
		printf("\n");
	}

	for (int y = 0; y < nSizeY; y++)
	{
		for (int x = 0; x < nSizeX; x++)
		{
			int idx = y * nSizeX + x;
			printf("%d[%d,%d]%d,", &arr2DFakeArray[idx], y, x, arr2DFakeArray[idx]);
		}
		printf("\n");
	}
}