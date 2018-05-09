#include "header.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct s_node *findStart(char *name, struct s_node **places){
	for (int i = 0; places[i]; i++)
		if (!strcmp(name, places[i]->name))
			return (places[i]);
	return (NULL);
}

void dairyQueen(struct s_queue *q, struct s_sellers *ret){
	for (int i = 0; q->first; i++){
		ret->placeNames = (char **)realloc(ret->placeNames, (sizeof(char *) * (i + 1)));
		struct s_node *tmp = dequeue(q);
		if (tmp)
			ret->placeNames[i] = tmp->name;
	}
}

struct s_sellers *closestSellers(struct s_graph *paris, char *loc){
	struct s_node *start = findStart(loc, paris->places);
	if (!start)
		return (NULL);
	struct s_queue *q = queueInit();
	struct s_queue *found = queueInit();
	enqueue(q, start);
	start->visited = 1;
	enqueue(q, NULL);
	int dist = 0;
	int total = 0;
	while (!total && q->first->place){
		struct s_node *curr;
		while ((curr = dequeue(q)) != NULL){
			curr->visited = 1;
			if (curr->hasCerealBar){
				enqueue(found, curr);
				total++;
			}
			else if (!total){
				for (int i = 0; curr->connectedPlaces[i]; i++)
					if (!curr->connectedPlaces[i]->visited){
						curr->connectedPlaces[i]->visited = 1;
						enqueue(q, curr->connectedPlaces[i]);
					}
			}
		}
		if (!total){
			dist++;
			enqueue(q, NULL);
		}
	}
	if (!total)
		return (NULL);
	struct s_sellers *ret = (struct s_sellers *)malloc(sizeof(struct s_sellers));
	if (start->hasCerealBar){
		ret->distance = 0;
		ret->placeNames[0] = loc;
		return (ret);
	}
	ret->distance = dist;
	dairyQueen(found, ret);
	return (ret);
}