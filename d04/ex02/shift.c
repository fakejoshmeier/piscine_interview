#include "header.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

char *rightShift(char *bin, int k){
	char *ret = (char *)malloc(sizeof(char) * 6);
	int i = 0;
	int j = -1;
	if (k == 0)
		return (bin);
	ret[0] = bin[0];
	while (i < k)
		ret[++i] = ret[0];
	while (i < 6){
		ret[i] = bin[++j];
		++i;
	}
	return (ret);
}

char *leftShift(char *bin, int k){
	char *ret = (char *)malloc(sizeof(char) * 6);
	int i = -1 + k;
	int j = -1;
	if (k == 0)
		return (bin);
	while (i < 6)
		ret[++j] = bin[++i];
	while (j < 6)
		ret[j++] = '0';
	return (ret);
}

int tc_neg(char *bits){
	int buf[6] = {0, 4, 3, 2, 1, 0};
	int i = 6;
	int ret = 0;
	if (!strcmp(bits, "111111"))
		return (1);
	while (--i > 0)
		if (bits[i] == '0')
			ret += (int)pow(2, buf[i]);
	return (ret + 1);
}

int toInt(char *bits){
	if (bits[0] == '1')
		return (-1 * tc_neg(bits));
	int buf[6] = {0, 4, 3, 2, 1, 0};
	int i = 6;
	int ret = 0;
	while (--i > 0)
		if (bits[i] == '1')
			ret += (int)pow(2, buf[i]);
	return (ret);
}