#include <stdio.h>
#include <string.h>
//�������� ���� ���� �����ڿ� ������������ �������� Ȯ���ϴ� ���α׷�.
void ValueAndOperatorMain();
//������ �Ǽ��� �����͸� �����ϰ�, �� ����� �����͸� ������ �Ǽ��� �����Ϳ� �����Ͽ�,
//��� �����鿡�� ������ ���ִ� ��� ����� ����Ͽ���.
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
//������ �Ǽ��� �����͸� �����ϰ�, �� ����� �����͸� ������ �Ǽ��� �����Ϳ� �����Ͽ�,
//��� �����鿡�� ������ ���ִ� ��� ����� ����Ͽ���.
void PointerMain()
{
	int nData = 10;
	float fData = 3.14f;
	int* pIntData = &nData;//������: �ּҰ��� �����ϴ� ����
	float* pFloatData = &fData;

	printf("nData[%d]:%d\n", &nData, nData);
	printf("fData[%d]:%f\n", &fData, fData);
	//*(����):�����Ͱ� ���� �ּҰ��� ����Ű�� ������ ��.
	printf("IntData[%d]:%d\n", *pIntData, pIntData);
	printf("FloatData[%f]:%d\n", *pFloatData, pFloatData);
}

void SwapVal(int a, int b)//�������� ȣ��
{
	printf("SwapVal[%d]%d<->[%d]%d\n", &a, a, &b, b);
	int temp = a;
	a = b;
	b = temp;
}

void SwapPtr(int* a, int* b)//�ּҰ������� ȣ��
{
	printf("SwapPtr[%d]%d<->[%d]%d\n", *a, a, *b, b);
	int temp = *a;
	*a = *b;
	*b = temp;
}

void SwapRef(int& a, int& b)//���������� ȣ��
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

void ArrayMain()//�迭�� �޸��� �ּҰ��� Ȱ���Ͽ� ������������ �����ϴ�.
{
	const int nSize = 3;
	int arrScore[nSize];//�����Ϸ��� �迭�� ũ�⸦ �˾ƾ߸� �Ҵ��Ҽ��ִ�.
	int arrSize = sizeof(arrScore) / sizeof(int);
	for (int i = 0; i < nSize; i++)
		arrScore[i] = 100 - i * 10;
	printf("arrScore[%d]:%d\n", &arrScore, arrScore);
	for (int i = 0; i < nSize; i++)
		printf("[%d/%d]:%d,",&arrScore[i],i,arrScore[i]);//�ε����� �̿��� ����
	printf("\n");
	for (int i = 0; i < nSize; i++)
		printf("[%d/%d]:%d,", (arrScore+i), i, *(arrScore+i)); //�������� ���� +n�Ͽ� ���
	printf("\n");
	int* pArrScore = arrScore;
	for (int i = 0; i < nSize; i++)
	{
		printf("[%d/%d]:%d,", pArrScore, i, *pArrScore);
		pArrScore++;//�����Ϳ��� ���� 1�� �����ؼ� ����
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