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

//�Ű������� �����͸� �����ؾ� ������ ���氡���ϴ�.
void InitGameObjectPtr(SGameObject* obj, const char* name, const char* tag, int layer)
{
	strcpy_s(obj->strName, name);//->: ����ü�� �����Ϳ����� ����� �����Ҷ� ���
	strcpy_s(obj->strTag, tag);
	obj->nLayer = layer;
}
//��Ģ�����δ� �Ű������� �����͸� �޾Ƽ� ������ ���� �����ؾ��Ѵ�.
void ToStringGameObjectPtr(char* strMsg, int size, const SGameObject* obj)
{
	sprintf_s(strMsg, size,"Name:%s, Tag:%s, Layer:%d", obj->strName, obj->strTag, obj->nLayer);
}

//�����Ͽ� ������ ���� ���������� �޸𸮸� �����ϴ� ��� ������ �߻����ɼ��� ����.
const char* ToStringGameObject(SGameObject obj)
{
	static char strMsg[2052];
	sprintf_s(strMsg, "Name:%s, Tag:%s, Layer:%d", obj.strName, obj.strTag, obj.nLayer);
	return strMsg;
}

//�Լ��� �Ű������� ������ �����Ҷ��� �����ڸ� ���� �ڵ尡 ����ϴ�.
void InitGameObjectRef(SGameObject& obj, const char* name, const char* tag, int layer)
{
	strcpy_s(obj.strName, name);//->: ����ü�� �����Ϳ����� ����� �����Ҷ� ���
	strcpy_s(obj.strTag, tag);
	obj.nLayer = layer;
}

void ToStringGameObjectRef(char* strMsg, int size, const SGameObject& obj)
{
	sprintf_s(strMsg, size,"Name:%s, Tag:%s, Layer:%d", obj.strName, obj.strTag, obj.nLayer);
}

//���ڸ� enum�� �̿��Ͽ� ���. ���۰��� �����ϸ� 1�������ϰ�, 
//�������������� 0���� �����ϰ� 1�������Ѵ�.
enum E_LAYER { Player = 8, Monster, Bullet };
//enum E_TAG { Player = 8, Monster, Bullet };

void StructRefTestMain()
{
	SGameObject sGameObject = {};// = { "eagle","Monster",0 };
	InitGameObjectRef(sGameObject, "eagle", "Monster", E_LAYER::Monster);
	printf("Name:%s\n", sGameObject.strName);
	printf("Tag:%s\n", sGameObject.strTag);
	printf("Layer:%d\n", sGameObject.nLayer);
	//printf("%s",ToStringGameObject(sGameObject));
	char strMsg[2048];
	ToStringGameObjectRef(strMsg, sizeof(strMsg), sGameObject);
	printf("%s", strMsg);
	//����üŸ���� ������
	SGameObject* pGameObject = &sGameObject;
	printf("Name:%s\n", pGameObject->strName);
	printf("Tag:%s\n", pGameObject->strTag);
	printf("Layer:%d\n", pGameObject->nLayer);
	//����ü�� ����ȴ�.
	SGameObject sCopyObject = sGameObject;
	//�Ű������� ���޵ɶ��� ����ǹǷ�, �����ڸ� �̿��ϴ� ���� ȿ�����̴�.
	ToStringGameObjectRef(strMsg, sizeof(strMsg), sCopyObject);
	printf("%s", strMsg);
}

void StructPtrTestMain()
{
	SGameObject sGameObject = {};// = { "eagle","Monster",0 };
	InitGameObjectPtr(&sGameObject, "eagle", "Monster", E_LAYER::Monster);
	printf("Name:%s\n", sGameObject.strName);
	printf("Tag:%s\n", sGameObject.strTag);
	printf("Layer:%d\n", sGameObject.nLayer);
	//printf("%s",ToStringGameObject(sGameObject));
	char strMsg[2048];
	ToStringGameObjectPtr(strMsg, sizeof(strMsg), &sGameObject);
	printf("%s", strMsg);
	//����üŸ���� ������
	SGameObject* pGameObject = &sGameObject;
	printf("Name:%s\n", pGameObject->strName);
	printf("Tag:%s\n", pGameObject->strTag);
	printf("Layer:%d\n", pGameObject->nLayer);
	//����ü�� ����ȴ�.
	SGameObject sCopyObject = sGameObject;
	//�Ű������� ���޵ɶ��� ����ǹǷ�, �����ڸ� �̿��ϴ� ���� ȿ�����̴�.
	ToStringGameObjectPtr(strMsg, sizeof(strMsg), &sCopyObject);
	printf("%s", strMsg);
}

//�����Ҵ�: ���α׷� �����߿� �޸𸮸� ���� ����ϴ� ��.
//�����Ҵ�: �����Ϸ� �ܿ��� �޸𸮰� �����ǰ� �����Ǵ� �� == �ڵ��Ҵ�: �������� ��� ��� ��������
//�����Ҵ��� �� ��� �� �����͸� ����ؾ��ϴ°�? 
//�����Ҵ��� �޸𸮰� �����ϴ��߿� �Ҵ�Ǿ����Ƿ�, 
//�̸��� ���������ʴ´�. �ٽ� �����ϱ����ؼ��� �ּҰ��� �˾ƾ��ϴµ�, ���ּҰ��� �����ϴµ� �����͸� ����Ѵ�.
void DynamicTestMain()
{
	void* pMalloc = NULL; //void������: Ÿ���� ���������� �޸��� �ּҸ� �����ϴ� ����. 
	int* pBuffur = NULL;
	int nSize = 5;
	printf("int Array Size?");
	scanf_s("%d", &nSize); //�Է°��� ���α׷� �����߿� �����ǹǷ� �����Ϸ��� �����ϴ� ���� �ƴϴ�.

	//�����Ҵ� �߿� �޸𸮰� �����ϸ� ��� �ɱ�?
	//pMalloc = malloc(nSize * sizeof(int));//�Է¹��� ũ���� �����迭����(������ �޸𸮴� Ÿ���� ���� ������ void�����ͷ� �Ҵ�ȴ�.)
	//pBuffur = (int*)malloc(nSize * sizeof(int)); //�޸𸮸� ����� ����Ÿ�Կ� �°� �ɽ����� �ؼ� �迭ó�� ����Ѵ�. //c
	pBuffur = new int[nSize];//c++

	if (pBuffur)//�޸𸮰� �Ҵ�����ʾҴٸ� null�� ��ȯ�Ͽ� ��������ʾƾ��Ѵ�.
	{
		for (int i = 0; i < nSize; i++)
			pBuffur[i] = i * 10;

		for (int i = 0; i < nSize; i++)
			printf("%d,", pBuffur[i]);
		printf("\n");

		//free(pBuffur);//�����Ҵ�� �޸� ���� //c
		delete[] pBuffur; //c++
	}

	//����ü�� �޸�ũ�⸸ŭ �Ҵ��Ѵ�.
	//SGameObject* pGameObject = (SGameObject*)malloc(sizeof(SGameObject));//c
	SGameObject* pGameObject = new SGameObject(); //c++
	if (pGameObject)
	{
		//�Ҵ�� �޸𸮸� ����ü�� ĳ�����Ͽ� �� ����� �����Ѵ�.
		InitGameObjectPtr(pGameObject, "test", "test", 0);
		char strMsg[2048];
		ToStringGameObjectPtr(strMsg, sizeof(strMsg), pGameObject);
		printf("%s", strMsg);
		//free(pGameObject);//c
		delete pGameObject;//c++
	}
}

void main()
{
	//StructTestMain();
	DynamicTestMain();
}