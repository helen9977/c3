#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int greedySelector(int s[],int f[],int a[],int t)//s存储开始时间，f存储结束时间，a表示是否能相容
{
    int n=10;
    a[1]=1;
    int j=t,i,count=1;
    for(i=t+1;i<n;i++)
    {
        if(s[i]>=f[j])
    	{
            a[i]=1;
            j=i;
            count++;
        }
        else a[i]=0;
    }
    return count;
}
int main()
{
    int s[10]={1,4,0,6,7,5,9,10,2,8};
    int f[10]={3,5,6,7,9,12,14,16,17,20};
    int a[10],count[10],i,max;
    for(i=0;i<9;i++)
    {
        count[i]=greedySelector(s,f,a,i);
    }
    max=count[1];
    for(i=0;i<9;i++)
        if(count[i]>max)
            max=count[i];
    printf("%d",max);

    return 0;
}
