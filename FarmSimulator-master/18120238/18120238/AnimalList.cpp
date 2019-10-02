#include "AnimalList.h"
#include "AnotherFunction.h"
void AnimalList::ListToFile()
{
	ofstream of;
	of.open("animal.txt");
	NodeAnimal* temp;
	for (temp = animallist.phead; temp != NULL; temp = temp->next)
	{
		of << temp->animal.GetAnimalId() << ",";
		of << temp->animal.GetAnimalType() << ",";
		of << temp->animal.GetWeight() << ",";
		if (temp->animal.GetStatus() == true)
		{
			of << "true" << endl;
		}
		else
		{
			of << "false" << endl;
		}
	}
	of.close();
}

void AnimalList::FileToList()
{
	ifstream in;
	Animal temp;
	string temp1;
	in.open("animal.txt");
	int n = FileSize("animal.txt");
	for (int i=0;i<n;i++)
	{
		getline(in, temp1,',');
		temp.SetAnimalId(temp1);
		int type;
		in >> type;
		temp.SetAnimalType(type);
		in.seekg(1, 1);
		in >> type;
		temp.SetWeight(type);
		in.seekg(1, 1);
		getline(in, temp1);
		if (temp1 == "true")
		{
			temp.SetStatus(true);
		}
		else
		{
			temp.SetStatus(false);
		}
		AddTail(temp);
	}
	in.close();
}

void AnimalList::Sort()
{
	NodeAnimal* temp1;
	NodeAnimal* temp2;
	Animal temp;
	for (temp1 = animallist.phead; temp1->next != NULL; temp1 = temp1->next)
	{
		for (temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next)
		{
			if (temp1->animal.GetWeight() > temp2->animal.GetWeight())
			{
				temp = temp1->animal;
				temp1->animal = temp2->animal;
				temp2->animal = temp;
			}
		}
	}
}

bool AnimalList::DeleteAnimalByID(const string& ID)
{
	NodeAnimal* temp = NULL;
	NodeAnimal* hold = NULL;
	bool Check = false;
	for (temp = animallist.phead; temp != NULL; temp = temp->next)
	{
		if (temp->animal.GetAnimalId().compare(ID) == 0)
		{
			Check = true;
		}
	}
	if (Check == false)
	{
		return false;
	}
	else
	{
		if (animallist.phead->animal.GetAnimalId() == ID)
		{
			hold = animallist.phead->next;
			delete animallist.phead;
			animallist.phead = hold;
		
		}
		else
		{
			for (temp = animallist.phead; temp != NULL; temp = temp->next)
			{
				if (temp->next->animal.GetAnimalId().compare(ID) == 0)
				{
					hold = temp->next->next;
					delete hold;
					temp->next = hold;
				}
			}
		}
		delete temp;
		return true;
	}


}

List AnimalList::getList()
{
	return this->animallist;
}

void AnimalList::AddTail(const Animal &ani)
{
	NodeAnimal *temp;
	temp = new NodeAnimal();
	temp->animal = ani;
	temp->next = NULL;
	if (this->animallist.ptail == NULL)
	{
		this->animallist.phead = this->animallist.ptail = temp;
	}
	else
	{
		this->animallist.ptail->next = temp;
		this->animallist.ptail = temp;
	}
}



void AnimalList::DisplayList()
{
	NodeAnimal* temp;
	for (temp = animallist.phead; temp != NULL; temp = temp->next)
	{
		cout << temp->animal;
	}
}

void AnimalList::DivideType(const int& Type,AnimalList &List)
{
	NodeAnimal* temp;
	for (temp = List.getList().phead; temp != NULL; temp = temp->next)
	{
		if (temp->animal.GetAnimalType() == Type)
		{
			AddTail(temp->animal);
		}
	}
	
}

AnimalList::AnimalList()
{
	animallist.phead = animallist.ptail = NULL;
}
AnimalList::~AnimalList()
{
	NodeAnimal *temp1;
	NodeAnimal*temp2;
	temp1 = animallist.phead;
	temp2 = NULL;
	while (temp1 != NULL)
	{
		temp2 = temp1->next;
		delete temp1;
		temp1 = temp2;
	}
	delete temp2;
	temp2 = NULL;

}
