#include<iostream>
#include<vector>
using namespace std;

vector<int> BubbleSprt(vector<int> arr){
	for (int i = 0; i < arr.size(); i++){
		for (int j = 0; j<arr.size()-i-1; j++){
			if (arr[j]>arr[j+1]){
				swap(arr[j], arr[j+1]);
			}
		}
	}
	return arr;
}
int main(){
	vector<int> arr = { 9,5,2,7,3,6,4,8,5};
	vector<int> v=BubbleSprt(arr);
	for (auto e : v){
		cout << e << endl;
	}
	system("pause");
	return 0;
}