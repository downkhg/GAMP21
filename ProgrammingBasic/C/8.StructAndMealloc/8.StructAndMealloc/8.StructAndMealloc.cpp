#include <stdio.h>
#include <string.h>
//구조체의 선언
struct SGameObject
{
	char strName[1024];
	char strTag[1024];
	int nLayer;
};
//매개변수는 포인터를 전달해야 원본을 변경가능하다.
void InitGameObject(SGameObject* obj, const char* name, const char* tag, int layer)
{
	strcpy_s(obj->strName, name);//->: 구조체의 포인터에서는 멤버를 접근할때 사용
	strcpy_s(obj->strTag, tag);
	obj->nLayer = layer;
}
//원칙적으로는 매개변수로 데이터를 받아서 원본의 값을 변경해야한다.
void ToStringGameObject(char* strMsg, int size, const SGameObject* obj)
{
	sprintf_s(strMsg, size,"Name:%s, Tag:%s, Layer:%d", obj->strName, obj->strTag, obj->nLayer);
}

//리턴하여 다음과 같이 지역변수의 메모리를 참조하는 경우 문제가 발생가능성이 높다.
//const char* ToStringGameObject(SGameObject obj)
//{
//	static char strMsg[2052];
//	sprintf_s(strMsg, "Name:%s, Tag:%s, Layer:%d", obj.strName, obj.strTag, obj.nLayer);
//	return strMsg;
//}

void StructTestMain()
{
	SGameObject sGameObject = {};// = { "eagle","Monster",0 };
	InitGameObject(&sGameObject, "eagle", "Monster", 0);
	printf("Name:%s\n", sGameObject.strName);
	printf("Tag:%s\n", sGameObject.strTag);
	printf("Layer:%d\n", sGameObject.nLayer);
	//printf("%s",ToStringGameObject(sGameObject));
	char strMsg[2048];
	ToStringGameObject(strMsg, sizeof(strMsg), &sGameObject);
	printf("%s", strMsg);
}

void main()
{
	StructTestMain();
}