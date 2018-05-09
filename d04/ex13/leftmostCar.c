#include "header.h"
#include <limits.h>

int leftmostCar(unsigned int parkingRow){
	if (parkingRow){
		for (int i = 0; i < INT_MAX; i++){
			int m = 1 << i;
			if (!(parkingRow & ~(m - 1)))
				return (i - 1);
		}
	}
	return (-1);
}