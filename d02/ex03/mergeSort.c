#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

struct s_player **arr(struct s_player **players, int from, int size)
{
	struct s_player **arr = (struct s_player**)malloc(sizeof(struct s_player*) * size);
	int i = -1;
	while (++i < size)
		arr[i] = players[from + i];
	return (arr);
}

void merge(struct s_player **players, int l, int m, int r){
	int l_size = m - l + 1;
	int r_size = r - m;
	int i = 0;
	int j = 0;
	int k = l;
	struct s_player **l_arr = arr(players, l, l_size);
	struct s_player **r_arr = arr(players, m + 1, r_size);
	while (i < l_size && j < r_size){
		// if (l_arr[i]->score == r_arr[j]->score){
		// 	if (strcmp(l_arr[i]->timeStamp, r_arr[j]->timeStamp) < 0)
		// 		players[k++] = l_arr[i++];
		// 	else
		// 		players[k++] = r_arr[j++];
		// }
		if (l_arr[i]->score > r_arr[j]->score)
			players[k++] = l_arr[i++];
		else
			players[k++] = r_arr[j++];
	}
	while (i < l_size)
		players[k++] = l_arr[i++];
	while (j < r_size)
		players[k++] = r_arr[j++];
	free(l_arr);
	free(r_arr);
}

void sort(struct s_player **players, int left, int rite){
	if (left < rite){
		int m = (rite + left) / 2;
		sort(players, left, m);
		sort(players, m + 1, rite);
		merge(players, left, m, rite);
	}
}

struct s_player **mergeSort(struct s_player **players){
	int i = -1;
	while (players[++i]);
	sort(players, 0, i - 1);
	return (players);
}