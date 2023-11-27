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
	int adjvex;                 //��������ָ��Ķ����λ��
	struct ArcNode* next;       //ָ����һ������ָ��
	InfoType info;              //����Ȩֵ
}ArcNode;                       //�߱���

typedef struct VNode{           //�������
	VertexType data;            //�������Ϣ�����������Ϣ������
	ArcNode* first;             //�����ָ��ĵ�һ����
}VNode,AdjList[MaxVertexNum];   //����Ľṹ

typedef struct ALGraph{         //
	AdjList vertices;           //�ڽӱ�
	int vexnum, arcnum;         //ͼ�Ķ������ͻ�����
}ALGraph;                       //���ٽ��洢��ͼ���͵Ľṹ



//AdjList�Ǵ洢����ͼ�����ÿ�������Ԫ�أ����ŵ�first�����Ⱥ������ӵĵ�һ���ߣ�Ȼ��
//���뵽arcnode�������adjvex���������ָ��Ķ����Ԫ���������е�λ�ã�arcnode *next��ָ����һ��Ԫ�ص�
//����һ���ߵ�Ԫ��