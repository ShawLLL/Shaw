#pragma once
#include<stdio.h>
#include <stdbool.h>
typedef int DataType;
#define MAX_SIZE (100)
typedef struct SeqList {
	DataType	array[MAX_SIZE];
	int			size;		// 表示数组有效个数的数量						
                  // 下一个可用空间的下标
}	SeqListR;
// 初始化/销毁
void SeqListInit(SeqListR *pSeq);
void SeqListDestroy(SeqListR *pSeq);

// 增/删/改/查
void SeqListPushBack(SeqListR *pSeq, DataType data);
void SeqListPushFront(SeqListR *pSeq, DataType data);
void SeqListInsert(SeqListR *pSeq, int pos, DataType data);

// 删 （根据下标做删除）
void SeqListPopBack(SeqListR *pSeq);
void SeqListPopFront(SeqListR *pSeq);
void SeqListErase(SeqListR *pSeq, int pos);

// 删	（根据数据做删除）
// 删除第一个遇到的 data，如果删除了，返回 0，否则返回 -1
int SeqListRemove(SeqListR *pSeq, DataType data);

// 删除遇到的所有 data
void SeqListRemoveAll(SeqListR *pSeq, DataType data);


// 找到第一个遇到，如果找到了，就返回下标，如果没找到，返回 -1
int SeqListFind(const SeqListR *pSeq, DataType data);

// 查看属性
bool SeqListEmpty(const SeqListR *pSeq);
bool SeqListFull(const SeqListR *pSeq);
int SeqListSize(const SeqListR *pSeq);

// 打印
void SeqListPrint(const SeqListR *pSeq);	// 不变
