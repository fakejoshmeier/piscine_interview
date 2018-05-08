#include "header.h"
#include <stdio.h>
#include <stdlib.h>

struct s_stack *stackInit(void){
	struct s_stack *ret = (struct s_stack *)malloc(sizeof(struct s_stack));
	ret->item = NULL;
	return (ret);
}

void	*pop(struct s_stack *stack){
	struct s_item *ret = stack->item;
	char *word = ret->word;
	if (!ret)
		return (NULL);
	if (ret->next)
		stack->item = ret->next;
	free(ret);
	return (word);
}

void	push(struct s_stack *stack, char *word){
	struct s_item *new = (struct s_item *)malloc(sizeof(struct s_item));
	new->word = word;
	new->next = stack->item;
	stack->item = new;
}

void	printReverseV2(struct s_node *lst){
	struct s_stack *s = stackInit();
	while (lst)
	{
		push(s, lst->word);
		lst = lst->next;
	}
	while (s->item->next)
		printf("%s ", (char*)pop(s));
	printf("%s\n", (char*)pop(s));
	free(s);
}