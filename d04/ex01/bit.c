#include "header.h"
#include <stdlib.h>
#include <math.h>

char *getAnd(char *a, char *b){
	char *ret = (char *)malloc(sizeof(char) * 4);
	int i = 4;
	while (--i >= 0){
		if (a[i] == '1' && b[i] == '1')
			ret[i] = '1';
		else
			ret[i] = '0';
	}
	return (ret);
}

char *getOr(char *a, char *b){
	char *ret = (char *)malloc(sizeof(char) * 4);
	int i = 4;
	while (--i >= 0){
		if (a[i] == '0' && b[i] == '0')
			ret[i] = '0';
		else
			ret[i] = '1';
	}
	return (ret);
}

int toInt(char *bits){
	int buf[4] = {3, 2, 1, 0};
	int i = -1;
	int ret = 0;
	while (bits[++i])
		if (bits[i] == '1')
			ret += (int)pow(2, buf[i]);
	return (ret);
}