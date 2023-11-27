#define _CRT_SECURE_NO_WARNINGS
#include<time.h>
#include<string.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<ctype.h>
#include<assert.h>
#include <math.h>
//int main()
//{
//	int a = 1;
//	char* p = (char*)&a;
//	//这里的（char*）表示的是强制转化成为char的指针类型
//	if (*p == 1)
//	{
//		printf("小端 \n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//
//	return 0;
//}  



//int main()
//{
//	char a = -1;
//	//-1的补码形式是
//	//111111111111111111
//	//只能取八位数字，取到的是11111111
//	//转成十进制数字就是-1
//
//	signed char b = -1;
//	//signed int就是int
//	//signed int同理
//	unsigned char c = -1;
//
//	//补码是11111111111
//	//整型提升，这里面没有符号位
//	//整型提升的时候，没有符号
//	//那么补完的结果是
//	//0000000000  0111111111
//	//8个1的十进制数字的大小就是255
//
//	printf("a=%d,b=%d,c=%d", a, b, c);
//	return 0;
//}

//int main()
//{
//	char a = -128;
//	printf("%u\n", a);
//	//%u表示的是打印的是无符号的数
//	//原因是
//	// 原码是1000000000000000001000000
//	//补码是1111111111111111000000
//	//七个0
//	//取舍
//	//10000000
//	//整型提升，无符号整型
//	//前面全部补充1
//	//11111111111111110000
//	//最后就是11111111后面七个0
//	//而且这时候的首位的1不表示符号
//	return 0;
//}



//char类型变量的取值范围一般的规定是[-128.127]
//假设已经给了char类型的变量
//10000000直接会被解析成为-128
//可以放进去128，但是会超越极限
//通过二进制数，转化为负数
//二进制的基础上加一


//
//int main()
//{
//	int i = -20;
//	unsigned int j = 10;
//	printf("%d\n", i + j);
//	//内存里全部都是补码
//	//补码和补码运算得到补码
//	//符号位不变，其他按未取反
//	//%d是按照有符号数打印的
//	return 0;
//}

//
//int main()
//{
//	unsigned int i = 1;
//	for (i = 9; i >= 0; i--)
//	{
//		printf("%u\n", i);
//
//	}
//	//调试一下再用二进制位手算一下就知道是什么东西了
//	return 0;
//}


//int main()
//{
//	char a[1000];
//	int i;
//	for (i = 0; i < 100; i++)
//	{
//		a[i] = -1 - i;
//	}
//	printf("%d", strlen(a));
//	return 0;
//}
//unsigned char i = 0;
//int main()
//{
//	for (i = 0; i <= 255; i++)
//	{
//		printf("%hello world\n");
//	}
//	//死循环代码
//	return 0;
//}



//int main()
//{
//	int n = 9;
//
//	float* pFloat = (float*)&n;
//
//	printf("n的值为：%d\n", n);
//
//	printf("*pFloat的值为：%f\n", *pFloat);
//
//	*pFloat = 9.0;
//	printf("num的值为：%d\n", n);
//
//	printf("*pFloat的值为：%f\n", *pFloat);
//
//	return 0;
//}


//int main()
//{
//	char* ps = "hello world";
//	char arr[] = "hello world";
//	printf("%c\n", *ps);
//	printf("%s\n", ps);
//	printf("%s\n", arr);
//	return 0;
//}

//int main()
//{
//	char str1[] = "hello world.";
//	char str2[] = "hello world.";
//	char* str3 = "hello world.";
//	char* str4 = "hello world.";
//	if (str1 == str2)
//	{
//		printf("str1 = str2\n");
//	}
//	else
//	{
//		printf("str1 !=str2\n");
//	}
//	if (str3 == str4)
//	{
//		printf("str3 = str4\n");
//	}
//	else
//	{
//		printf("str3 !=str4\n");
//	}
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int* arr[3] = {&a,&b,&c};
//	return 0;
//}//指针数组


