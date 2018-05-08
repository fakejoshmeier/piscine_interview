#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

struct s_stack *stackInit(void){
	struct s_stack *ret = (struct s_stack *)malloc(sizeof(struct s_stack));
	ret->item = NULL;
	return (ret);
}

int 	pop(struct s_stack *stack){
	struct s_item *ret = stack->item;
	int idx = ret->idx;
	if (!ret)
		return (0);
	stack->item = ret->next;
	free(ret);
	return (idx);
}

void	push(struct s_stack *stack, int idx){
	struct s_item *new = (struct s_item *)malloc(sizeof(struct s_item));
	new->idx = idx;
	new->next = stack->item;
	stack->item = new;
}

char	*console(){
	char buf[256];
	struct s_stack *stack = stackInit();
	char *msg = (char *)malloc(sizeof(char) * 256);
	int undo;
	memset(msg, 0, 256);
	while (1){
		printf("u up?: ");
		scanf("%[\n]", buf);
		scanf("%255[^\n]", buf);

		if (!strcmp(buf, "UNDO"))
		{
			undo = pop(stack);
			memset(msg + undo, 0, 256 - undo);
		}
		else if (!strcmp(buf, "SEND"))
		{
			while (stack->item)
				pop(stack);
			free (stack);
			break ;
		}
		else
		{
			push(stack, strlen(msg));
			strcat(msg, buf);
		}
		printf("%s\n\n", msg);
	}
	return (msg);
}