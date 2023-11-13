#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int LTDataType;

typedef struct ListNode
{
	LTDataType val;
	struct ListNode* prev;
	struct ListNode* next;
}LTNode;

LTNode* LTInit();
void LTPrint(LTNode* phead);
void LTPushBack(LTNode* phead, LTDataType x);
void LTPushFront(LTNode* phead, LTDataType x);
void LTPopBack(LTNode* phead);
void LTPopFront(LTNode* phead);
LTNode* LTFind(LTNode* phead, LTDataType x);
void LTInsert(LTNode* pos, LTDataType x);
void LTErase(LTNode* pos);
void LTDestroy(LTNode* phead);