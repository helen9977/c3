#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int maxv=1000;
int N,W;//商品个数，背包重量

struct node 
{
	int v,w;
    
}commodity[1000];

int book[1000][1000];

/*寻找哪些物品被装入背包中*/
void print()
{
    int remindspace = W;
    for(int i=N;i>0;i--)
    {
        if (commodity[i].w<=remindspace)
        {
            if(commodity[i].v==book[i][remindspace]-book[i-1][remindspace-commodity[i].w])
            {
                cout<<"goods "<<i<<" is selected!"<<endl;
                remindspace-=commodity[i].w;  
            }
        }
    }

}


/*生成book表，最优子结构*/
void max_value()
{
	for(int i=1;i<=N;i++)
		for(int w=1;w<=W;w++)
	    {
    		if (commodity[i].w<=W)
    		{
    			book[i][w]=max(book[i-1][w],book[i-1][w-commodity[i].w]+commodity[i].v);
    		}
    		else
    		{
    			book[i][w]=book[i-1][w];
    		}
        }

}

int main ()
{
	cin>>N;
    cin>>W;
	memset(commodity,0,sizeof(commodity));
	memset(book,0,sizeof(book));
	for(int i=1;i<=N;i++)
	{
		cin>>commodity[i].v;
		cin>>commodity[i].w; 
	}
	max_value(); 
	print();
    cout<<"the max_value is :"<<endl;
    cout<<book[N][W];

	return 0;
}
