/*##################################
����Ʈ��(C��� ������)
���ϸ�: BinaryTree.cpp
�ۼ��� : ��ȫ��(downkhg@gmail.com)
������������¥ : 2022.03.04
���� : 1.01
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
	//printf("%d\n", pNode->nData); //����
	Traverse(pNode->pLeft);
	//printf("%d\n", pNode->nData); //����
	Traverse(pNode->pRight);
	printf("%d\n", pNode->nData); //����
}

void Print(SNode* pSeed)
{
	Traverse(pSeed);
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