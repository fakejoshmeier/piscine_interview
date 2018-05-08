#include "header.h"
#include <string.h>
#include <stdio.h>

int		recurse(struct s_art **arts, char *name, int s, int e)
{
	if (s > e)
	 	return (-1);
	int mid = (s + e) / 2;
	if (strcmp(name, arts[mid]->name) > 0)
		return (recurse(arts, name, mid + 1, e));
	if (strcmp(name, arts[mid]->name) < 0)
		return (recurse(arts, name, s, mid - 1));
	return (arts[mid]->price);
}
int		searchPrice(struct s_art **arts, int n, char *name)
{
	return (recurse(arts, name, 0, n));
}