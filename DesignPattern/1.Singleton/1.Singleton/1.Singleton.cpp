#include <iostream>

using namespace std;
//�̱���: Ŭ������ ��ü�� 1���� �����Ҽ��ֵ��� �����ϴ� Ŭ����.
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
	//pSingleObject = pSingleObject->GetInstance(); //��������� ���������� ���⶧���� ������ �����ϳ�, ������ ���� ����� �Ϲ��������� �ʴ�.
	pSingleObject = SingleObject::GetInstance(); //��������Լ��� ���� ��ü�� �����Ǳ������� �Լ��� ���ٰ����ϵ��� �������Ѵ�.
	pSingleObject->Print();
	pSingleObject->Release();
	pSingleObject->Print(); //��ü�� �Ҹ�Ǿ��⶧���� ������ ���� �Լ��� �Ϲݸ���� �����Ѱ�� ������ �߻��Ҽ��ִ�.
	//delete pSingleObject; //��ü�ܺο��� ��ü�� �Ҹ��ų�������� �Ҹ��ڸ� �����Ѵ�.
}