//
//int main()
//{
//	//double* d[5];
//	//double*(*pd)[5]=&d;
//	//注意这里对指针数组取指针的时候的操作
//	//是*（*pd）   一般的*是跟随后面的命名的
//	int arr[10] = { 0 };
//	int* p = arr;
//	int(*p2)[10] = &arr;
//	printf("%p\n", arr);
//	printf("%p\n", &arr);
//	return 0;
//}


//int main()
//{
//	int j = 0, i = 0, shu = 0, sn = 0, geshu = 0;
//	scanf("%d %d", &shu, &geshu);
//	for (i = 1; i <= geshu; i++)
//	{
//		int b = 0;
//		for (j = 1; j <= i;j++ )
//		{
//			b = b + shu * pow(10, j - 1);
//		}
//		sn = sn + b;
//	}
//	printf("%d", sn);
//	return 0;
//}


//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 100000; i++)
//	{
//		int ret = 0;
//		int j = 0;
//		int shu = i;
//		int n = log10(i) + 1;
//		for (j = 0; j < n; j++)
//		{
//			int c = shu % 10;
//			shu = shu / 10;
//			int plus = pow(c, n);
//			ret = ret + plus;
//		}
//
//		if (ret == i)
//		{
//			printf("%d是水仙花数\n",ret);
//		}
//	}
//	return 0;
//}
//
//void bubble(int* arr, int sz)
//{
//	int a = 0;
//	for (a = 0; a < sz; a++)
//	{
//		int b = 0;
//		while (arr[b] > arr[b + 1])
//		{
//			int tmp = arr[b];
//			arr[b] = arr[b + 1];
//			arr[b + 1] = tmp;
//			b++;
//			if (b >= sz-1)
//			{
//				break;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int i = 0;
//	int arr[] = { 9,8,7,6,5,4,3,2,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble(arr, sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d\n", arr[i]);
//	}
//
//	return 0;
//}
//void zhuanhuan(int arr[], int sz)
//{
//	int i = 0, j = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		for (j = 0; j < sz - i - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//			else
//			{
//				continue;
//			}
//
//		}
//
//	}
//}
//
//void print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//
//		printf("%d ", arr[i]);
//
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr[10] = {7,5,9,3,6,0,1,3,4,8};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	zhuanhuan(arr, sz);
//	print(arr, sz);
//
//	return 0;
//}



//
//struct Stu
//{
//	char name[20];
//	int age;
//};
//
//int sort_by_age(const void* e1, const void* e2)
//{
//	return((struct Stu*)e1)->age -( (struct Stu*)e2)->age;
//}
//
//int sort_by_name(const void* e1, const void* e2)
//{
//	return((struct Stu*)e1)->name - ((struct Stu*)e2)->name;
//}
//
//void test2()
//{
//	struct Stu s[3] = { {"zhangsan",30} ,{"lisi",34},{"wangwu",20} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	//按照名利来查询
//	//qsort(s, sz, sizeof(s[0]), sort_by_name);
//	//按照学号来进行查询
//	qsort(s, sz, sizeof(s[0]), sort_by_age);
//}
//
//int main()
//{
//
//	/*test1();*/
//
//	test2();
//
//	return 0;
//}

//int main() {
//    char* names[] = { "Alice", "Bob", "Charlie", "David", "Eve", "Frank" };
//    int n = sizeof(names) / sizeof(names[0]); // 计算数组中元素的个数
//    int i;
//
//    printf("Before sorting:\n");
//    for (i = 0; i < n; i++) {
//        printf("%s\n", names[i]);
//    }
//
//    qsort(names, n, sizeof(char*), strcmp); // 调用qsort函数对字符串数组进行排序
//
//    printf("\nAfter sorting:\n");
//    for (i = 0; i < n; i++) {
//        printf("%s\n", names[i]);
//    }
//    return(0);
//}


//
//void Swap(char* buf1, char* buf2, int width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char tmp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = tmp;
//		buf1++, buf2++;
//	}
//}
//int main()
//{
//	int buf1 = 8;
//	int buf2 = 10;
//	Swap((char*)buf1, (char*)buf2,4);
//	printf("%d", &buf1);
//
//}
//void Swap(int* buf1, int* buf2)
//{
//	int tmp = *buf1;
//	*buf1 = *buf2;
//	*buf2 = tmp;
//}
//int main()
//{
//	int buf1 = 8;
//	int buf2 = 10;
//	Swap(&buf1, &buf2,4);
//	printf("buf1 = % d, buf2 = % d\n", buf1, buf2);
//	return 0;
//}

//
//#include <stdio.h>
//
//int fibonacci(int n) {
//    int a = 0;
//    int b = 1;
//    int temp;
//
//    if (n == 0)
//        return a;
//    else if (n == 1)
//        return b;
//
//    for (int i = 2; i <= n; i++) {
//        temp = a + b;
//        a = b;
//        b = temp;
//    }
//
//    return b;
//}
//
//int main() {
//    int n;
//    printf("请输入要计算的斐波那契数列项数：");
//    scanf("%d", &n);
//
//    printf("第%d项的斐波那契数列值为：%d\n", n, fibonacci(n));
//
//    return 0;
//}
//
//struct Stu
//{
//	char name[20];
//	int age;
//};
//
//int sort_by_age(const void* e1, const void* e2)
//{
//	return((struct Stu*)e1)->age -( (struct Stu*)e2)->age;
//}
//
//int sort_by_name(const void* e1, const void* e2)
//{
//	return((struct Stu*)e1)->name - ((struct Stu*)e2)->name;
//}
//
//
//void Swap(char* buf1, char* buf2, int width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//
//		char tmp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = tmp;
//		buf1++;
//		buf2++;
//	}
//}
//int cmp(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//
//
//void bubble_sort(void* base, 
//				int sz,	
//				int width,	
//				int(*cmp)(const void* e1, const void* e2))
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
//			{
//				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//			}
//		}
//	}
//}
//
//void test2()
//{
//	struct Stu s[3] = { {"zhangsan",30} ,{"lisi",34},{"wangwu",20} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	//按照名利来查询
//	//bubble_sort(s, sz, sizeof(s[0]), sort_by_name);
//	//按照学号来进行查询
//	bubble_sort(s, sz, sizeof(s[0]), sort_by_age);
//	//添加以下代码
//	int i;
//	for (i = 0; i < sz; i++)
//	{
//		printf("name: %s, age: %d\n", s[i].name, s[i].age);
//	}
//}
//
//
//void test3()
//{
//	int arr[] = {1,26,7,8,9,10};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz, sizeof(arr[0]), cmp);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d  ", arr[i]);
////	}
////}
////int main()
////{
////	test2();
////	//test3();
////	return 0;
////}
//
//
//int main()
//{
//	//int a[] = { 1,2,3,4 };
//	//printf("%d\n", sizeof(a));
//	//printf("%d\n", sizeof(a+0));
//	//printf("%d\n", sizeof(*a));
//	//printf("%d\n", sizeof(a + 1));
//	//printf("%d\n", sizeof(a[1]));
//	//printf("\n");
//	//printf("%d\n", sizeof(&a));
//	//printf("%d\n", sizeof(*&a));
//	//printf("%d\n", sizeof(&a+1));
//	//printf("%d\n", sizeof(&a[0]));
//	//printf("%d\n", sizeof(&a[0]+1));
//
//	/*char arr[] = { 'a','b','c','d','e'};
//	printf("%d\n", sizeof(arr));
//	printf("%d\n", sizeof(arr + 0));
//	printf("%d\n", sizeof(*arr));
//	printf("%d\n", sizeof(arr + 1));
//	printf("%d\n", sizeof(arr[1]));
//	printf("\n");
//	printf("%d\n", sizeof(&arr));
//	printf("%d\n", sizeof(*&arr));
//	printf("%d\n", sizeof(&arr + 1));
//	printf("%d\n", sizeof(&arr[0]));
//	printf("%d\n", sizeof(&arr[0] + 1));*/
//
//	//char arr[] = "abcdef";
//	//printf("%d\n", sizeof(arr));
//	//printf("%d\n", sizeof(arr + 0));
//	//printf("%d\n", sizeof(*arr));
//	//printf("%d\n", sizeof(arr + 1));
//	//printf("%d\n", sizeof(arr[1]));
//	//printf("\n");
//	//printf("%d\n", sizeof(&arr));
//	//printf("%d\n", sizeof(*&arr));
//	//printf("%d\n", sizeof(&arr + 1));
//	//printf("%d\n", sizeof(&arr[0]));
//	//printf("%d\n", sizeof(&arr[0] + 1));
//
//	//char arr[] = { 'a','b','c','d','e' };
//	//printf("%d\n", strlen(arr));
//	//printf("%d\n", strlen(arr + 0));
//	///*printf("%d\n", strlen(*arr));
//	//printf("%d\n", strlen(arr[1]));*/
//	////这两个是错误的，剩下的是有关联的随机值
//	//printf("\n");
//	//printf("%d\n", strlen(&arr));
//	//printf("%d\n", strlen(&arr + 1));
//	//printf("%d\n", strlen(&arr[0] + 1));
//
//	//char arr[] = "abcdef";
//	//printf("%d\n", strlen(arr));
//	//printf("%d\n", strlen(arr + 0));
//	////printf("%d\n", strlen(*arr));
//	////printf("%d\n", strlen(arr[1]));
//	////这两个是错误的，剩下的是有关联的随机值
//	//printf("\n");
//	//printf("%d\n", strlen(&arr));
//	//printf("%d\n", strlen(&arr + 1));
//	//printf("%d\n", strlen(&arr[0] + 1));
//
//	//char* p = "abcdef";
//	//printf("%d\n", sizeof(p));
//	//printf("%d\n", sizeof(p+1));	
//	//printf("%d\n", sizeof(*p));
//	//printf("%d\n", sizeof(p[0]));
//	//printf("%d\n", sizeof(&p));
//	//printf("%d\n", sizeof(&p+1));
//	//printf("%d\n", sizeof(&p[0]+1));
//
//	//char* p = "abcdef";
//	//printf("%d\n", strlen(p));//6
//	//printf("%d\n", strlen(p + 1));//5
//	////printf("%d\n", strlen(*p));//err
//	////printf("%d\n", strlen(p[0]));//err
//	//printf("%d\n", strlen(&p));//6（这个6是随机值）
//	//printf("%d\n", strlen(&p + 1));//随机值（这个随机值和前面的那个随机值没有任何关系）
//	//printf("%d\n", strlen(&p[0] + 1));//5取到a的地址，加一
//
//
//	int a[3][4] = { 0 };
//
//	printf("%d\n", sizeof(a));
//	printf("%d\n", sizeof(a[0][0]));
//	printf("%d\n", sizeof(a[0]));
//	printf("%d\n", sizeof(a[0]+1));
//	//a[0]作为数组名并没有到哪都放在sizeof内部，//也没有取地址，所以a[0]就是第一行的第一个数的地址
//	//a[0]+1,就是第一行第二个元素的地址
//	printf("%d\n", sizeof(*(a[0]+1)));
//	//第一行的第二个元素
//	printf("%d\n", sizeof(a+1));
//	//a是二维数组的数组名，并没有取地址，也没有单独放在sizeof内部，所以a就表示二维数组首元素的地址，即：第一行的
//	//地址。a+1就是二维数组第二行的地址
//	printf("%d\n", sizeof(*(a+1)));
//	//*（a+1）就表示a[1]和a[0]一样占内存为16
//	//第二行的大小
//	printf("%d\n", sizeof(&a[0]+1));
//	//取出第一行的地址加一，得到的是第二行的地址
//	//内存就是4/8
//	printf("%d\n", sizeof(*(&a[0]+1)));
//	//取出的是第二行的地址，然后解，得到第二行
//	//16
//	printf("%d\n", sizeof(*a));
//	//直接对a解引用，这时候a是首元素的地址
//	//也就是第一行，解引用得到的是第一行
//	printf("%d\n", sizeof(a[3]));
//	//下标为3，所以这个是第四行。sizeof（a[3]）在数组里面不存在。
//	//但是还是16.a[3]原理还是a[n]
//	//表达式有两个属性一个是值属性，一个是类型属性。
//	//比如int 8的值属性是8，类型属性是int
//	//a[3]的类型属性是int[4].sizeof计算的结果是，它不会真正的访问a[3]
//
//	return 0;
//}


