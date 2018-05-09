#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	//int arr[] = {10, -2, 2, 21, -5, 16, 3, -6, 17, 11};
	int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5};
	
	int n;
	int k;
	struct s_max *res;

	res = NULL;
	n = 16;
	k = 10;
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	/*-------------------
	launch your test here
	--------------------*/

	res = maxSlidingWindow(arr, n, k);
	if (res) {
	 	for (int i = 0; i < res->length; i++)
	 		printf("%d ", res->max[i]);
	 	printf("\n");
	}

	return (0);
}



// Function used for the test
// Don't go further :)
