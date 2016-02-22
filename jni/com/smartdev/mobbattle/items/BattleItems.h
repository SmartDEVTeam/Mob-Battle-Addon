#pragma once

class Item;

class BattleItems {
public:
	static Item* iniciator;
	
	static void initItems();
	static void initCreativeItems();
	static int getNextItemId();
};