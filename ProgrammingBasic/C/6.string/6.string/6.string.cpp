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
void ArrayPrint(char* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d",arr[i]);
	}
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
	//StringPrint("const");
	ArrayPrint(arr, 100);
}

//���ڿ��� �����ϴ� ����
//���� �̸��� �Է¹޾Ƽ� �ѱ���, �̱��� �̸��� Ǯ������ ����Ͽ���.
//������: ��, �̸�, �ѱ���, �̱��� -> ���ڿ�,ũ��
//�˰���: �ѱ��� = �� + �̸� / �̱��� = �̸� + �� //���ڿ����̺귯��
//��(���ڿ�)�� �̸�(���ڿ�)�� ��ġ�� -> ���ڿ� ��ġ��
void FullNameMakerMain()
{
	char strLastName[10] = "k";
	char strFirstName[10] = "hg";
	char strFullNameKr[20] = {};// = "";
	char strFullNameEn[20] = {};// = "";

	printf("[%d]%s\n",strlen(strLastName),strLastName);
	printf("[%d]%s\n", strlen(strFirstName), strFirstName);
	//strcpy: �����ϱ� , strcpy: �ڿ� �ٿ��ֱ�
	//strcpy(strFullNameKr, strLastName);
	//strcat(strFullNameKr, strFirstName);

	sprintf(strFullNameKr, "%s%s", strLastName, strFirstName);

	//strcpy(strFullNameEn, strFirstName);
	//strcat(strFullNameEn, strLastName);

	sprintf(strFullNameEn, "%s%s", strFirstName, strLastName);

	printf("kr:%s\n",strFullNameKr);
	printf("en:%s\n",strFullNameEn);

	if (strFullNameKr == strFullNameEn)
		printf("%d<->%d\n", strFullNameKr,strFullNameEn);
	else
		printf("%d<->%d\n", strFullNameKr, strFullNameEn);

	int nResult = strcmp(strFullNameKr, strFullNameEn);
	printf("Result:%d\n",nResult);
	if (!nResult)//0 
		printf("%s == %s\n", strFullNameKr, strFullNameEn);
	else
		printf("%s != %s\n", strFullNameKr, strFullNameEn);
}

void main()
{
	//StringTestMain();
	FullNameMakerMain();
}