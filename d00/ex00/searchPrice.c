#include "header.h"
#include <string.h>

int		searchPrice(struct s_art **arts, char *name)
{
	int		i;

	i = -1;
	while (arts[++i])
	{
		if (!strcmp(arts[i]->name, name))
			return (arts[i]->price);
	}
	return (-1);
}