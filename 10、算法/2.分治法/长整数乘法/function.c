#include "function.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* �˺������ڶ���һ�����ĳ�������x�У��������س�������ʵ�ʳ���*/
int readlongint(char * x)
{
    int count = 0;  //��¼��������ʵ�ʳ���
    char ch;
    int valid = 1; //�ж�������������Ƿ���Ч
    while((ch=getchar()) != '#')  //��#����Ϊ������
    {
        if(ch == '\n')
            continue;
        if(ch >='0' && ch <='9') //�ж�������ַ��Ƿ�����0-9֮��
        {
            x[count] = ch;
            count++;
        }
        else  //������ַ�����0-9֮�䣬˵���������������Ч
            valid = 0;
    }
    if(valid == 1)
    {
        x[count] ='\0';//�ַ���������
        return count;  //������������ʵ�ʳ���
    }
    else
        return -1; //��Ч�������
}
//����һ����Ч��������x
int readdata(char *x)
{
    int count;
    while(1)
    {
        count = readlongint(x);
        if(count == -1)
        {
            printf("�������������Ч���������������.\n");
            continue;
        }
        else
            break;
    }
    return count;
}

//�����ַ���
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
/*�˺�������ʵ�����ַ�����ʾ�ĳ������ļӷ�����*/
char *addition(char *x,char *y)
{
    char *z;  //x��y����ͽ��
    int carry = 0;  //��λ
    int ret; //��ǰλ��ͽ��
    int i;
    int len_x = strlen(x); //x�ĳ���
    int len_y = strlen(y); //y�ĳ���
    int len_z = len_x > len_y ? len_x : len_y; //z�ĳ���ȥx��y�����
    z = (char*)malloc(sizeof(char)*(len_x+1)); //��̬����洢�ռ�
    memset(z,0,len_x+1);//����z��ʼΪ0
    //��x��y�������򷽱�ӵ�λ���λ�������
    reverse_string(x); //����x
    reverse_string(y); //����y
    //�ȼ�����ͬλ����
    for(i=0;i<len_x && i<len_y;i++)
    {
        ret = (x[i]^0x30) + (y[i]^0x30) + carry; //�������ַ�ת��Ϊ��Ӧ�����ֽ������
        z[i] =  (ret % 10) | 0x30; //�����������ת��Ϊ�����ַ��洢z��
        carry = ret / 10;
    }
    //���㻹û�м���ĸ�λ
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
    //����λ�н�λ����Ҫ����
    if(carry)
        z[i++] = carry | 0x30; 
    z[i] = '\0'; //����ַ���ĩβ
    reverse_string(x); //�ָ�ԭ���Ĵ���
    reverse_string(y); //�ָ�ԭ���Ĵ���
    reverse_string(z); //����z���Ӹ�λ����λ���
    return z;
}
/*���������������ƶ�nλ*/
void left_move(char *x,int n)
{
    int len = strlen(x);
    int i;
    realloc(x,(len+n+2)*sizeof(char));
    for(i=0;i<n;i++)
    {
        x[len] = '0'; //ĩβ���һ��0
        len++;
    }
    x[len] = '\0';//�ַ���������
}

//��x�ۼ�n��
char* addition_n_times(char* x,int n)
{
    int i;
    char *z = NULL;
    int len = strlen(x)+2; //�͵ĳ���
    char *ret = (char*)malloc(sizeof(char)*len);
    memset(ret,0,len);  //����Ϊ0
    z = addition(x,"0"); //����zΪx
    strcpy(ret,z);  //��z���浽ret��
    //�ͷ�z���ڴ�ռ�
    if(z != NULL)
        free(z);
    z = NULL;
    for(i=0;i<n;i++)
    {
        z = addition(ret,x); //�����ۼ����
        strcpy(ret,z);
        if(z != NULL)
            free(z);
        z = NULL;
    }
    return ret;
}
/*�˺�������ʵ�����ַ�����ʾ�������������ĳ˷�����*/
char *multiplacation(char * x,char *y)
{
    //��������
    char *z,*c,*ret; //ret������˻����
    int i,m,n;
    int len_x,len_y,len_z;
    //������ʼ��
    z = NULL;
    c = NULL;
    ret = NULL;
    len_x = strlen(x);
    len_y = strlen(y);
    len_z = len_x+len_y+2;

    ret = (char*)malloc(sizeof(char)*(len_z));
    memset(ret,0,len_z+1);
    //y�Ǳ�����
    for(i=0;i<len_y;i++)
    {
        n = len_y-i-1; //��ǰ�����ڵ�λ��
        m = (y[i]^0x30)-1; //��ǰλ������
        c = addition_n_times(x,m); //���ۼƺ�
        left_move(c,n); //���ƶ�nλ
        z = addition(ret,c); //�������
        if(c != NULL)
            free(c);
        c = NULL;
        strcpy(ret,z); //������
    }
    return ret;
}
