#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<math.h>
#define MAX 10
typedef char stractdata;
typedef int intstractdata;

typedef struct Stract
{
    stractdata a;
    struct Stract* next;
    struct Stract* prev;
}Stract;
//带有头节点和尾节点的双向链表

typedef struct Stracts
{
    Stract* head;
    Stract* tail;
}Stracts;

typedef struct intStract
{
	intstractdata a;
	struct intStract* next;
	struct intStract* prev;
}intStract;

typedef struct intStracts
{
	intStract* head;
	intStract* tail;
}intStracts;

void intInitializes(intStracts* pa);

void intStractPush(intStracts* pa, intstractdata x);

void intStractPop(intStracts* pa);

bool intIsEmpty(intStracts* pa);

void Initializes(Stracts* pa);

void StractPush(Stracts* pa, stractdata x);

void StractPop(Stracts* pa);

void change(char* middle, char* last);

bool IsEmpty(Stracts* pa);

int caculate(char *last);

int char_to_int(char* last);