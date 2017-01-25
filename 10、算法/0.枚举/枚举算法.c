# include <stdio.h>
/*
int main()
{ 
	int a,b,c,d;//四个空间
	int s=0;
	for(a=1;a<5;a++)
		for(b=1;b<5;b++)
			for(c=1;c<5;c++)
				for(d=1;d<5;d++)
				{
					if(a!=b && a!=c && b!=d && c!=d )
					{
						s++;
					}
				}
	printf("%d\n",s);
	return 0;
}

*/

int main()
{
	int chicken,rabbit;
	for(chicken=1;chicken<47;chicken++)
		for(rabbit=1;rabbit<24;rabbit++)
			if(chicken+rabbit==35 && chicken*2+rabbit*4==94)
				printf("%d %d\n",chicken,rabbit);
	return 0;
}
