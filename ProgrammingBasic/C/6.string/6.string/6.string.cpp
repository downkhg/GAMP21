#include <stdio.h>
#include <string.h>
//%s�� �̿��� ���ڿ� ��°� ���� ����
//�ι���(\0)�� ������ ���ڿ��� ������ �˼��ִ�.
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
//���ڿ��� ���� Ȯ���ϴ� ���α׷�
void StringTestMain()
{
	char str[] = "test";//���ڿ��� �ʱ�ȭ�Ҷ� ""�� �ʱ�ȭ�ϸ� ���������ڿ� �ι��ڰ� ����.
	printf("[%d]%s\n", sizeof(str) ,str);
	StringPrint(str);
	char arr[100];
	arr[0] = 't';
	arr[1] = 'e'; 
	arr[2] = 's';
	arr[3] = 't';
	arr[4] = '\0';//���ڿ����� �˸��¹���.
	scanf("%s", arr);//%s�� �Է¹����� ���ڿ����� ���ԵǾ� �Էµȴ�.
	//���ڿ����� �˼������� �Լ����� ���ڿ��� ����Ҷ� ������ ����ؾ��ϴ��� �˼�����.
	printf("[%d]%s\n", sizeof(arr), arr); 
	StringPrint(arr);
	StringPrint("const");
}

//���ڿ��� �����ϴ� ����
//���� �̸��� �Է¹޾Ƽ� �ѱ���, �̱��� �̸��� Ǯ������ ����Ͽ���.
//������: ��, �̸�, �ѱ���, �̱��� -> ���ڿ�,ũ��
//�˰���: �ѱ��� = �� + �̸� / �̱��� = �̸� + �� //���ڿ����̺귯��
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