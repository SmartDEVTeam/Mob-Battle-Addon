#pragma once

#include "minecraftpe/world/item/Item.h"

class Iniciator : public Item
{
public:
    Iniciator(const std::string &name, short id);
	
	virtual bool canDestroyInCreative() const;
	virtual CameraItemComponent interactEnemy(ItemInstance*, Mob*, Player*);
};

