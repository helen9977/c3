#include <iostream>
#include <stdio.h>
using namespace std;

int equationCount(int n,int m)
{
    if(n==1||m==1)
        return 1;
    else if(n<m)
        return equationCount(n,n);
    else if(n==m)
        return 1+equationCount(n,n-1);
    else
        return equationCount(n,m-1)+equationCount(n-m,m);
}

int main()
{
    int n;
    while( scanf("%d",&n)!=EOF && (n>=1&&n<=120))
    {
     cout<<equationCount(n,n)<<endl;
    }
    return 0;
}