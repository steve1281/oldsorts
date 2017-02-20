#include "stdafx.h"
#include <stdio.h>
#include "Scursers.h"


void qswap(int [], int , int );

/*
* quicksort - page adapted from The C programming Language 2nd Ed. page 87
*/
void quicksort(int v[], int left, int right)
{
	int last, i;

	if (left >= right)
		return;
	qswap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++) {
		comparedraw(v, i, left);
		if (v[i] > v[left])
			qswap(v, ++last, i);
	}
	qswap(v, left, last);
	quicksort(v, left, last - 1);
	quicksort(v, last + 1, right);
}

/*
* qswap - for quick
*/
void qswap(int v[], int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
	swapdraw(v, i, j);
}


