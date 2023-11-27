#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

////int main()
////{
////	printf("比特\n");//所有的函数需要在头文件引用
////
////	return 0;
////}
//
////编译加运行代码，ctrl+f5
////esc加fn关闭f快捷键
//
////int main()
////{
////	printf("%d\n", 100);//%d是整数显示
////	//sizeof（）所占空间大小。每句后面加分号；
////
////	return 0;
////}
////int main()
////{
////	int age = 19;
////	long big = 100;
////	double weight = 75.3;
////	age = age + 1;
////	printf("%d", age);
////	return 0;
////}
////int a = 100;
//////全局变量
////int main()
////{
////	int a = 19;//局部变量
////	long big = 100;//局部变量
////	double weight = 75.3;//局部变量
////	printf("%d", a);
////	return 0;
////}
//
////scanf函数是输入函数
////int main()
////{
////	int a = 0;
////	int b = 0;
////	int sum = 0;
////	scanf("%d %d", &a, &b);
////	sum = a + b;
////	printf("sum=%d",sum );
////	return 0;
////}
//
////int main()
////{
////	3.14;//字面常量
////	'a';//字符常量，单引号
////	"abcdef";//字符串常量，双引号
////
////	const int num = 10;
////	num10;
////
////	return 0;
////}
////#define定义，定义的东西就是代码内的标准。比如定义max=10000
////那么输入n=max。n就等于10000，且max的大小不能修改
////define定义的是常量
////枚举常量，可以一一列举的常量。
////周一到周天，性别的男女，
////enum定义枚举产量。
//
//
////int main()
////{
////
////	enum sex
////	{
////		man,
////		woman,
////		secret
////	};
////	printf("%d\n", man);
////	printf("%d\n", woman);
////	printf("%d\n", secret);
////	return 0;
////}
////字符串就是一串字符，双引号引起来的字符就叫字符串，字符串的结束标志是/0
////字符数组-一组相同类型的元素
//
////int main()
////{
////	printf("%c\n",'\'');
////	printf("%s\n", "\"");
////	printf("%s\n", "abc");
////	printf("c:\\test\\test.c");
////	return 0;
////}
////int main()
////{
////	printf("%c\n",'\130');//这里是八进位制
////	//结果是X，因为X的ASCII码值是88，八进制的130转化为十进制数是88
////	printf("%c\n", '\x30');//这里是十六进位制
////	return 0;
////}
//
////int main()
////{
////	int input = 0;
////	printf("你要好好学习吗<1/0>？");
////		scanf("%d", &input);
////		if (input == 1)
////			printf("有佳鑫\n");
////		else
////			printf("没佳鑫\n");
////
////	return 0;
////}
//
////循环语句
////int main()
////{
////
////	int input = 0;
////	while (input < 3000)
////	{
////		printf("想佳鑫，%d",input);
////		input++;
////	}
////	if(input==3000)
////	{
////		printf("佳鑫");
////	}
////	return 0;
////}
//
////  int Add(int x,int y)
////{
////	int z = 0;
////	z = x + y;
////	return z;
////
////}
////int main()
////{
////
////	int input1 = 0;
////	int input2 = 0;
////	scanf(" %d%d", &input1, &input2);
////	/*int sum = input1 + input2;*/
////	int sum = Add(input1, input2);
////	printf("%d\n", sum);
////	return 0;
////}
//
////int main()
////{
////	int a = 2;
////	int b = a << 1;
////	printf("%d\n", b);
////	
////	return 0;
////}
//
//
////int main()
////{
////	int a = 2;
////	printf("%d\n", ~a);
////
////	return 0;
////}
//
////int main()
////{
////	int a = 10;
////	int b = a++;
////	printf("%d\n", b);
////	printf("%d\n", a);
////	return 0;
////}
//
////int main()
////{
////	int a = (int)3.14;
////	printf("%d\n", a);
////	return 0;
////}
//
////int main()
////{
////	int a = 3;
////	int b = 5;
////	int c = a && b;//a||b的结果就是错，c等于0
////	printf("%d\n", c);
////	return 0;
////}
//
////int main()
////{
////	int a = 3;
////	int b = 5;
////	int max = 0;
////	/*if (a > b)
////		max = a;
////	else
////		max = b;*/
////	max = a > b ? a : b;//和上面的功能相同
////	printf("%d\n", max);
////	return 0;
////}
//
////int main()
////{
////	int a = 0;
////	int b = 3;
////	int c = 5;
////	int d = (a = b + 2, c = a - 4, b = c + 2);
////	//这就是逗号表达式，从左向右依次，然后赋值给对应的字母，计算，结果是最后一个表达式的计算值
////	printf("%d\n", d);
////	return 0;
////}
//
//
////int main()
////{
////	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
////	printf("%d\n", arr[5]);
////	//下标引用操作符
////	return 0;
////}
//
////
////int main()
////{
////
////	printf("hehe\n");
////	printf("%d", 100);
////	//下标引用操作符
////	return 0;
////}
//
//
////关键字，c语言提供，不能自己创建，关键字不能做变量名
////#define max 1000
////int main()
////{
////	printf("%d",max);
////	
////	return 0;
////}
//
////
////#define add(x,y) ((x)+(y))
////int main()
////{
////
////	printf("%d\n", 2*add(23, 3));
////	return 0;
////}
//
//
////#define add(x,y) x+y
////int main()
////{
////
////	printf("%d\n", 2 * add(23, 3));
////	return 0;
////}
//
////struct stu
////{
////	char name[20];
////	int age;
////	double score;
////};
////int main()
////{
////	struct stu s = { "zhangsan",20,85.5 };
////	printf("%s %d %f\n", s.name, s.age, s.score );
////	struct stu* ps = &s;
////	printf("%s %d %f\n", (*ps).name, (*ps).age, (*ps).score);
////	printf("%s %d %f", ps->name, ps->age, ps->score);
////	return 0;
////}
//
//
////int main()
////{
////	int a = 10;
////
////	int* pa = &a;
////
////	char ch = 'w';
////	char* pc = &ch;
////	printf("number's address=%p\n", pa);
////	return 0;
////
////}
//
////int main()
////{
////	int a = 10;
////
////	int* pa = &a;
////
////	char ch = 'w';
////	char* pc = &ch;
////	printf("number's address=%p\n", &a);
////	return 0;
////
////
//
//
////int compose(int a, int b)
////{
////	int max = 0;
////	if (a < b)
////	{
////		max = b;
////		printf("b is bigger and b is %d", max);
////	}
////	else
////	{
////		max = a;
////		printf("a is bigger and a is %d", max);
////	}
////	return max;
////}
////int main()
////{
////	int x = 0;
////	int y = 0;
////	scanf("%d%d",&x,&y);
////	compose(x, y);
////	return 0;
////
////}
//
//
////int main()
////{
////	int age = 24;
////	if (age < 18)
////		printf("少年\n");
////	else if (age >= 18 && age < 26)
////		printf("青年\n");
////	else if (age >= 26 && age < 40)
////		printf("壮年\n");
////	else if (age >= 40 && age < 60)
////		printf("中年\n");
////	else if (age >= 60 && age < 100)
////		printf("老年\n");
////	else if (age >= 100)
////		printf("老了\n");
////
////	return 0;
////}
//
//
////int main()
////{
////	int num = 0;
////	while (num < 100)
////	{
////		if (num % 2 == 1)
////		{
////			printf("奇数%d\n", num);
////		}
////		num = num++;
////	}
////	return 0;
////}
//
//
//
////int main()
////{
////
////	int day = 0;
////	scanf("%d", &day);
////	switch (day)
////	{
////	case 1:
////		printf("周1\n");
////		break;
////	case 2:
////		printf("周2\n");
////		break;
////	case 3:
////		printf("周3\n");
////		break;
////	case 4:
////		printf("周4\n");
////		break;
////	case 5:
////		printf("周5\n");
////		break;
////	case 6:
////		printf("周6\n");
////		break;
////	case 7:
////		printf("周7\n");
////		break;
////	default:
////		printf("输入错误");
////		break;
////	}
////	return 0;
////}
//
////int main()
////{
////	int ch = getchar();
////	printf("%c\n", ch);
////	putchar(ch);
////	return 0;
////}
//
////int main()
////{
////	int ch = 0;
////	while ((ch = getchar()) != EOF)
////	{
////		putchar(ch);
////	}
////
////	return 0;
////}
//
//
////int main()
////{
////	char password[20] = { 0 };
////	printf("请输入密码：>");
////	scanf("%s", password);
////	printf("请确认密码（Y/N）：>");
////	//缓冲区有内容，要提前清楚
////	//getchar也可以带走这个内容
////	//getchar();
////	int ge = 0;
////	while ((ge = getchar()) != '\n')
////	{
////		;
////	}
////	int ch = getchar();
////	if (ch == 'Y')
////	{
////		printf("确认成功");
////	}
////	else
////	{
////		printf("确认失败");
////	}
////	return 0;
////}
//
////int main()
////{
////	int i = 0;
////	for (i = 1; i <= 10; i++)
////	{
////		if (i == 5)
////			continue;
////
////		printf("%d\n", i);
////	}
////	return 0;
////}
////int main()
////{
////	int i = 1;
////	do
////	{
////		printf("%d\n", i);
////		i++;
////	} while (i <= 10);
////	return 0;
////}

