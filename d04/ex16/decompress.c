#include "header.h"
#include <stdlib.h>

int **pianoDecompress(struct s_bit *bit, int l){
	int **ret = (int **)malloc(sizeof(int *) * bit->n);
	for (int i = 0; i < bit->n; i++){
		ret[i] = (int *)calloc(l, sizeof(int));
		int bitron = bit->arr[i];
		int j = -1;
		while (++j < l) //&& ((bitron & (1 << j)) >> j))
			ret[i][j] = (bitron & (1 << j) >> j);
	}
	return (ret);
}