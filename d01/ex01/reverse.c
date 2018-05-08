#include "header.h"
#include <stdio.h>

void	printReverse(struct s_node *lst){
	static int i = 0;
	if (lst->next){
		++i;
		printReverse(lst->next);
	}
	--i;
	printf("%s", lst->word);
	i == -1 ? printf("\n") : printf(" ");
}