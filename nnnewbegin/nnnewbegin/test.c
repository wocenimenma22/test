#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>

//int main() {
//    char ch[100];
//d
//    printf("������һ���ַ���: ");
//    scanf("%s", ch);
//
//    printf("������ַ�����: %s\n", ch);
//
//    return 0;
//}
void accessStringElement(char* str, int i) {
    char element = str[i];
    printf("Element at index %d: %c\n", i, element);
}

int main() {
    char ch[100] = "1+2+3+4";
    accessStringElement(ch, 4); // Accessing the 3rd element (index 2)
    return 0;
}