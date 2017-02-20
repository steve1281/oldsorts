#include "stdafx.h"
#include <stdio.h>
#include "Scursers.h"

/*
*       insertion sort - adapted from Turbo Algorithms
*                        page 33
*/
void insertionsort(int a[], int numdata)
{
	int tempo, i, j, k;
	int nomatch;

	if (numdata == 0) return;
	i = 1;
	while (i<numdata) {
		j = 0;
		nomatch = 1;
		while (j<i && nomatch) {
			comparedraw(a, i, j);
			if (a[i] >= a[j]) {
				nomatch = 0;
				tempo = a[i];
				for (k = i; k>j; k--) {
					a[k] = a[k - 1];
					a[k - 1] = tempo;
					swapdraw(a, k - 1, k);
				}
				a[j] = tempo;
				swapdraw(a, j, i);
			}
			else
				j++;
		}
		i++;
	}
}

