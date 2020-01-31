#include<iostream>
#include<vector>
using namespace std;
int binarysearch(vector<int> a,int k){
	int len = a.size();
	int left = 0;
	int right = len-1;
	while (left < right){
		int mid = (right-left) / 2+left;
		if (a[mid] > k)right = mid;
		else if (a[mid] < k)left = mid + 1;
		else return mid;
	}
	return -1;
}
int main(){

	vector<int> a = {1,2,3,4,5,6,7};
	int k = 5;
	int n=binarysearch(a,k);
	cout << n << endl;
	system("pause");
	return 0;
}