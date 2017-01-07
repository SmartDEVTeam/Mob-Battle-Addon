#pragma once

#include "minecraftpe/world/item/Item.h"

class Iniciator : public Item
{
public:
    Iniciator(const std::string &name, short id);
	
	virtual bool canDestroyInCreative() const;
	virtual void interactEnemy(ItemInstance*, Mob*, Player*);
	virtual const std::string buildDescriptionName(const ItemInstance&) const;
};

