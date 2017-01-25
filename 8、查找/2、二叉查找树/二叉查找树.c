#include <stdio.h>
#include <stdlib.h>


#define maxv 100
int key;

typedef struct BiNode
{
	int data;
	struct BiNode *lchild,*rchild;
	
}BiNode,*BiTree;

int CreatBiTree(BiTree *T)
{
  	int c;
	scanf("%d",&c);
	if (c==' ')
		(*T)=NULL;
	else
	{
		*T=(BiTree)malloc (sizeof(BiNode));
		if(!(*T))
			return 0;
		(*T)->data=c;
		scanf("%d",&c);
		if(c<(*T)->data)
			CreatBiTree(&(*T)->lchild);
		else
			CreatBiTree(&(*T)->rchild);
	}

	return 1;
}

int SearchBiTree(BiTree T)
{
		if(T->data==key)
			return T->data;
		else if (T->data < key)
			return SearchBiTree(T->rchild);
		else
			return SearchBiTree(T->lchild);

}

int main()
{
	BiTree T =NULL;
	CreatBiTree(&T);
	scanf("%d",&key);
	SearchBiTree(T);
	return 0;
}