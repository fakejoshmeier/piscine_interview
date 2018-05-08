#include "header.h"
#include <stdlib.h>

struct s_queue *queueInit(void){
	struct s_queue *ret = (struct s_queue *)malloc(sizeof(struct s_queue));
	ret->first = NULL;
	ret->last = NULL;
	return (ret);
}

char *dequeue(struct s_queue *queue){
	if (!queue->first)
		return (NULL);
	struct s_node *q = queue->first;
	queue->first = q->next;
	if (!queue->first)
		queue->last = NULL;
	char *ret = q->message;
	free(q);
	return (ret);
}

void enqueue(struct s_queue *queue, char *message){
	struct s_node *new = (struct s_node *)malloc(sizeof(struct s_node));
	new->message = message;
	new->next = NULL;
	if (!queue->first)
		queue->first = new;
	else
		queue->last->next = new;
	queue->last = new;
}

char *peek(struct s_queue *queue){
	return(queue->first == NULL ? NULL : queue->first->message);
}

int isEmpty(struct s_queue *queue){
	if (queue->first)
		return (1);
	return (0);
}