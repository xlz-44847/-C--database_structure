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

//���������ӿ�

void SListPrint(const SLTNode* phead);//��ӡ������
void SListDestory(SLTNode** pphead);//���ٵ�����

void SListPushFront(SLTNode** pphead, SLTDataType x);//ǰ��
void SListPushBack(SLTNode** pphead, SLTDataType x);//���
void SListPopFront(SLTNode** pphead);//ǰɾ
void SListPopBack(SLTNode** pphead);//��ɾ

void SListInsert(SLTNode** pphead, SLTDataType pos, SLTDataType x);//����λ��ǰ����
void SListInsertAfter(SLTNode** pphead, SLTDataType pos, SLTDataType x);//����λ�ú����
void SListErase(SLTNode** pphead, SLTDataType pos);//����λ��ɾ��
