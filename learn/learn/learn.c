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
//	//����ģ�char*����ʾ����ǿ��ת����Ϊchar��ָ������
//	if (*p == 1)
//	{
//		printf("С�� \n");
//	}
//	else
//	{
//		printf("���\n");
//	}
//
//	return 0;
//}  



//int main()
//{
//	char a = -1;
//	//-1�Ĳ�����ʽ��
//	//111111111111111111
//	//ֻ��ȡ��λ���֣�ȡ������11111111
//	//ת��ʮ�������־���-1
//
//	signed char b = -1;
//	//signed int����int
//	//signed intͬ��
//	unsigned char c = -1;
//
//	//������11111111111
//	//����������������û�з���λ
//	//����������ʱ��û�з���
//	//��ô����Ľ����
//	//0000000000  0111111111
//	//8��1��ʮ�������ֵĴ�С����255
//
//	printf("a=%d,b=%d,c=%d", a, b, c);
//	return 0;
//}

//int main()
//{
//	char a = -128;
//	printf("%u\n", a);
//	//%u��ʾ���Ǵ�ӡ�����޷��ŵ���
//	//ԭ����
//	// ԭ����1000000000000000001000000
//	//������1111111111111111000000
//	//�߸�0
//	//ȡ��
//	//10000000
//	//�����������޷�������
//	//ǰ��ȫ������1
//	//11111111111111110000
//	//������11111111�����߸�0
//	//������ʱ�����λ��1����ʾ����
//	return 0;
//}



//char���ͱ�����ȡֵ��Χһ��Ĺ涨��[-128.127]
//�����Ѿ�����char���͵ı���
//10000000ֱ�ӻᱻ������Ϊ-128
//���ԷŽ�ȥ128�����ǻᳬԽ����
//ͨ������������ת��Ϊ����
//�����ƵĻ����ϼ�һ


//
//int main()
//{
//	int i = -20;
//	unsigned int j = 10;
//	printf("%d\n", i + j);
//	//�ڴ���ȫ�����ǲ���
//	//����Ͳ�������õ�����
//	//����λ���䣬������δȡ��
//	//%d�ǰ����з�������ӡ��
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
//	//����һ�����ö�����λ����һ�¾�֪����ʲô������
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
//	//��ѭ������
//	return 0;
//}



//int main()
//{
//	int n = 9;
//
//	float* pFloat = (float*)&n;
//
//	printf("n��ֵΪ��%d\n", n);
//
//	printf("*pFloat��ֵΪ��%f\n", *pFloat);
//
//	*pFloat = 9.0;
//	printf("num��ֵΪ��%d\n", n);
//
//	printf("*pFloat��ֵΪ��%f\n", *pFloat);
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
//}//ָ������


//
//int main()
//{
//	//double* d[5];
//	//double*(*pd)[5]=&d;
//	//ע�������ָ������ȡָ���ʱ��Ĳ���
//	//��*��*pd��   һ���*�Ǹ�������������
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
//			printf("%d��ˮ�ɻ���\n",ret);
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
//	//������������ѯ
//	//qsort(s, sz, sizeof(s[0]), sort_by_name);
//	//����ѧ�������в�ѯ
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
//    int n = sizeof(names) / sizeof(names[0]); // ����������Ԫ�صĸ���
//    int i;
//
//    printf("Before sorting:\n");
//    for (i = 0; i < n; i++) {
//        printf("%s\n", names[i]);
//    }
//
//    qsort(names, n, sizeof(char*), strcmp); // ����qsort�������ַ��������������
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
//    printf("������Ҫ�����쳲���������������");
//    scanf("%d", &n);
//
//    printf("��%d���쳲���������ֵΪ��%d\n", n, fibonacci(n));
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
//	//������������ѯ
//	//bubble_sort(s, sz, sizeof(s[0]), sort_by_name);
//	//����ѧ�������в�ѯ
//	bubble_sort(s, sz, sizeof(s[0]), sort_by_age);
//	//������´���
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
//	////�������Ǵ���ģ�ʣ�µ����й��������ֵ
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
//	////�������Ǵ���ģ�ʣ�µ����й��������ֵ
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
//	//printf("%d\n", strlen(&p));//6�����6�����ֵ��
//	//printf("%d\n", strlen(&p + 1));//���ֵ��������ֵ��ǰ����Ǹ����ֵû���κι�ϵ��
//	//printf("%d\n", strlen(&p[0] + 1));//5ȡ��a�ĵ�ַ����һ
//
//
//	int a[3][4] = { 0 };
//
//	printf("%d\n", sizeof(a));
//	printf("%d\n", sizeof(a[0][0]));
//	printf("%d\n", sizeof(a[0]));
//	printf("%d\n", sizeof(a[0]+1));
//	//a[0]��Ϊ��������û�е��Ķ�����sizeof�ڲ���//Ҳû��ȡ��ַ������a[0]���ǵ�һ�еĵ�һ�����ĵ�ַ
//	//a[0]+1,���ǵ�һ�еڶ���Ԫ�صĵ�ַ
//	printf("%d\n", sizeof(*(a[0]+1)));
//	//��һ�еĵڶ���Ԫ��
//	printf("%d\n", sizeof(a+1));
//	//a�Ƕ�ά���������������û��ȡ��ַ��Ҳû�е�������sizeof�ڲ�������a�ͱ�ʾ��ά������Ԫ�صĵ�ַ��������һ�е�
//	//��ַ��a+1���Ƕ�ά����ڶ��еĵ�ַ
//	printf("%d\n", sizeof(*(a+1)));
//	//*��a+1���ͱ�ʾa[1]��a[0]һ��ռ�ڴ�Ϊ16
//	//�ڶ��еĴ�С
//	printf("%d\n", sizeof(&a[0]+1));
//	//ȡ����һ�еĵ�ַ��һ���õ����ǵڶ��еĵ�ַ
//	//�ڴ����4/8
//	printf("%d\n", sizeof(*(&a[0]+1)));
//	//ȡ�����ǵڶ��еĵ�ַ��Ȼ��⣬�õ��ڶ���
//	//16
//	printf("%d\n", sizeof(*a));
//	//ֱ�Ӷ�a�����ã���ʱ��a����Ԫ�صĵ�ַ
//	//Ҳ���ǵ�һ�У������õõ����ǵ�һ��
//	printf("%d\n", sizeof(a[3]));
//	//�±�Ϊ3����������ǵ����С�sizeof��a[3]�����������治���ڡ�
//	//���ǻ���16.a[3]ԭ����a[n]
//	//���ʽ����������һ����ֵ���ԣ�һ�����������ԡ�
//	//����int 8��ֵ������8������������int
//	//a[3]������������int[4].sizeof����Ľ���ǣ������������ķ���a[3]
//
//	return 0;
//}


