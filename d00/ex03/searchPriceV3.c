#include "header.h"
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

size_t	hash(char *input){
	unsigned char *p = (unsigned char *)input;
	size_t h = 0;
	for (int i = 0; p[i]; i++)
	{
		h += p[i];
		h += (h << 10);
		h ^= (h >> 6);
	}
	h += (h << 3);
	h ^= (h >> 11);
	h += (h << 15);
	return (h);
}

struct	s_dict *dictInit(int capacity){
	struct s_dict *ret = (struct s_dict *)malloc(sizeof(struct s_dict));
	ret->items = (struct s_item **)malloc(sizeof(struct s_item *) * capacity);
	bzero(ret->items, sizeof(struct s_item *) * capacity);
	ret->capacity = capacity;
	return (ret);
}

void	listAdd(struct s_item **head, struct s_item *new){
	if (*head == NULL)
		*head = new;
	else {
		struct s_item *list_iter = *head;
		while (list_iter->next)
			list_iter = list_iter->next;
		list_iter->next = new;
	}
}

int		 dictInsert(struct s_dict *dict, char *key, struct s_art *value){
	struct s_item *item = (struct s_item *)malloc(sizeof(struct s_item));
	if (item == NULL)
		return (0);
	item->key = key;
	item->value = value;
	item->next = NULL;
	listAdd(&dict->items[hash(key) % dict->capacity], item);
	return (1);
}

struct	s_art *dictSearch(struct s_dict *dict, char *key){
	struct s_item *shelf = dict->items[hash(key) % dict->capacity];
	while (shelf){
		if (!strcmp(key, shelf->key))
			return(shelf->value);
		shelf = shelf->next;
	}
	return (NULL);
}

int		searchPrice(struct s_dict *dict, char *name){
	struct s_art *art = dictSearch(dict, name);
	if (art == NULL)
		return (-1);
	return (art->price);
}