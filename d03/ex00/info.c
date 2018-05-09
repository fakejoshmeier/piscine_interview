#include "header.h"
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int findMin(struct s_node *root){
	if (root == NULL)
		return (INT_MAX);
	int ret = root->value;
	int	left = findMin(root->left);
	int rite = findMin(root->right);
	ret = left < ret ? left : ret;
	ret = rite < ret ? rite : ret;
	return (ret);
}

int findMax(struct s_node *root){
	if (root == NULL)
		return (INT_MIN);
	int ret = root->value;
	int	left = findMax(root->left);
	int rite = findMax(root->right);
	ret = left > ret ? left : ret;
	ret = rite > ret ? rite : ret;
	return (ret);
}

int findElem(struct s_node *root){
	if (!root)
		return (0);
	return (1 + findElem(root->left) + findElem(root->right));
}

int findHeight(struct s_node *root){
	if (!root)
		return (-1);
	if (!root->right && !root->left)
		return (0);
    int left = findHeight(root->left);
    int rite = findHeight(root->right);
	if (left > rite)
		return (left + 1);
	return (rite + 1);
}

int checkBST(struct s_node *root, int min, int max){
	if (!root)
		return (1);
	else if (root->value > max || root->value < min)
		return (0);
	return (checkBST(root->left, min, root->value) && \
			checkBST(root->right, root->value, max));
}

int checkBal(struct s_node *root){
	if (!root)
		return (1);
	int lh = findHeight(root->left);
	int rh = findHeight(root->right);
	if (abs(lh - rh) <= 1 && checkBal(root->right) && checkBal(root->left))
		return (1);
	return (0);
}

struct s_info getInfo(struct s_node *root){
	struct s_info ret;
	ret.max = findMax(root); //done
	ret.min = findMin(root); //done
	ret.elements = findElem(root); //done
	ret.height = findHeight(root); //done
	ret.isBST = checkBST(root, INT_MIN, INT_MAX); //done
	ret.isBalanced = checkBal(root); //done
	return (ret);
}