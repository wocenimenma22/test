#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//int main()
//{
//    //int n, i, a = 1, b = 1, c;
//    //printf("������Ҫ�����쳲��������е�������");
//    //scanf("%d", &n);
//    //printf("쳲��������е�ǰ%d��Ϊ��\n", n);
//    //printf("%d\n%d\n", a, b); //��ӡ��һ��͵ڶ���
//    //for (i = 3; i <= n; i++) //�ӵ����ʼѭ��
//    //{
//    //    c = a + b; //���㵱ǰ��Ϊǰ����֮��
//    //    printf("%d\n", c); //��ӡ��ǰ��
//    //    a = b; //����ǰ�����ֵ
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
//		//�ȴ������
//	zhuazhi(arr, k, sz-1);
//	    //���ұ�
//	zhuazhi(arr, 0, sz-1);
//	    //���һ��
//}
//
//int main()
//{
//	int arr[] = { 3,4,2,0 ,10,2,4};
//	int k = 0;
//	printf("������Ҫ��ת����:");
//	scanf("%d", &k);
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	zhuanhuan(arr, sz,k);
//	//int a=find(arr, sz);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d   ", arr[i]);
//	}
//	//printf("�������%d", a);
//	return 0;
//}

//struct student {
//    int score;
//    char name[];
//};
//
//int main() {
//    // ����һ��ָ����� 3 ��ѧ���������ָ��
//    struct student* students[3];
//
//    // Ϊÿ��ѧ�������ڴ沢��ֵ
//    for (int i = 0; i < 3; i++) {
//        students[i] = malloc(sizeof(struct student) + sizeof(char) * 10);
//    }
//    strcpy(students[0]->name, "����");
//    students[0]->score = 91;
//    strcpy(students[1]->name, "����");
//    students[1]->score = 80;
//    strcpy(students[2]->name, "����");
//    students[2]->score = 85;
//
//    // ��ӡ�������������
//    for (int i = 0; i < 3; i++) {
//        printf("������%s���ɼ���%d\n", students[i]->name, students[i]->score);
//    }
//
//    // �ͷ�����������ڴ�
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
//	// ֱ��ʹ�������ڴ�
//	strcpy(students[0].name, "����");
//	students->score = 91000;
//
//	strcpy(students[1].name, "����");
//	students[1].score = 80;
//
//	strcpy(students[2].name, "����");
//	students[2].score = 85;
//
//	// ��ӡ
//	printf("����:%s,�ɼ�:%d\n", students->name, students->score);
//	printf("����:%s,�ɼ�:%d\n", students[1].name, students[1].score);
//	printf("����:%s,�ɼ�:%d\n", students[2].name, students[2].score);
//
//	// �ͷ��ڴ�
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