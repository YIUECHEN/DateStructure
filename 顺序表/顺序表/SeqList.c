#include "SeqList.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define DEFAULT_CAPACITY (16)


static void ensureCapacity(SeqList *seq) {
	if (seq->size < seq->capacity) {
		// 容量够用
		return;
	}

	// 1. 找新房子
	// 通常来说，新申请的房子是原来的 1.5 或者 2 倍
	int newCapacity = 2 * seq->capacity;
	int *newArray = (int *)malloc(sizeof(int)* newCapacity);
	
	for (int i = 0; i < seq->size; i++) {
		newArray[i] = seq->array[i];
	}

	free(seq->array);

	seq->array = newArray;
}

// 初始化
// O(1)
void SeqListInit(SeqList *seq) {

	seq->array = (int *)malloc(sizeof(int)* DEFAULT_CAPACITY);
	seq->capacity = DEFAULT_CAPACITY;
	seq->size = 0;
}

// 销毁

void SeqListDestroy(SeqList *seq) {
	free(seq->array);
	// 下面的属于可加可不加
	seq->capacity = 0;
	seq->size = 0;
}

// 头插

void SeqListPushFront(SeqList *seq, int val) {
	/*
	for (int i = seq->size - 1; i >= 0; i--) {
		seq->array[i + 1] = seq->array[i];
	}

	seq->array[0] = val;
	seq->size++;
	*/
	SeqListInsert(seq, 0, val);
}
// 尾插

void SeqListPushBack(SeqList *seq, int val) {
	// 先不考虑放不下的问题
#if 0
	seq->array[seq->size] = val;
	seq->size++;
#endif
	SeqListInsert(seq, seq->size, val);
}

// O(n)	头插
void SeqListInsert(SeqList *seq, int index, int val) {
	if (index < 0 || index > seq->size) {
		printf("Errors！");
		return;
	}

	ensureCapacity(seq);

	for (int i = seq->size; i > index; i--) {
		seq->array[i] = seq->array[i - 1];
	}

	seq->array[index] = val;
	seq->size++;
}

// 头删
void SeqListPopFront(SeqList *seq) {
	assert(seq->size > 0);
	for (int i = 0; i <= seq->size - 2; i++) {
		seq->array[i] = seq->array[i + 1];
	}
	seq->size--;
}

// 尾删
void SeqListPopBack(SeqList *seq) {
	// 函数调用合法性的校验
	assert(seq->size > 0);
	seq->size--;
}

// 根据下标做删除
void SeqListErase(SeqList *seq, int index) {
	assert(seq->size > 0);

	for (int i = index; i <= seq->size - 2; i++) {
		seq->array[i] = seq->array[i + 1];
	}

	seq->size--;
}

// 打印
void SeqListPrint(SeqList *seq) {
	for (int i = 0; i < seq->size; i++) {
		printf("%d, ", seq->array[i]);
	}
	printf("\n");
}

int SeqListFind(SeqList *seq, int val) {
	for (int i = 0; i < seq->size; i++) {
		if (seq->array[i] == val) {
			return i;
		}
	}
	return -1;
}