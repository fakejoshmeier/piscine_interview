#include "header.h"
#include <stdlib.h>
#include <math.h>

char *getXor(char *a, char *b){
	char *ret = (char *)malloc(sizeof(char) * 6);
	int i = -1;
	while (++i < 6){
		if (a[i] == b[i])
			ret[i] = '0';
		else
			ret[i] = '1';
	}
	return (ret);
}

int toInt(char *bits){
	int buf[6] = {5, 4, 3, 2, 1, 0};
	int i = -1;
	int ret = 0;
	while (bits[++i])
		if (bits[i] == '1')
			ret += (int)pow(2, buf[i]);
	return (ret);
}