#include "stdafx.h"
#include <stdio.h>
#include "Scursers.h"

/*
*	bubble sort - converted from page 101 of Algorithms
*/
void bubblesort(int *v, int n)
{
	int i, j, t;

	for (i = n; i>0; i--)
		for (j = 1; j<i; j++) {
			comparedraw(v, j - 1, j);
			if (v[j - 1]<v[j]) {
				t = v[j - 1];
				v[j - 1] = v[j];
				v[j] = t;
				swapdraw(v, j, j - 1);
			}
		}

}