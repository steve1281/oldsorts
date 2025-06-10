/* 	
*	(from: gsortsim.c  - a set of C fuctions for sort simulations, circa 1989, MAIN)
*	(converted from K&R C, 2017, when windows 10 added terminal support back in)
*/

// ok, the headers have been re-worked to let the old (haha) style C work.
// (not sure what m$ is thinking here, but it seems to work)
//
#include <stdio.h>
#include "stdafx.h"
#include <windows.h>
#include <conio.h>
#define DEFINE_CONSOLEV2_PROPERTIES

// Standard library C-style
#include <wchar.h>
#include <stdlib.h>

// Standard library C-style
#include <wchar.h>
#include <stdlib.h>
#include <stdio.h>
#include "Scursers.h" //<graphics.h> 

#define MAXARRAY 1000
#define OFFSET 40
#define randint(i,j)	rand()%j+1+i // random(j-i)+i // C++ what happened to random I wonder.

int sleep_factor = 10; // delay between compare_draws (milliseconds)
int push = 5;

int adjust = 1;
long int comps = 0;
long int swaps = 0;
int sample_size = 0;

/*
*	main
*/
int main()
{
	

	int v[MAXARRAY], aux[MAXARRAY];
	int n, i;

	// set up vt emulation
	EnableVTMode(); // initialize the console to a terminal emulator.
	if (!SetWindow(100, 50)) {
		return (0);
	}
	
	// title screen added to explain program.
	HideCursor();
	title();
	
	// sample size for demo
	ShowCursor();
	printdw(1,5,"Enter sample size (75 is good): ");
	scanf_s("%d", &n);
	if (n>100) {
		printf("Max sample size 100\n");
		return(0); // exit not C++, changed to return
	}
	sample_size = n;

	// remove the cursor
	HideCursor();

	// generate the array 
	generate(aux, n);

	// demo loop
	while (1) {
		// fresh copy of the unsorted array
		for (i = 0; i<n; i++)
			v[i] = aux[i];
		
		// pick option and execute
		switch (menu()) {
		case 10:	// 10 is the default if the menu can't figure, for now, assign to 8
		case 8:
			printdw(1, 45, "Data");
			dumparray(v, n);
			break;
		case 9:
			printdw(1, 45, "Data Distribution");
			arraydraw(v, n);
			break;
		case 1:
			printdw(1, 45, "Bubble Sort");
			arraydraw(v, n);
			bubblesort(v, n);
			break;
		case 7:
			printdw(1, 45, "Shell Sort");
			arraydraw(v, n);
			shellsort(v, n);
			break;
		case 4:
			printdw(1, 45, "Selection Sort");
			arraydraw(v, n);
			selectionsort(v, n);
			break;
		case 3:
			printdw(1, 45, "Insertion Sort");
			arraydraw(v, n);
			insertionsort(v, n);
			break;
		case 5:
			printdw(1, 45, "Quick Sort");
			arraydraw(v, n);
			quicksort(v, 0, n - 1);
			break;
		case 2:
			printdw(1, 45, "Merge Sort");
			arraydraw(v, n);
			mergesort(v, 0, n - 1);
			break;
		case 6:
			printdw(1, 45, "Heap Sort");
			arraydraw(v, n);
			heapsort(v, n);
			break;
		case 0:
			return(0); // exit converted to a return for C++
		default: break;
		
		}
		// wait for a key
		setColor(YELLOW);
		printdw(20, 45, "--- Press any key ---");
		_getch();
		
	}
}
/*
* title
*/
void title()
{
	clr();
	int y = 3;
	int x = 3;
	setColor(BACKGROUND_BLUE);
	border(1, 1, 49, 99, ' ');
	setColor(BACKGROUND_BLACK);

	setColor(GREEN);
	setColor(ATTRIBUTES_BRIGHT);
	setColor(ATTRIBUTES_UNDERSCORE);
	printdw(30,y++," ---- Collection of Sorts --- ");
	setColor(ATTRIBUTES_RESET);
	setColor(GREEN);
	y++;
	printdw(x, y++,"Back in 1989 I did a demo program, written in K&R C, for showing sorts...");
	printdw(x, y++,"Recently (Feb 2017) I stumbled on the sources, and got them working again");
	printdw(x, y++,"in visual studio 2015 C++. The original code would have been designed to");
	printdw(x, y++,"compile on a VAX 780 and an EGA capable IBM PC 286.");
	y++;
	printdw(x, y++,"If you look at the source for the sorts, past me referred to text books where the");
	printdw(x, y++,"sorts came from; my C book, Algorithms book, an old Pascal book, etc. Keep in mind");
	printdw(x, y++,"that 1989 predated (my) access to the internet... so books!");
	y++;
	printdw(x, y++, "Oh, you will need to set, in your project->properties->preprocessor:");
	printdw(x, y++,"_CRT_SECURE_NO_WARNINGS");
	printdw(x, y++,"Or its gonna complain. The rest of the twiddling is captures in headers and three new method");
	printdw(x, y++,"calls."); 
	printdw(x, y++,"(Escape codes on the screen means you are not supporting vt100 emulation; need win10.)");
	y++;
	printdw(x, y++, "So what happens is, you will be asked for a sample size, whether we should read the data ");
	printdw(x, y++, "from a file or generate it on the fly.  You will then get a menu with three basic options:");
	printdw(x, y++, "1-7 demo a sort, 8 - display the numbers in the sample, and 9 just display the sample.");
	y++;
	printdw(x, y++,"--- Press Any Key --");
	
	_getch();
	clr();
}
/*
*	menu
*/
int menu()
{
	int option;
	clr();
	swaps = comps = 0;
	setColor(GREEN);
	setColor(BACKGROUND_GREEN);
	border(1, 1, 15, 30, ' ');
	setColor(BACKGROUND_BLACK);
	printdw(7, 3, "*** MENU ***");
	printdw(5, 5, "[1] Bubble Sort");
	printdw(5, 6, "[2] Merge Sort");
	printdw(5, 7, "[3] Insertion Sort");
	printdw(5, 8, "[4] Selection Sort");
	printdw(5, 9, "[5] Quick Sort");
	printdw(5, 10, "[6] Heap Sort");
	printdw(5, 11, "[7] Shell Sort");
	printdw(5, 12, "[8] Raw Data");
	printdw(5, 13, "[9] Distribution");
	printdw(5, 14, "[0] Abort");

	option = _getch();
	option = option - '0';
	if (option < 0 || option >9) option = 10;

	clr();
	return option;
}

