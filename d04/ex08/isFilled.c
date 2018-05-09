#include "header.h"

int isFilled(unsigned int parkingRow){
	if (parkingRow & (parkingRow + 1))
		return (0);
	return (1);
}