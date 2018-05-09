#include "header.h"
#include <math.h>

// col gives the power needed to raise a bit
// from row to whatever distance + row is
void correctSong(struct s_bit *bit, int l, int row, int col, int dist){
	if (col < l)
		for (int i = row; i < row + dist && i < bit->n; i++)
			bit->arr[i] = pow(2, col);
}