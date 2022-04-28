#include <iostream>

using namespace std;

class State;
class StateOne;
class StateTow;
class StateThree;
class Context;

__interface State
{
public:
	virtual void GoNext(Context* pContect) 
	{ 
		cout << typeid(*this).name() << endl; 
	};
};

class StateOne: public State
{
public:
	void GoNext(Context* pContect) override;
};

class StateTow : public State
{
public:
	void GoNext(Context* pContect) override;
};

class StateThree : public State
{
public:
	void GoNext(Context* pContect) override;
};

class Context
{
	State* m_pState;
public:
	~Context()
	{
		if (m_pState)
		{
			delete m_pState;
			m_pState = NULL;
		}
	}
	void SetState(State* pState)
	{
		if (m_pState != NULL) delete m_pState;
		m_pState = pState;
	}

	void GoNext()
	{
		m_pState->GoNext(this);
	}
};

void StateOne::GoNext(Context* pContect)
{
	cout << typeid(*this).name() << endl;
	pContect->SetState(new StateTow());
};

void StateTow::GoNext(Context* pContect)
{
	cout << typeid(*this).name() << endl;
	pContect->SetState(new StateThree());
};


void StateThree::GoNext(Context* pContect)
{
	cout << typeid(*this).name() << endl;
	pContect->SetState(new StateOne());
};

void main()
{
	//_CrtSetBreakAlloc(169); //�޸� ������ ��ȣ�� ������ �Ҵ��ϴ� ��ġ�� �극��ũ ����Ʈ�� �Ǵ�.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //�޸� ���� �˻� 

	Context cContext;
	cContext.SetState(new StateOne());
	cContext.GoNext();
	cContext.GoNext();
	cContext.GoNext();
}