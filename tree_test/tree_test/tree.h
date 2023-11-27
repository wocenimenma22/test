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
//����������������ͣ���һ�֣���������ͣ���test�ļ����洴�������ʱ��ֱ��TreeNode[n]��n����������������Ԫ�صĸ���
//�ڶ��֣���������ͣ�һ��Ԫ�ش�Ŷ����Ϣ�����������Һ��ӣ����ڵ������ַ����ʵ����������Ƿ�Ҫ����
//û��������NULL
typedef struct BiTNode {
	Element value;
	struct BiTNode* left, * right;
	struct BiTNode* parent;
}BiTNode,*BiTree;

//������BiTreeǰ�����һ��*�ŵ���˼�ǣ�������ṹ���ָ���������������Ϊ����Ҫ����õ�
//����ָ��
//�����￪ʼ
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

//ͷβָ�붼�еģ�˫������
//����ջ
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
//������Ƕ��еĴ���
void inittree(BiTree gen);
void morebranch(BiTree now, Element a);
void PreOrder(BiTree gen);//�������ͨ���ݹ�
int treedeep(BiTree gen);
void MidOrder(BiTree gen);//�������ͨ���ݹ�
void FaiOrder(BiTree gen);//��������ͨ���ݹ�
void level_order(BiTree gen);//�������

void noPreOrder(BiTree gen);//��ͨ���ݹ��ǰ�����
void noMidOrder(BiTree gen);//��ͨ���ݹ���������
void noFaiOrder(BiTree gen);//��ͨ���ݹ�ĺ������


//����ɾ����ʼ������ӡ��ղ���
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