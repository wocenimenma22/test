#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>	
#include<assert.h>
#include<stdbool.h>
#define MAX 10;
typedef int stractdata;
//头尾指针都有的，双向链表
//这是栈
typedef struct Stract
{
	stractdata a;
	struct Stract* next;
	struct Stract* prev;
}Stract;

typedef struct Stracts
{
	Stract* head;
	Stract* tail;
}Stracts;
//插入删除初始化，打印测空测满
void Initializes(Stracts* pa);

void StractPush(Stracts* pa, stractdata x);//头插

void StractPop(Stracts* pa);//头删

bool IsEmpty(Stracts* pa);

bool IsFull(Stracts* pa);

stractdata StractFind(Stracts* pa, int x);

void print(Stracts* pa);