#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

////int main()
////{
////	printf("����\n");//���еĺ�����Ҫ��ͷ�ļ�����
////
////	return 0;
////}
//
////��������д��룬ctrl+f5
////esc��fn�ر�f��ݼ�
//
////int main()
////{
////	printf("%d\n", 100);//%d��������ʾ
////	//sizeof������ռ�ռ��С��ÿ�����ӷֺţ�
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
//////ȫ�ֱ���
////int main()
////{
////	int a = 19;//�ֲ�����
////	long big = 100;//�ֲ�����
////	double weight = 75.3;//�ֲ�����
////	printf("%d", a);
////	return 0;
////}
//
////scanf���������뺯��
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
////	3.14;//���泣��
////	'a';//�ַ�������������
////	"abcdef";//�ַ���������˫����
////
////	const int num = 10;
////	num10;
////
////	return 0;
////}
////#define���壬����Ķ������Ǵ����ڵı�׼�����綨��max=10000
////��ô����n=max��n�͵���10000����max�Ĵ�С�����޸�
////define������ǳ���
////ö�ٳ���������һһ�оٵĳ�����
////��һ�����죬�Ա����Ů��
////enum����ö�ٲ�����
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
////�ַ�������һ���ַ���˫�������������ַ��ͽ��ַ������ַ����Ľ�����־��/0
////�ַ�����-һ����ͬ���͵�Ԫ��
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
////	printf("%c\n",'\130');//�����ǰ˽�λ��
////	//�����X����ΪX��ASCII��ֵ��88���˽��Ƶ�130ת��Ϊʮ��������88
////	printf("%c\n", '\x30');//������ʮ����λ��
////	return 0;
////}
//
////int main()
////{
////	int input = 0;
////	printf("��Ҫ�ú�ѧϰ��<1/0>��");
////		scanf("%d", &input);
////		if (input == 1)
////			printf("�м���\n");
////		else
////			printf("û����\n");
////
////	return 0;
////}
//
////ѭ�����
////int main()
////{
////
////	int input = 0;
////	while (input < 3000)
////	{
////		printf("����Σ�%d",input);
////		input++;
////	}
////	if(input==3000)
////	{
////		printf("����");
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
////	int c = a && b;//a||b�Ľ�����Ǵ�c����0
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
////	max = a > b ? a : b;//������Ĺ�����ͬ
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
////	//����Ƕ��ű��ʽ�������������Σ�Ȼ��ֵ����Ӧ����ĸ�����㣬��������һ�����ʽ�ļ���ֵ
////	printf("%d\n", d);
////	return 0;
////}
//
//
////int main()
////{
////	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
////	printf("%d\n", arr[5]);
////	//�±����ò�����
////	return 0;
////}
//
////
////int main()
////{
////
////	printf("hehe\n");
////	printf("%d", 100);
////	//�±����ò�����
////	return 0;
////}
//
//
////�ؼ��֣�c�����ṩ�������Լ��������ؼ��ֲ�����������
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
////		printf("����\n");
////	else if (age >= 18 && age < 26)
////		printf("����\n");
////	else if (age >= 26 && age < 40)
////		printf("׳��\n");
////	else if (age >= 40 && age < 60)
////		printf("����\n");
////	else if (age >= 60 && age < 100)
////		printf("����\n");
////	else if (age >= 100)
////		printf("����\n");
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
////			printf("����%d\n", num);
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
////		printf("��1\n");
////		break;
////	case 2:
////		printf("��2\n");
////		break;
////	case 3:
////		printf("��3\n");
////		break;
////	case 4:
////		printf("��4\n");
////		break;
////	case 5:
////		printf("��5\n");
////		break;
////	case 6:
////		printf("��6\n");
////		break;
////	case 7:
////		printf("��7\n");
////		break;
////	default:
////		printf("�������");
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
////	printf("���������룺>");
////	scanf("%s", password);
////	printf("��ȷ�����루Y/N����>");
////	//�����������ݣ�Ҫ��ǰ���
////	//getcharҲ���Դ����������
////	//getchar();
////	int ge = 0;
////	while ((ge = getchar()) != '\n')
////	{
////		;
////	}
////	int ch = getchar();
////	if (ch == 'Y')
////	{
////		printf("ȷ�ϳɹ�");
////	}
////	else
////	{
////		printf("ȷ��ʧ��");
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
//		printf("���������룺>");
//		scanf("%s", password);
//		if (strcmp(password,"123456") == 0)
//		{
//			printf("��¼�ɹ�\n");
//				break;
//		}
//		else
//		{
//			printf("���������������!\n");
//		}
//		if (i == 3)
//			printf("����������󳬹����Σ��˳�����");
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
//}//��ѭ����䣬��flagִ�е�gotoflag

#include<stdlib.h>
#include<string.h>
//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 60");
//again:
//	printf("��ĵ��Խ�����60���ػ������롰����������ֹͣ�ػ�");
//	scanf("%s", input);
//	if (strcmp(input, "������")==0)
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
//		printf("��ĵ��Խ�����60���ػ������롰����������ֹͣ�ػ�\n");
//		scanf("%s", input);
//		if (strcmp(input, "������") == 0)
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
//	char* p = str; //����һ��ָ�����p��������ָ���ַ���"hello"
//	printf("%s\n", p); //����ַ���"hello"
//	printf("%c\n", *p); //�����һ���ַ�'h'
//
//	return 0;
//}

#include <stdio.h>

