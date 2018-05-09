#include "header.h"

void	swapper(struct s_player **players, int a, int b){
	struct s_player *tmp = players[a];
	players[a] = players[b];
	players[b] = tmp;
}

int		partition(struct s_player **players, int low, int high){
	struct s_player *tmp = players[high];
	int i = low;
	for (int j = low; j < high; j++)
	{
		if (players[j]->score > tmp->score)
		{
			swapper(players, i, j);
			++i;
		}
	}
	swapper(players, high, i);
	return (i);
}

void	quicksort(struct s_player **players, int low, int high){
	while (low < high){
		int pivot = partition(players, low, high);
		if (pivot - low < high - pivot)
		{
			quicksort(players, low, pivot - 1);
			low = pivot + 1;
		}
		else
		{
			quicksort(players, pivot + 1, high);
			high = pivot - 1;
		}
	}
}

void	quickSort(struct s_player **players){
	int i = -1;
	while (players[++i]);
	quicksort(players, 0, i - 1);
}