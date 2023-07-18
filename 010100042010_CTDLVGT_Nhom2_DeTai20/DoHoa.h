#pragma once // tránh ð?ng ð? thý vi?n khi g?i ch?ng file lên nhau
#include <stdio.h>
#include <conio.h>
#include<ctime> /* thý vi?n h? tr? v? th?i gian th?c */
#include "windows.h" // thý vi?n này bá ð?o l?m nhé - ch?a nhi?u ð? chõi nek - c? t?m hi?u d?n d?n s
//======= l?y t?a ð? x c?a con tr? hi?n t?i =============
#define KEY_NONE	-1
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
//========= l?y t?a ð? y c?a con tr? hi?n t?i =======
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}
//============== d?ch con tr? hi?n t?i ð?n ði?m có t?a ð? (x,y) ==========
void gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
//============= ð?t màu cho ch? =========
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
//============== làm ?n tr? chu?t ===========
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
//======= tr? v? m? phím ngý?i dùng b?m =========
int inputKey()
{
	if (_kbhit()) //true
	{
		int key = _getch();

		if (key == 224)
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return KEY_NONE;
	}
	return KEY_NONE;
}
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void hop(int x, int y, int w, int h, string s, int mau)
{
	textcolor(mau);
	for (int i = x + 1; i < w + x + 3; i++)
	{
		gotoXY(i, y);
		printf("%c", 196);
		gotoXY(i, y + h + 1);
		printf("%c", 196);
	}

	int nx = (w - s.length()) / 2, ny = h / 2;
	gotoXY(x + nx + 2, y + ny + 1);
	cout << s;
	for (int i = y + 1; i < h + y + 1; i++)
	{
		gotoXY(x, i);
		printf("%c", 179);
		gotoXY(x + w + 3, i);
		printf("%c", 179);
	}
	gotoXY(x, y);
	printf("%c", 218);
	gotoXY(x + 3 + w, y);
	printf("%c", 191);
	gotoXY(x, h + y + 1);
	printf("%c", 192);
	gotoXY(w + x + 3, h + y + 1);
	printf("%c", 217);
	SetColor(7);
}
void hopKhongChu(int x, int y, int w, int h, int mau)
{
	textcolor(mau);
	for (int i = x + 1; i < w + x + 3; i++)
	{
		gotoXY(i, y);
		printf("%c", 196);
		gotoXY(i, y + h + 1);
		printf("%c", 196);
	}
	for (int i = y + 1; i < h + y + 1; i++)
	{
		gotoXY(x, i);
		printf("%c", 179);
		gotoXY(x + w + 3, i);
		printf("%c", 179);
	}
	gotoXY(x, y);
	printf("%c", 218);
	gotoXY(x + 3 + w, y);
	printf("%c", 191);
	gotoXY(x, h + y + 1);
	printf("%c", 192);
	gotoXY(w + x + 3, h + y + 1);
	printf("%c", 217);
	SetColor(7);
}
void fixDuoi(int x, int y, int w,int mau)
{
	SetColor(mau);
	gotoXY(x, y);
	printf("%c", 192);
	gotoXY(x+w+3, y);
	printf("%c", 217);
	SetColor(7);
}
void fixTren(int x, int y, int w,int mau)
{
	SetColor(mau);
	gotoXY(x, y);
	printf("%c", 218);
	gotoXY(x + w + 3, y);
	printf("%c", 191);
	SetColor(7);
}
void doiMauChu(int x, int y, int w, int h, string s, int mau)
{
	textcolor(mau);
	gotoXY(x + 1, y + 1);
	int nx = (w - s.length()) / 2;
	for (int i = 0; i <= nx; i++)
		printf(" ");
	cout << s;
	for (int i = 0; i <= nx; i++)
		printf(" ");
	if ((w - s.length()) % 2 != 0)
		printf(" ");
	textcolor(7);
}
void fixGiuaTren(int x, int y, int w, int h, int mau)
{
	SetColor(mau);
	gotoXY(x, y);
	printf("%c", 195);
	gotoXY(x + w + 3, y);
	printf("%c", 180);
	SetColor(7);
}