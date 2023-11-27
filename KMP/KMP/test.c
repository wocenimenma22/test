#include "KMP.h"
int main()
{
    char* mainnn = "googlogooglegooglo";
    char* pattern = "ababacb";
    int patternLength = strlen(pattern);
    printf("%d\n", patternLength);
    int b = 4;
    int* next; // 定义一个 int 类型的指针 a
    next = (int*)malloc(patternLength+1 * sizeof(int)); // 为 a 分配四个 int 类型的空间
    if (next == NULL) // 检查是否分配成功
    {
        printf("内存分配失败\n");
        return -1;
    }
    getnext(pattern, next, patternLength);
    int i = 0;
    for (i = 0; i < patternLength; i++)
    {
        printf("%d\n", next[i]);
    }
    //int a=compatute(mainnn, pattern, next);
    //printf("%d", a);
   // free(next); // 释放数组占用的内存
    return 0;
}