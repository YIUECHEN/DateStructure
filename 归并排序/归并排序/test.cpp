#include<stdio.h>
  
void merge(int a[],int left,int mid,int right,int n){
	int *temp = new int[n];

	int i = left;
	int j = mid + 1;
	int k = 0;
	while (i <= mid&&j <= right){
		if (a[i] <= a[j]){
			temp[k++] = a[i++];
		}
		else{
			temp[k++] = a[j++];
		}
	}
	while (i <= mid){
		temp[k++] = a[i++];
	}
	while (j <= right){
		temp[k++] = a[j++];
	}
	for (i = left, k = 0; i <= right; k++,i++){
		a[i] = temp[k];
	}
	delete[] temp;
}
void mergesort(int a[],int left,int right){
	if (left >= right){
		return;
	}

	int mid = left + (right - left) / 2;

	mergesort(a, left, mid);
	mergesort(a, mid + 1, right);
	merge(a, left, mid, right, right - left + 1);
}

int main(){

	int a[] = { 2, 5, 4, 1, 8, 5, 7, 9, 6 };
	int n = sizeof(a) / sizeof(int);
	int left = 0;
	int right = n - 1;
	mergesort(a, left, right);
	for (int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	return 0;
}