#include<stdio.h>

int main() {

	int input_arr[100], i, j, n, min, swap;

	printf("Enter number of input\n");
	scanf("%d", &n);
	
	printf("Enter input array\n");
	for (i=0; i<n; i++) {
		scanf("%d", &input_arr[i]);
	}

	/* Selection sort algorithm */

	for (i=0; i<(n-1); i++) {
		min=i;
		for (j=i+1; j<n; j++) {
			if (input_arr[j]<input_arr[min]) {
				min=j;
			}
		}
		swap=input_arr[i];
		input_arr[i]=input_arr[min];
		input_arr[min]=swap;
	}

	printf("The sorted array is :-\n");
	for (i=0; i<n; i++) {
		printf("%d\t", input_arr[i]);
	}
}
