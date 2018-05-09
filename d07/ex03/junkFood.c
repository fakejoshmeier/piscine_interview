#include "header.h"
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdio.h>

void dairyQueen(struct s_queue *q, struct s_sellers *ret){
	for (int i = 0; q->first; i++){
		ret->placeNames = (char **)realloc(ret->placeNames, (sizeof(char *) * (i + 1)));
		struct s_node *tmp = dequeue(q);
		if (tmp)
			ret->placeNames[i] = strdup(tmp->name);
	}
}

void dijkstra(struct s_node *node, char *name, struct s_queue *queue, struct s_sellers *ret, int dist)
{
	int i = -1;
	node->visited = 1;
	while (node->connectedPlaces[++i]){
		if (!node->connectedPlaces[i]->visited && dist <= ret->distance \
		&& node->connectedPlaces[i]->hasCerealBar){
			ret->distance = dist;
			enqueue(queue, node->connectedPlaces[i]);
			node->connectedPlaces[i]->visited = 1;
		}
	}
	i = -1;
	while (node->connectedPlaces[++i]){
		if (dist + 1 <= ret->distance && strcmp(node->connectedPlaces[i]->name, name)&& \
		!node->connectedPlaces[i]->visited){
			dijkstra(node->connectedPlaces[i], name, queue, ret, dist + 1);
		}
	}
}

struct s_sellers *closestSellers(struct s_graph *paris, char *loc){
	struct s_node *start = NULL;
	if (!paris || !loc)
		return (NULL);
	for (int i = 0; paris->places[i]; i++){
		if (!strcmp(paris->places[i]->name, loc)){
			start = paris->places[i];
			break;
		}
	}
	if (!start)
		return (NULL);
	start->visited = 1;
	struct s_sellers *ret = (struct s_sellers *)malloc(sizeof(struct s_sellers));
	ret->placeNames = (char **)malloc(sizeof(char *));
	ret->distance = INT_MAX;
	if (start->hasCerealBar){
		ret->distance = 0;
		ret->placeNames[0] = strdup(loc);
		return (ret);
	}
	int dist = 1;
	struct s_queue *queue = queueInit();
	dijkstra(start, loc, queue, ret, dist);
	if (ret->distance == INT_MAX)
		return (NULL);
	dairyQueen(queue, ret);
	return (ret);
}