#include "header.h"
#include <stdlib.h>

struct s_node *createBS(int *arr, int s, int e){
	if (s > e)
		return (NULL);
	struct s_node *root = (struct s_node *)malloc(sizeof(struct s_node));
	int mid = (s + e) / 2;
	root->value = arr[mid];
	root->left = createBS(arr, s, mid - 1);
	root->right = createBS(arr, mid + 1, e);
	return (root);
}

struct s_node *createBST(int *arr, int n){
	return(createBS(arr, 0, n - 1));
}