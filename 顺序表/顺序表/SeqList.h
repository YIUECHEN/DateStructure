#pragma once	      // ��֤ͷ�ļ�ֻ����һ��

struct SeqList{
	int* array;      //��¼���ݴ�ŵ�λ��
	int capacity;    //��¼������
	int size;        //��¼�������ݸ���
};

//Ϊ������һ������
typedef struct SeqList SeqList;

//��ʼ��
void SeqListInit(SeqList *seq);

//����
void SeqListDestroy(SeqList *seq);

//ͷ��
void SeqListPushFront(SeqList *seq, int val);

//β��
void SeqListPushBack(SeqList *seq, int val);

//�����±�������
void SeqListInsert(SeqList *seq, int index, int val);

//ͷɾ
void SeqListPopFront(SeqList *seq);

// βɾ
void SeqListPopBack(SeqList *seq);

// �����±���ɾ��
void SeqListErase(SeqList *seq, int index);

// ����
int SeqListFind(SeqList *seq, int val);

// ��ӡ
void SeqListPrint(SeqList *seq);