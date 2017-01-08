#include "AttackInitiator.h"

#include "minecraftpe/world/entity/Mob.h"

AttackInitiator::AttackInitiator(short id) : Item("attackInitiator", id)
{
	creativeCategory = CreativeItemCategory::Tools;
	setIcon("attack_init", 0);
	setMaxStackSize(1);
	setHandEquipped();
}

int AttackInitiator::getAttackDamage()
{
	return 0;
}

bool AttackInitiator::canDestroyInCreative() const
{
	return false;
}

void AttackInitiator::hurtEnemy(ItemInstance *item, Player *player, Mob *mob)
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
		first->spawnAnim();
			
		first = NULL;
		second = NULL;
	}
}

const std::string AttackInitiator::buildDescriptionName(const ItemInstance &item) const
{
	return "Attack Initiator";
}

