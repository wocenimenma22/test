#include"prefixToInfix.h"
int main()
{

	char middle[100];
	printf("������Ҫ�������׺���ʽ:");
	scanf("%s", middle);
	char last[100];
	change(middle, last);
	printf("��Ӧ�ĺ�׺���ʽΪ��%s\n", last);
	//�����ַ�����ʱ��Ҫ����[],����ᵱ�������ַ�ȥ����
	/*char a[] = "-12132";
	int c=char_to_int(&a);
	printf("%d", c);
	return 0;*/
	int a = caculate(last);
	printf("��׺���ʽ�ļ�����Ϊ%d", a);
	//ע�������ӡ��ʱ��a����Ҫȡ��ַ��
	return 0;
}