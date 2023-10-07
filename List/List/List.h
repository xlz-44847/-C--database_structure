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

//�ӿں���

LTNode* ListInit();//�����ʼ��
void ListPrint(LTNode* phead);//�����ӡ
void ListDestroy(LTNode* phead);//��������

void ListPushFront(LTNode* phead, LTDataType x);//ͷ��
void ListPushBack(LTNode* phead, LTDataType x);//β��
void ListPopFront(LTNode* phead);//ͷɾ
void ListPopBack(LTNode* phead);//βɾ

LTNode* ListFind(LTNode* phead, LTDataType x);//����
void ListInsert(LTNode* pos, LTDataType x);//�������
void ListErase(LTNode* pos);//����ɾ��