//int main()
//{
//	int i = 1;
//	int b = 0;
//	int sum = 1;
//	int max = 0;
//	int a = 0;
//	scanf("%d", &max);
//	for (b = 1; b <= max; b++)
//	{
//		while (i <= b)
//		{
//			sum = sum * i;
//			i++;
//		}
//		a = a + sum;
//	}
//	printf("%d", a);
//	return 0;
//}

//#include<string.h>
//int main()
//{
//	int i = 0;
//	char password[20] = { 0 };
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入密码：>");
//		scanf("%s", password);
//		if (strcmp(password,"123456") == 0)
//		{
//			printf("登录成功\n");
//				break;
//		}
//		else
//		{
//			printf("密码错误，重新输入!\n");
//		}
//		if (i == 3)
//			printf("密码输入错误超过三次，退出程序");
//	}
//	return 0;
//}


//int main()
//{
//flag:
//	printf("dddd");
//	printf("aaaaa");
//	goto flag;
//	return 0;
//}//死循环语句，从flag执行到gotoflag

#include<stdlib.h>
#include<string.h>
//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 60");
//again:
//	printf("你的电脑将会在60秒后关机，输入“我是猪”即可停止关机");
//	scanf("%s", input);
//	if (strcmp(input, "我是猪")==0)
//	system("shutdown -a");
//	else
//		goto again;
//	return 0;
//}
//
//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 60");
//	while (1)
//	{
//		printf("你的电脑将会在60秒后关机，输入“我是猪”即可停止关机\n");
//		scanf("%s", input);
//		if (strcmp(input, "我是猪") == 0)
//		{
//			system("shutdown -a");
//			break;
//		}
//		else
//			;
//	}
//	return 0;
//}


