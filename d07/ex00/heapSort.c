#include "header.h"
#include <string.h>

void swap(struct s_art **s1, struct s_art **s2){
	struct s_art *tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void heapify(struct s_art **arr, int n, int i){
	int big = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && strcmp(arr[l]->name, arr[big]->name) > 0)
		big = l;
	if (r < n && strcmp(arr[r]->name, arr[big]->name) > 0)
		big = r;
	if (big != i){
		swap(&arr[i], &arr[big]);
		heapify(arr, n, big);
	}
}

void heapSort(struct s_art **masterpiece, int n){
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(masterpiece, n, i);
	for (int i = n - 1; i >= 0; i--){
		swap(&masterpiece[0], &masterpiece[i]);
		heapify(masterpiece, i, 0);
	}
}