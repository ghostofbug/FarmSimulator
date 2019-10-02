#pragma once
#include <iostream>
#include "AnimalList.h"
#include "AnotherFunction.h"
 class menuandUI
{
public:
	static void MainMenu();
	static void MenuInput(AnimalList &list,CowList &cowlist,PigList &piglist,HenList &henlist);
	static void DeleteMenu(AnimalList &list);
	static void MenuSaveToFile(AnimalList& list);
	static void MenuDisplayByType(AnimalList& list, CowList& listcow, HenList& listhen, PigList& listpig);
	static void MenuDisplayOrder(CowList listcow, HenList listhen, PigList listpig);
};

