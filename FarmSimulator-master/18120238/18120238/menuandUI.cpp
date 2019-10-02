#include "menuandUI.h"
#include "Animal.h"
#include "AnimalList.h"
void menuandUI::MenuInput(AnimalList &list,CowList &listcow,PigList &listpig,HenList &listhen)
{
	Animal standardAnimal;
	cout << "nhap so luong vat nuoi can them: ";
	int size;
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		cin >> standardAnimal;
		list.AddTail(standardAnimal);
		if (standardAnimal.GetAnimalType() == 2)
		{
			listcow.AddTail(standardAnimal);
		}
		else if (standardAnimal.GetAnimalType() == 1)
		{
			listpig.AddTail(standardAnimal);
		}
		else
		{
			listhen.AddTail(standardAnimal);
		}
	}
	list.Sort();
	listpig.Sort();
	listhen.Sort();
	listcow.Sort();
}
void menuandUI::DeleteMenu(AnimalList &list)
{
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "|      ID dong vat     |    Loai    |     Can Nang    |        Tinh Trang    |" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	list.DisplayList();
	string ID;
	cout << "Nhap ID vat nuoi can xoa: ";
	cin >> ID;
	if (list.DeleteAnimalByID(ID) == false)
	{
		cout << "ID khong ton tai" << endl;
	}
	else
	{
		list.ListToFile();
		cout << "da cap nhat list vao file" << endl;
	}
}
void menuandUI::MenuSaveToFile(AnimalList& list)
{
	list.ListToFile();
	cout << "da luu thanh cong" << endl;
}
void menuandUI::MenuDisplayByType(AnimalList& list,CowList& listcow, HenList &listhen,PigList &listpig)
{
	int selection;
	string Selection;
	NodeAnimal* temp;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "|      ID dong vat     |    Loai    |     Can Nang    |        Tinh Trang    |" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "nhap loai vat nuoi can hien thi(1:heo,2:bo,3:ga) : ";
	int i = 0;
	int y = wherey();
	do {
		gotoxy(StringSize("nhap loai vat nuoi can hien thi(1:heo,2:bo,3:ga) : "), y);
		cin >> Selection;
	} while (Selection != "1" && Selection != "2" && Selection != "3");
	if (Selection == "1")
	{
		selection = 1;
	}
	else if (Selection == "2")
	{
		selection = 2;
	}
	else
	{
		selection = 3;
	}
	gotoxy(0, y);
	for (int i = 0; i < StringSize("nhap loai vat nuoi can hien thi(1:heo,2:bo,3:ga) : "); i++)
	{
		cout << " ";
	}
	gotoxy(0, y);
	if (selection == 2)
	{
		listcow.DisplayList();
	}
	else if (selection == 1)
	{
		listpig.DisplayList();
	}
	else
	{
		listhen.DisplayList();
	}
	
}
void menuandUI::MenuDisplayOrder(CowList listcow,HenList listhen,PigList listpig)
{
	int weightcow;
	int weighthen;
	int weightpig;
	cout << "nhap 0 de huy dat vat nuoi do, luu y neu khoi luong khong co thu nuoi dap ung, don dat vat nuoi do se bi huy" << endl;;
	cout << "nhap khoi luong vat nuoi (BO) can dat:  ";
	int y = wherey();
	do
	{
		cin >> weightcow;
		if (weightcow < 0)
		{
			gotoxy(StringSize("nhap khoi luong vat nuoi (BO) can dat:  "), y);
		}
	} while (weightcow < 0);
	cout << "nhap khoi luong vat nuoi (GA) can dat:  ";
	 y = wherey();
	do
	{
		cin >> weighthen;
		if (weighthen < 0)
		{
			gotoxy(StringSize("nhap khoi luong vat nuoi (BO) can dat:  "), y);
		}
	} while (weighthen < 0);
	cout<< "nhap khoi luong vat nuoi (HEO) can dat: ";
	y = wherey();
	do
	{
		cin >> weightpig;
		if (weightpig < 0)
		{
			gotoxy(StringSize("nhap khoi luong vat nuoi (BO) can dat:  "), y);
		}
	} while (weightpig < 0);
	LoadingDot("Dang tien hanh lap don ");
	cout << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	cout << "|      ID dong vat     |    Loai    |     Can Nang    |        Tinh Trang    |" << endl;
	cout << "------------------------------------------------------------------------------" << endl;
	listcow.OrderGet(weightcow);
	listhen.OrderGet(weighthen);
	listpig.OrderGet(weightpig);
}
void menuandUI::MainMenu()
{
	AnimalList list;
	CowList listcow;
	PigList listpig;
	HenList listhen;
	list.FileToList();
	listcow.DivideType(2, list);
	listhen.DivideType(3, list);
	listpig.DivideType(1, list);
	int selection = 0;
	do
	{
		system("cls");
		cout << "UNG DUNG QUAN LY DOANH TRAI" << endl;
		cout << "***************************" << endl;
		cout << "1. Them vat nuoi             2.Xoa thong tin cua vat nuoi" << endl;
		cout << "3.Nhap don dat hang          4.DS vat nuoi theo loai     " << endl;
		cout << "5.Luu vo file                6.Thoat                     " << endl;
		cout << "nhap lua chon: ";
		cin >> selection;
		if (selection == 1)
		{
			system("cls");
			menuandUI::MenuInput(list,listcow,listpig,listhen);
			system("pause");
		}
		if (selection == 2)
		{
			system("cls");
			menuandUI::DeleteMenu(list);
			system("pause");
		}
		if (selection == 3)
		{
			system("cls");
			menuandUI::MenuDisplayOrder(listcow, listhen, listpig);
			system("pause");
		}
		if (selection == 4)
		{
			system("cls");
			menuandUI::MenuDisplayByType(list,listcow,listhen,listpig);
			system("pause");
		}
		if (selection == 5)
		{
			system("cls");
			menuandUI::MenuSaveToFile(list);
			system("pause");
		}
	} while (selection !=6);

}
