#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//구조체의 선언
struct SGameObject
{
	char strName[1024];
	char strTag[1024];
	int nLayer;
};

////매개변수는 포인터를 전달해야 원본을 변경가능하다.
//void InitGameObject(SGameObject* obj, const char* name, const char* tag, int layer)
//{
//	strcpy_s(obj->strName, name);//->: 구조체의 포인터에서는 멤버를 접근할때 사용
//	strcpy_s(obj->strTag, tag);
//	obj->nLayer = layer;
//}
////원칙적으로는 매개변수로 데이터를 받아서 원본의 값을 변경해야한다.
//void ToStringGameObject(char* strMsg, int size, const SGameObject* obj)
//{
//	sprintf_s(strMsg, size,"Name:%s, Tag:%s, Layer:%d", obj->strName, obj->strTag, obj->nLayer);
//}

//리턴하여 다음과 같이 지역변수의 메모리를 참조하는 경우 문제가 발생가능성이 높다.
//const char* ToStringGameObject(SGameObject obj)
//{
//	static char strMsg[2052];
//	sprintf_s(strMsg, "Name:%s, Tag:%s, Layer:%d", obj.strName, obj.strTag, obj.nLayer);
//	return strMsg;
//}

//함수의 매개변수로 원본을 전달할때는 참조자를 쓰면 코드가 깔끔하다.
void InitGameObject(SGameObject& obj, const char* name, const char* tag, int layer)
{
	strcpy_s(obj.strName, name);//->: 구조체의 포인터에서는 멤버를 접근할때 사용
	strcpy_s(obj.strTag, tag);
	obj.nLayer = layer;
}

void ToStringGameObject(char* strMsg, int size, const SGameObject& obj)
{
	sprintf_s(strMsg, size,"Name:%s, Tag:%s, Layer:%d", obj.strName, obj.strTag, obj.nLayer);
}

//숫자를 enum을 이용하여 사용. 시작값을 지정하면 1씩증가하고, 
//지정하지않으면 0부터 시작하고 1씩증가한다.
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
	//구조체타입의 포인터
	SGameObject* pGameObject = &sGameObject;
	printf("Name:%s\n", pGameObject->strName);
	printf("Tag:%s\n", pGameObject->strTag);
	printf("Layer:%d\n", pGameObject->nLayer);
	//구조체는 복사된다.
	SGameObject sCopyObject = sGameObject;
	//매개변수로 전달될때도 복사되므로, 참조자를 이용하는 것이 효율적이다.
	ToStringGameObject(strMsg, sizeof(strMsg), sCopyObject);
	printf("%s", strMsg);
}
//동적할당
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