#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int LTDataType;
typedef struct ListNode
{
	struct ListNode* prev;
	LTDataType data;
	struct ListNode* next;
}LTNode;

//接口函数

LTNode* ListInit();//链表初始化
void ListPrint(LTNode* phead);//链表打印
void ListDestroy(LTNode* phead);//链表销毁

void ListPushFront(LTNode* phead, LTDataType x);//头插
void ListPushBack(LTNode* phead, LTDataType x);//尾插
void ListPopFront(LTNode* phead);//头删
void ListPopBack(LTNode* phead);//尾删

LTNode* ListFind(LTNode* phead, LTDataType x);//查找
void ListInsert(LTNode* pos, LTDataType x);//任意插入
void ListErase(LTNode* pos);//任意删除