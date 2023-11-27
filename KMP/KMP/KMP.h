#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<math.h>

void getnext(char* pattern, int* next, int patternLength);
int compatute(char* mainl, char* cchar, int next[]);