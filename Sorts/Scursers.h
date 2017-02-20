#pragma once

// defines for colors and effects VT terminal emulation
#define YELLOW 33
#define BLACK 30 
#define RED 31 
#define GREEN 32 
#define YELLOW 33
#define BLUE 34
#define MAGENTA 35
#define CYAN 36
#define WHITE 37
#define BACKGROUND_YELLOW 43
#define BACKGROUND_BLACK 40 
#define BACKGROUND_RED 41 
#define BACKGROUND_GREEN 42 
#define BACKGROUND_YELLOW 43
#define BACKGROUND_BLUE 44
#define BACKGROUND_MAGENTA 45
#define BACKGROUND_CYAN 46
#define BACKGROUND_WHITE 47
#define ATTRIBUTES_RESET 0	
#define ATTRIBUTES_BRIGHT 1	
#define ATTRIBUTES_DIM 2	
#define ATTRIBUTES_UNDERSCORE 4	
#define ATTRIBUTES_BLINK 5	
#define ATTRIBUTES_REVERSE 7	
#define ATTRIBUTES_HIDDEN 8	

// prototypes for Scursers...
void clr();
void gotoxy(int , int);
void printdhw(int , int , char *);
void printdw(int , int , char *);
void vline(int , int , int , char );
void hline(int , int , int , char );
void border(int , int , int , int , char );
void beep();

void setColor(int );
bool EnableVTMode();
bool SetWindow(int , int );
bool HideCursor();
bool ShowCursor();
bool SetCursorVisibility(bool);

// prototypes for Sorts
void title();
void dumparray(int [], int );
void comparedraw(int [], int, int);
void generate(int *, int);
int menu();
void arraydraw(int *, int);
void swapdraw(int *, int, int);
void stats();
void generateRandom(int *, int );

// prototypes for various sorts
void quicksort(int [], int , int );
void bubblesort(int *, int);
void heapsort(int *, int);
void insertionsort(int[], int);
void shellsort(int *, int);
void selectionsort(int[], int);
void mergesort(int [], int , int );
