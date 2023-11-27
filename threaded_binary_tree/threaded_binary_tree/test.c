#include"tree.h"
int main()
{
	BiTree gen = (BiTree)malloc(sizeof(BiTNode));
	//这里的BiTree要用malloc申请一块空间因为这个是要链表存储
	inittree(gen);
	morebranch(gen, 1);
	morebranch(gen, 2);
	morebranch(gen->left, 3);
	morebranch(gen->left, 4);
	morebranch(gen->right, 5);
	morebranch(gen->right, 6);
	//real_mid(gen);//把最后一位元素的地址变为空，让后rtag等于1这样中序遍历的时候就能停止下来。
	//midrun(gen);
	//real_ord(gen);
	//ordrun(gen);
	//real_fai(gen);
	nofaithread(gen);
	fairun(gen);
	//real_ord(gen);//同上
	/*pre1->right = NULL;
	pre1->rtag = 1;*/
	//faithreaded(gen);
	//faithreaded(gen);
	return 0;
}