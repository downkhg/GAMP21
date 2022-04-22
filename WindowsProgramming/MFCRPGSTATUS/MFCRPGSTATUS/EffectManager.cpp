﻿#include "pch.h"
//#include "EffectManager.h"
//#include "SkillManager.h"
//#include "Player.h"

using namespace std;

void HillEffect::Use(Player& caster, Player& target)
{
	target.GetStatus().nHP += caster.GetStatus().nInt;
	cout << target.GetName().c_str() << "+ HP:"<< caster.GetStatus().nInt << endl;
}

void EffectManager::Init()
{
	AddEffect(new HillEffect());
}
void EffectManager::Release()
{
	for (int i = 0; i < m_listEffect.size(); i++)
		delete m_listEffect[i];
	m_listEffect.clear();
}
void EffectManager::AddEffect(Effect* effect)
{
	m_listEffect.push_back(effect);
}
Effect* EffectManager::GetEffect(int idx)
{
	return m_listEffect[idx];
}
