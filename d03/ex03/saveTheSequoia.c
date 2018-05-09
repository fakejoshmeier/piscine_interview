#include "header.h"
#include <stdio.h>
#include <stdlib.h>

void reset(struct s_flag **f){
	(*f)->tmp = NULL;
	(*f)->lr = 0;
}

void swap(struct s_node **root, struct s_flag **f){
	struct s_node *leaf_l;
	struct s_node *leaf_r;
	struct s_node *root_l;
	struct s_node *root_r;
	if (!*root)
		return ;
	if ((*root)->left && (*root)->left->value > (*root)->right->value){
		if ((*root)->left->value > (*root)->value){
			(*f)->lr = 1;
			(*f)->swap = 1;
			(*f)->tmp = (*root)->left;
			leaf_r = (*root)->left->right;
			leaf_l = (*root)->left->left; 
			root_r = (*root)->right;
			(*root)->left->left = *root;
			(*root)->left->right = root_r;
			(*root)->right = leaf_r;
			(*root)->left = leaf_l;
		}
	}
	else if ((*root)->right){
		if ((*root)->right->value > (*root)->value){
			(*f)->lr = 1;
			(*f)->swap = 1;
			(*f)->tmp = (*root)->right;
			leaf_r = (*root)->right->right;
			leaf_l = (*root)->right->left; 
			root_l = (*root)->left;
			(*root)->right->right = *root;
			(*root)->right->left = root_l;
			(*root)->right = leaf_r;
			(*root)->left = leaf_l;  
		}
	}
}

void savior(struct s_node **root, struct s_flag **f){
	if (!*root)
		return ;
	savior(&(*root)->left, f);
	if ((*f)->lr)
		(*root)->left = (*f)->tmp;
	reset(f);
	savior(&(*root)->right, f);
	if ((*f)->lr)
		(*root)->right = (*f)->tmp;
	reset(f);
	swap(root, f);
}

void saveTheSequoia(struct s_node **root){
	struct s_flag *f = (struct s_flag *)malloc(sizeof(struct s_flag));
	reset(&f);
	f->swap = 0;
	savior(&(*root)->left, &f);
	if (f->lr)
		(*root)->left = f->tmp;
	reset(&f);
	savior(&(*root)->right, &f);
	if (f->lr)
		(*root)->right = f->tmp;
	reset(&f);
	swap(root, &f);
	if (f->lr)
		*root = f->tmp;
	if (!f->swap)
		return ;
	saveTheSequoia(root);
}