//int main()
//{
//	short s = 5;
//	int a = 4;
//	printf("%d\n", sizeof(s = a + 6));
//	printf("%d\n", s);
//	//��ΪsΪshort���ͣ���aΪint���ͣ�s=a+6���õ���s��Ҫ��һ��short���͵���
//	//��������ֱ�����2���������ټ��㣬�����ٴ�ӡs�õ��Ļ���2
//
//
//}

//int main()
//{
//	int a[5] = { 1,2,3,4,5 };
//	int* ptr = (int*)(&a + 1);//ȡ��ַa+1�õ�����5֮����Ǹ�λ�õĵ�ַ
//	//��ǿ��ת��Ϊint*���͵���������һ������ָ�룬��Ϊ������һ������ָ��
//	printf("%d,%d", *(a + 1), *(ptr - 1));
//	//��Ϊ����ǰ���Ѿ�ǿ��ת����Ϊint*ָ���ˣ�����ptr-1��ǰŲ���ĸ��ֽڡ�
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
//	//����Ľṹ��Ĵ�С��20
//	//����p��1��ֱ������20
//	printf("%p\n",(unsigned long)p+0x1 );
//	//�����p��ǿ��ת��Ϊ�޷������͵�����
//	//����ֱ�������ε���ʽ�������㣬ֱ�Ӽ�һ
//	printf("%p\n", (unsigned int*)p+0x1);
//	//���ﱻת��Ϊ�޷�������ָ�룬һ��ָ��Ĵ�С��4/8
//	// ��������Ǽ�4/8
//	//ָ�����;�����ָ�������
//	return 0;
//	//��δ��������в������ģ���Ϊpû�ж�������ֻ��Ϊ��˵��
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


//str str ��һ���ַ���������һ���ַ���

//int main()
//{
//	char arr1[] = "abcdefghi";
//	char arr2[] = "cdef";
//	char* ret = strstr(arr1, arr2);
//	//��������Ϊchar*
//	if (ret == NULL)
//	{
//		printf("û�ҵ�\n");
// 
//	}
//	else
//	{
//		printf("�ҵ���:%s\n", ret);
//	}
//	return 0;
//}

//kmp�㷨
//strtok���� �и��ַ���
//strerror����������


