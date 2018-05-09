#include "header.h"
#include <stdio.h>
#include <string.h>
#define UTENSIL_AMT 15

void countSort(unsigned char *utensils, int n)
{
	int count[UTENSIL_AMT + 1], i, j;
	bzero(count, sizeof(count));
	i = j = -1;
	while (++i < n)
		++count[utensils[i]];
	for (i = 0; i <= UTENSIL_AMT; i++)
		while (--count[i] > -1)
			utensils[++j] = i;
}