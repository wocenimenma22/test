#include"tree.h"
int main()
{
	BiTree gen = (BiTree)malloc(sizeof(BiTNode));
	//�����BiTreeҪ��malloc����һ��ռ���Ϊ�����Ҫ����洢
	inittree(gen);
	morebranch(gen, 1);
	morebranch(gen, 2);
	morebranch(gen->left, 3);
	morebranch(gen->left, 4);
	morebranch(gen->right, 5);
	morebranch(gen->right, 6);
	//real_mid(gen);//�����һλԪ�صĵ�ַ��Ϊ�գ��ú�rtag����1�������������ʱ�����ֹͣ������
	//midrun(gen);
	//real_ord(gen);
	//ordrun(gen);
	//real_fai(gen);
	nofaithread(gen);
	fairun(gen);
	//real_ord(gen);//ͬ��
	/*pre1->right = NULL;
	pre1->rtag = 1;*/
	//faithreaded(gen);
	//faithreaded(gen);
	return 0;
}