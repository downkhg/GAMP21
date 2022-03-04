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
	//배열을 정렬되도록 로직을 짜기
	//1. 값을 선택한다.
	//2. 선택된 값을 제외하고, 나머지 값중에서 가장 작은 값을 찾는다.
	//3. 선택된 값과 가장 작은 값을 교환한다.
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

	//다음출력에서 1~9까지 순서대로 정렬되도록 만들기
	printf("Data:");
	for (int i = 0; i < 9; i++)
		printf("%d,",arrData[i]);
	printf("\n");
}

void main()
{
	InsertSort();
}