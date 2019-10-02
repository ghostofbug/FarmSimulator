#pragma once
#include "Animal.h"
#include <string>
#include <fstream>
struct NodeAnimal {
	Animal animal;
	NodeAnimal* next;
};

struct List
{
	NodeAnimal* phead;
	NodeAnimal* ptail;
};
class AnimalList
{
	
private:
	List animallist;

public:
	void ListToFile();
	void FileToList();
	void Sort();
	bool DeleteAnimalByID(const string& ID);
	List getList();
	void AddTail(const Animal &ani);
	void DisplayList();
	void DivideType(const int& Type,AnimalList &List);
	AnimalList();
	
	void OrderGet(const int& weight)
	{
		int TotalWeight = 0;
		NodeAnimal* temp;
		for (temp = getList().phead; temp != NULL; temp = temp->next)
		{
			if (temp->animal.GetStatus() == true)
			{
				TotalWeight += temp->animal.GetWeight();
				if (TotalWeight <= weight)
				{
					cout << temp->animal;

					
				}
			}
		}
	}
	virtual ~AnimalList();
};
class CowList : public AnimalList
{
public:
	using AnimalList::AnimalList;
};
class PigList : public AnimalList
{
	using AnimalList::AnimalList;
	
	
};
class HenList :public AnimalList
{
	using AnimalList::AnimalList;
};