//int main()
//{
//	char str[] = "hello";
//	char* p = str; //定义一个指针变量p，并让它指向字符串"hello"
//	printf("%s\n", p); //输出字符串"hello"
//	printf("%c\n", *p); //输出第一个字符'h'
//
//	return 0;
//}

#include <stdio.h>

//int main()
//{
//    int a = 999; // 定义一个 int 类型的变量 a
//    char c = 'c'; // 定义一个 char 类型的变量 c
//    printf("The address of a is %p\n", &a); // 打印 a 的地址
//    printf("The value of a is %d\n", a); // 打印 a 的值
//    printf("The address of c is %p\n", &c); // 打印 c 的地址
//    printf("The value of c is %c\n", c); // 打印 c 的值
//    return 0;
//}


//#include <stdio.h>
//
//void swap(int* x, int* y) // 定义一个交换两个 int 型变量值的函数，使用指针作为形参
//{
//    int temp = *x; // 定义一个临时变量 temp，并将 x 所指向的变量的值赋给它
//    *x = *y; // 将 y 所指向的变量的值赋给 x 所指向的变量
//    *y = temp; // 将 temp 的值赋给 y 所指向的变量
//}
//
//int main()
//{
//    int a = 10; // 定义一个 int 类型的变量 a，并初始化为10
//    int b = 20; // 定义一个 int 类型的变量 b，并初始化为20
//    printf("Before swap: a = %d, b = %d\n", a, b); // 打印交换前的 a 和 b 的值
//    swap(&a, &b); // 调用 swap 函数，传入 a 和 b 的地址
//    printf("After swap: a = %d, b = %d\n", a, b); // 打印交换后的 a 和 b 的值
//    return 0;
//}


