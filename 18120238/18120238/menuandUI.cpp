#include "menuandUI.h"
#include "Animal.h"
void menuandUI::MenuInput()
{
	Animal standardAnimal;
	cout << "nhap so luong vat nuoi can them: ";
	int size;
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		cin >> standardAnimal;
	}
}
void menuandUI::DeleteMenu()
{
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "|      ID dong vat     |    Loai    |     Can Nang    |        Tinh Trang    |" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	Animal::DisplayList(Animal::listAnimal);
	string ID;
	cout << "Nhap ID vat nuoi can xoa: ";
	cin >> ID;
	Animal::DeleteAnimalByID(ID);
}
void menuandUI::MainMenu()
{
	int selection = 0;
	do
	{
		system("cls");
		cout << "UNG DUNG QUAN LY DOANH TRAI" << endl;
		cout << "***************************" << endl;
		cout << "1. Them vat nuoi             2.Xoa thong tin cua vat nuoi" << endl;
		cout << "3.Nhap don dat hang          4.Thoat                     " << endl;
		cout << "nhap lua chon: ";
		cin >> selection;
		if (selection == 1)
		{
			system("cls");
			menuandUI::MenuInput();
			system("pause");
		}
		if (selection == 2)
		{
			system("cls");
			menuandUI::DeleteMenu();

		}
		if (selection == 3)
		{

		}
	} while (selection !=4);

}
