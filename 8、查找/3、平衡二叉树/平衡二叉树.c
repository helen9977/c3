#include <stdio.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 

#define LH +1 //左高
#define EH  0
#define RH -1 //右高

typedef int Status;
typedef int ElemType;

typedef struct BSTNode
{
	ElemType data;
	int bf; //结点的平衡因子
	struct BSTNode *lchild,*rchild;
}BSTNode, *BSTree;

void R (BSTree *p) //右旋转
{
	BSTree lc;
	lc=(*p)->lchild;
	(*p)->lchild=lc->rchild;
	lc->rchild=*p;
	*p=lc;
}

void L (BSTree *p)//左旋转
{
	BSTree rc;
	rc=(*p)->rchild;
	(*p)->rchild = rc->lchild;
	rc->lchild=*p;
	*p=rc;
}



void LeftBalance(BSTree *T)
{
	BSTree lr,l;
	l=(*T)->lchild;
	switch(l=>bf)
	{
		case LH:
			(*T)->bf=l->bf=EH;
			R(T);
			break;
		case RH:
			lr=l->rchild;
			switch:
				case LH:
				(*T)->bf=RH;
				l->bf=EH;
				break;
				case EH:
				(*T)->bf=l->bf=EH;
				break;
				case RH:
				(*T)->bf=EH;
				l->bf=LH;
				break;

	}
	lr-bf=EH;
	L (&(*T)->lchild);
	R (T);	
}

void RightBalance (BSTree *T)	
{
	BSTree r,rl;
	r=(*T)->rchild;
	switch(r->bf)	
	{
		case RH:
			(*T)->bf=r->bf=EH;
			L (T);
			break;	
		case LH:
			rl=r->lchild;
			switch(rl->bf)
			{
				case RH:
					(*T)->bf=LH;
					r->bf=EH;
					break;
				case EH:
					(*T)->bf=r->bf=EH;
					break;
				case LH:
					(*T)->bf=EH;
					r-bf=RH;
					break;
			}
		rl-bf=EH;
		R (&(*T)->rchild);
		L (T);
	}
}

void InsertAVL(BSTree *T,int e,BOOL *taller)
{
	if(!*T)
	{
		*T=(BSTree)malloc (sizeof(BSTNode));
		(*T)->data =e;
		(*T)->lchild=(*T)->rchild=NULL;
		(*T)->bf=EH;
		*taller =TRUE;
	}

	else
	{
		if(e==(*T)->data)
		{
			taller = FALSE;
			return FALSE;
		}

		if(e<(*T)->data)
		{
			if(!InsertAVL(&(*T)->lchild,e,taller))
				return FALSE;
			if(taller)
				switch((*T)->bf):
				{
					case LH:
						LeftBalance(T);
						*taller=FALSE;
						break;
					case EH:
						(*T)->bf=LH;
						*taller=TRUE;
						break;
					case RH:
						(*T)->bf=EH;
						*taller=FALSE;
						break;
				}	
		}
		else
		{
			if(!InsertAVL(&(*T)->rchild,e,taller))
				return FALSE;
			if(*taller)
			{
				switch((*T)->bf)
				{
					case LH:
						(*T)->bf=EH;
						*taller=FALSE;
						break;
					case EH:
						(*T)->bf=RH;
						*taller=TURE;
						break;
					case RH:
						RightBalance(T);
						*taller=FALSE;
						break;
				}
			}
		}
	}
	return TRUE;
}