#include "header.h"
#include <string.h>
#include <stdio.h>

void	swapper(struct s_art **arts, int a, int b){
	struct s_art *tmp = arts[a];
	arts[a] = arts[b];
	arts[b] = tmp;
}

int		partition(struct s_art **arts, int low, int high){
	struct s_art *tmp = arts[high];
	int i = low;

	for (int j = low; j < high; j++)
	{
		if (strcmp(arts[j]->name, tmp->name) < 0)
		{
			swapper(arts, i, j);
			++i;
		}
	}
	swapper(arts, high, i);
	return (i);
}

void	quicksort(struct s_art **arts, int low, int high){
	while (low < high){
		int pivot = partition(arts, low, high);
		if (pivot - low < high - pivot)
		{
			quicksort(arts, low, pivot - 1);
			low = pivot + 1;
		}
		else
		{
			quicksort(arts, pivot + 1, high);
			high = pivot - 1;
		}
	}
}

void	sortArts(struct s_art **arts)
{
	int i = -1;
	while (arts[++i]);
	quicksort(arts, 0, i - 1);
}