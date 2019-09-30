#ifndef __Animal_h__
#define __Animal_h__
#include <iostream>
#include <list>
#include <iomanip>
using namespace std;
class Animal
{

private:
		string AnimalId;
		int Type;
		unsigned int Weight;
		bool Status;
		
public:
	static void SortType();
	static list <Animal> listAnimal;
	static list <Animal> listCow;
	static list <Animal> listPig;
	static list<Animal> listHen;
	string GetAnimalId();
	void SetAnimalId(const string& Id);
	int GetAnimalType();
	void SetAnimalType(const int type);
	int GetWeight();
	void SetWeight(const unsigned int& weight);
	bool GetStatus();
	void SetStatus(const bool& status);
	static void DisplayList(list<Animal> listname);
	Animal();
	~Animal();
	Animal(const Animal& ani);
	Animal(string Id, int type, unsigned int weight, bool status);
	friend ostream& operator<<(ostream& out, const Animal& ani);
	friend istream& operator>>(istream& in, Animal& ani);
	static void DeleteAnimalByID(const string &ID);
};
#endif

