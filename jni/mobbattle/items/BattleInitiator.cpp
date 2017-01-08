#include "BattleInitiator.h"

#include "minecraftpe/world/entity/Mob.h"

BattleInitiator::BattleInitiator(short id) : Item("battleInitiator", id)
{
	creativeCategory = CreativeItemCategory::Tools;
	setIcon("battle_init", 0);
	setMaxStackSize(1);
	setHandEquipped();
}

int BattleInitiator::getAttackDamage()
{
	return 0;
}

bool BattleInitiator::canDestroyInCreative() const
{
	return false;
}

void BattleInitiator::hurtEnemy(ItemInstance *item, Player *player, Mob *mob)
{
	//entity->playSound("random.click", 1.0F, 1.5F);
	if(first == NULL) {
		first = mob;
		//first->playSound("random.click", 1.0F, 1.0F);
	} else if(first != NULL && first != mob) {
		second = mob;
		//first->playSound("random.levelup", 1.0F, 1.0F);
		//second->playSound("random.levelup", 1.0F, 1.0F);
			
		first->setTarget(second);
		second->setTarget(first);
		first->spawnAnim();
		second->spawnAnim();
			
		first = NULL;
		second = NULL;
	}
}

const std::string BattleInitiator::buildDescriptionName(const ItemInstance &item) const
{
	return "Battle Initiator";
}

