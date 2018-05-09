#include "header.h"
#include <stdlib.h>
#include <string.h>

struct s_stack *init(void){
	struct s_stack *in = (struct s_stack*)malloc(sizeof(struct s_stack));
	in->top = NULL;
	return (in);
}

struct s_node *pop(struct s_stack *stack){
	if (!stack->top)
		return (NULL);
	struct s_item *tf = stack->top;
	struct s_node *ret = stack->top->node;
	stack->top = stack->top->next;
	free(tf);
	return (ret);
}

void push(struct s_stack *stack, struct s_node *node){
	struct s_item *ret = (struct s_item *)malloc(sizeof(struct s_item));
	ret->node = node;
	if (stack->top){
		ret->next = stack->top;
		stack->top = ret;
	}
	else {
		stack->top = ret;
		ret->next = NULL;
	}
}

void findSpec(struct s_node *root, struct s_stack *stk, char *species){
	if (!root)
		return ;
	if (!strcmp(species, root->name)){
		push(stk, root);
		return ;
	}
	for (int i = 0; root->children[i]; i++){
		findSpec(root->children[i], stk, species);
		if (stk->top){
			push(stk, root);
			break ;
		}
	}
}

struct s_node *intersection(struct s_stack *s1, struct s_stack *s2){
	struct s_node *ret;
	while (s1->top && s2->top && !strcmp(s1->top->node->name, s2->top->node->name)){
		ret = pop(s1);
		pop(s2);
	}
	return (ret);
}

struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies){
	struct s_stack *spec1 = init();
	struct s_stack *spec2 = init();
	findSpec(root, spec1, firstSpecies);
	findSpec(root, spec2, secondSpecies);
	if (!spec1->top || !spec2->top)
		return (NULL);
	struct s_node *ret = intersection(spec1, spec2);
	while (spec1->top || spec2->top){
		pop(spec1);
		pop(spec2);
	}
	free(spec1);
	free(spec2);
	return (ret);
}