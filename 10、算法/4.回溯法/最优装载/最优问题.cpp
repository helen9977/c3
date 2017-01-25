#include"iostream"  
#include"stdlib.h"  
#include <string.h>  
  
/* 
 
 
2 
3 
50 50 
20 10 30 
3 
50 50 
10  40 30 
*/  
using namespace std ;  
class Loading {  
  public :  
  int n ;//集装箱数  
  int w[40] ;//集装箱重量数组  
  int c ;//第一搜轮船的载重量  
  int cw;//当前载重量  
  int bestw;//当前最优载重量  
  int r;//剩余集装箱重量  
public :  
  int maxLoading( )  
  {  
    cw = 0 ;  
    bestw = 0;  
  
    //初始化r  
  
    backtrack(1);  
    //计算最优解  
    return bestw;  
  
  }  
  void backtrack(int i )  
  {  
   
    //搜索第i层结点  
    if(i>n)  
      //到达叶子结点  
    {  
      if(cw>bestw)  
        bestw = cw ;  
      return;  
    }  
    //  
    //搜索子树  
    //！！！  
    r -=w[i];  
    if(cw+w[i]<=c)  
    {  
      //搜索左子树  
      cw+=w[i];  
      backtrack(i+1);  
      cw-=w[i];  
    }  
    if(cw+r>bestw)  
    {  
      backtrack(i+1);  
    }  
    r+=w[i];  
  }  
  
};  
  
  
  
int main()  
{  
  
  Loading load ;  
  int T ;  
  int j =1 ;  
  cin>>T ;  
  int c1 ;  
  while(T>0)  
  {  
      cin>>load.n;  
      cin>>load.c;  
      cin>>c1;  
  
      int i =1 ;  
      int sum = 0;  
      load.r =0 ;  
      while(i<=load.n)  
      {  
          cin>>load.w[i];  
          load.r=load.r+load.w[i];  
       //   cout<<"第"<<i<<"个集装箱"<<load.w[i]<<endl;  
          sum+=load.w[i];  
          i++;  
  
      }  
     // cout<<"sum:"<<sum<<endl;  
      load.maxLoading();  
      if(load.bestw>0&& ((sum-load.bestw)<=c1))  
      {  
          cout<<"Case "<<j<<":"<<endl;  
          cout<<load.bestw<<endl;  
      }else if(sum<=c1){  
          cout<<"Case "<<j<<":"<<endl;  
          cout<<load.bestw<<endl;  
  
      }else{  
          cout<<"Case "<<j<<":"<<endl;  
          cout<<"No"<<endl;  
      }  
    load.bestw = 0 ;  
    load.c = 0;  
    load.cw = 0;  
    load.n  = 0 ;  
    load.r = 0 ;  
    int b =1 ;  
    for(  ;  b <40 ; b ++)  
        load.w[b]=0;  
    T--;  
    j++;  
  }  
  
  
  return 0 ;  
}  
