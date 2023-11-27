#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//int main()
//{
//    //int n, i, a = 1, b = 1, c;
//    //printf("请输入要计算的斐波那契数列的项数：");
//    //scanf("%d", &n);
//    //printf("斐波那契数列的前%d项为：\n", n);
//    //printf("%d\n%d\n", a, b); //打印第一项和第二项
//    //for (i = 3; i <= n; i++) //从第三项开始循环
//    //{
//    //    c = a + b; //计算当前项为前两项之和
//    //    printf("%d\n", c); //打印当前项
//    //    a = b; //更新前两项的值
//    //    b = c;
//    //}
//
//    int i = 0;
//    for (i = 0; i < 9; ++i)
//    {
//        printf("%d\n", i);
//    }
//    for (i = 0; i < 9; i++)
//    {
//        printf("%d\n", i);
//    }
//    return 0;
//}

//int find(int arr[], int sz)
//{
//	int i = 0;
//	int ret = 0;
//	for (i = 0; i <= sz; i++)
//	{
//		ret ^= i;
//	}
//	for (i = 0; i < sz; i++)
//	{
//		ret ^= arr[i];
//	}
//	return ret;
//}
//
//void zhuazhi(int arr[], int left, int right)
//{
//	int a = 0;
//	while(left<right)
//	{
//		a = arr[right];
//		arr[right] = arr[left];
//		arr[left] = a;
//		left++;
//		right--;
//	}
//}
//
//void zhuanhuan(int *arr, int sz, int k)
//{
//	int rel = k % sz;
//	zhuazhi(arr, 0, k - 1);
//		//先处理左边
//	zhuazhi(arr, k, sz-1);
//	    //再右边
//	zhuazhi(arr, 0, sz-1);
//	    //最后一起
//}
//
//int main()
//{
//	int arr[] = { 3,4,2,0 ,10,2,4};
//	int k = 0;
//	printf("请输入要流转的数:");
//	scanf("%d", &k);
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	zhuanhuan(arr, sz,k);
//	//int a=find(arr, sz);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d   ", arr[i]);
//	}
//	//printf("这个数是%d", a);
//	return 0;
//}

//struct student {
//    int score;
//    char name[];
//};
//
//int main() {
//    // 创建一个指向包含 3 个学生的数组的指针
//    struct student* students[3];
//
//    // 为每个学生分配内存并赋值
//    for (int i = 0; i < 3; i++) {
//        students[i] = malloc(sizeof(struct student) + sizeof(char) * 10);
//    }
//    strcpy(students[0]->name, "张三");
//    students[0]->score = 91;
//    strcpy(students[1]->name, "李四");
//    students[1]->score = 80;
//    strcpy(students[2]->name, "王五");
//    students[2]->score = 85;
//
//    // 打印柔性数组的内容
//    for (int i = 0; i < 3; i++) {
//        printf("姓名：%s，成绩：%d\n", students[i]->name, students[i]->score);
//    }
//
//    // 释放柔性数组的内存
//    for (int i = 0; i < 3; i++) {
//        free(students[i]);
//    }
//
//    return 0;
//}

//struct student {
//	int score;
//	char name[];
//};
//
//int main() 
//{
//	struct student* students = malloc(sizeof(struct student) + 30 * sizeof(char));
//
//	// 直接使用整块内存
//	strcpy(students[0].name, "张三");
//	students->score = 91000;
//
//	strcpy(students[1].name, "李四");
//	students[1].score = 80;
//
//	strcpy(students[2].name, "王五");
//	students[2].score = 85;
//
//	// 打印
//	printf("姓名:%s,成绩:%d\n", students->name, students->score);
//	printf("姓名:%s,成绩:%d\n", students[1].name, students[1].score);
//	printf("姓名:%s,成绩:%d\n", students[2].name, students[2].score);
//
//	// 释放内存
//	free(students);
//
//	return 0;
//}

//int main()
//{
//	char a = 90;
//	printf("%c",a);
//
//	return 0;
//}

int main()
{


		
	return 0;
}