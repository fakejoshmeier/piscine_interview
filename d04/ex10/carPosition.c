#include "header.h"

int carPosition(unsigned int parkingRow){
	int i = 1;
	int c = 0;
	if (parkingRow && !(parkingRow & (parkingRow - 1))){
		while (!(i & parkingRow)){
			i <<= 1;
			++c;
		}
		return (c);
	}
	return (-1);
}