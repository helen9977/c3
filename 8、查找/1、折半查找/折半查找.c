#include <stdio.h>
#include <stdlib.h>

#define maxv 100

int Binary_Search(int *arr,int n,int key)
{
	int low,high,mid;
	low=1;
	high=n-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(key==arr[mid])
			return mid;
		else if (key<arr[mid])
			high=mid-1;
		else
			low=mid+1;

	}
	return 0;
}

int main()
{
	int a[maxv],i,N,Key,re;
	scanf("%d",&N);
	for(i=0;i<N;i++)
		a[i]=i;
	scanf("%d",&Key);
	re = Binary_Search(a,N,Key);
	printf("the key position is in ：%d\n",re);
	return 0;

}