//int main()
//{
//	short s = 5;
//	int a = 4;
//	printf("%d\n", sizeof(s = a + 6));
//	printf("%d\n", s);
//	//因为s为short类型，而a为int类型，s=a+6，得到的s还要是一个short类型的数
//	//所以这里直接输出2，而不会再计算，所以再打印s得到的还是2
//
//
//}

//int main()
//{
//	int a[5] = { 1,2,3,4,5 };
//	int* ptr = (int*)(&a + 1);//取地址a+1得到的是5之后的那个位置的地址
//	//再强制转化为int*类型的数，就是一个整形指针，因为本来是一个数组指针
//	printf("%d,%d", *(a + 1), *(ptr - 1));
//	//因为这里前面已经强制转化成为int*指针了，所以ptr-1向前挪动四个字节。
//
//	return 0;
//}

//struct Test
//{
//	int Num;
//	char* pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4]
//}; p;
//
//int main()
//{
//	printf("%p\n", p + 0x1);
//	//这里的结构体的大小是20
//	//所以p加1是直接跳过20
//	printf("%p\n",(unsigned long)p+0x1 );
//	//这里的p被强制转化为无符号类型的整形
//	//所以直接以整形的形式参与运算，直接加一
//	printf("%p\n", (unsigned int*)p+0x1);
//	//这里被转化为无符号整形指针，一个指针的大小是4/8
//	// 所以这就是加4/8
//	//指针类型决定了指针的运算
//	return 0;
//	//这段代码是运行不起来的，因为p没有定义内容只是为了说明
//}

