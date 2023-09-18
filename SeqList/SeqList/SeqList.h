#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
/*
//顺序表的静态储存
#define MAX 10 //顺序表数组最大存储个数
*/typedef int SLDataType; //顺序表数据存储类型

//通过上两步设定，使得可以更方便管理顺序表
/*struct SeqList
{
	SLDataType arr[MAX];
	int size;
};*/

//顺序表的动态储存
typedef struct SeqList
{
	SLDataType* a;
	int size; //顺序表内元素个数
	int capacity; //顺序表容量大小
}SL;

//顺序表的接口函数

void SLInit(SL* ps1);//顺序表初始化
void SLPrint(const SL* ps1);//顺序表打印
void SLDestory(SL* ps1);//顺序表销毁

void SLPushFront(SL* ps1, SLDataType x);//顺序表头插
void SLPushBack(SL* ps1, SLDataType x);//顺序表尾插
void SLInsert(SL* ps1, SLDataType x, size_t pos);//顺序表任意下标插入

void SLPopFront(SL* ps1);//顺序表头删
void SLPopBack(SL* ps1);//顺序表尾删
void SLErase(SL* ps1, size_t pos);//顺序表任意下标删除

int SLFind(SL* ps1, SLDataType x);//顺序表查找