//int main()
//{
//    int a = 999; // ����һ�� int ���͵ı��� a
//    char c = 'c'; // ����һ�� char ���͵ı��� c
//    printf("The address of a is %p\n", &a); // ��ӡ a �ĵ�ַ
//    printf("The value of a is %d\n", a); // ��ӡ a ��ֵ
//    printf("The address of c is %p\n", &c); // ��ӡ c �ĵ�ַ
//    printf("The value of c is %c\n", c); // ��ӡ c ��ֵ
//    return 0;
//}


//#include <stdio.h>
//
//void swap(int* x, int* y) // ����һ���������� int �ͱ���ֵ�ĺ�����ʹ��ָ����Ϊ�β�
//{
//    int temp = *x; // ����һ����ʱ���� temp������ x ��ָ��ı�����ֵ������
//    *x = *y; // �� y ��ָ��ı�����ֵ���� x ��ָ��ı���
//    *y = temp; // �� temp ��ֵ���� y ��ָ��ı���
//}
//
//int main()
//{
//    int a = 10; // ����һ�� int ���͵ı��� a������ʼ��Ϊ10
//    int b = 20; // ����һ�� int ���͵ı��� b������ʼ��Ϊ20
//    printf("Before swap: a = %d, b = %d\n", a, b); // ��ӡ����ǰ�� a �� b ��ֵ
//    swap(&a, &b); // ���� swap ���������� a �� b �ĵ�ַ
//    printf("After swap: a = %d, b = %d\n", a, b); // ��ӡ������� a �� b ��ֵ
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
//		printf("%c-->%c\n", A, C);//aΪ��ʼ����cΪĿ����
//	}
//	else
//	{
//		hannuota(A, C, B, n - 1);//�������1����n-1�����ӿ���һ�����壬�ȷŵ��м������(���ʱ���м�����Ӿ���Ŀ������)
//		//��Ϊ�������Ǹ�����������Կ����Ȱ������Ե���ֱ�Ӷ������n-1������ʹ�õݹ飬ֱ�����n-1����1
//		printf("%c-->%c\n",A, C);//��һ����ֱ�Ӱ��������Ӵ�a�ƶ���c������a�ǿյģ�c��һ����������
//		//b��n-1�����ӡ���b������ʼ����c����Ŀ������a�����м���������ִ������Ĳ���
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


//��ά����
//��ʼ����������ͬʱ�����Ը�ֵ



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
//	while (*dest++ = *str++)//dest��Ҫ������Ϊ���ַ���
//	{
//		;
//	}
//	return ret;
//	//���洫�ݸ�ret�����ַ���dest�ĵ�ַ��
//	//��������ַ�����ret������dest�ı仯���仯
//}
//int main()
//{
//	char arr1[20] = "xxxxxxxxxxxxxx";
//	char arr2[] = "hello";
//	printf("%s", my_strcpy(arr1, arr2));//1.Ŀ��ռ��ԭʼ��ַ��ע���������ǵ�ַ�����������Ҫ�ı�Ϊhello������������xxxxxxxxxxx
//	//2.Ŀ��ռ�Ľ������
//	//��arr2�����arr1
//	return 0;
//}



//
////�������ʹ��size_t,Ҳ����unsigned int �޷�������
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
//    // ����ַ���Ϊ�ջ�ֻ��һ���ַ���ֱ�ӷ���
//    if (str == NULL || strlen(str) <= 1) {
//        return;
//    }
//    // ��������ָ�룬�ֱ�ָ���ַ����Ŀ�ͷ�ͽ�β
//    char* left = str;
//    char* right = str + strlen(str) - 1;
//    // ����һ����ʱ���������ڽ����ַ�
//    char temp;
//    // ѭ����������ָ����ָ���ַ���ֱ���������߽���
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
//    // ����һ���ַ���
//    char str[] = "abcdefg";
//    // ��ӡԭʼ�ַ���
//    printf("Original string: %s\n", str);
//    // ���÷�ת����
//    reverse(str);
//    // ��ӡ��ת����ַ���
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
//		str++;//�������ַ�������λ��ַ��λ�ã�1�����Ǳ�������abcdefg����λӦ����a����һ���b
//	}
//	return count;
//}
//
//void fanzhuan(char* str)
//{
//	int left = 0;
//	int right = lengths(str) - 1;//�����ַ����ĳ��ȣ�����дһ�������ĺ�����
//	//�Ժ�Ҳ����ֱ��ʹ�á�
//	char a = str[left];//����Ҳ����ʹ��*��str+left�����ȴ���һ�£�����ߵ���ֵ��ÿ���˳�һ�׵ĵݹ飬�͸�ֵ�����һ��
//	*(str + left) = str[right];//�����ұߵ��ַ�������ֵ���Ƹ�����ߡ�
//	*(str + right) = '\0';//������󣬽����ұߵ���ֵ�޸�Ϊ\0����������
//	if (lengths(str + 1) >= 2)//���ʣ�µ��ַ����ĳ��ȴ��ڵ���2����ô���ܼ�������ѭ��
//		//������һ���ַ��Ѿ�ת��Ϊ\0�ˣ��ٰ�ǰһ����ַ��Ϣ���Ե�����ȥ������β���ַ�
//	{
//		fanzhuan(str + 1);
//	}
//	*(str + right) = a;
//}
//int main()
//{
//	char arr[MAX_LEN];
//	printf("������һ���ַ�����\n");
//	scanf("%s", arr);
//	fanzhuan(arr);
//
//	printf("��������ַ��ǣ�\n%s", arr);
//	return 0;
//}

//
//int main()
//{
//	int a = 10100;
//	return 0;
//}

