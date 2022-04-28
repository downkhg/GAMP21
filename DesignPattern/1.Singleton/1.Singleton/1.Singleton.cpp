#include <iostream>

using namespace std;
//싱글톤: 클래스의 객체가 1개만 존제할수있도록 강제하는 클래스.
class SingleObject
{
	static SingleObject* m_pInstance;
	int m_nData = 0;
	SingleObject() {};
	~SingleObject() {};
public:
	static SingleObject* GetInstance()
	{
		if (m_pInstance == NULL)
			m_pInstance = new SingleObject();
		return m_pInstance;
	}
	void Release()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = NULL;
		}
	}
	void Print()
	{
		cout << "SingleObject:"<< m_pInstance << endl;
		cout << "Data:" << m_nData << endl;
	}
};

SingleObject* SingleObject::m_pInstance = NULL;

void main()
{
	//SingleObject cObjA;
	//SingleObject cObjArr[10];
	SingleObject* pSingleObject = NULL;
	//pSingleObject = pSingleObject->GetInstance(); //정적멤버는 전역변수와 같기때문에 접근은 가능하나, 다음과 같은 사용이 일반적이지는 않다.
	pSingleObject = SingleObject::GetInstance(); //정적멤버함수를 통해 객체가 생성되기전에도 함수에 접근가능하도록 만들어야한다.
	pSingleObject->Print();
	pSingleObject->Release();
	pSingleObject->Print(); //객체가 소멸되었기때문에 다음과 같은 함수는 일반멤버에 접근한경우 문제가 발생할수있다.
	//delete pSingleObject; //객체외부에서 객체를 소멸시킬수없도록 소멸자를 은닉한다.
}