#include <stdio.h>
//���������� static�����ڸ� ���̸� �ش� ���Ͽ����� ��밡���ϴ�.
int g_nDataA;
static int g_nStaticDataB;

void PrintDataA()
{
	printf("DataA:%d\n", g_nDataA);
}
static void PrintDataB()
{
	printf("DataB:%d\n", g_nStaticDataB);
}
