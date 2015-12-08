#include<stdio.h>

int main() {

	int input_arr[100], i, j, index, n;

	printf("Enter the number of inputs\n");
	scanf("%d", &n);

	printf("Enter %d elements\n",n);
	for (i=0; i<n; i++) {
		scanf("%d", &input_arr[i]);
	}

	/* Insertion sort algorithm */
	for (i=1; i<n; i++) {
		index=input_arr[i];
		j=i;
		while(j>0 && input_arr[j-1]>index) {
			input_arr[j] = input_arr[j-1];
			j--;
		}
		input_arr[j]=index;
	}

	printf("The sorted array is :-\n");
	for (i=0; i<n; i++) {
		printf("%d\t", input_arr[i]);
	}
}
