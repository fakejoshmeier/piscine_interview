#include "header.h"
#include <stdlib.h>

struct s_node *recurse(int arr[], int s, int e){
	if (s > e)
		return (NULL);
	struct s_node *ret = (struct s_node *)malloc(sizeof(struct s_node));
	int mid = (s + e) / 2;
	ret->value = arr[mid];
	ret->left = recurse(arr, s, mid - 1);
	ret->right = recurse(arr, mid + 1, e);
	return (ret);
}

struct s_node *createBST(int arr[], int n){
	return (recurse(arr, 0, n - 1));
}