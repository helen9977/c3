#ifndef FUNCTUON_HEAD
#define FUNCTION_HEAD

//大数计算函数声明

/* 此函数用于读入一个正的长整数到x中，函数返回长整数的实际长度*/
int readlongint(char * x);
//读入一个有效的正整数x
int readdata(char *x);
//逆序字符串
void reverse_string(char *x);

/*此函数用于实现用字符串表示的长整数的加法运算*/
char *addition(char *x,char *y); 
//x累计n次
char* addition_n_times(char* x,int n);
/*将正整数进行左移动n位*/
void left_move(char *x);
/*此函数用于实现用字符串表示的两个长整数的乘法运算*/
char *multiplacation(char * x,char *y);

#endif
