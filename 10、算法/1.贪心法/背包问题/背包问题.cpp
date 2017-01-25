#include <iostream>
#include <algorithm>

#define N 3//物品总数
#define SUM 50 //背包可容纳最大重量

using namespace std;

struct pack
{

	float w,v;

}f[N];

bool com(pack x,pack y)
{
	float a,b;
	a=(x.v)/(x.w);
	b=(y.v)/(y.w);
	return a>b;
}

void package(int n, pack f[],float x[])
{

	float c=SUM;
	int i;
	for (i=0;i<n;i++)
	{
		x[i]=0;
	}

	for(i=0;i<n;i++)
	{
		if(f[i].w>c)
			{break;}
		x[i]=1;
		c-=f[i].w;
	}
	if (i<n)
	{
		x[i]=c/f[i].w;
	}

}
int main ()
{
	pack f[N];
	float x[N];
	for(int i=0;i<N;i++)
	{
		cin>>f[i].w>>f[i].v;
	}
	sort (f,f+N,com);
	package(N,f,x);
	cout<<"物品单位价值排序如下"<<endl;
	for(int i=0; i<N; i++)  
    {  
        cout<<"["<<i<<"]:("<<f[i].w<<","<<f[i].v<<")"<<endl;  
    }  
	cout<<"选择装下物品的比例如下："<<endl;  
    for(int i=0; i<N; i++)  
    {  
        cout<<"["<<i<<"]:"<<x[i]<<endl;  
    }  
  
    return 0;  
}
