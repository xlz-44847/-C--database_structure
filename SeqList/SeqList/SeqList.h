#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
/*
//˳���ľ�̬����
#define MAX 10 //˳����������洢����
*/typedef int SLDataType; //˳������ݴ洢����

//ͨ���������趨��ʹ�ÿ��Ը��������˳���
/*struct SeqList
{
	SLDataType arr[MAX];
	int size;
};*/

//˳���Ķ�̬����
typedef struct SeqList
{
	SLDataType* a;
	int size; //˳�����Ԫ�ظ���
	int capacity; //˳���������С
}SL;

//˳���Ľӿں���

void SLInit(SL* ps1);//˳����ʼ��
void SLPrint(const SL* ps1);//˳����ӡ
void SLDestory(SL* ps1);//˳�������

void SLPushFront(SL* ps1, SLDataType x);//˳���ͷ��
void SLPushBack(SL* ps1, SLDataType x);//˳���β��
void SLInsert(SL* ps1, SLDataType x, size_t pos);//˳��������±����

void SLPopFront(SL* ps1);//˳���ͷɾ
void SLPopBack(SL* ps1);//˳���βɾ
void SLErase(SL* ps1, size_t pos);//˳��������±�ɾ��

int SLFind(SL* ps1, SLDataType x);//˳������
