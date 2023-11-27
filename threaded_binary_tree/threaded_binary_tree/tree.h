#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<math.h>
#define MAX 10

typedef int Element;
typedef int Pointertag;
typedef struct BiTNode {
	Element value;
	struct BiTNode* left, * right;
	struct BiTNode* parent;
	Pointertag ltag;
	Pointertag rtag;

}BiTNode, * BiTree;
//头尾指针都有的，双向链表
//这是栈
typedef struct Stract
{
	BiTree a;
	struct Stract* next;
	struct Stract* prev;
}Stract;

typedef struct Stracts
{
	Stract* head;
	Stract* tail;
}Stracts;	
void inittree(BiTree gen);
void morebranch(BiTree now, Element a);
void midthreaded(BiTree p);
void ordthreaded(BiTree p);
void faithreaded(BiTree p);
void real_mid(BiTree p);
void real_ord(BiTree p);
void real_fai(BiTree p);
BiTree first(BiTree p);
BiTree next(BiTree p);
void midrun(BiTree p);
void ordrun(BiTree p);
void fairun(BiTree p);
void nofaithread(BiTree p);

void Initializes(Stracts* pa);

void StractPush(Stracts* pa, BiTree gen);

void StractPop(Stracts* pa);

bool IsEmpty(Stracts* pa);

bool IsFull(Stracts* pa);