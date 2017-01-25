#include <stido.h>
#define maxv 1000
typedef struct 
{
	int arr[maxv+1];
	int length;
	
}sqlist;

/*直接插入*/
void insertsort(sqlist *L)
{
	int i,j;
	for(i=2;i<=L->length;i++)
	{
		if(L->arr[i]<L->arr[i-1])
			L->arr[0]=L->arr[i];
		for(j=i-1;L->arr[j]>L->arr[0];i--)
		{
			L->arr[j+1]=L->arr[j];
		}
		L->arr[j+1]=L->arr[0];
	}

}

/*折半插入*/
void binsertsort(sqlist *L)
{
	int i,j,low,high,mid;
	for(i=2;i<=L->length;i++)
	{
		L->arr[0]=L->arr[i];
		low=1;
		high=i-1;
		while(low<=high)
		{
			mid=(low+high)/2;
			if(L->arr[0]<L->arr[mid])
				high=mid-1;
			else
				low=mid+1;
		}
		for(j=i-1;j>=high+1;j--)
			L->arr[j+1]=L->arr[j];
		L->arr[high+1]=L->arr[0];
	}
}

/*希尔插入*/
void shellinsert(sqlist *L)
{
	int i,j;
	int increment=L->length;
	do{
		increment=increment/3+1;
		for(i=increment+1;i<L->length;i++)
		{
			if(L->arr[i]<L->arr[i-increment])
			 {
			 	L->arr[0]=L->arr[i];
			 	for (j=i-increment;j>0&&L->arr[0]<L->arr[j];j-=increment)
				L->arr[j+increment]=L->arr[j];
				L->arr[j+increment]=L->arr[0];
			 }
		}
	}
	while(increment>1);
}

/*选择排序*/
void selectsort (sqlist *L)
{
	int i,j,min;
	for(i=1;i<L->length;j++)
	{
		min=i;
		for(j=i+1;j<L->length;j++)
		{
			if(L->arr[min]>L->arr[j])
				min = j;

		}
	    
		if(i!=min)
		{
			int temp = L->arr[i];
			L->arr[i]=L->arr[min];
			L->arr[min]=temp;
		}
	}

}


/*堆排序*/
/*建立一个大顶堆*/
void heapadjust(sqlist *L,int s,int m)
{
	int temp;
	int j;
	temp = L->arr[s];
	for(j=2*s;j<=m;j*=2)
	{
		if(j<m&&L->arr[j]<L->arr[j+1])
			++j;
		if(temp>=L->arr[j])
			break;
		L->arr[s]=L->arr[j];
		s=j;
	}
	L->arr[s]=temp;
}

void heapsort(sqlist *L)
{
	int i ;
	for (i=L->length/2;i>0;i--)
	{
		heapadjust(L,i,L->length);
	}
	for(i=L->length;i>1;i--)
	{
		int temp =L->arr[i];
		L->arr[i]=L->arr[1];
		L->arr[1]=temp;
		heapadjust(L,1,i-1);
	}
}

/*归并排序*/
void merge (int sr[],int tr[],int i, int m,int n)
{
	int j,k,l;
	for(j=m+1,k=i;i<=m&&j<=n;k++)
	{
		if (sr[i]<tr[i])
	}
}