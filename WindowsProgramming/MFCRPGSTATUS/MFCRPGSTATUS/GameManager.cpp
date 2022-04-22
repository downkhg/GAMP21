﻿#include "pch.h"

void GameManager::Init()
{
	m_pItemManager = new ItemManager();
	m_pEffectManager = new EffectManager();
	m_pEffectManager->Init();
	m_pSkillManager = new SkillManager(m_pEffectManager);
	m_pPlayer = new Player();
	m_pMonster = new Player();
	m_pShop = new Player();

	m_pEffectManager->Init();
	m_pSkillManager = new SkillManager(m_pEffectManager);

	m_pShop->SetIventory(m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::WOOD_SOWRD));
	m_pShop->SetIventory(m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::WOOD_ARMOR));
	m_pShop->SetIventory(m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::WOOD_RING));
	m_pShop->SetIventory(m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::BONE_SOWRD));
	m_pShop->SetIventory(m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::BONE_AMROR));
	m_pShop->SetIventory(m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::BONE_RING));
	m_pShop->SetIventory(m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::HP_POTION));
	m_pShop->SetIventory(m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::MP_POTION));
	m_pShop->SetIventory(m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::STONE));
	m_pShop->SetIventory(m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::BOOM));

	m_pMonster->Set("Slime", 100, 100, 20, 10, 10, 100);
	m_pMonster->SetIventory(m_pItemManager->GetItem(ItemManager::E_ITEM_LIST::WOOD_SOWRD));

	Skill* pHill = m_pSkillManager->GetSkill(0);
	m_pPlayer->AddSkill(pHill);
}

void GameManager::Release()
{
	delete m_pSkillManager;
	delete m_pShop;
	delete m_pMonster;
	delete m_pShop;

	delete m_pSkillManager;
	delete m_pEffectManager;
	delete m_pItemManager;
}

void GameManager::EventCreate()
{
	string name;
	cout << "케릭터 이름을 입력하세요!:";
	cin >> name;
	m_pPlayer->Set(name, 100, 100, 20, 10, 10, 0);
	m_eStage = E_STAGE::TOWN;
}
void GameManager::EventInvetory()
{
	m_pPlayer->Show();
	int nSelect;
	cout << "메뉴를 선택하세요!(1: 아이템사용-> 2: 장비해제 etc: 마을):";
	cin >> nSelect;
	if (nSelect == 1)
	{
		cout << "사용할 아이템을 구하세요!:";
		cin >> nSelect;
		if (!m_pPlayer->UseItem(nSelect))
			cout << "사용할수없습니다!" << endl;
	}
	else if (nSelect == 2)
	{
		cout << "장비해제할 장비함에서 선택하세요!:";
		cin >> nSelect;
		m_pPlayer->ReleaseEqument(nSelect);
	}
	else
		m_eStage = E_STAGE::TOWN;
}
void GameManager::EventShop(Player* pShop)
{
	pShop->Show();
	int nInput;
	cout << "상점입니다. 무엇을 하시겠습니까? 1: 구매, 2: 팔기, etc:마을";
	cin >> nInput;
	switch (nInput)
	{
	case 1:
	{
		cout << "구매할 아이템을 목록에서 선택하세요! -1:마을";
		cin >> nInput;
		if (nInput != -1)
			m_pPlayer->Buy(m_pShop, nInput);
		else
			m_eStage = E_STAGE::TOWN;
	}
	break;
	case 2:
	{
		m_pPlayer->Show();
		cout << "판매할 아이템을 목록에서 선택하세요! -1:마을";
		cin >> nInput;
		if (nInput != -1)
			m_pPlayer->Sell(nInput);
		else
			m_eStage = E_STAGE::TOWN;
	}
	break;
	default:
	{
		m_eStage = E_STAGE::TOWN;
	}
	break;
	}
}
void GameManager::EventTown()
{
	const char* strStageName[] = { "CRATE", "INVENTORY","SHOP","TOWN", "FILED", "BATTLE", "GAME_OVER", "THE_END" };

	cout << "마을 입니다->" << endl;
	cout << "어디로 가시겠습니까?" << endl;
	for (int i = E_STAGE::CRATE + 1; i < E_STAGE::BATTLE; i++)
		cout << i << ":" << strStageName[i] << ",";
	cin >> m_eStage;
}
void GameManager::EventFiled()
{
	const char* strMonsterName[] = { "SILME", "SKELETON", "BOSS" };
	int nSelect;
	cout << "어디로 가시겠습니까?";
	for (int i = 0; i < E_MONSTER::MON_MAX; i++)
		cout << i << ":" << strMonsterName[i] << ",";
	cin >> nSelect;
	switch (nSelect)
	{
	case E_MONSTER::SILME:
		m_pMonster->Set("Slime", 100, 100, 20, 10, 10, 100);
		break;
	case E_MONSTER::SKELETON:
		m_pMonster->Set("Skeleton", 200, 200, 30, 10, 10, 100);
		break;
	case E_MONSTER::BOSS:
		m_pMonster->Set("Boss", 300, 100, 50, 10, 10, 100);
		break;
	}
	m_eStage = E_STAGE::BATTLE;
}