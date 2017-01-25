#include "function.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 此函数用于读入一个正的长整数到x中，函数返回长整数的实际长度*/
int readlongint(char * x)
{
    int count = 0;  //记录正整数的实际长度
    char ch;
    int valid = 1; //判断输入的正整数是否有效
    while((ch=getchar()) != '#')  //‘#’作为结束符
    {
        if(ch == '\n')
            continue;
        if(ch >='0' && ch <='9') //判断输入的字符是否是在0-9之间
        {
            x[count] = ch;
            count++;
        }
        else  //输入的字符不在0-9之间，说明输入的正整数无效
            valid = 0;
    }
    if(valid == 1)
    {
        x[count] ='\0';//字符串结束符
        return count;  //返回正整数的实际长度
    }
    else
        return -1; //无效整数标记
}
//读入一个有效的正整数x
int readdata(char *x)
{
    int count;
    while(1)
    {
        count = readlongint(x);
        if(count == -1)
        {
            printf("输入的正整数无效，请输入的正整数.\n");
            continue;
        }
        else
            break;
    }
    return count;
}

//逆序字符串
void reverse_string(char *x)
{
    int len = strlen(x);
    int i;
    char ch;
    for(i=0;i<len/2;i++)
    {
        ch = x[i];
        x[i] = x[len-i-1];
        x[len-i-1] = ch;
    }
}
/*此函数用于实现用字符串表示的长整数的加法运算*/
char *addition(char *x,char *y)
{
    char *z;  //x和y的求和结果
    int carry = 0;  //进位
    int ret; //当前位求和结果
    int i;
    int len_x = strlen(x); //x的长度
    int len_y = strlen(y); //y的长度
    int len_z = len_x > len_y ? len_x : len_y; //z的长度去x和y中最长的
    z = (char*)malloc(sizeof(char)*(len_x+1)); //动态分配存储空间
    memset(z,0,len_x+1);//设置z初始为0
    //将x和y进行逆序方便从低位向高位求和运算
    reverse_string(x); //逆序x
    reverse_string(y); //逆序y
    //先计算相同位数的
    for(i=0;i<len_x && i<len_y;i++)
    {
        ret = (x[i]^0x30) + (y[i]^0x30) + carry; //将数字字符转换为对应的数字进行求和
        z[i] =  (ret % 10) | 0x30; //将计算的数字转换为数字字符存储z中
        carry = ret / 10;
    }
    //计算还没有计算的高位
    while(i<len_x)
    {
        ret = (x[i]^0x30) + carry;
        z[i] =  (ret % 10) | 0x30;
        carry = ret / 10;
        i++;
    }
    while(i<len_y)
    {
        ret = (y[i]^0x30) + carry;
        z[i] =  (ret % 10) | 0x30;
        carry = ret / 10;
        i++;
    }
    //最后高位有进位，需要考虑
    if(carry)
        z[i++] = carry | 0x30; 
    z[i] = '\0'; //添加字符串末尾
    reverse_string(x); //恢复原来的次序
    reverse_string(y); //恢复原来的次序
    reverse_string(z); //逆序z，从高位到低位输出
    return z;
}
/*将正整数进行左移动n位*/
void left_move(char *x,int n)
{
    int len = strlen(x);
    int i;
    realloc(x,(len+n+2)*sizeof(char));
    for(i=0;i<n;i++)
    {
        x[len] = '0'; //末尾添加一个0
        len++;
    }
    x[len] = '\0';//字符串结束符
}

//将x累加n次
char* addition_n_times(char* x,int n)
{
    int i;
    char *z = NULL;
    int len = strlen(x)+2; //和的长度
    char *ret = (char*)malloc(sizeof(char)*len);
    memset(ret,0,len);  //设置为0
    z = addition(x,"0"); //设置z为x
    strcpy(ret,z);  //将z保存到ret中
    //释放z的内存空间
    if(z != NULL)
        free(z);
    z = NULL;
    for(i=0;i<n;i++)
    {
        z = addition(ret,x); //进行累加求和
        strcpy(ret,z);
        if(z != NULL)
            free(z);
        z = NULL;
    }
    return ret;
}
/*此函数用于实现用字符串表示的两个长整数的乘法运算*/
char *multiplacation(char * x,char *y)
{
    //变量定义
    char *z,*c,*ret; //ret存放最后乘积结果
    int i,m,n;
    int len_x,len_y,len_z;
    //遍历初始化
    z = NULL;
    c = NULL;
    ret = NULL;
    len_x = strlen(x);
    len_y = strlen(y);
    len_z = len_x+len_y+2;

    ret = (char*)malloc(sizeof(char)*(len_z));
    memset(ret,0,len_z+1);
    //y是被乘数
    for(i=0;i<len_y;i++)
    {
        n = len_y-i-1; //当前数字在的位数
        m = (y[i]^0x30)-1; //当前位的数字
        c = addition_n_times(x,m); //求累计和
        left_move(c,n); //左移动n位
        z = addition(ret,c); //进行求和
        if(c != NULL)
            free(c);
        c = NULL;
        strcpy(ret,z); //保存结果
    }
    return ret;
}
