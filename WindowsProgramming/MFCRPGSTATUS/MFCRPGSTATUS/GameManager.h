#pragma once
#include <string.h>
#include "pch.h"
class GameManager
{
public:
	enum E_STAGE { EXIT = -1, CRATE, IVNETORY, SHOP, TOWN, FILED, BATTLE, GAME_OVER, THE_END, MAX };
	enum E_MONSTER { SILME, SKELETON, BOSS, MON_MAX };

	void Init();

	void Release();

	void EventCreate();
	void EventInvetory();
	void EventShop(Player* pShop);
	void EventTown();
	void EventFiled();
	void EventBattle();

	void Update();
	int GetStage();
private:
	int m_eStage = E_STAGE::CRATE;

	class EffectManager* m_pEffectManager;
	class SkillManager* m_pSkillManager;
	class ItemManager* m_pItemManager;
	class Player* m_pPlayer;
	class Player* m_pMonster;
	class Player* m_pShop;

public:
	EffectManager* GetEffectManager() { return m_pEffectManager; }
	SkillManager* GetSkillManager(){ return m_pSkillManager; }
	ItemManager* GetItemManager(){ return m_pItemManager; }
	Player* GetPlayer(){ return m_pPlayer; }
	Player* GetMonster(){ return m_pMonster;}
	Player* GetShop(){ return m_pShop;}
};
