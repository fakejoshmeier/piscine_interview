#include "header.h"
#include <math.h>

int carPosition(unsigned int parkingRow){
	if (parkingRow){
		int pos = log2(parkingRow);
		if (parkingRow != pow(2, pos))
			return (-1);
		return (pos);
	}
	return (-1);
}