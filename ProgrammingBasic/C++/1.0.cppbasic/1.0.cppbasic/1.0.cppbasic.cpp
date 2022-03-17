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
//네임스페이스: 공간에 이름을 두어 전역변수나 함수의 공간을 분리함.
void NamespaceTestMain()
{
	A::g_nData = 10;
	A::PrintData();
	B::g_nData = 20;
	B::PrintData();
}
//함수의 오버로딩: 함수의 매개변수의 갯수나 타입이 다르면 같은이름의 함수를 정의가능한것.
//int Sum(int a, int b, int c) { return a + b + c; }
//int Sum(int a, int b) { return a + b + 30; }
//int Sum(int a) { return a + 20 + 30; }
//int Sum() { return 10 + 20 + 30; }

//디폴트매개변수: 매개변수에 값을 생략하면, 지정된 값이 자동으로 채워진다.
//inline: 매크로함수처럼 컴파일러단에 함수대신에 코드로 변경해준다.(단, 모두 붙인다고 되는것은 아님)
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
	int& refData = nData; //반드시 참조하는 대상이 초기화되어야한다.
	cout << "Addr:" << &nData << "/" << &refData << endl;
	cout << "1. nData:" << nData <<"/refData:"<<refData<< endl;
	nData = 20;
	cout << "2. nData:" << nData << "/refData:" << refData << endl;
	refData = 30;
	cout << "2. nData:" << nData << "/refData:" << refData << endl;
}
//카피,뒤에 붙이기,비교,
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

//1. 메모리를 삭제하지않고, 사용하는 것이 효율적이다. -> 문자는 기본적으로 배열이다.
//2. 객체이므로 인덱스를 이용한 접근보다는, 함수를 이용하여 처리한다.
void main()
{
	//NamespaceTestMain();
	//efTestMain();
	StringTestMain();
}