//int main()
//{
//	int a[4] = { 1,2,3,4 };
//	int* ptr1 = (int*)(&a + 1);
//	int* ptr2 = (int*)((int)a + 1);
//
//	printf("%x,%x", ptr1[-1], *ptr2);
//	return 0;
//
//}


//int main()
//{
//	char* a[] = { "work","at","alibaba" };
//	char** pa = a;
//	pa++;
//	printf("%s\n", *pa);
//	return 0;
//}


//int main()
//{
//	char* c[] = { "ENTER","NEW","POINT","FIRST" };
//	char** cp[] = { c + 3,c + 2,c + 1,c };
//	char*** cpp = cp;
//
//	printf("%s\n", **++cpp);
//	printf("%s\n", *-- * ++cpp + 3);
//	printf("%s\n", *cpp[-2] + 3);
//	printf("%s\n", cpp[-1][-1] + 1);
//	return 0;
//
//}


//void zuoxuan(char* str, int k)
//{
//	int i = 0;
//	int len = strlen(str);
//	for(i=0;i<k;i++)
//	{
//		char tmp = str[0];
//		int j = 0;
//		for (j = 0; j < len - 1; j++)
//		{
//			*(str + j) = *(str + j + 1);
//		}
//		*(str + len - 1) = tmp;
//	}
//}
//
//int main()
//{
//	char arr[] = "ABCDE";
//	int k = 2;
//	zuoxuan(arr, k);
//
//	printf("%s", arr);
//
//	return 0;
//}


//str str 在一个字符串中找另一个字符串

//int main()
//{
//	char arr1[] = "abcdefghi";
//	char arr2[] = "cdef";
//	char* ret = strstr(arr1, arr2);
//	//返回类型为char*
//	if (ret == NULL)
//	{
//		printf("没找到\n");
// 
//	}
//	else
//	{
//		printf("找到了:%s\n", ret);
//	}
//	return 0;
//}

//kmp算法
//strtok函数 切割字符串
//strerror函数，报错


