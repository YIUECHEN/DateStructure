#include "SeqList.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define DEFAULT_CAPACITY (16)


static void ensureCapacity(SeqList *seq) {
	if (seq->size < seq->capacity) {
		// ��������
		return;
	}

	// 1. ���·���
	// ͨ����˵��������ķ�����ԭ���� 1.5 ���� 2 ��
	int newCapacity = 2 * seq->capacity;
	int *newArray = (int *)malloc(sizeof(int)* newCapacity);
	
	for (int i = 0; i < seq->size; i++) {
		newArray[i] = seq->array[i];
	}

	free(seq->array);

	seq->array = newArray;
}

// ��ʼ��
// O(1)
void SeqListInit(SeqList *seq) {

	seq->array = (int *)malloc(sizeof(int)* DEFAULT_CAPACITY);
	seq->capacity = DEFAULT_CAPACITY;
	seq->size = 0;
}

// ����

void SeqListDestroy(SeqList *seq) {
	free(seq->array);
	// ��������ڿɼӿɲ���
	seq->capacity = 0;
	seq->size = 0;
}

// ͷ��

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
// β��

void SeqListPushBack(SeqList *seq, int val) {
	// �Ȳ����ǷŲ��µ�����
#if 0
	seq->array[seq->size] = val;
	seq->size++;
#endif
	SeqListInsert(seq, seq->size, val);
}

// O(n)	ͷ��
void SeqListInsert(SeqList *seq, int index, int val) {
	if (index < 0 || index > seq->size) {
		printf("Errors��");
		return;
	}

	ensureCapacity(seq);

	for (int i = seq->size; i > index; i--) {
		seq->array[i] = seq->array[i - 1];
	}

	seq->array[index] = val;
	seq->size++;
}

// ͷɾ
void SeqListPopFront(SeqList *seq) {
	assert(seq->size > 0);
	for (int i = 0; i <= seq->size - 2; i++) {
		seq->array[i] = seq->array[i + 1];
	}
	seq->size--;
}

// βɾ
void SeqListPopBack(SeqList *seq) {
	// �������úϷ��Ե�У��
	assert(seq->size > 0);
	seq->size--;
}

// �����±���ɾ��
void SeqListErase(SeqList *seq, int index) {
	assert(seq->size > 0);

	for (int i = index; i <= seq->size - 2; i++) {
		seq->array[i] = seq->array[i + 1];
	}

	seq->size--;
}

// ��ӡ
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