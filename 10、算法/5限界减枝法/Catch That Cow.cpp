#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

int N,K;
int book[100001];

struct node
{
    int x;
    int p;//步数
};

int ifok(int y)
{
    if (y==K)
        return 1;
    else 
        return 0;
} 

int BFS()
{
    queue<node>q;
    node next1,next2,next3,cur;
    cur.x=N;
    cur.p=0;
    q.push(cur);
    while (!q.empty())
    {
        cur=q.front();
        q.pop();

        if(ifok(cur.x))
            return cur.p;

        next1.x=cur.x+1;
        next2.x=cur.x-1;
        next3.x=cur.x*2;

        if(book[next1.x]==0)
        {
            next1.p=cur.p+1;
            q.push(next1);
            book[next1.x]=1;
        }
        if(next2.x>=0 && book[next2.x]==0)
        {
            next2.p=cur.p+1;
            q.push(next2);
            book[next2.x]=1;
        }
        if(next3.x<=100000 && (next3.x-K)<(K-cur.x) && book[next3.x]==0)
        {
            next3.p=cur.p+1;
            q.push(next3);
            book[next3.x]=1;
        }
    }
    return 0;
}

int main()
{
    

    while (scanf("%d%d",&N,&K)!=EOF)
    {
        memset(book,0,sizeof(book));
        int step;
        if (N>K)
            step=N-K;
        else step = BFS();
        printf("%d\n",step);
    }

    
    return 0;


}
