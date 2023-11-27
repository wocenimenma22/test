#include"head.h"

void inittree(PRTree* nod)
{
	int i = 0;
	while (i < MAX_SIZE)
	{
		nod->nodes[i].parent = -1;
		i++;
	}
	nod->nodes[0].data = 0;
	nod->n = 1;
}

void inpuut(PRTree* nod, int i,int parent,Element a)
{
	if(nod->n<MAX_SIZE)
	{
		nod->nodes[i].data = a;
		nod->nodes[i].parent = parent;
		nod->n = nod->n + 1;
	}
	return;
}

void poptree(PRTree* nod, int n)
{
	nod->nodes[n].parent = -1;
	nod->nodes[n].data = NULL;
	nod->n = nod->n - 1;
}

int task1(PRTree* nod, int i, int j)
{
	while (i!=-1&&j!=-1)
	{
		if (i > j)
		{
			i = nod->nodes[i].parent;
		}
		else if (i < j)
		{
			j = nod->nodes[j].parent;
		}
		else
		{
			Element a = nod->nodes[i].data;
			printf("这两个结点的最近的共同的祖先是%d\n", a);
			return i;
		}
	}
	return NULL;
}
