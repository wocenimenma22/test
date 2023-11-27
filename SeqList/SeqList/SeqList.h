#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define	N 1000
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef double SLDataType;
typedef struct Seqlist
{
	SLDataType* a;
	int size;//顺序表现在总共存储的数据的大小
	int capacity;//顺序表的容量
}SL;
void SeqListInit(SL* ps);//初始化数组
void SeqListPushBack(SL* ps, SLDataType x);//尾部插入
void SeqListPopBack(SL* ps);//尾部删除
void SeqListFind(SL* ps);//寻找函数
void SeqListPushFront(SL* ps, SLDataType x);//头部插入
void SeqListPopFront(SL* ps);//头部删除
void SeqListPrint(SL* ps);//打印函数
void SeqListDestory(SL* ps);//销毁内存函数
void SeqListChange(SL* ps);//改变指定位置的函数
void SeqListInsert(SL* ps, int pos, SLDataType x);//指定位置插入函数
void SeqListErase(SL* ps, int pos, SLDataType x);