// int is_leap_year(int x)
//{
//	 if ((x % 4 == 0 && x % 100!=0)||(x % 400 == 0))
//	 {
//		 return 1;
//	 }
//	 else
//	 {
//		 return 0;
//	 }
//}
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1000; i <= 2000; i++)
//	{
//		if (is_leap_year(i) == 1)
//		{
//			count++;
//			printf("%d  ", i);
//		}
//		
//	}
//	printf("\n%d", count);
//	return 0;
//}

//#include "ad.h"
//int main()
//{
//	printf("%d\n", printf("%d", printf("%d", 43)));
//	printf("%d", ad(2, 3));
//	return 0;
//}


//void print(unsigned int x)
//{
//	if (x > 9)
//	{
//		print(x / 10);
//	}
//	printf("%u  ", x % 10);
//}
//
//int main()
//{
//	unsigned int num = 0;
//	scanf("%u", &num);
//	print(num);
//	return 0;
//}

//int mylength(char *str)
//{
//	if (*str != '\0')
//	{
//		return 1 + mylength(str + 1);
//	}
//	else
//		return 0;
//}
//
//
//int main()
//{
//	char arr[] = "bit";
//	printf("%d", mylength(arr));
//	return 0;
//}


//int main()
//{
//	int i = 0, a = 0;
//	double b = 0, c = 0;
//	for (i = 1; i <= 100; i=i + 2)
//		b = b + 1.0/ i;
//	for (a = 2; a <= 100; a=a + 2)
//		c = c + 1.0 / a;
//	double last = b - c;
//	printf("%lf", last);
//	return 0;
//}


//int main()
//{
//	int a = 0, b = 0, c = 0;
//	scanf("%d", &c);
//	for (a = 1; a <= c; a++)
//	{
//		for (b = 1; b <= a; b++)
//		{
//			int c = a * b;
//			printf("%d*%d=%-2d  ", a, b, c);
//		}
//		printf("\n");
//	}
//	return 0;
//}


//void hannuota(char A, char B, char C, int n)
//{
//	if (n == 1)
//	{
//		printf("%c-->%c\n", A, C);//a为开始柱，c为目标柱
//	}
//	else
//	{
//		hannuota(A, C, B, n - 1);//如果不是1，把n-1个盘子看成一个整体，先放到中间的柱子(这个时候，中间的柱子就是目标柱子)
//		//因为最下面那个盘子最大，所以可以先把他忽略掉。直接对上面的n-1个盘子使用递归，直到这个n-1等于1
//		printf("%c-->%c\n",A, C);//这一步，直接把最大的盘子从a移动到c。现在a是空的，c有一个最大的盘子
//		//b有n-1个盘子。把b看作开始柱，c看作目标柱，a看作中间柱。继续执行上面的操作
//		hannuota(B, A, C, n - 1);
//	}
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	hannuota('A', 'B', 'C', n);
//	return 0;
//}



//int qiuhe(int a)
//{
//	int h = 0, b = 0;
//	h = a % 10;
//	if (a != 0)
//	{
//		b = h + qiuhe(a / 10);
//	}
//	return b;
//}
//int main()
//{
//	int a = 0, c = 0;
//	scanf("%d", &a);
//	c = qiuhe(a);
//	printf("%d", c);
//	return 0;
//}


//二维数组
//初始化：创建的同时，给以赋值



//int main()
//{
//	int a = 3;
//	int b = (++a) + (++a) + (++a);
//	printf("%d", b);
//	return 0;
//}