//// ����һ��ģ��strstr�����ĺ���������Ϊmy_strstr
//char* my_strstr(const char* haystack, const char* needle)
//{
//    // ���needleΪ���ַ������ͷ���haystack
//    if (*needle == '\0')
//    {
//        return (char*)haystack;
//    }
//
//    // ����haystack��ֱ������'\0'�����ҵ�needle
//    while (*haystack != '\0')
//    {
//        // ��������ָ��ֱ�ָ��haystack��needle
//        const char* p1 = haystack;
//        const char* p2 = needle;
//
//        // �Ƚ�����ָ��ָ����ַ��Ƿ���ȣ������ȣ���ͬʱ����һλ�������Ƚ�
//        while (*p1 == *p2 && *p1 != '\0' && *p2 != '\0')
//        {
//            p1++;
//            p2++;
//        }
//
//        // ���p2ָ����'\0'��˵��needle�Ѿ�ƥ����ϣ�����haystack
//        if (*p2 == '\0')
//        {
//            return (char*)haystack;
//        }
//
//        // ����haystack����һλ����������
//        haystack++;
//    }
//
//    // ���������haystack��û���ҵ�needle���ͷ��ؿ�ָ��
//    return NULL;
//}
//
//// ���Ժ���
//int main()
//{
//    // ���������ַ���
//    char s1[] = "Hello, world!";
//    char s2[] = "world";
//
//    // ����my_strstr����������s2��s1�е�λ��
//    char* result = my_strstr(s1, s2);
//
//    // ��ӡ���
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
//{ // ��һ�������ڵ��ļ�
//	FILE *fp = fopen("no_such_file.txt", "r");
//	// ����Ƿ�򿪳ɹ� 
//	
//	if (fp == NULL) 
//	{ // ���ʧ�ܣ���ӡ������Ϣ
//		/*printf("Error: % s\n", strerror(errno));*/
//		perror("fogen");
//		// �˳����� 
//		return -1; 
//	} 
//		// // ����ɹ����ر��ļ� 
//		fclose(fp);
//		// ��������ֵ
//		 return 0;
//}


//int main()
//{
//	char ch = '*';
//	// ��char���͵Ĳ���ǿ��ת��Ϊint����
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
//	//���ļ�
//	FILE* pf = fopen("text.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//		
//	}
//	//д�ļ�
//	fputc('a', pf);
//	fputc('b', pf);
//	fputc('c', pf);
//		//�ر��ļ�
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
//	//��ȡ�ļ�
//	int ch = fgetc(pf);
//	printf("%c\n", ch);
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//	//�ر��ļ�
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
//    //if (NUM == 10)�������NUM��һ���꣬����#define����Ϊ10��
//    // �����������Ϊ�棬�ͻ�ִ��if����Ĵ��룬Ҳ����printf(��NUM is 10\n��);��
//    // ��else����Ĵ���Ͳ���ִ�С�����ж����ڳ�������ʱ���еġ�
////#if x == 20�������x��һ��������������ֵΪ20������#if����ʹ�ñ����������������Ϊ�٣�
//// �ͻ�����#if����Ĵ��룬��#else����Ĵ���ͻᱻ���롣����ж����ڳ������ʱ���еġ�
//    return 0;
//}

//ʹ��#pragma commentָ������ߺͰ汾��Ϣ��Ϊע�ͼ�¼�����ִ���ļ���
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
//		printf("��Ч�Ĵ�ӡ:%d\n", ret);
//	}
//	else if (state == 0)
//	{
//		printf("��Ч�Ĵ�ӡ:%d\n", ret);
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
		ret ^= arr[i];//ע�����ﲻ�ǵ��ںţ�������^=�Ƕ���һ��^�ŵ�
		//^=��ʾ���ǰ�λ�����Ϊ�����ѭ�����ʣ�������Ȼ�����ÿ��ѭ�����
		//��������д���������Ļ���ֻ����������ͬ������
		//������ͬ����������0.һ������0���õ��������������
	}
	for (i = 0; i < 32; i++)
	{
		if (((ret >> i) & 1) == 1)
		{
			//��λ��1�õ��Ľ��ֻ����1����0
			//ret��ǰ�澭�����õ��ģ���ΪҪ���������������ԭ����ڲ���
			//��Ϊret��ǰ�澭�����õ��ģ�����ret�Ĳ����е�һ��Ϊ1�������ǲ��뿪ʼ��ͬ����
			//����00001111011010��00001111001010���õ�����00000000010000����ô��һ������1��λ�ã�����
			//���ǵĲ��뿪ʼ��ͬ��λ��
			//��ͨ�����ѭ���õ����λ��
			pos = i;
			break;
		}
	}
	//pos��Ϊ�������������λ�𣬵�һ������ͬ�Ĳ����λ��
	int num1 = 0;
	int num2 = 0;
	for (i = 0; i < sz; i++)
	{
		if (((arr[i] >> pos) & 1) == 1)
		{
			num1 ^= arr[i];
			//ע�⣬����Ҳ���ǵȺ�
			//���������posλ�Ĳ�����а�λ��1
			//Ȼ��ѵõ����������浽һ���������棬���а�λ����ܵõ�Ŀ�����
		}
		else if(((arr[i] >> pos) & 1) == 0)
		{
			num2 ^= arr[i];
			//ע�⣬����Ҳ���ǵȺ�
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