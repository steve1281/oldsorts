/* mergesort.c
*
*	Adapted from  Data Structures Using Pascal
*				    Aaron M. Tenenbaum, Moshe J. Augenstein.
*				    (c) 1986, Prentice Hall 2nd Ed.
*				    page 426.
*/
#include "stdafx.h"
#include <stdio.h>
#include "Scursers.h"

/*
*	mswap - swap for merge sort
*/
void mswap(int v[], int x, int y)
{
	int temp;

	temp = v[x];
	v[x] = v[y];
	v[y] = temp;
}

/*
*	merge - merge two sorted arrays together
*		Note: this is done inline, and is inefficient time-wise
*/
void merge(int v[], int l1, int u1, int u2)
{
	int i;
	int size;

	while (1) {
		if (l1 == u1 + 1 || u1 == u2)
			return;		/* we are done */
		comparedraw(v, l1, u1 + 1);
		if (v[l1] < v[u1 + 1]) {
			for (i = u1; i >= l1; i--) {
				mswap(v, i, i + 1);
			}
			swapdraw(v, l1, u1 +1);
			u1++;
		}
		l1++;
	}
}

/*
*	mergesort - recursively sort v[0..n-1]
*/
void mergesort(int v[], int l, int u)
{
	int mid;

	if (l != u) {
		mid = (l + u) / 2;
		mergesort(v, l, mid);
		mergesort(v, mid + 1, u);
		merge(v, l, mid, u);
	}
}


