#include<stdio.h>

int  main() {

	int input_arr[100], i, j, n, swap;

	printf("Enter number of input\n");
	scanf("%d", &n);
	
	printf("Enter input array\n");
	for (i=0; i<n; i++) {
		scanf("%d", &input_arr[i]);
	}

	/* Bubble sort algorithm */

	for (i=0; i<n; i++) {
		for (j=1; j<(n-i); j++) {
			if (input_arr[j]<input_arr[j-1]) {
				swap=input_arr[j];
				input_arr[j]=input_arr[j-1];
				input_arr[j-1]=swap;
			}
		}
	}

	printf("The sorted array is :-\n");
	for (i=0; i<n; i++) {
		printf("%d\t", input_arr[i]);
	}
}
		
