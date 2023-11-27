#include"tree.h"
int main()
{
	BiTree gen = (BiTree)malloc(sizeof(BiTNode));
	inittree(gen);
	morebranch(gen, 1);
	morebranch(gen, 2);
	morebranch(gen->left, 3);
	morebranch(gen->left, 4);
	morebranch(gen->right, 5);
	morebranch(gen->right, 6);
	morebranch(gen->left->left, 7);
	morebranch(gen->left->left, 7);
	morebranch(gen->left->right, 7);
	morebranch(gen->left->right, 7);
	morebranch(gen->right->left, 7);
	morebranch(gen->right->left, 7);
	morebranch(gen->right->right, 7);
	morebranch(gen->right->right, 7);

	//gen->right= NULL;
	//int a = Btdepth(gen);
	//printf("%d\n", a);
	//judge(gen);
	//printf("\n");
	//int arr[] = {1,2,4,5,3,6,7};
	//int arr2[] = {4,2,5,1,6,3,7};
	//BiTree p = PreInCreat(arr, arr2, 0, 6, 0, 6);
	/*int a = treedeep(gen);
	printf("%d\n", a);
	PreOrder(gen);
	printf("\n");
	MidOrder(gen);
	printf("\n");
	FaiOrder(gen);
	printf("\n");
	level_order(gen);
	noMidOrder(gen);
	printf("\n");
	noPreOrder(gen);
	printf("\n");
	noFaiOrder(gen);
	printf("\n");*/
	//fanlevel_order(gen);
	//noFaiOrder(p);
	//printf("\n");
	/*int a = alevel_order(gen);
	printf("%d", a);*/
	//blevel_order(gen);
	//kpre(gen, 4);
	//delpre(gen, 4);
	//noFaiOrder(gen);
	//xparent(gen,4);

	//ownparent(gen, gen->left->left, gen->left->right);

	//longest(gen);

	int arr[7] = { 0,1,3,4,2,5,6 };
	//printfFai(arr, 7);
	int arr2[7];
	printfFai2(arr, 7, arr2);
	return 0;
}