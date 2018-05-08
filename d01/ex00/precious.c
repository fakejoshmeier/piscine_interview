#include "header.h"
#include <stdlib.h>

struct s_node *create(void){
	struct s_node *new;
	struct s_node *ret = (struct s_node *)malloc(sizeof(struct s_node));
	ret->c = CS[0];
	struct s_node *save = ret;
	int i = 0;
	while (CS[++i]){
		new = (struct s_node *)malloc(sizeof(struct s_node));
		new->c = CS[i];
		new->prev = ret;
		ret->next = new;
		ret = new;
	}
	ret->next = save;
	save->prev = ret;
	return (save);
}

char	decode(int move, int *pos, struct s_node *ring){
	int i = 0;
	while (i != *pos){
		if (i < *pos){
			++i;
			ring = ring->next;
		}
		else {
			--i;
			ring = ring->prev;
		}
	}
	if (move == 0)
		return (ring->c);
	int j = *pos + move;
	while (*pos != j){
		if (move > 0){
			++*pos;
			ring = ring->next;
		}
		else {
			--*pos;
			ring = ring->prev;
		}
	}
	return (ring->c);
}

char	*precious(int *test, int size){
	char *ret = (char *)malloc(sizeof(char) * size);
	struct s_node *cs = create();
	int i = -1;
	int pos = 0;
	while (++i < size){
		ret[i] = decode(test[i], &pos, cs);
	}
	ret[size] = '\0';
	return (ret);
}