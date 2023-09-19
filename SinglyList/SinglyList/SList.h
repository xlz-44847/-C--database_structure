#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

//单链表函数接口

void SListPrint(const SLTNode* phead);//打印单链表
void SListDestory(SLTNode** pphead);//销毁单链表

void SListPushFront(SLTNode** pphead, SLTDataType x);//前插
void SListPushBack(SLTNode** pphead, SLTDataType x);//后插
void SListPopFront(SLTNode** pphead);//前删
void SListPopBack(SLTNode** pphead);//后删

void SListInsert(SLTNode** pphead, SLTDataType pos, SLTDataType x);//任意位置前插入
void SListInsertAfter(SLTNode** pphead, SLTDataType pos, SLTDataType x);//任意位置后插入
void SListErase(SLTNode** pphead, SLTDataType pos);//任意位置删除
