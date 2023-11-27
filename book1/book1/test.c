#include"head.h"
int main()
{
	PRTree a;
	
	inittree(&a);
	inpuut(&a, 1, 0,1);
	inpuut(&a, 2, 0, 2);
	inpuut(&a, 3, 1, 3);
	inpuut(&a, 4, 1, 4);
	inpuut(&a, 5, 1, 5);
	inpuut(&a, 6, 0, 6);
	inpuut(&a, 7, 2, 7);
	inpuut(&a, 8, 2, 8);
	inpuut(&a, 9, 2, 9);
	inpuut(&a, 10, 3,10);
	inpuut(&a, 12, 3,12);
	inpuut(&a, 13, 3,13);
	inpuut(&a, 14, 4,14);
	inpuut(&a, 15, 4,15);
	inpuut(&a, 16, 4,16);
	inpuut(&a, 17, 7,17);
	inpuut(&a, 18, 7,18);
	inpuut(&a, 19, 7,19);
	inpuut(&a, 20, 17,20);
	inpuut(&a, 21, 18,21);
	inpuut(&a, 22, 19,22);
	int tasknumber1 = task1(&a, 6, 20);
	return 0;
}