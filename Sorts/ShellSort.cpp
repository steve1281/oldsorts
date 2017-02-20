#include "stdafx.h"
#include <stdio.h>
#include "Scursers.h"


/*
*	shellsort: sort v[0]...v[n-1] into increasing order
*	THE C PROGRAMMING LANGAUGE, B.W. Kernighan, D.M. Ritchie
*	FIRST ED., page 108
*
*/
void shellsort(int *v, int n)
{
	int gap, i, j;
	int temp;

	for (gap = n / 2; gap > 0; gap /= 2) {
		for (i = gap; i < n; i++)
			for (j = i - gap; j >= 0; j -= gap) {
				comparedraw(v, j, j + gap);
				if (v[j] > v[j + gap])
					break;
				temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;
				swapdraw(v, j, j + gap);
			}
	}
}



