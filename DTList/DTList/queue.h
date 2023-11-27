#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>	
#include<assert.h>
#include<stdbool.h>

//╤сап
typedef int	QDataType;

typedef struct QueneNode
{
	struct QueueNode* next;
	QDataType a;
}QueneNode;

typedef struct Queue
{
	QueneNode* head;
	QueneNode* tail;
}Queue;

QueneNode* Buynode(QDataType x);
void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);
void printttt(Queue* pq);