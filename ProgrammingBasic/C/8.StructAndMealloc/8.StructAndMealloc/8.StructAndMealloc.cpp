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

//매개변수는 포인터를 전달해야 원본을 변경가능하다.
void InitGameObjectPtr(SGameObject* obj, const char* name, const char* tag, int layer)
{
	strcpy_s(obj->strName, name);//->: 구조체의 포인터에서는 멤버를 접근할때 사용
	strcpy_s(obj->strTag, tag);
	obj->nLayer = layer;
}
//원칙적으로는 매개변수로 데이터를 받아서 원본의 값을 변경해야한다.
void ToStringGameObjectPtr(char* strMsg, int size, const SGameObject* obj)
{
	sprintf_s(strMsg, size,"Name:%s, Tag:%s, Layer:%d", obj->strName, obj->strTag, obj->nLayer);
}

//리턴하여 다음과 같이 지역변수의 메모리를 참조하는 경우 문제가 발생가능성이 높다.
const char* ToStringGameObject(SGameObject obj)
{
	static char strMsg[2052];
	sprintf_s(strMsg, "Name:%s, Tag:%s, Layer:%d", obj.strName, obj.strTag, obj.nLayer);
	return strMsg;
}

//함수의 매개변수로 원본을 전달할때는 참조자를 쓰면 코드가 깔끔하다.
void InitGameObjectRef(SGameObject& obj, const char* name, const char* tag, int layer)
{
	strcpy_s(obj.strName, name);//->: 구조체의 포인터에서는 멤버를 접근할때 사용
	strcpy_s(obj.strTag, tag);
	obj.nLayer = layer;
}

void ToStringGameObjectRef(char* strMsg, int size, const SGameObject& obj)
{
	sprintf_s(strMsg, size,"Name:%s, Tag:%s, Layer:%d", obj.strName, obj.strTag, obj.nLayer);
}

//숫자를 enum을 이용하여 사용. 시작값을 지정하면 1씩증가하고, 
//지정하지않으면 0부터 시작하고 1씩증가한다.
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
	//구조체타입의 포인터
	SGameObject* pGameObject = &sGameObject;
	printf("Name:%s\n", pGameObject->strName);
	printf("Tag:%s\n", pGameObject->strTag);
	printf("Layer:%d\n", pGameObject->nLayer);
	//구조체는 복사된다.
	SGameObject sCopyObject = sGameObject;
	//매개변수로 전달될때도 복사되므로, 참조자를 이용하는 것이 효율적이다.
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
	//구조체타입의 포인터
	SGameObject* pGameObject = &sGameObject;
	printf("Name:%s\n", pGameObject->strName);
	printf("Tag:%s\n", pGameObject->strTag);
	printf("Layer:%d\n", pGameObject->nLayer);
	//구조체는 복사된다.
	SGameObject sCopyObject = sGameObject;
	//매개변수로 전달될때도 복사되므로, 참조자를 이용하는 것이 효율적이다.
	ToStringGameObjectPtr(strMsg, sizeof(strMsg), &sCopyObject);
	printf("%s", strMsg);
}

//동적할당: 프로그램 실행중에 메모리를 만들어서 사용하는 것.
//정적할당: 컴파일러 단에서 메모리가 생성되고 관리되는 것 == 자동할당: 이전까지 배운 모든 변수선언
void DynamicTestMain()
{
	void* pMalloc = NULL; //void포인터: 타입을 가지지않은 메모리의 주소를 저장하는 변수. 
	int* pBuffur = NULL;
	int nSize = 5;
	printf("int Array Size?");
	scanf_s("%d", &nSize); //입력값은 프로그램 실행중에 결정되므로 컴파일러가 결정하는 것이 아니다.

	//동적할당 중에 메모리가 부족하면 어떻게 될까?
	pMalloc = malloc(nSize * sizeof(int));//입력받은 크기의 동적배열생성(생성된 메모리는 타입이 없는 형태의 void포인터로 할당된다.)
	pBuffur = (int*)pBuffur; //메모리를 사용할 변수타입에 맞게 케스팅을 해서 배열처럼 사용한다.

	if (pBuffur)
	{
		for (int i = 0; i < nSize; i++)
			pBuffur[i] = i * 10;

		for (int i = 0; i < nSize; i++)
			printf("%d,", pBuffur[i]);
		printf("\n");

		free(pBuffur);//동적할당된 메모리 제거
	}

	//구조체의 메모리크기만큼 할당한다.
	pMalloc = malloc(sizeof(SGameObject));
	if (pMalloc)
	{
		//할당된 메모리를 구조체로 캐스팅하여 각 멤버에 접근한다.
		SGameObject* pGameObject = (SGameObject*)pMalloc;
		InitGameObjectPtr(pGameObject, "test", "test", 0);
		char strMsg[2048];
		ToStringGameObjectPtr(strMsg, sizeof(strMsg), pGameObject);
		printf("%s", strMsg);
		free(pGameObject);
	}
}

void main()
{
	//StructTestMain();
	DynamicTestMain();
}