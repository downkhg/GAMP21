#include <iostream>
#include <list>
using namespace std;

class Unit
{
public:
	virtual void Move(int x, int y)
	{
		cout << "Move(" << x << "," << y <<")"<< endl;
	}
	virtual void Attack(int x, int y)
	{
		cout << "Attack(" << x << "," << y << ")" << endl;
	}
};

class Marin : public Unit
{
	
};

class Medic : public Unit
{
	void Attack(int x, int y)
	{
		Move(x, y);
	}
};

class Commander
{
	list<Unit*> m_listUnits;
public:

	void SelectUnit(Unit* pUnit)
	{
		m_listUnits.push_back(pUnit);
	}

	void Deselect(Unit* pUnit)
	{
		auto it = find(m_listUnits.begin(), m_listUnits.end(), pUnit);
		m_listUnits.erase(it);
	}

	void Attack(int x, int y)
	{
		auto it = m_listUnits.begin();
		for (it; it != m_listUnits.end(); it++)
		{
			(*it)->Attack(x, y);
		}
	}

	void Move(int x, int y)
	{
		auto it = m_listUnits.begin();
		for (it; it != m_listUnits.end(); it++)
		{
			(*it)->Move(x, y);
		}
	}
};

void main()
{

}