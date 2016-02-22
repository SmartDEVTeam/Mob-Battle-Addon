#pragma once

#include "com/mojang/minecraftpe/world/item/Item.h"

class Iniciator : public Item
{
public:
    Iniciator(const std::string&, short);
	virtual bool canDestroyInCreative() const;
   virtual void interactEnemy(ItemInstance*, Mob*, Player*);
};
