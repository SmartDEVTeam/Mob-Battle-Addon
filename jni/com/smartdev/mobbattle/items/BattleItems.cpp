#include "BattleItems.h"

#include "Iniciator.h"

#include "com/mojang/minecraftpe/world/item/Item.h"

Item* BattleItems::iniciator;


void BattleItems::initItems() {
   iniciator = new Iniciator("iniciator", getNextItemId());
	
	initCreativeItems();
}

void BattleItems::initCreativeItems() {
	Item::addCreativeItem(iniciator, 0);
}

int BattleItems::getNextItemId() {
	for(int testId = 1000; testId < 4096; testId++) {
		if(Item::mItems[testId] == NULL)
			return testId;
	}
	return 4096;
}