#include<stdio.h>

void partition(int [], int, int);
void merge(int [], int, int, int);

int main() {

	int input_arr[100], i, n;

	printf("Enter number of input\n");
	scanf("%d", &n);
	
	printf("Enter input array\n");
	for (i=0; i<n; i++) {
		scanf("%d", &input_arr[i]);
	}

	/* Merge algorithm */

	partition(input_arr, 0, n-1);

	printf("The sorted array is :-\n");
	for (i=0; i<n; i++) {
		printf("%d\t", input_arr[i]);
	}
}

void partition(int arr[], int min, int max) {

	int mid;

	if (min<max) {

		mid=(min+max)/2;
		partition(arr, min, mid);
		partition(arr, mid+1, max);
		merge(arr, min, mid, max);
	}
}
void merge(int arr[], int min, int mid, int max) {

	int i, j, k, m;
	int tmp[100];

	j=min;
	m=mid+1;
	for (i=min; j<=mid && m<=max; i++) {
		if (arr[j]<=arr[m]) {
			tmp[i]=arr[j];
			j++;
		} else {
			tmp[i]=arr[m];
			m++;
		}
		
	}
	if (j>mid) {
		for (k=m; k<=max; k++) {
			tmp[i]=arr[k];
			i++;
		}
	} else {
		for (k=j; k<=mid; k++) {
			tmp[i]=arr[k];
			i++;
		}
	}
	for (k=min; k<=max; k++) {
		arr[k]=tmp[k];
	}
}
			
