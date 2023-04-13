// RogueLike.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//https://stackoverflow.com/questions/8329103/identifier-not-found-error-on-function-call
// Det är fan hlsl igen.
// Fan också.

#include <iostream>
#include <windows.h>
#include <string>
#include <thread>
#include <iostream>
#include <Windows.h>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

std::string player = "X";

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

void DrawSquare(int x, int y, int width, int height)
{
	for (int i = 0; i < height; i++)
	{
		gotoxy(x, y + i);
		for (int j = 0; j < width; j++)
		{
			std::cout << "#";
		}
	}
}
void DrawBox(int x, int y, int width, int height)
{
	gotoxy(x, y);
	for (int j = 0; j < width; j++)
	{
		std::cout << "#";
	}
	for (int i = 1; i < height - 1; i++)
	{
		gotoxy(x, y + i);
		std::cout << "#";
		gotoxy(x + width - 1, y + i);
		std::cout << "#";
	}
	gotoxy(x, y + height - 1);
	for (int j = 0; j < width; j++)
	{
		std::cout << "#";
	}
}

int main()
{
	srand(time(NULL));

	std::cout << "Hello World!\n";
	gotoxy(5, 5);
	std::cout << "Hello World!\n";

	int roomX = 2;
	int roomY = 7;
	int roomWidth = rand() % 50 + 20;
	int roomHeigth = rand() % 10 + 10;

	int x = rand() % (roomWidth - 2) + roomX + 1;
	int y = rand() % (roomHeigth - 2) + roomY + 1;

	int a = rand();
	int b = rand();
	int c = rand();

	DrawBox(roomX, roomY, roomWidth, roomHeigth);
	bool bKey[4];
	gotoxy(x, y);
	std::cout << "X";
	while (true)
	{
		std::this_thread::sleep_for(50ms);
		int oldX = x;
		int oldY = y;
		//getchar();
		for (int k = 0; k < 4; k++)
		{
			//  L   U   R   D
			bKey[k] = (0x8000 & GetAsyncKeyState((unsigned char)("\x25\x26\x27\x28"[k]))) != 0;
		}
		gotoxy(0, 0);
		std::cout << "                            ";
		gotoxy(0, 0);
		short temp = GetAsyncKeyState((unsigned char)("\x25"[0]));
		std::cout << temp;
		if (bKey[0] && x - 1 > roomX)
		{
			x--;
		}
		if (bKey[1] && y - 1 > roomY)
		{
			y--;
		}
		if (bKey[2] && x + 2 < roomX + roomWidth)
		{
			x++;
		}
		if (bKey[3] && y + 2 < roomY + roomHeigth)
		{
			y++;
		}
		if (x != oldX || y != oldY)
		{
			gotoxy(oldX, oldY);
			std::cout << " ";
			gotoxy(x, y);
			std::cout << "X";
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file