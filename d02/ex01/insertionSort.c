#include "header.h"

void insertionSort(struct s_player **players){
	int i = 0;
	while (players[++i]){
		struct s_player *curr = players[i];
		int j = i - 1;
		while (j >= 0 && players[j]->score < curr->score){
			players[j + 1] = players[j];
			--j;
		}
		players[j + 1] = curr;
	}
}