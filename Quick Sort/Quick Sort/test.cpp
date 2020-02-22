#include<iostream>
#include<vector>
using namespace std;
void QuickSort(int v[], int l, int r){
	if (l < r){
		int i = l, j = r, pivot = v[l];
		while (i < j){
			while (i<j&&v[j]>=pivot){
				j--;
			}
			if (i < j){
				v[i++] = v[j];
			}
			
			while (i < j&&v[i] < pivot){
				i++;
			}
			if (i < j){
				v[j--] = v[i];
			}
		}
		v[i] = pivot;
		QuickSort(v, l, i - 1);
		QuickSort(v, i + 1, r);
	}
}



int main(){
	int v[] = { 4, 2, 6, 8, 3, 9, 1, 6, 5 };
	for (auto e : v){
		cout << e << " ";
	}
	cout << endl;
	int len = sizeof(v) / sizeof(int);
	QuickSort(v, 0, len - 1);
	for (auto e : v){
		cout << e <<" ";
	}
	cout << endl;
	system("pause");
	return 0;

}
