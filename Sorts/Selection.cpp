#include "stdafx.h"
#include <stdio.h>
#include "Scursers.h"

/*
*	selection sort - page 98 of Algorithms
*/
void selectionsort(int v[], int n)
{
	int i, j, min, t;

	for (i = 0; i<n - 1; i++) {
		min = i;
		for (j = i + 1; j<n; j++) {
			comparedraw(v, min, j);
			if (v[j] > v[min])
				min = j;
		}
		t = v[min];
		v[min] = v[i];
		v[i] = t;
		swapdraw(v, i, min);

	}
}



