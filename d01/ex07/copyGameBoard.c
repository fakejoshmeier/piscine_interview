#include "header.h"
#include <stdlib.h>
#include <stdio.h>

struct s_node *find(struct s_node *head, int to_find){
	while (head){
		if (head->value == to_find)
			return (head);
		head = head->next;
	}
	return (NULL);
}

struct s_node *create_clone(struct s_node *node){
	struct s_node *ret = (struct s_node *)malloc(sizeof(struct s_node));
	ret->value = node->value;
	ret->random = node->random ? node->random : NULL;
	ret->next = !node->next ? NULL : (create_clone(node->next));
	return (ret);
}

struct s_node *cloneGameBoard(struct s_node *node){
	struct s_node *ret = create_clone(node);
	struct s_node *head = ret;
	while (node){
		if (node->random)
			ret->random = find(head, node->random->value);
		ret = ret->next;
		node = node->next;
	}
	return (head);
}