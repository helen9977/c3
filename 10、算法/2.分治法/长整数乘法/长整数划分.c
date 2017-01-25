#include "function.h"
#include <stdlib.h>
#include <stdio.h>

#define MAXNUM 256

void menu(); //菜单函数声明
char a[MAXNUM];
char b[MAXNUM];

int main()
{
    int count_a,count_b;
    char *c;
    int choice,flag;
    flag = 0;
    c = NULL;
    menu();
    while(1)
    {
        printf("\n请选择操作: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("请输入长正整数a(输入'#'结束): ");
            count_a = readdata(a);
            printf("请输入长正整数b(输入'#'结束): ");
            count_b = readdata(b);
            printf("长正整数a为: %s\n",a);
            printf("长正整数b为: %s\n",b);
            flag = 1;
            break;
        case 2:
            if(flag == 1)
            {
                c = addition(a,b);
                printf("两个大正整数的和为: %s\n",c);
            }
            else
             printf("请先输入两个长正整数,再执行求和操作.\n");
            break;
        case 3:
            if(flag == 1)
            {
                c = multiplacation(a,b);
                printf("两个大正整数的乘积为: %s\n",c);
            }
            else
             printf("请先输入两个长正整数，再执行乘积操作.\n");
            break;
        case 0:
            printf("谢谢使用，再见.\n");
            system("pause");
            exit(0);
        default:
            printf("输入错误，请按要求选择操作.\n");
        }
    }
    return 0; 
}

void menu()
{
    printf("长正整数运算.\n");
    printf("1.输入两个长正整数.\n");
    printf("2.求两个长正整数的和.\n");
    printf("3.求两个长正整数的积.\n");
    printf("0.退出操作.\n");
}
