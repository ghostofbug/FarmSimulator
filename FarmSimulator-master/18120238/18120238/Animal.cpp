#include "Animal.h"
#include "AnotherFunction.h"

string Animal::GetAnimalId()
{
	return this->AnimalId;
}
int Animal::GetAnimalType()
{
	return this->Type;
}
void Animal::SetAnimalType(const int type)
{
	this->Type = type;
}
int Animal::GetWeight()
{
	return this->Weight;
}
void Animal::SetWeight(const unsigned int& weight)
{
	this->Weight = weight;
}
bool Animal::GetStatus()
{
	return this->Status;
}
void Animal::SetStatus(const bool& status)
{
	this->Status = status;
}
void Animal::SetAnimalId(const string& Id)
{
	this->AnimalId = Id;
}
 istream& operator>>(istream& in, Animal& ani)
{
	 cout << "nhap ID dong vat                   : ";
	 in >> ani.AnimalId;
	 cout << "nhap loai(1:heo,2:bo,3:ga)         : ";// 1 cho heo , 2 cho bo ,3 cho ga
	 int y = wherey();
	 string typetemp;
	 while (typetemp.compare("1") != 0 && typetemp.compare("2") != 0 && typetemp.compare("3") != 0)
	 {
		 gotoxy(StringSize("nhap loai(1:heo,2:bo,3:ga)         : "), y);
		 for (int i = 0; i < typetemp.size(); i++)
		 {
			 cout << " ";
		 }
		 gotoxy(StringSize("nhap loai(1:heo,2:bo,3:ga)         : "), y);
		 in >> typetemp;
	 }
	 if (typetemp.compare("1") == 0)
	 {
		 ani.Type = 1;
	 }
	 else if (typetemp.compare("2") == 0)
	 {
		 ani.Type = 2;
	 }
	 else if (typetemp.compare("3") == 0)
	 {
		 ani.Type = 3;
	 }
	 cout << "nhap can nang                      : ";
	 y = wherey();
	 do {
		 in >> ani.Weight;
		 if (ani.Weight <= 0)
		 {
			 cin.clear();
			 gotoxy(StringSize("nhap can nang                      : "), y);
		 }
	 } while (ani.Weight <= 0);
	 cout << "nhap trang thai(1:khoe manh,0:benh): "; //1 cho khoe mang,0 cho benh
	 int i;
	 y = wherey();
	 do
	 {
		 in >> i;
		 if (i != 1 && i != 0)
		 {
			 cin.clear();
			 gotoxy(StringSize("nhap trang thai(1:khoe mang,0:benh): "), y);
		 }
	 } while (i != 1 && i != 0);
	 if (i == 1)
	 {
		 ani.Status = true;
	 }
	 else
	 {
		 ani.Status = false;
	 }

	 return in;
}
 ostream& operator<<(ostream& out, const Animal& ani)
 {
	 out << "| " << setw(20) << left << ani.AnimalId;
	 out << " | ";
	 if (ani.Type == 1)
	 {
		 out << setw(10) << "heo";
	 }
	 else if (ani.Type == 2)
	 {
		 out << setw(10) << "bo";
	 }
	 else
	 {
		 out << setw(10) << "ga";
	 }
	 out << " | " << setw(15) << ani.Weight;
	 if (ani.Status == true)
	 {
		 out << " | " << setw(20) << "khoe manh" << " | " << endl;
	 }
	 else
	 {
		 out << " | " << setw(20) << "bi benh" << " | " << endl;
	 }
	 return out;
 }
Animal::Animal()
{
	this->AnimalId = "";
	this->Weight = 0;
	this->Status = false;
	this->Type = -1;
}
Animal::~Animal()
{
}

Animal::Animal(const Animal& ani)
{
	this->AnimalId = ani.AnimalId;
	this->Weight = ani.Weight;
	this->Type = ani.Type;
	this->Status = ani.Status;
}

Animal::Animal(string Id, int type, unsigned int weight, bool status)
{
	this->AnimalId = Id;
	this->Type = type;
	this->Weight = weight;
	this->Status = status;
	if (type > 3 || type <= 0)
	{
		this->Type = 1;
	}
	if (weight < 0)
	{
		this->Weight = 0;
	}
}

Animal Animal::operator=(const Animal ani)
{
	this->AnimalId = ani.AnimalId;
	this->Weight = ani.Weight;
	this->Type = ani.Type;
	this->Status = ani.Status;
	return Animal();
}

