#include <jni.h>
#include <dlfcn.h>
#include <stdlib.h>
#include "Substrate.h"

#include "mobbattle/items/Iniciator.h"

void (*_Item$initClientData)();
void Item$initClientData()
{
	_Item$initClientData();
	
	Item::mItems[750] = new Iniciator("iniciator", 750 - 256);
}

void (*_Item$initCreativeItems)();
void Item$initCreativeItems()
{
	_Item$initCreativeItems();
	
	Item::addCreativeItem(750, 0);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
	MSHookFunction((void*) &Item::initClientData, (void*) &Item$initClientData, (void**) &_Item$initClientData);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	
	return JNI_VERSION_1_6;
}

