#include <stdio.h>

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int FindMinIndex(int arr[], int size, int idxS)
{
	int nMinIdx = idxS;//8
	for (int i = idxS; i < size; i++)
	{
		if (arr[nMinIdx] > arr[i])
			nMinIdx = i;
	}
	return nMinIdx;
}

void InsertSort()
{
	int arrData[] = { 8,1,7,4,2,3,9,5,6 };

	//-------------------------------
	//�迭�� ���ĵǵ��� ������ ¥��
	//1. ���� �����Ѵ�.
	//2. ���õ� ���� �����ϰ�, ������ ���߿��� ���� ���� ���� ã�´�.
	//3. ���õ� ���� ���� ���� ���� ��ȯ�Ѵ�.
	int nSize = sizeof(arrData)/sizeof(int);
	for (int select = 0; select < nSize-1; select++)//0
	{
		//
		int nMinIdx = FindMinIndex(arrData, nSize, select);
		if(nMinIdx !=  select)
			Swap(arrData[select], arrData[nMinIdx]);
		printf("%d:",select);
		for (int i = 0; i < 9; i++)
			printf("%d,", arrData[i]);
		printf("\n");
	}
	//-------------------------------

	//������¿��� 1~9���� ������� ���ĵǵ��� �����
	printf("Data:");
	for (int i = 0; i < 9; i++)
		printf("%d,",arrData[i]);
	printf("\n");
}

void main()
{
	InsertSort();
}