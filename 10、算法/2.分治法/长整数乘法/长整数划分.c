#include "function.h"
#include <stdlib.h>
#include <stdio.h>

#define MAXNUM 256

void menu(); //�˵���������
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
        printf("\n��ѡ�����: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("�����볤������a(����'#'����): ");
            count_a = readdata(a);
            printf("�����볤������b(����'#'����): ");
            count_b = readdata(b);
            printf("��������aΪ: %s\n",a);
            printf("��������bΪ: %s\n",b);
            flag = 1;
            break;
        case 2:
            if(flag == 1)
            {
                c = addition(a,b);
                printf("�������������ĺ�Ϊ: %s\n",c);
            }
            else
             printf("��������������������,��ִ����Ͳ���.\n");
            break;
        case 3:
            if(flag == 1)
            {
                c = multiplacation(a,b);
                printf("�������������ĳ˻�Ϊ: %s\n",c);
            }
            else
             printf("������������������������ִ�г˻�����.\n");
            break;
        case 0:
            printf("ллʹ�ã��ټ�.\n");
            system("pause");
            exit(0);
        default:
            printf("��������밴Ҫ��ѡ�����.\n");
        }
    }
    return 0; 
}

void menu()
{
    printf("������������.\n");
    printf("1.����������������.\n");
    printf("2.���������������ĺ�.\n");
    printf("3.���������������Ļ�.\n");
    printf("0.�˳�����.\n");
}
