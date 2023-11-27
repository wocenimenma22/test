#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<math.h>
#define MAX_SIZE 100
typedef int Element;
typedef struct PTNode {
	Element data;
	int parent;
}PTNode;

typedef struct PRTree {
	PTNode nodes[MAX_SIZE];
	int n;
}PRTree;



//向树里面插入元素；
void inittree(PRTree* nod);
void inpuut(PRTree* nod, int i,int parent,Element a);

void poptree (PRTree* nod, int n);

int task1(PRTree* nod,int i,int j);