#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define	N 1000
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef double SLDataType;
typedef struct Seqlist
{
	SLDataType* a;
	int size;//˳��������ܹ��洢�����ݵĴ�С
	int capacity;//˳��������
}SL;
void SeqListInit(SL* ps);//��ʼ������
void SeqListPushBack(SL* ps, SLDataType x);//β������
void SeqListPopBack(SL* ps);//β��ɾ��
void SeqListFind(SL* ps);//Ѱ�Һ���
void SeqListPushFront(SL* ps, SLDataType x);//ͷ������
void SeqListPopFront(SL* ps);//ͷ��ɾ��
void SeqListPrint(SL* ps);//��ӡ����
void SeqListDestory(SL* ps);//�����ڴ溯��
void SeqListChange(SL* ps);//�ı�ָ��λ�õĺ���
void SeqListInsert(SL* ps, int pos, SLDataType x);//ָ��λ�ò��뺯��
void SeqListErase(SL* ps, int pos, SLDataType x);