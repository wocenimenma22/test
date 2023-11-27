// contact.h
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<errno.h>
#include <math.h>
#include<ctype.h>
#include<assert.h>
#define max 1000
#define defulat 3
#define incc 2
#define name_max 20
#define sex_max 3
#define number_max 16
#define addresss_max 15
// 定义一个枚举类型 contact_option，用于表示用户的选择
enum contact_option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	PRINT
};

typedef struct people
{
	char name[name_max];
	int age;
	char sex[sex_max];
	char numeber[number_max];
	char address[addresss_max];
}people;
//静态版本
//typedef struct contactt
//{
//	people data[max];
//	int sz;
//}contactt;

//动态版本 
typedef struct contactt
{
	people *data;
	int sz;
	int capacity;//通讯录当前最大的容量
}contactt;
// 其他函数的声明
void addcon(contactt* pc);
void delcon(contactt* pc);
int findd(contactt* pc,char* name);
void seacon(contactt* pc);
void modcon(contactt*pc);
void sorcon(contactt*pc);
void pricon(contactt* pc);
void begincon(contactt*pc);
void connnn(contactt* pc);
void readcon(contactt* pc);
void zengrong(contactt* pc);