//// 定义一个模拟strstr函数的函数，命名为my_strstr
//char* my_strstr(const char* haystack, const char* needle)
//{
//    // 如果needle为空字符串，就返回haystack
//    if (*needle == '\0')
//    {
//        return (char*)haystack;
//    }
//
//    // 遍历haystack，直到遇到'\0'或者找到needle
//    while (*haystack != '\0')
//    {
//        // 定义两个指针分别指向haystack和needle
//        const char* p1 = haystack;
//        const char* p2 = needle;
//
//        // 比较两个指针指向的字符是否相等，如果相等，就同时后移一位，继续比较
//        while (*p1 == *p2 && *p1 != '\0' && *p2 != '\0')
//        {
//            p1++;
//            p2++;
//        }
//
//        // 如果p2指向了'\0'，说明needle已经匹配完毕，返回haystack
//        if (*p2 == '\0')
//        {
//            return (char*)haystack;
//        }
//
//        // 否则，haystack后移一位，继续查找
//        haystack++;
//    }
//
//    // 如果遍历完haystack还没有找到needle，就返回空指针
//    return NULL;
//}
//
//// 测试函数
//int main()
//{
//    // 定义两个字符串
//    char s1[] = "Hello, world!";
//    char s2[] = "world";
//
//    // 调用my_strstr函数，查找s2在s1中的位置
//    char* result = my_strstr(s1, s2);
//
//    // 打印结果
//    if (result != NULL)
//    {
//        printf("%s\n", result);
//    }
//    else
//    {
//        printf("Not found\n");
//    }
//
//    return 0;
//}


//#include <stdio.h> #include <errno.h> #include <string.h>

//int main() 
//{ // 打开一个不存在的文件
//	FILE *fp = fopen("no_such_file.txt", "r");
//	// 检查是否打开成功 
//	
//	if (fp == NULL) 
//	{ // 如果失败，打印错误消息
//		/*printf("Error: % s\n", strerror(errno));*/
//		perror("fogen");
//		// 退出程序 
//		return -1; 
//	} 
//		// // 如果成功，关闭文件 
//		fclose(fp);
//		// 返回正常值
//		 return 0;
//}


//int main()
//{
//	char ch = '*';
//	// 将char类型的参数强制转换为int类型
//	//int ret = isdigit((int)ch);
//	int ret = islower(ch);
//	printf("%d\n", ret);
//	return 0;
//}

//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	void* ret = dest;
//	assert(dest && src);
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//	return ret;
//}
//int main()
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[10] = { 0 };
//	my_memcpy(arr2, arr1, 20);
//
//	return 0;
//}


//void* my_memmove(void* dest, void* rest, size_t num)
//{
//	void* ret = 0;
//	assert(dest && rest);
//	if (dest < rest)
//	{
//		while (num--)
//		{
//			*(char*)dest = *(char*)rest;
//			dest = (char*)dest + 1;
//			rest = (char*)rest + 1;
//		}
//	}
//	else
//	{
//		while (num--)
//		{
//			*((char*)dest + num) = *((char*)rest + num);
//		}
//	}
//	return ret;
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	my_memmove(arr, arr + 2, 20);
//
//	int size = sizeof(arr) / sizeof(arr[1]);
//
//	int a = 0;
//	for (a = 0; a < size; a++)
//	{
//		printf("%d", arr[a]);
//	}
//	return 0;
//}
//enum color
//{
//	red = 5,
//	green=9,
//	blue=100
//};
//
//int main()
//{
//	enum color c = blue;
//	
//	printf("%d", sizeof(c));
//
//
//	return 0;
//}

//
//union un
//{
//	char a[5];
//	int i;
//};
//int main()
//{
//
//	union un a;
//
//	printf("%d", sizeof(a));
//
//	return 0;
//}


//int main()
//{
//	//打开文件
//	FILE* pf = fopen("text.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//		
//	}
//	//写文件
//	fputc('a', pf);
//	fputc('b', pf);
//	fputc('c', pf);
//		//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}



