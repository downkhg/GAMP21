#include <iostream>

using namespace std;

namespace A
{
	int g_nData;
	void PrintData() { cout << "DataA[" << &g_nData << "]:" << g_nData << endl; }
};

namespace B
{
	int g_nData;
	void PrintData() { cout << "DataB["<<&g_nData<<"]:"  << g_nData << endl; };
}

using namespace A;
using namespace B;
//���ӽ����̽�: ������ �̸��� �ξ� ���������� �Լ��� ������ �и���.
void NamespaceTestMain()
{
	A::g_nData = 10;
	A::PrintData();
	B::g_nData = 20;
	B::PrintData();
}
//�Լ��� �����ε�: �Լ��� �Ű������� ������ Ÿ���� �ٸ��� �����̸��� �Լ��� ���ǰ����Ѱ�.
//int Sum(int a, int b, int c) { return a + b + c; }
//int Sum(int a, int b) { return a + b + 30; }
//int Sum(int a) { return a + 20 + 30; }
//int Sum() { return 10 + 20 + 30; }

//����Ʈ�Ű�����: �Ű������� ���� �����ϸ�, ������ ���� �ڵ����� ä������.
//inline: ��ũ���Լ�ó�� �����Ϸ��ܿ� �Լ���ſ� �ڵ�� �������ش�.(��, ��� ���δٰ� �Ǵ°��� �ƴ�)
inline int Sum(int a = 10, int b = 20, int c = 30) { return a + b + c; }

void FunctionOverlodingTestMain()
{
	cout << Sum(10,20,30) << endl;
	cout << Sum(10,20) << endl;
	cout << Sum(10) << endl;
	cout << Sum() << endl;
}

void RefTestMain()
{
	int nData = 10;
	int& refData = nData; //�ݵ�� �����ϴ� ����� �ʱ�ȭ�Ǿ���Ѵ�.
	cout << "Addr:" << &nData << "/" << &refData << endl;
	cout << "1. nData:" << nData <<"/refData:"<<refData<< endl;
	nData = 20;
	cout << "2. nData:" << nData << "/refData:" << refData << endl;
	refData = 30;
	cout << "2. nData:" << nData << "/refData:" << refData << endl;
}
//ī��,�ڿ� ���̱�,��,
void StringTestMain()
{
	string strFirstName;
	string strLastName;
	string strFullName;

	strFirstName = "hg";
	strLastName = "k";

	strFullName = strLastName + strFirstName;//kr
	strFullName = strFirstName + strLastName; //en

	int nIdx = strFullName.find('h', 0);
	cout << strFullName << endl;
	cout << nIdx << ":" << strFirstName[nIdx] << endl;
	strFullName.replace(1, 1, 3, strFullName[nIdx]);

	cout << strFullName << endl;
}

//1. �޸𸮸� ���������ʰ�, ����ϴ� ���� ȿ�����̴�. -> ���ڴ� �⺻������ �迭�̴�.
//2. ��ü�̹Ƿ� �ε����� �̿��� ���ٺ��ٴ�, �Լ��� �̿��Ͽ� ó���Ѵ�.
void main()
{
	//NamespaceTestMain();
	//efTestMain();
	StringTestMain();
}