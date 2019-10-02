#include "AnotherFunction.h"
#include <string>
size_t StringSize(string text)
{
	return text.size();
}
int FileSize(string file)
{
	ifstream fin;
	fin.open(file, ios::in);
	int dem = 0;
	string x;
	while (getline(fin, x))
	{
		dem++;
	}
	fin.close();
	return dem;
}
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (!GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&csbi
	))
		return -1;
	return csbi.dwCursorPosition.X;
}
void LoadingDot(string text)
{
	cout << text;
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << ".";
			cout.flush();
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
		gotoxy(StringSize(text), wherey());
		for (int k = 0; k < 6; k++)
		{
			cout << " ";
		}
		gotoxy(StringSize(text), wherey());

	}
}

int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (!GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&csbi
	))
		return -1;
	return csbi.dwCursorPosition.Y;
}
