/*
*	(from: curser.c - a set of C fuctions for VT100 screen maniputlation, circa 1989)
*	(converted from K&R C, 2017, when windows 10 added terminal support back in)
*
*   --- original comments ---
*	clr() - clear the screen
*	gotoxy(int x, int y) - move to screen location
*
*	these do not work on IBM version
*	printdhw(int x, int y, char *output) - print double high,wide output
*	printdw(int x, int y, char *output) - print double wide output
*
*	vline(int x, int y, int r, char s)  - print vertical line, r of s
*	hline(int x, int y, int r, char s)  - print horizontel line, r of s
*	border(int x,int y,int h, int w, char s)
*	beep()   - make a beep sound
*   --- ----------------- ---
*   --- 2017 comments ---
*   EnableVTMode() - enable vt emulation in the console
*/

// changed around imports to match the 2017 C++ requirements...

#include <stdio.h>
#include "stdafx.h"
#include <windows.h>
#include <wincon.h>

#define DEFINE_CONSOLEV2_PROPERTIES

// Standard library C-style
#include <wchar.h>
#include <stdlib.h>
#include <stdio.h>

#include "Scursers.h"

/* works on windows 10 - */
/*
*	HideCursor - hides the cursor
*/
bool HideCursor()
{
	return SetCursorVisibility(FALSE);
}
/*
*	ShowCursor - shows the cursor
*/
bool ShowCursor()
{
	return SetCursorVisibility(TRUE);
}
bool SetCursorVisibility(bool visible)
{
	//Get a console handle
	HANDLE myconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CURSOR;
	BOOL result;
	CURSOR.dwSize = 1;
	CURSOR.bVisible = visible;
	result = SetConsoleCursorInfo(myconsole, &CURSOR);
	return result;
}
bool SetWindow(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	// Get handle of the standard output 
	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
	if (Handle == NULL)
	{
		return FALSE;
	}

	// Set the window size to that specified in Rect 
	if (!SetConsoleWindowInfo(Handle, TRUE, &Rect))
	{
		return FALSE;
	}

	return TRUE;
}
bool EnableVTMode()
{
	// Set output mode to handle virtual terminal sequences
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hOut == INVALID_HANDLE_VALUE)
	{
		return false;
	}

	DWORD dwMode = 0;
	if (!GetConsoleMode(hOut, &dwMode))
	{
		return false;
	}

	dwMode |= 0x0004; //ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	if (!SetConsoleMode(hOut, dwMode))
	{
		return false;
	}
	return true;
}

// --- original code converted --
/*
*   Clear the screen
*/
void clr()
{
	putchar(27);
	printf("[2J");

}

/*
*   Go To a x,y spot on the screen
*/
void gotoxy(int x, int y)
{
	char output[80];

	putchar(27);
	sprintf_s(output, "[%d;%dH", y, x);   /* Line, Column */
	printf("%s", output);
}

/*
	setColor - sets foreground color, background color, and attributes.
	           (Once set, stays set.  There is a ATTRIBUTE_RESET define you can use
			   to clear all the settings.)
*/
void setColor(int c)
{
	printf("%c[%dm",27,c);
}

/*
*	Double High , Double Wide printf function
*      - double high/wide is not supported on win10; so I modified it to simple print
*/
void printdhw(int x, int y, char *output)
{
	gotoxy(x, y);
	printf("%s", output);
}

/*
*	print double wide characters
*   - double wide is not supported on win10; so I modfified it to simple print
*/
void printdw(int x, int y, char *output)
{
	gotoxy(x, y);
	printf("%s", output);
}
/*
*   	Vertical line from x,y for r positions
*/
void vline(int x, int y, int r, char c)
{
	for (int i = y; i< r + y; i++) {
		gotoxy(x, i);
		putchar(c);
	}
}

/*
*	Horizontel line from x,y
*/
void hline(int x, int y, int r, char c)
{
	gotoxy(x, y);
	for (int i = 0; i < r; i++)
		putchar(c);
}

/*
*	Border from x,y using character c of height h, width w
*
*/
void border(int x, int y, int h, int w, char c)
{
	vline(x, y, h + 1, c);
	hline(x, y, w + 1, c);
	vline(x + w , y, h +1, c);
	hline(x, y + h , w +1, c);
}

/*
*	Give him a beep
*/
void beep()
{
	putchar(7);
}
