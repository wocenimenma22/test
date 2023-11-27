#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>	
#include<assert.h>
#include<stdbool.h>
#define MAX 10
typedef int queuedata;
typedef struct Queuenode//���Ǹ�����
{
	queuedata data[MAX];
	int front;
	int tail;
}SqQueue;
//����ɾ����ʼ������ղ�����ӡ
void print(SqQueue* a);
void InitQueue(SqQueue* a);
void QueuePush(SqQueue* a,queuedata x);
void QueuePop(SqQueue* a);
bool IsFull(SqQueue* a);
bool IsEmpty(SqQueue* a);