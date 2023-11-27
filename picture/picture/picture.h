#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<math.h>
#define MaxVertexNum 100


//
typedef int InfoType;
typedef int VertexType;
typedef struct ArcNode {
	int adjvex;                 //这条弧所指向的顶点的位置
	struct ArcNode* next;       //指向下一条弧的指针
	InfoType info;              //网的权值
}ArcNode;                       //边表结点

typedef struct VNode{           //顶点表结点
	VertexType data;            //顶点的信息，所储存的信息的内容
	ArcNode* first;             //顶点的指向的第一条边
}VNode,AdjList[MaxVertexNum];   //顶点的结构

typedef struct ALGraph{         //
	AdjList vertices;           //邻接表
	int vexnum, arcnum;         //图的顶点数和弧的数
}ALGraph;                       //以临界表存储的图类型的结构



//AdjList是存储整个图里面的每个顶点的元素，跟着的first是首先和他连接的第一个边，然后
//进入到arcnode，里面的adjvex是这个边所指向的顶点的元素在数组中的位置，arcnode *next是指向上一个元素的
//另外一条边的元素