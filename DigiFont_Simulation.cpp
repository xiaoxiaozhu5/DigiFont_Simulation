// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define USE_RAYLIB

#ifdef USE_RAYLIB
#include <raylib.h>
#else
#include <graphics.h>
#include <conio.h>
#endif
#include <cstdio>

#define CPP

#ifdef CPP
#include "DigiFont.h"
#else
#include "digifont_c.h"
#endif

#ifdef USE_RAYLIB
void customLineH(int x0, int x1, int y, int c)
{
	DrawLine(x0,y,x1,y,WHITE);
}
void customLineV(int x, int y0, int y1, int c)
{
	DrawLine(x,y0,x,y1,WHITE);
}
void customRect(int x, int y, int w, int h, int c)
{
	DrawRectangle(x,y,w,h,WHITE);
}
#else
void customLineH(int x0, int x1, int y, int c)
{
	line(x0,y,x1,y);
}
void customLineV(int x, int y0, int y1, int c)
{
	line(x,y0,x,y1);
}
void customRect(int x, int y, int w, int h, int c)
{
	fillrectangle(x,h,y,w);
}
#endif

#ifdef CPP
DigiFont font(customLineH, customLineV, customRect);
#endif

int main()
{
    const int screenWidth = 640;
    const int screenHeight = 480;
	int cnt = 23456;
	char buf[20];
#ifdef USE_RAYLIB
    InitWindow(screenWidth, screenHeight, "Hello World");
	SetTargetFPS(60);
#else
	initgraph(screenWidth, screenHeight);
#endif

#ifdef CPP
	font.setColors(1, 0);
	font.setSpacing(2);
	font.setClearBg(0);
#else
	DigiFont_init(customLineH, customLineV, customRect);
	DigiFont_setColors(1,0);
	DigiFont_setSpacing(2);
	DigiFont_setClearBg(0);
#endif

#ifdef USE_RAYLIB
	while (!WindowShouldClose())
	{
		BeginDrawing();
#endif

	{
		snprintf(buf, 6, "%05ld", cnt);
#ifdef CPP
		font.setSize1(30, 68 - 10, 7);
		font.printNumber1(buf + 4, 0, 10);
#else
		DigiFont_setSize1(30, 68 - 10, 7);
		DigiFont_printNumber1(buf + 4, 0, 10);
#endif
		snprintf(buf, 6, "%s", "6:45");
#ifdef CPP
		font.setSize1(17, 35, 5);
		font.printNumber1(buf, 34, 10);
		font.setSize1(10, 20, 3);
		font.printNumber1(buf, 34, 48);
#else
		DigiFont_setSize1(17, 35, 5);
		DigiFont_printNumber1(buf, 34, 10);
		DigiFont_setSize1(10, 20, 3);
		DigiFont_printNumber1(buf, 34, 48);
#endif
	}

#ifdef USE_RAYLIB
		EndDrawing();
	}
	CloseWindow();
#else
	_getch();
	closegraph();
#endif
	return 0;
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
