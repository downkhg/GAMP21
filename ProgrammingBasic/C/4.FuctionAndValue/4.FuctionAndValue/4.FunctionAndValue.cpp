#include <stdio.h>

//�Լ� -> ��
//�������� -> ����
//�������� -> �������
//������ ��������� �������ִ�.   
//�Լ��� ���������� ����Ҽ��ִ�.
//��������� ��� ���̳� ���� �������ִ�.
//���������� ��� �Լ��� ��� �� �� �ִ�.

//�޸𸮰� 1g�� �ִٰ� �Ѵٸ�, ��� ������ ���������� ����� �ִ� 1g�� ��밡���ϴ�.
//�޸𸮰� 1g�� �ְ�, ���������� 500mb����ϰ�, �� �Լ����� 500mb�� ���������� ����ϸ�, 
//�Լ� ȣ���� ������ �ٸ� �Լ��� ��� �Ҽ� �ִ�.

//��������: ����Լ����� ���ٰ����� ����.{}�ȿ� ������������ ����. ���α׷��� ����ɶ����� �����ȴ�.
int g_nData;

//��������: �Լ�(����)�ȿ����� �����ϴ� ����. �Ű������� ���������� �����̴�.
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
	//nDataA = 100; //�����Լ��� �ִ� ������ ���ٰ����ϴ�.
	//nParameter = 200; //�Ű������� ����������.
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
	inc(nData);//�Ű������� ���޵� ���� �Լ����ο��� �����Ǵ��� �ݿ������ʴ´�.
	nData = inc(nData);//���Ϲ��������� �����ؼ� �ٸ����������� �ʱ�ȭ�ؾ��Ѵ�.
	printf("2. Data:%d\n", nData);
}
//������������: �Լ��� ����ǵ� ���� �����ϴ� ����.
//��������: �Լ��� ȣ��ɶ����� �ʱ�ȭ�Ǵ� ����.
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

extern int g_nDataA; //extern: �̷��� ���������� ������ ���⿡�� ������ ���� �ƴ�.(�Լ��� ����� ����)
extern /*static*/int g_nStaticDataB; //extern�� static�� ���� ����Ҽ� ����.

extern void PrintDataA();//exturn�Լ�: �� �Լ��� ���Ǵ� �ٸ����Ͽ� �ִ�.
//extern void PrintDataB(); //static�Լ��� �ش����Ͽ����� ���ٰ����ϹǷ� extern�� �ϴ��� ����� �Ұ����ϴ�.

void GrobalStaticTestMain()
{
	g_nDataA = 100;
	PrintDataA();
	//static�� ���̸� �ش� ���Ͼȿ����� ��밡���ϴ�.
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