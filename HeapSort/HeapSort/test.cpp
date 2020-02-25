#include<iostream>
using namespace std;

//堆化：使一个元素符合堆的要求
void heapify(int a[], int size, int index){
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	int max;
	if (left > size||right>size){
		return;
	}
	max = a[left] >= a[right] ? left : right;
	if (a[index] >= a[max]){
		return;
	}
	else{
		swap(a[index], a[max]);
		heapify(a, size, max);

	}

}
//建堆
void creatHeap(int a[], int size){
	for (int i = (size / 2)-1; i >= 0; i--){
		heapify(a, size, i);
	}
	return;
}

//堆排序
void HeapSort(int a[], int size){
	creatHeap(a, size);
	for (int i = size-1; i >= 0; i--){
		swap(a[0], a[i]);
		heapify(a, i - 1, 0);
	}
}
int main(){
	int a[] = { 8, 3, 12, 7, 5, 25, 94, 33 };
	int len = sizeof(a) / sizeof(int);
	for (auto &e : a){
		cout << e << " ";
	}
	cout << endl;
	HeapSort(a, len);
	for (auto &e : a){
		cout << e << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
