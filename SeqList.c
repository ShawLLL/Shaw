#include "SeqList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

//创建一个静态顺序表
void SeqListInit(SeqListR *pSeq)
{
	assert(pSeq != NULL);

	pSeq->size = 0;
}

void SeqListDestroy(SeqListR *pSeq)
{
	assert(pSeq != NULL);

	pSeq->size = 0;
}
void SeqListPushBack(SeqListR *pSeq, DataType data)
{
	assert(pSeq != NULL);
	if (pSeq->size == MAX_SIZE) {
		printf("满了\n");
		return;
	}

	pSeq->array[pSeq->size] = data;
	pSeq->size += 1;
}

void SeqListPushFront(SeqListR *pSeq, DataType data)
{
	assert(pSeq != NULL);
	if (pSeq->size == MAX_SIZE) {
		printf("满了\n");
		return;
	}

	pSeq->array[0] = data;
	pSeq->size++;
}

void SeqListInsert(SeqListR *pSeq, int pos, DataType data)
{
	assert(pSeq->size < MAX_SIZE);
	assert(pos >= 0 && pos <= pSeq->size);

	for (int i = pSeq->size; i >= pos + 1; i--) {
		pSeq->array[i] = pSeq->array[i - 1];
	}

	pSeq->array[pos] = data;
	pSeq->size += 1;
}

void SeqListPrint(const SeqListR *pSeq)
{
	for (int i = 0; i < pSeq->size; i++) {
		printf("%d ", pSeq->array[i]);
	}
	printf("\n");
}

void SeqListPopBack(SeqListR *pSeq)
{
	assert(pSeq != NULL);	// 传入地址判空
	assert(pSeq->size > 0);	// 顺序表判空

	pSeq->size--;
}

void SeqListPopFront(SeqListR *pSeq)
{
	assert(pSeq != NULL);	
	assert(pSeq->size > 0);	

	for (int i = 0; i <= pSeq->size - 2; i++) {
		pSeq->array[i] = pSeq->array[i + 1];
	}

	pSeq->size--;
}

void SeqListErase(SeqListR *pSeq, int pos)
{
	assert(pSeq != NULL);	
	assert(pSeq->size > 0);	
	assert(pos >= 0 && pos < pSeq->size);	// 不能越界
	for (int i = pos; i <= pSeq->size - 2; i++) {
		pSeq->array[i] = pSeq->array[i + 1];
	}

	pSeq->size--;
}

int SeqListFind(const SeqListR *pSeq, DataType data)
{
	for (int i = 0; i < pSeq->size; i++) {
		if (data == pSeq->array[i]) {
			return i;
		}
	}

	return -1;
}

int SeqListRemove(SeqListR *pSeq, DataType data)
{
	int pos = SeqListFind(pSeq, data);
	if (pos == -1) {
		return -1;
	}

	SeqListErase(pSeq, pos);
}

void SeqListRemoveAll(SeqListR *pSeq, DataType data)
{
	// O(n^2)
	//while (SeqListRemove(pSeq, data) != -1) {};

	int i = 0, j = 0;
	// 新建数组，把不等于 data 的数据 copy 到 extra
	for (; i < pSeq->size; i++) {
		if (pSeq->array[i] != data) {
			pSeq->array[j++] = pSeq->array[i];
		}
	}

	pSeq->size = j;
}


bool SeqListEmpty(const SeqListR *pSeq)
{
	return pSeq->size == 0;
}

bool SeqListFull(const SeqListR *pSeq)
{
	return pSeq->size == MAX_SIZE;
}

int SeqListSize(const SeqListR *pSeq)
{
	return pSeq->size;
}

void Swap(DataType *a, DataType *b)
{
	DataType t = *a;
	*a = *b;
	*b = t;
}
