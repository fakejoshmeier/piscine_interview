#include "header.h"
#include <stdlib.h>

char *NthLastCity(struct s_city *city, int n)
{
	int i = -1;
	struct s_city *marker = city;
	struct s_city *ret = city;
	while (++i < n + 1){
		if (!marker->next)
			return (NULL);
		marker = marker->next;
	}
	while (marker){
		marker = marker->next;
		ret = ret->next;
	}
	if (!ret)
		return (NULL);
	return (ret->name);
}