#include"prefixToInfix.h"
int main()
{

	char middle[100];
	printf("请输入要计算的中缀表达式:");
	scanf("%s", middle);
	char last[100];
	change(middle, last);
	printf("对应的后缀表达式为：%s\n", last);
	//定义字符串的时候，要加上[],否则会当作单个字符去处理
	/*char a[] = "-12132";
	int c=char_to_int(&a);
	printf("%d", c);
	return 0;*/
	int a = caculate(last);
	printf("后缀表达式的计算结果为%d", a);
	//注意这里打印的时候，a不需要取地址。
	return 0;
}