//int main()
//{
//	FILE* pf = fopen("text.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//读取文件
//	int ch = fgetc(pf);
//	printf("%c\n", ch);
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//struct S
//{
//	char arr[15];
//	int age;
//	float f;
//};
//
//int main()
//{
//	struct S s = { "hello,world",20,5.5f };
//	char buf[100] = { 0 };
//	sprintf(buf, "%s %d %f", s.arr, s.age, s.f);
//
//	printf("%s\n", buf);
//
//	return 0;
//}
//int main()
//{
//	int a[4] = { 1,2,3,4 };
//	/*int* ptr1 = (int*)(&a + 1);*/
//	int* ptr2 = (int*)(((int*)a) + 1);
//
//	printf("%x", //*(ptr1 - 1)); 
//		*ptr2);
//	return 0;
//}


//int main()
//{
//	printf("%s\n", __FILE__);
//	printf("%d\n", __LINE__);
//	printf("%s\n", __DATE__);
//	printf("%s\n", __TIME__);
//	printf("%s\n", __FUNCTION__);
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	FILE* pf = fopen("log.txt", "a+");
//	if (pf == NULL)
//	{
//		perror("fopen\n");
//		return 1;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		fprintf(pf, "%s %d %s %s %d\n", __FILE__, __LINE__, __DATE__, __TIME__, i);
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//#define SQUARE(X) X*X
//int main()
//{
//	printf("%d\n", SQUARE(3));
//	printf("%d\n", SQUARE(3+1));
//	printf("%d\n", 3 * 3);
//	return 0;
//}

//#define PRINT(X,FORMAT) printf("the value of "#X" is "#FORMAT"\n",X)
//
//int main()
//{
//	int a = 10;
//	PRINT(a,%d);
//	float b = 5.0;
//	PRINT(b,%f);
//	return 0;
//}

//#define CAT(X,Y) X##Y
//int main()
//{
//	int class101 = 100;
//	printf("%d\n", CAT(class, 101));
//	printf("%d\n", class101);
//	return 0;
//}

//#define MAX(X,Y) ((X)>(Y)?(X):(Y))
//int main()
//{
//	int a = 5;
//	int b = 8;
//	int m = MAX(a++, b++);
//	printf("a=%d b=%d\n", a, b);
//	printf("m=%d\n", m);
//	return 0;
//}

//#define NUM 10
//#define DEBUG
//
//int main()
//{
//    int x = 20;
//    if (NUM == 10)
//    {
//        printf("NUM is 10\n");
//    }
//    else
//    {
//        printf("NUM is not 10\n");
//    }
//
//#if x == 20
//    printf("x is 20\n");
//#else
//    printf("x is not 20\n");
//#endif
//    //if (NUM == 10)，这里的NUM是一个宏，它被#define定义为10，
//    // 所以这个条件为真，就会执行if后面的代码，也就是printf(“NUM is 10\n”);，
//    // 而else后面的代码就不会执行。这个判断是在程序运行时进行的。
////#if x == 20，这里的x是一个变量，它被赋值为20，但是#if不能使用变量，所以这个条件为假，
//// 就会跳过#if后面的代码，而#else后面的代码就会被编译。这个判断是在程序编译时进行的。
//    return 0;
//}

//使用#pragma comment指令，将作者和版本信息作为注释记录放入可执行文件中
// 
// 
//#pragma comment (exestr, "Author: Bing")
//#pragma comment (exestr, "Version: 1.0")
//int main()
//{
//    printf("Hello, this is a simple program.\n");
//    return 0;
//}


//#define A 2
//#define B 3
//#define MAX_SIZE A+B
//struct _Record_Struct
//{
//	unsigned char Env_Alarm : 4;
//	unsigned char Paral : 2;
//	unsigned char state;
//	unsigned char avail : 1;
//}*Env_Alarm_Record;
//
//int main()
//{
//	int sz = (sizeof(struct _Record_Struct) * MAX_SIZE);
//	printf("%d\n", sz);
//	return 0;
//}

