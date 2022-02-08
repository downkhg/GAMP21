#include <stdio.h>
#include <string.h>
//%s를 이용한 문자열 출력과 같은 원리
//널문자(\0)를 만나야 문자열의 끝인지 알수있다.
void StringPrint(const char* str)
{
	int idx = 0;
	while (str[idx] != '\0')
	{
		printf("%c", str[idx]);
		idx++;
	}
	printf("\n");
}
//문자열의 끝을 확인하는 프로그램
void StringTestMain()
{
	char str[] = "test";//문자열의 초기화할때 ""로 초기화하면 마지막문자에 널문자가 들어간다.
	printf("[%d]%s\n", sizeof(str) ,str);
	StringPrint(str);
	char arr[100];
	arr[0] = 't';
	arr[1] = 'e'; 
	arr[2] = 's';
	arr[3] = 't';
	arr[4] = '\0';//문자열끝을 알리는문자.
	scanf("%s", arr);//%s로 입력받으면 문자열끝이 포함되어 입력된다.
	//문자열끝을 알수없으면 함수에서 문자열을 출력할때 어디까지 출력해야하는지 알수없음.
	printf("[%d]%s\n", sizeof(arr), arr); 
	StringPrint(arr);
	StringPrint("const");
}

//문자열을 가공하는 예제
//성과 이름을 입력받아서 한국식, 미국식 이름을 풀네임을 출력하여라.
//데이터: 성, 이름, 한국식, 미국식 -> 문자열,크기
//알고리즘: 한국식 = 성 + 이름 / 미국식 = 이름 + 성 //문자열라이브러리
void FullNameMakerMain()
{
	char strLastName[100];
	char strFirstName[100];
	char strFullNameKr[200];
	char strFullNameEn[200];


	printf("kr:%s\n",strFullNameKr);
	printf("en:%s\n",strFullNameEn);
}

void main()
{
	StringTestMain();
}