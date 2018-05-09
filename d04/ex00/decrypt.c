#include "header.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

char *getSum(char *a, char *b){
	char *ret = (char *)malloc(sizeof(char) * 6);
	int i = 6;
	int uno = 0;
	while (--i >= 0){
		if (uno){
			if (a[i] == '1' && b[i] == '1')
				ret[i] = '1';
			if (a[i] == '0' && b[i] == '0'){
				ret[i] = '1';
				uno = 0;
			}
			if ((a[i] == '0' && b[i] == '1') || (a[i] == '1' && b[i] == '0'))
				ret[i] = '0';
		}
		else {
			if (a[i] == '1' && b[i] == '1'){
				ret[i] = '0';
				uno = 1;
			}
			if (a[i] == '0' && b[i] == '0')
				ret[i] = '0';
			if ((a[i] == '0' && b[i] == '1') || (a[i] == '1' && b[i] == '0'))
				ret[i] = '1';
		}
		if (uno){
			printf("too damn big!\n");
			exit(1);
		}
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