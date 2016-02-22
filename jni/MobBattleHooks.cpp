#include <Headers.h>

static void (*_Item$initCreativeItems)();
static void Item$initCreativeItems() {
	_Item$initCreativeItems();
	
	BattleItems::initItems();
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) { 
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
}