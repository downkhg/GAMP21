#include <stdio.h> //���̺귯��: ���������� å�� ������ ��ó�� �Լ��� �ʿ��Ҷ����� �����ͼ� ����ϴ� ��.
//�Լ�: ����� ���� ����ϴ� ��.
//���ϰ�: ���� ����� �Լ������� �����°�. ������ ������ �Լ��� ����ȴ�.
//�Ű�����: �Լ��ۿ��� ���� ���� �������ִ� ����.
//�Լ���: �Լ��� ȣ���Ҷ� ����ϴ� �̸�.
//���ϰ� �Լ���(�Ű�����.....)
int square(int x)//������ ���ϴ� �Լ�
{
	return x * x; 
}

//������ ���ϴ� �Լ��� ����, ���ڸ� ������ �������� ����ϴ� ���α׷��� �����
//����:����-����
//�˰���:���ڸ� ���� -> ����*����
void SquareCalculatorMain()
{
	int nNumber = 5;

	//int nSquare = nNumber* nNumber;
	int nSquare = square(nNumber);//�μ�: �Ű������� ���޵Ǵ� ��.

	printf("%d^2 = %d\n", nNumber, nSquare);//���̺귯�� �Լ�
}

int Add(int a, int b) //�Լ��� �Ű������� 2���̻� ������ִ�.
{
	return a + b;
}

float Add_fi(float a, int b) //�Լ��� �Ű������� Ÿ���� �޶� �������. //���ϰ��� ������� ������ ���� Ÿ���� �����ϸ�ȴ�.
{
	return a + b;
}

int ResutnTest()//�Լ����� ���� 2���̻� ����� ����������� ���������� ������ �̿��ؾ��Ѵ�.(���� �ٷ�)
{
	printf("ResutnTest 1");
	return 1; //������ ������ �Լ��� ����ǹǷ� �ڿ� �ڵ�� ���ǹ��ϴ�.
	printf("ResutnTest 2");
	return 2;
	printf("ResutnTest 3");
	return 3;
	printf("ResutnTest 4");
}

int Max(int a, int b)//���ǿ� ���� ���ϰ��� ���� �ٸ� ��� ���� ��ΰ� �ٸ��Ƿ� �������.
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
//�Լ��� ����: �̷� Ÿ���� �Լ��� �ִ�. ������ ������ �˼�����.
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
//�Լ��� ����: ����� �Լ��� ������ �ۼ���.
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