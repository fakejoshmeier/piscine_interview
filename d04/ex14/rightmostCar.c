#include "header.h"
#include <math.h>

int rightmostCar(unsigned int parkingRow){
	if (parkingRow){
		parkingRow &= -parkingRow;
		return (log2(parkingRow));
	}
	return (-1);
}