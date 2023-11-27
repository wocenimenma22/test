#pragma once
#pragma once
#define ROW 9
#define COL 9
#define geshu 10
#define ROWS 11
#define COLS 11
#define _CRT_SECURE_NO_WARNINGS
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
void chushihua(char str[ROWS][COLS], int rows, int cols, char sets);
void display(char str[ROWS][COLS], int rows, int cols);
void buzhi(char str[ROWS][COLS], int rows, int cols, int cishu);
void saolei(char show[ROWS][COLS], char mine[ROWS][COLS], int rows, int cols, int cishu);