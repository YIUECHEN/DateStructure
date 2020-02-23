#include<iostream>
using namespace std;

void heapify(int a[], int size, int index){
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	int max;
	if (left > size||right>size){
		return;
	}
	max = a[left] > a[right] ? left : right;
	if (a[index] > a[max]){
		return;
	}
	else{
		swap(a[index], a[max]);
	}
	heapify(a, size, max);
}

void creatHeap(int a[], int size){
	for (int i = (size - 2) / 2; i >= 0; i--){
		heapify(a, size, i);
	}
	return;
}

void HeapSort(int a[], int size){
	creatHeap(a, size);
	for (int i = size; i >= 0; i--){
		swap(a[0], a[i]);
		heapify(a, i - 1, 0);
	}
}
int main(){
	int a[] = { 8, 3, 12, 7, 5, 25, 94, 33 ,44};
	int len = sizeof(a) / sizeof(int);
	HeapSort(a, len);
	for (auto e : a){
		cout << e << " ";
	}
	system("pause");
	return 0;
}