//int main()
//{
//	int a = (int)3.14;
//	printf("%d", a);
//	return 0;
//}

#include <stdio.h>

//int my_strlen(char* ch)
//{
//	char* str = ch;
//	int a = 0;
//	if (*ch != '\0')
//	{
//		ch++;
//		a = my_strlen(ch);
//		a++;
//	}
//	return a;
//}
//
//int main()
//{
//	char* ch = "abc";
//	int a = my_strlen(ch);
//	printf("%d", a);
//	return 0;
//}

#include<assert.h>
//char* my_strcpy(char* dest, const char* str)
//{
//	assert(str != 'NULL');
//	assert(dest != 'NULL');
//	char* ret = dest;
//	while (*dest++ = *str++)//dest是要交换成为的字符串
//	{
//		;
//	}
//	return ret;
//	//上面传递给ret的是字符串dest的地址。
//	//所以这个字符串的ret会随着dest的变化而变化
//}
//int main()
//{
//	char arr1[20] = "xxxxxxxxxxxxxx";
//	char arr2[] = "hello";
//	printf("%s", my_strcpy(arr1, arr2));//1.目标空间的原始地址，注意这里面是地址，里面的内容要改变为hello，但是现在是xxxxxxxxxxx
//	//2.目标空间的结果内容
//	//把arr2赋予给arr1
//	return 0;
//}



//
////这里可以使用size_t,也就是unsigned int 无符号整型
//int my_strlen(const char* str)
//{
//	assert(str != 'NULL');
//	int a = 0;	
//	while (*str++)
//	{
//		a++;
//	}
//	return a;
//}
//int main()
//{
//	char arr1[20] = "abcdefgh";
//	printf("%d\n", my_strlen(arr1));
//	return 0;
//}


#include <stdio.h>
#include <string.h>

//void reverse(char* str)
//{
//    // 如果字符串为空或只有一个字符，直接返回
//    if (str == NULL || strlen(str) <= 1) {
//        return;
//    }
//    // 定义两个指针，分别指向字符串的开头和结尾
//    char* left = str;
//    char* right = str + strlen(str) - 1;
//    // 定义一个临时变量，用于交换字符
//    char temp;
//    // 循环交换两个指针所指的字符，直到相遇或者交叉
//    while (left < right)
//    {
//        temp = *left;
//        *left = *right;
//        *right = temp;
//        left++;
//        right--;
//    }
//}

//int main()
//{
//    // 定义一个字符串
//    char str[] = "abcdefg";
//    // 打印原始字符串
//    printf("Original string: %s\n", str);
//    // 调用反转函数
//    reverse(str);
//    // 打印反转后的字符串
//    printf("Reversed string: %s\n", str);
//    return 0;
//}

//#include <stdio.h>
//#define MAX_LEN 100
//int lengths(char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		count++;
//		str++;//这里是字符串的首位地址的位置＋1，就是比如输入abcdefg，首位应该是a，加一变成b
//	}
//	return count;
//}
//
//void fanzhuan(char* str)
//{
//	int left = 0;
//	int right = lengths(str) - 1;//计算字符串的长度，这里写一个单独的函数。
//	//以后也可以直接使用。
//	char a = str[left];//这里也可以使用*（str+left），先储存一下，最左边的数值，每次退出一阶的递归，就赋值给最后一个
//	*(str + left) = str[right];//将最右边的字符串的数值复制给最左边。
//	*(str + right) = '\0';//复制完后，将最右边的数值修改为\0，结束符号
//	if (lengths(str + 1) >= 2)//如果剩下的字符串的长度大于等于2，那么还能继续进行循环
//		//最后面的一个字符已经转化为\0了，再把前一个地址信息忽略掉，就去掉了首尾的字符
//	{
//		fanzhuan(str + 1);
//	}
//	*(str + right) = a;
//}
//int main()
//{
//	char arr[MAX_LEN];
//	printf("请输入一个字符串：\n");
//	scanf("%s", arr);
//	fanzhuan(arr);
//
//	printf("反方向的字符是：\n%s", arr);
//	return 0;
//}

//
//int main()
//{
//	int a = 10100;
//	return 0;
//}

