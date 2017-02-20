/* heapsort .c */
#include "stdafx.h"
#include <stdio.h>
#include "Scursers.h"

/*
*	heapsort - Adapted from Data Structures and C programs, page 232
*/
# define MAXHEAP 1000

int *heap;
int heapnum = 0;

bool empty()
{
	return heapnum == 0;
}

int findmin()
{
	if (empty()) {
		printf("findmin - HEAP IS EMPTY\n");
		return(0);
	}
	return heap[0];
}


void hswap(int x, int y)
{
	int temp;

	temp = heap[x];
	heap[x] = heap[y];
	heap[y] = temp;
	swapdraw(heap, x, y);
}

void insert(int x)
{
	int cur, parent;

	if (heapnum >= MAXHEAP) {
		printf("insert - HEAP too small\n");
		throw "insert - HEAP too small\n";

	}

	cur = ++heapnum;

	heap[cur] = x;
	parent = (cur - 1) / 2;

	while (heap[parent] > heap[cur]) {
		comparedraw(heap, parent, cur);
		if (cur == 0)
			return;
		hswap(parent, cur);
		cur = parent;
		parent = (cur - 1) / 2;
	}
}

void deletemin()
{
	int cur, child;
	if (empty()) {
		printf("deletemin - HEAP is empty\n");
		throw "deletemin - HEAP is empty\n";
		
	}

	hswap(0, heapnum);  /* actual "sort" */
	heapnum--;

	cur = 0;
	child = 1;
	while (child <= heapnum) {
		comparedraw(heap, cur, child);
		if (child < heapnum && heap[child + 1] < heap[child])
			child++;
		comparedraw(heap, child, child + 1);
		if (heap[cur] > heap[child]) {
			if (child > heapnum) {
				printf("deletemin - beyond HEAP\n");
				throw "deletemin - beyond HEAP\n";
			}
			hswap(cur, child);
			cur = child;
			child = 2 * cur + 1;
		}
		else
			break;
	}
}

/*
*	heapsort
*/
void heapsort(int v[], int n)
{
	int i, temp;

	heap = v;

	/*	printdw(20,21,"Building Heap"); */
	for (i = 1; i<n; i++)
		insert(v[i]);

	/*	printdw(20,21,"             "); */

	/*	printdw(20,21,"Sorting Heap");    */

	while (!empty())
		deletemin();

	/*	printdw(20,21,"            "); */

}


