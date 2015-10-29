/*利用函数成绩排序 */ 

#include "stdio.h"
#define M  10
void input(int a[M]);
void output(int a[M]);
void change(int a[M]);
int m;
int main()
{
    int a[M];
    printf("please input m:");
	scanf("%d",&m);
	input(a);
	printf("\n\n");
    output(a);
    change(a);  //排序
}
void input(int a[M])
{
	int i; 
	printf("输入成绩：\n"); 
	for(i=0;i<m;i++)
		scanf("%d",&a[i]);
}
void change(int a[M])
{
	int *p[M],*q;
	int i,j;
	for(i=0;i<m;i++)
      p[i]=&a[i];
    for(i=0;i<m-1;i++)
	{
		for(j=0;j<m-1-i;j++)
			if(*p[j]>*p[j+1])
			{ q=p[j];p[j]=p[j+1];p[j+1]=q;}
	}
	printf("\n正确的排序为 :\n");
	for(i=0;i<m;i++)
		printf("%d\t",*p[i]);
	    printf("\n");
}

void output(int a[M])
{
	int i;
    for(i=0;i<m;i++)
		printf("%d\t",a[i]);
		printf("\n"); 
}
