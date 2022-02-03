#include <stdio.h>
//전역변수에 static한정자를 붙이면 해당 파일에서만 사용가능하다.
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
