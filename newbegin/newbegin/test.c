#include"hhh.h"
int main()
{
	Stracts a;
	Initializes(&a);
	StractPush(&a, 1);
	print(&a);

	StractPush(&a, 2);
	StractPush(&a, 3);
	StractPush(&a, 4);
	StractPush(&a, 5);
	StractPush(&a, 6);
	print(&a);

	StractPop(&a);
	StractPop(&a);
	print(&a);
	return 0;
}

