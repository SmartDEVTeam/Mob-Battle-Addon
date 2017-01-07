#include "Iniciator.h"

#include "minecraftpe/world/item/ItemInstance.h"
#include "minecraftpe/world/entity/Mob.h"

Mob* first = NULL;
Mob* second = NULL;

Iniciator::Iniciator(const std::string &name, short id) : Item(name, id)
{
	creativeCategory = CreativeItemCategory::Tools;
	setIcon("selection", 0);
	setMaxStackSize(1);
	setHandEquipped();
}

bool Iniciator::canDestroyInCreative() const
{
	return false;
}

void Iniciator::interactEnemy(ItemInstance *item, Mob *entity, Player *player)
{
	//entity->playSound("random.click", 1.0F, 1.5F);
	if(first == NULL) {
		first = entity;
		//first->playSound("random.click", 1.0F, 1.0F);
	} else if(first != NULL && first != entity) {
		second = entity;
		//first->playSound("random.levelup", 1.0F, 1.0F);
		//first->playSound("random.levelup", 1.0F, 1.0F);
			
		first->setTarget(second);
		second->setTarget(first);
		first->spawnAnim();
		second->spawnAnim();
			
		first = NULL;
		second = NULL;
	}
}

const std::string Iniciator::buildDescriptionName(const ItemInstance &item) const
{
	return "Iniciator";
}

