#include <iostream>

using namespace std;

namespace IsA
{
	class Cookie
	{
	public:
		int m_nFlour;
		int m_nSugar;
	};

	class ChocoCookie : public Cookie
	{
	public:
		int m_nChoco;
	};



	class AmondChocoCookie : public ChocoCookie
	{
	public:
		int m_nAmond;
	};
}

namespace HasA
{
	class Cookie
	{
	public:
		int m_nFlour;
		int m_nSugar;
	};

	class ChocoCookie
	{
		Cookie m_cCooke;
	public:
		int m_nChoco;
	};

	class AmondChocoCookie
	{
		ChocoCookie m_cChocoCookie;
	public:
		int m_nAmond;
	};
}

class Spiker
{
	bool m_bPower;
	float m_fVolume;
public:
	Spiker()
	{
		m_bPower = false;
		m_fVolume = 0;
	}
	void SwitchOn()
	{
		m_bPower = true;
	}
	void SwitchOff()
	{
		m_bPower = false;
	}
	void VolumeUp()
	{
		m_fVolume++;
	}
	void VolumeDown()
	{
		m_fVolume--;
	}
};

class Antena
{
	float m_fHertz;
public:
	void HertzUp()
	{
		m_fHertz++;
	}
	void HertzDown()
	{
		m_fHertz--;
	}
};

class TapePlayer
{
	void Play();
	void Stop();
	void Puase();
	void Rewind();
	void Forwrd();
};

//is-a: ����� �̿��ϸ� �ڵ带 ���� �ۼ������ʰ� ������ִ�.
class RadioIsA : public Spiker, public Antena, public TapePlayer
{

};
//has-a: �� ��ü�� ���δ� �Լ��� ������Ѵ�.
//���鶧 ������ ��ǰ�� �� ���� ��ǰ�� ����Ҽ��ִ�.
//(���ǿ� ������� ���� �������̽��� ���ο� ���忡 �����ϹǷ� ���⿡ �ش�ɼ��� �ִ�.)
class RadioHasA
{
	Spiker* m_pSpiker;
	Antena* m_pAntena;
	TapePlayer* m_pTapePlayer;
public:
	RadioHasA(Spiker* spiker, Antena* antena)
	{
		m_pSpiker = spiker;
		m_pAntena = antena;
	}
	void SwitchOn()
	{
		m_pSpiker->SwitchOn();
	}
	void SwitchOff()
	{
		m_pSpiker->SwitchOff();
	}
	void VolumeUp()
	{
		m_pSpiker->VolumeUp();
	}
	void VolumeDown()
	{
		m_pSpiker->VolumeDown();
	}
	void HertzUp()
	{
		m_pAntena->HertzUp();
	}
	void HertzDown()
	{
		m_pAntena->HertzDown();
	}
	void Play()
	{

	}
	void Stop();
	void Puase();
	void Rewind();
	void Forwrd();
};



void main()
{

}