/*
*	dump array
*/
void dumparray(int v[], int n)
{
	setColor(GREEN);
	char out[80];
	for (int i = 0; i < n; i+=5)
	{
		sprintf(out, "%d\t%d\t%d\t%d\t%d\n", v[i], v[i + 1], v[i + 2], v[i + 3], v[i + 4]);
		printdw(10,(i+10)/5, out);
	}
}
/*
* draw a line
*/
void drawline(int v, int column, int color)
{
	setColor(color);
	vline(push + adjust*(column + 1), OFFSET - v, v, ' ');
	setColor(BACKGROUND_BLACK);
}

/*
*	arraydraw - draw the array on the screen
*/
void arraydraw(int *v, int n)
{
	setColor(BACKGROUND_MAGENTA);
	int i, j;
	for (i = 0; i<n; i++) {
		drawline(v[i], i, BACKGROUND_MAGENTA);
	}
}

/*
*	swapdraw - draw the column swap on the screen
*/
void swapdraw(int *v, int i, int j)
{
	int  temp;

	// erase column i, column j
	drawline(OFFSET, i, BACKGROUND_BLACK);
	drawline(OFFSET, j, BACKGROUND_BLACK);

	if (v[i] > v[j]) {
		temp = j;
		j = i;
		i = temp;
	}
	
	// redraw column i, column j
	drawline(v[i], i, BACKGROUND_RED);
	drawline(v[j], j, BACKGROUND_RED);

	swaps++; 
	stats(); // update stats
	
}


/*
*	comparedraw - indicate which elements are being compared
*/
void comparedraw(int v[], int i, int j)
{

	drawline(v[i], i, BACKGROUND_YELLOW);
	drawline(v[j], j, BACKGROUND_WHITE);

	Sleep(sleep_factor); // so we can see the comparison...

	drawline(v[i], i, BACKGROUND_MAGENTA);
	drawline(v[j], j, BACKGROUND_MAGENTA);

	comps++; stats();
	
}

/*
*	stats on the sorts
*/
void stats()
{
	setColor(GREEN);
	char outs[100];

	sprintf_s(outs, "Swaps: %ld", swaps);
	printdw(50, 45, outs);

	sprintf_s(outs, "Compares: %ld", comps);
	printdw(65, 45, outs);

	sprintf_s(outs, "Elements: %d      ", sample_size);
	printdw(80, 45, outs);

	setColor(RED);

}

/*
*	gernateRandom - generate n random values, limited by OFFSET.
*/
void generateRandom(int *v, int n)
{
	for (int i = 0; i < n; i++) {
		v[i] = randint(1, OFFSET);
	}
}
/*
*	generate - n random numbers into v
*/
void generate(int *v, int n)
{
	int x, i=0;
	FILE *fp;
	char title[50];
	clr();
	printf("Use stored sample (y/N)?");
	char yesno = _getch();
	if (yesno == 'y' || yesno == 'Y') {
		printf("\nFilename? ");
		scanf("%s", title);
		if ((fp = fopen(title, "r")) == NULL) {
			printf("\nError - %s not found\n", title);
			_getch();
			exit(0);
		} else {
			while (!feof(fp)) {
				fscanf(fp, "%d\n", &x);
				v[i++] = x;
				if (i == n) break;
			} 
			
		}
	} else {
		generateRandom(v, n);
		strcpy(title, "Random Sample");
	}
}

