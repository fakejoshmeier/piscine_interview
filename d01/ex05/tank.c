#include "header.h"
#include <stdlib.h>

void tankPush(struct s_tank *tank, int energy){
	if (energy < 10 || energy > 100)
		return ;
	if (energy + tank->stacks[tank->n - 1]->sum > 1000){
		++tank->n;
		tank->stacks = (struct s_stack**)\
		realloc(tank->stacks, sizeof(struct s_stack*) * (tank->n));
		struct s_stack *new = (struct s_stack*)malloc(sizeof(struct s_stack));
		new->elem = NULL;
		new->sum = 0;
		tank->stacks[tank->n - 1] = new;
	}
	struct s_elem *new = (struct s_elem*)malloc(sizeof(struct s_elem));
	new->energy = energy;
	new->next = tank->stacks[tank->n - 1]->elem;
	tank->stacks[tank->n - 1]->elem = new;
	tank->stacks[tank->n - 1]->sum += energy;
}

int stackPop(struct s_stack *stack)
{
	struct s_elem *top = stack->elem;
	if (top == NULL)
		return (0);
	int energy = top->energy;
	stack->elem = top->next;
	stack->sum -= energy;
	free(top);
	return (energy);
}

int tankPop(struct s_tank *tank){
	if (tank->n == 1 && !tank->stacks[0]->sum)
		return (0);
	int energy = stackPop(tank->stacks[tank->n - 1]);
	if (!energy && tank->n > 1){
		free(tank->stacks[tank->n - 1]);
		--tank->n;
		//(tank->stacks = (struct s_stack **)realloc(tank->stacks, sizeof(struct s_stack) * tank->n));
	}
	return (energy);
}

struct s_tank *initTank(void){
	struct s_tank *ret = (struct s_tank*)malloc(sizeof(struct s_tank));
	ret->stacks = (struct s_stack**)malloc(sizeof(struct s_stack*));
	ret->stacks[0] = (struct s_stack*)malloc(sizeof(struct s_stack));
	ret->n = 1;
	return (ret);
}