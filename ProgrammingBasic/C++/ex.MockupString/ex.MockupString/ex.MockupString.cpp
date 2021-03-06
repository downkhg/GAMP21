/*##################################
ex.MockupString(C++ 수업용)
파일명: ex.MockupString.cpp
작성자 : 김홍규(downkhg@gmail.com)
마지막수정날짜 : 2022.03.16
버전 : 1.00
###################################*/
#include <iostream>
#include <stdlib.h> //메모리 동적할당 헤더
#include <crtdbg.h> //메모리 누수 탐지 헤더

using namespace std;
//문자열 클래스를 활용해보고, 해당 함수를 가능한 선까지 구현하고 테스트를 하여
//정상적으로 작동하는지, 확인해보자.
void STDStringMain()
{
	cout << "##### STDStringMain Start######" << endl;
	string strMsg("Test"); //생성자
	string strMsg2("DataTest"); //생성자
	string srtCopyMsg = strMsg; //복사생성자: 객체가 복사되며 초기회될때 호출되는 함수.

	cout << strMsg.c_str() << endl; //const char*를 리턴하는 함수 //Test
	printf("%d:%s\n", strMsg.c_str(), strMsg.c_str()); //0x01:Test
	cout << strMsg2.c_str() << endl; //DataTest
	printf("%d:%s\n", strMsg2.c_str(), strMsg2.c_str()); //0x02:DataTest
	printf("%d:%s\n", srtCopyMsg.c_str(), srtCopyMsg.c_str()); //0x03:Test
	cout << "##### STDStringMain End######" << endl;
}

namespace Mockup
{
	class string
	{
		char* pStr; //동적할당된 문자열의 주소를 저장할 포인터
	public:
		string()
		{
			pStr = NULL;
		}
		//생성자에서 동적할당된 메모리는 객체가 소멸될때 호출되어야한다.
		string(const char* str)
		{
			int nSize = strlen(str) + 1;
			//매개변수로 받은 문자열을 동적할당(문자열의 길이 +1 만큼)된 문자열에 포인터에 저장하고,
			pStr = new char[nSize];
			//동적할당된메모리에 매개변수의 문자열을 복사한다.
			strcpy_s(pStr, nSize, str);
			cout << "FakeString[" << this << "]:" << (int)pStr << endl;
		}
		string(const string& str)
		{
			//깊은복사: 동적할당된 객체를 같은 크기의 동적할당된 메모리를 생성하고, 해당값을 복사하는 것. 
			/*int nSize = strlen(str.pStr) + 1;
			pStr = new char[nSize];
			strcpy_s(pStr, nSize, str.pStr);*/
			//얕은복사
			//this->pStr = str.pStr;
			memcpy_s(this, sizeof(string), &str, sizeof(str));
			//단순대입은 다음과같이 메모리카피로 작동한다.
			//그러므로, 포인터의 경우 객체가 아닌 참조값이 복사되므로 의도하지않은 문제가 발생한다. 
			cout << "FakeString Copy[" << this << "]:" << (int)pStr << endl;
		}
		//생성자에서 동적할당하였으므로 반드시 소멸자에서 동적할당된 객체를 정리한다.
		~string()
		{
			cout << "~FakeString[" << this << "]:" << (int)pStr << endl;
			delete[] pStr;
		}
		const char* c_str()
		{
			return pStr;
		}
	};
}

void MockupStringMain()
{
	cout << "##### FakeStringMain Start ######" << endl;
	Mockup::string strMsg("Test"); //생성자
	Mockup::string strMsg2("DataTest"); //생성자
	Mockup::string srtCopyMsg = strMsg; //복사생성자

	cout << strMsg.c_str() << endl; //const char*를 리턴하는 함수 //Test
	printf("%d:%s\n", strMsg.c_str(), strMsg.c_str()); //0x01: Test
	cout << strMsg2.c_str() << endl; //DataTest
	printf("%d:%s\n", strMsg2.c_str(), strMsg2.c_str()); //0x02: DataTest
	cout << srtCopyMsg.c_str() << endl; //0x01: Test
	printf("%d:%s\n", srtCopyMsg.c_str(), srtCopyMsg.c_str()); //0x01:Test -> 0x03:Test
	cout << "##### FakeStringMain End######" << endl;
}

void main()
{
	//_CrtSetBreakAlloc(150); //메모리 누수시 번호를 넣으면 할당하는 위치에 브레이크 포인트를 건다.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //메모리 누수 검사 

	STDStringMain();
	MockupStringMain();
}