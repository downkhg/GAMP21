#include <stdio.h>
#include <string.h>
//����ü�� ����
struct SGameObject
{
	char strName[1024];
	char strTag[1024];
	int nLayer;
};
//�Ű������� �����͸� �����ؾ� ������ ���氡���ϴ�.
void InitGameObject(SGameObject* obj, const char* name, const char* tag, int layer)
{
	strcpy_s(obj->strName, name);//->: ����ü�� �����Ϳ����� ����� �����Ҷ� ���
	strcpy_s(obj->strTag, tag);
	obj->nLayer = layer;
}
//��Ģ�����δ� �Ű������� �����͸� �޾Ƽ� ������ ���� �����ؾ��Ѵ�.
void ToStringGameObject(char* strMsg, int size, const SGameObject* obj)
{
	sprintf_s(strMsg, size,"Name:%s, Tag:%s, Layer:%d", obj->strName, obj->strTag, obj->nLayer);
}

//�����Ͽ� ������ ���� ���������� �޸𸮸� �����ϴ� ��� ������ �߻����ɼ��� ����.
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