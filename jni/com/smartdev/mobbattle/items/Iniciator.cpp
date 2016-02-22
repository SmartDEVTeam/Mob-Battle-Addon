#include "Iniciator.h"

#include "com/mojang/minecraftpe/world/item/ItemInstance.h"
#include "com/mojang/minecraftpe/world/entity/Mob.h"


Mob* first = NULL;
Mob* second = NULL;

Iniciator::Iniciator(const std::string& name, short itemId) : Item(name, itemId - 0x100)
{
	creativeCategory = 3;
	setIcon("stick", 0);
	setMaxStackSize(1);
	setHandEquipped();
	Item::mItems[itemId] = this;
}

bool Iniciator::canDestroyInCreative() const{
	return false;
}

void Iniciator::interactEnemy(ItemInstance* item, Mob* entity, Player* player){
entity->playSound("random.click", 1.0F, 1.5F);
   if(first == NULL) {
		first = entity;
       first->playSound("random.click", 1.0F, 1.0F);
	}
	else if(first != NULL && first != entity) {
		second = entity;
       first->playSound("random.levelup", 1.0F, 1.0F);
       first->playSound("random.levelup", 1.0F, 1.0F);
			
		first->setTarget(second);
		second->setTarget(first);
       first->spawnAnim();
       second->spawnAnim();
			
		first = NULL;
	   second = NULL;
	}
}