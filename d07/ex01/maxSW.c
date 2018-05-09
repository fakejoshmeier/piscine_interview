#include "header.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

struct s_deque *dequeInit(void){
	struct s_deque *ret = (struct s_deque *)malloc(sizeof(struct s_deque));
	ret->first = NULL;
	ret->last = NULL;
	return (ret);
}

void pushFront(struct s_deque *dq, int value){
	if (!dq)
		return ;
	struct s_dequeNode *new = (struct s_dequeNode *)malloc(sizeof(struct s_dequeNode));
	new->value = value;
	new->prev = NULL;
	if (dq->first)
		dq->first->prev = new;
	new->next = dq->first;
	dq->first = new;
	if (!dq->last)
		dq->last = new;
}

void pushBack(struct s_deque *dq, int value){
	if (!dq)
		return ;
	struct s_dequeNode *new = (struct s_dequeNode *)malloc(sizeof(struct s_dequeNode));
	new->value = value;
	new->next = NULL;
	if (dq->last)
		dq->last->next = new;
	new->prev = dq->last;
	dq->last = new;
	if (!dq->first)
		dq->first = new;
}

int popFront(struct s_deque *dq){
	if (!dq->first)
		return (INT_MIN);
	struct s_dequeNode *pop = dq->first;
	int ret = pop->value;
	dq->first = dq->first->next;
	if (dq->first)
		dq->first->prev = NULL;
	else
		dq->last = NULL;
	free(pop);
	return (ret);
}

int popBack(struct s_deque *dq){
	if (!dq->last)
		return (INT_MIN);
	struct s_dequeNode *pop = dq->last;
	int ret = pop->value;
	dq->last = dq->last->prev;
	if (dq->last)
		dq->last->next = NULL;
	else
		dq->first = NULL;
	free(pop);
	return (ret);
}

struct s_max *maxSlidingWindow(int arr[], int n, int k){
	if (!k)
		return (NULL);
	struct s_max *ret = (struct s_max *)malloc(sizeof(struct s_max));
	struct s_deque *dq = dequeInit();
	ret->length = n - k + 1;
	ret->max = (int*)malloc(sizeof(int) * ret->length);
	for (int i = 0; i < k; i++){
		while (dq->last && arr[dq->last->value] <= arr[i])
			popBack(dq);
		pushBack(dq, i);
	}
	for (int i = k; i < n; i++){
		ret->max[i - k] = arr[dq->first->value];
		while (dq->first && dq->first->value <= i - k)
			popFront(dq);
		while (dq->last && arr[dq->last->value] <= arr[i])
			popBack(dq);
		pushBack(dq, i);
	}
	ret->max[n - k] = arr[dq->first->value];
	return (ret);
}