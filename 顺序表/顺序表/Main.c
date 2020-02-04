#include "SeqList.h"

/*void swap(int a[], int i, int j) {
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}
//冒泡排序
void bubbleSort(int a[], int size){
	for(int i=0;i<size;i++){
		for(int j=0;j<size-i-1;j++){
			if(a[j]>a[j+1]){
				swap(a,j,j+1);
			}
		}
	}
}*/

void testSeqList() {
	// 初始化/销毁
	// 增/删/查/改

	SeqList seqList;	// 没有初始化
	// SeqListInit(seqList); 不用它
	SeqListInit(&seqList);
	// 1. 初始化一定会变更变量的值，值传递没有用
	// 2. 指针比结构体大小要小

	SeqListPushBack(&seqList, 1);
	SeqListPushBack(&seqList, 2);
	SeqListPushBack(&seqList, 3);
	SeqListPushBack(&seqList, 4);

	SeqListPrint(&seqList);	// 1, 2, 3, 4

	SeqListPushFront(&seqList, 10);
	SeqListPushFront(&seqList, 20);
	SeqListPushFront(&seqList, 30);

	SeqListPrint(&seqList);	// 30, 20, 10, 1, 2, 3, 4

	SeqListInsert(&seqList, 3, 100);
	SeqListInsert(&seqList, 2, 200);

	SeqListPrint(&seqList);	// 30, 20, 200, 10, 100, 1, 2, 3, 4

	SeqListPopFront(&seqList);
	SeqListPopFront(&seqList);

	SeqListPrint(&seqList);	// 200, 10, 100, 1, 2, 3, 4

	SeqListPopBack(&seqList);
	SeqListPopBack(&seqList);

	SeqListPrint(&seqList);	// 200, 10, 100, 1, 2

	SeqListErase(&seqList, 1);
	SeqListPrint(&seqList);	// 200, 100, 1, 2

	SeqListDestroy(&seqList);
}

int main() {
	testSeqList();
	
	system("pause");
	return 0;
}