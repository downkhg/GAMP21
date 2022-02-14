#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//����ü�� ����
struct SGameObject
{
	char strName[1024];
	char strTag[1024];
	int nLayer;
};

////�Ű������� �����͸� �����ؾ� ������ ���氡���ϴ�.
//void InitGameObject(SGameObject* obj, const char* name, const char* tag, int layer)
//{
//	strcpy_s(obj->strName, name);//->: ����ü�� �����Ϳ����� ����� �����Ҷ� ���
//	strcpy_s(obj->strTag, tag);
//	obj->nLayer = layer;
//}
////��Ģ�����δ� �Ű������� �����͸� �޾Ƽ� ������ ���� �����ؾ��Ѵ�.
//void ToStringGameObject(char* strMsg, int size, const SGameObject* obj)
//{
//	sprintf_s(strMsg, size,"Name:%s, Tag:%s, Layer:%d", obj->strName, obj->strTag, obj->nLayer);
//}

//�����Ͽ� ������ ���� ���������� �޸𸮸� �����ϴ� ��� ������ �߻����ɼ��� ����.
//const char* ToStringGameObject(SGameObject obj)
//{
//	static char strMsg[2052];
//	sprintf_s(strMsg, "Name:%s, Tag:%s, Layer:%d", obj.strName, obj.strTag, obj.nLayer);
//	return strMsg;
//}

//�Լ��� �Ű������� ������ �����Ҷ��� �����ڸ� ���� �ڵ尡 ����ϴ�.
void InitGameObject(SGameObject& obj, const char* name, const char* tag, int layer)
{
	strcpy_s(obj.strName, name);//->: ����ü�� �����Ϳ����� ����� �����Ҷ� ���
	strcpy_s(obj.strTag, tag);
	obj.nLayer = layer;
}

void ToStringGameObject(char* strMsg, int size, const SGameObject& obj)
{
	sprintf_s(strMsg, size,"Name:%s, Tag:%s, Layer:%d", obj.strName, obj.strTag, obj.nLayer);
}

//���ڸ� enum�� �̿��Ͽ� ���. ���۰��� �����ϸ� 1�������ϰ�, 
//�������������� 0���� �����ϰ� 1�������Ѵ�.
enum E_LAYER { Player = 8, Monster, Bullet };
//enum E_TAG { Player = 8, Monster, Bullet };

void StructTestMain()
{
	SGameObject sGameObject = {};// = { "eagle","Monster",0 };
	InitGameObject(sGameObject, "eagle", "Monster", E_LAYER::Monster);
	printf("Name:%s\n", sGameObject.strName);
	printf("Tag:%s\n", sGameObject.strTag);
	printf("Layer:%d\n", sGameObject.nLayer);
	//printf("%s",ToStringGameObject(sGameObject));
	char strMsg[2048];
	ToStringGameObject(strMsg, sizeof(strMsg), sGameObject);
	printf("%s", strMsg);
	//����üŸ���� ������
	SGameObject* pGameObject = &sGameObject;
	printf("Name:%s\n", pGameObject->strName);
	printf("Tag:%s\n", pGameObject->strTag);
	printf("Layer:%d\n", pGameObject->nLayer);
	//����ü�� ����ȴ�.
	SGameObject sCopyObject = sGameObject;
	//�Ű������� ���޵ɶ��� ����ǹǷ�, �����ڸ� �̿��ϴ� ���� ȿ�����̴�.
	ToStringGameObject(strMsg, sizeof(strMsg), sCopyObject);
	printf("%s", strMsg);
}
//�����Ҵ�
void DynamicTestMain()
{
	int* pBuffur = NULL;
	int nSize = 5;
	printf("int Array Size?");
	scanf_s("%d", &nSize);

	pBuffur = (int*)malloc(nSize * sizeof(int));
	for (int i = 0; i < nSize; i++)
		pBuffur[i] = i * 10;

	for (int i = 0; i < nSize; i++)
		printf("%d,",pBuffur[i]);
	printf("\n");

	free(pBuffur);
}

void main()
{
	//StructTestMain();
	DynamicTestMain();
}