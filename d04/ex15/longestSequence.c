#include "header.h"
#include <limits.h>

int longestSequence(unsigned int parkingRow){
	for (int i = 0; i < INT_MAX; i++){
		if (!(parkingRow & (parkingRow << i)))
			return (i);
	}
	return (0);
}