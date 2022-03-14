/*##################################
이진트리(C언어 수업용)
파일명: BinaryTree.cpp
작성자 : 김홍규(downkhg@gmail.com)
마지막수정날짜 : 2022.03.04
버전 : 1.01
###################################*/
#include <stdio.h>

using namespace std;

struct SNode {
	int nData;
	SNode* pLeft;
	SNode* pRight;
};

SNode* CreateNode(int data)
{
	SNode* pTemp = new SNode;
	pTemp->nData = data;
	pTemp->pLeft = NULL;
	pTemp->pRight = NULL;
	return pTemp;
};
bool MakeLeft(SNode* pParent, SNode* pChilde)
{
	if (pParent == NULL)
		return false;
	pParent->pLeft = pChilde;
	return true;
};
bool MakeRight(SNode* pParent, SNode* pChilde)
{
	if (pParent == NULL)
		return false;
	pParent->pRight = pChilde;
	return true;
};

void Traverse(SNode* pNode)
{
	if (pNode == NULL) return;
	//printf("%d\n", pNode->nData); //전위
	Traverse(pNode->pLeft);
	//printf("%d\n", pNode->nData); //중위
	Traverse(pNode->pRight);
	printf("%d\n", pNode->nData); //후위
}

void Print(SNode* pSeed)
{
	Traverse(pSeed);
}

void Swap(int& a, int& b)
{
	printf("Swap[%d <->%d]\n", a, b);
	int temp = a;
	a = b;
	b = temp;
}

void MinHipTreeInsert(SNode* pParent, SNode* pInsert)
{
	if (pParent == NULL) return;
	if (pParent->nData > pInsert->nData)
	{
		printf("Swap Parent\n");
		Swap(pParent->nData, pInsert->nData);

		MinHipTreeInsert(pParent, pInsert);
	}
	else
	{
		if (pParent->pLeft == NULL)
		{
			pParent->pLeft = pInsert;
			printf("MinHipTreeInsert_Left:%d\n", pInsert->nData);
			return;
		}
		else if (pParent->pRight == NULL)
		{
			pParent->pRight = pInsert;
			printf("MinHipTreeInsert_Right:%d\n", pInsert->nData);
			return;
		}
		else
			MinHipTreeInsert(pParent->pLeft, pInsert);
	}
}

void HipTreeTestMain()
{
	const int nSize = 7;
	SNode* arrNode[nSize];

	for (int i = 0; i < nSize; i++)
		//arrNode[i] = CreateNode((i + 1) * 10); //Best
		arrNode[i] = CreateNode((nSize - 1 * i) * 10); //Worst

	for (int i = 1; i < nSize; i++)
		MinHipTreeInsert(arrNode[0], arrNode[i]);

	Print(arrNode[0]);
}

void main()
{
	SNode* pSeed = NULL;

	SNode* pParent = CreateNode(10);
	SNode* pLeft = CreateNode(20);
	SNode* pRight = CreateNode(30);
	SNode* pD = CreateNode(40);
	SNode* pE = CreateNode(50);

	MakeLeft(pParent, pLeft);
	MakeRight(pParent, pRight);

	MakeLeft(pLeft, pD);
	MakeRight(pLeft, pE);

	pSeed = pParent;

	Print(pSeed);
}