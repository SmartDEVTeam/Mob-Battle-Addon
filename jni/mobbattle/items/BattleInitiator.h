#pragma once

#include "minecraftpe/world/item/Item.h"

class BattleInitiator : public Item
{
private:
	Mob* first = NULL;
	Mob* second = NULL;
public:
    BattleInitiator(short id);
	
	virtual bool canDestroyInCreative() const;
	virtual int getAttackDamage();
	virtual void hurtEnemy(ItemInstance*, Player*, Mob*);
	virtual const std::string buildDescriptionName(const ItemInstance&) const;
};

