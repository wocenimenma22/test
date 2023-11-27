#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<math.h>
#define MAX_SIZE 100
#define MAX 10

typedef int Element;
//typedef struct treenode {
//	Element value;
//	bool isEmpty;
//}TreeNode;
//定义的两种数的类型，第一种，数组的类型，在test文件里面创建对象的时候，直接TreeNode[n]，n代表这个数组里面的元素的个数
//第二种，链表的类型，一个元素存放多个信息，包括左孩子右孩子，父节点这个地址根据实际情况决定是否要加上
//没有则填入NULL
typedef struct BiTNode {
	Element value;
	struct BiTNode* left, * right;
	struct BiTNode* parent;
}BiTNode,*BiTree;

//这里在BiTree前面加上一个*号的意思是，对这个结构体的指针进行重命名。因为后面要多次用到
//树的指针
//从这里开始
typedef BiTree QDataType;

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

QueneNode* Buynode(QDataType x);
void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);
//到这里，是队列的创建
void inittree(BiTree gen);
void morebranch(BiTree now, Element a);
void PreOrder(BiTree gen);//先序遍历通过递归
int treedeep(BiTree gen);
void MidOrder(BiTree gen);//中序遍历通过递归
void FaiOrder(BiTree gen);//后续遍历通过递归
void level_order(BiTree gen);//层序遍历

void noPreOrder(BiTree gen);//不通过递归的前序遍历
void noMidOrder(BiTree gen);//不通过递归的中序遍历
void noFaiOrder(BiTree gen);//不通过递归的后序遍历


//插入删除初始化，打印测空测满
void Initializes(Stracts* pa);

void StractPush(Stracts* pa, BiTree gen);

void StractPop(Stracts* pa);

bool IsEmpty(Stracts* pa);

bool IsFull(Stracts* pa);

BiTree StractFind(Stracts* pa, int x);

void fanlevel_order(BiTree gen);

int Btdepth(BiTree T);

void judge(BiTree gen);

BiTree PreInCreat(int A[], int B[], int l1, int h1, int l2, int h2);

int  alevel_order(BiTree gen);

void blevel_order(BiTree gen);

void kpre(BiTree gen, int n);

void delpre(BiTree gen, int x);


void freeall(BiTree gen);

void xparent(BiTree gen, int x);

void ownparent(BiTree gen, BiTree r, BiTree p);

void forpraent(BiTree gen, BiTree d, int* arr[]);

void longest(BiTree gen);

BiTree PretoFai(int arr[], int sz);

void printfFai(int arr[], int sz);


void PretoFai2(int arr[], int sz, int* sz2, int arrover[]);

void printfFai2(int arr[], int sz,int arr2[]);