//
//int main()
//{
//	unsigned char puc[4];
//	struct tagPIM
//	{
//		unsigned char ucPim1;
//		unsigned char ucDate0:1;
//		unsigned char ucDate1:2;
//		unsigned char ucDate2:3;
//	}*pstPimDate;
//	pstPimDate = (struct tagPIM*)puc;
//	memset(puc, 0, 4);
//	pstPimDate->ucPim1 = 2;
//	pstPimDate->ucDate0 = 3;
//	pstPimDate->ucDate1 = 4;
//	pstPimDate->ucDate2 = 5;
//	printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);
//	return 0;
//}


//int main()
//{
//	char* p = "1234";
//	int ret = atoi(p);
//	printf("%d\n", ret);
//	return 0;
//}

//enum bale
//{
//	unvalue,
//	value
//};
//enum bale state=value;
//int my_aoti(const char* s)
//{
//	if (s == NULL)
//	{
//		return 0;
//	}
//	if (*s == '\0')
//	{
//		return 0;
//	}
//	while (isspace(*s))
//	{
//		s++;
//	}
//	int flag = 1;
//	if (*s == '-')
//	{
//		flag = -1;
//		s++;
//	}
//	else if(*s=='+')
//	{
//		flag = 1;
//		s++;
//	}
//	long long n = 0;
//	while (isdigit(*s))
//	{
//			n = 10 * n + flag*(*s - '0');
//			if (n > INT_MAX || n < INT_MIN)
//			{
//				return 0;
//			}
//			s++;
//	}
//	if (*s == '\0')
//	{
//		state = value;
//		return n;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int main()
//{
//	const char* p = "-12345";
//	int ret = my_aoti(p);
//	if (state == 1)
//	{
//		printf("有效的打印:%d\n", ret);
//	}
//	else if (state == 0)
//	{
//		printf("无效的打印:%d\n", ret);
//	}
//	return 0;
//}

void Find(int arr[], int sz,int*x,int*y)
{
	int pos = 0;
	int i = 0;
	int ret = 0;
	for (i = 0; i < sz; i++)
	{
		ret ^= arr[i];//注意这里不是等于号，这里是^=是多了一个^号的
		//^=表示的是按位异或，因为异或遵循交换率，所以虽然这个是每次循环算出
		//但是整体写下来，异或的还是只有那两个不同的数，
		//两个相同的数异或等于0.一个数和0异或得到的是这个数本身
	}
	for (i = 0; i < 32; i++)
	{
		if (((ret >> i) & 1) == 1)
		{
			//按位与1得到的结果只能是1或者0
			//ret是前面经过异或得到的，因为要算的是正数，所以原码等于补码
			//因为ret是前面经过异或得到的，所以ret的补码中第一个为1的数就是补码开始不同的数
			//比如00001111011010和00001111001010异或得到的是00000000010000，那么第一个出现1的位置，就是
			//他们的补码开始不同的位置
			//再通过这个循环得到这个位数
			pos = i;
			break;
		}
	}
	//pos即为，两个数从最低位起，第一个不相同的补码的位数
	int num1 = 0;
	int num2 = 0;
	for (i = 0; i < sz; i++)
	{
		if (((arr[i] >> pos) & 1) == 1)
		{
			num1 ^= arr[i];
			//注意，这里也不是等号
			//这里把所有pos位的补码进行按位与1
			//然后把得到的所有数存到一个数组里面，进行按位或就能得到目标的数
		}
		else if(((arr[i] >> pos) & 1) == 0)
		{
			num2 ^= arr[i];
			//注意，这里也不是等号
		}
	}
	*x = num1;
	*y = num2;
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,1,2,3,4 };
	int sz = (sizeof(arr) / sizeof(arr[0]));
	int x = 0, y = 0;
	Find(arr, sz,&x,&y);
	printf("%d %d", x, y);
	return 0;
}


//int main()
//{
//	int a = 100;
//	int sz=sizeof((char)a);
//	int sz1 = sizeof(a);
//	printf("%d\n", sz);
//	printf("%d", sz1);
//	return 0;
//}