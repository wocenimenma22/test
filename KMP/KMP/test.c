#include "KMP.h"
int main()
{
    char* mainnn = "googlogooglegooglo";
    char* pattern = "ababacb";
    int patternLength = strlen(pattern);
    printf("%d\n", patternLength);
    int b = 4;
    int* next; // ����һ�� int ���͵�ָ�� a
    next = (int*)malloc(patternLength+1 * sizeof(int)); // Ϊ a �����ĸ� int ���͵Ŀռ�
    if (next == NULL) // ����Ƿ����ɹ�
    {
        printf("�ڴ����ʧ��\n");
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
   // free(next); // �ͷ�����ռ�õ��ڴ�
    return 0;
}