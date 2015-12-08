#include<stdio.h>

int partition (int [], int, int);
void quick_sort (int [], int, int);
void swap (int *, int *);

int main() {

	int input_arr[100], i, n;

	printf("Enter number of input\n");
	scanf("%d", &n);
	
	printf("Enter input array\n");
	for (i=0; i<n; i++) {
		scanf("%d", &input_arr[i]);
	}

	/* Quick Sort algorithm */

	quick_sort(input_arr, 0, n-1);

	printf("The sorted array is :-\n");
	for (i=0; i<n; i++) {
		printf("%d\t", input_arr[i]);
	}
}

void quick_sort (int arr[], int low, int high) {

	int pivot_pos;
	if (low<high) {
		pivot_pos=partition(arr, low, high);
		quick_sort(arr, low, pivot_pos-1);
		quick_sort(arr, pivot_pos+1, high);
	}
}

int partition (int arr[], int low, int high) {

	int pivot=arr[low];
	int leftwall=low;
	int i=0;

	for (i=low+1; i<=high; i++) {
		if (arr[i] < pivot) {
			leftwall=leftwall+1;
			swap(&arr[i], &arr[leftwall]);
		}
	}
	swap(&arr[low], &arr[leftwall]);
	return(leftwall);
}

void swap (int *a, int *b) {

	int temp;

	temp=*a;
	*a=*b;
	*b=temp;
}
