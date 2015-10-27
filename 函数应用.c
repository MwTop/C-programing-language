 #include "stdio.h"
 #define N 5
 int i,j,k;
 void input(int a[][N],int,int);
 void output(int a[][N],int,int);
 void f1(int a[][N],int b[][N],int m,int n);
  int f2(int a[][N],int b[][N],int c[][N],int m,int n);
 void f3(int (*p)[N],int,int);
 int main()
{	int i,j;
    int a[N][N],b[N][N],c[N][N]={0},m,n;
	printf("input m,n:(m,n<=%d)",N);
	scanf("%d %d",&m,&n);
    input(a,m,n);
	output(a,m,n);
	f1(a,b,m,n);
	output(b,n,m);
	f2(a,b,c,m,n); 
	output(c,m,m);
	f3(c,m,n);
	output(c,m,m);
	
	
	
}
void input(int a[][N],int m,int n)
{
	for(i=0;i<m;i++)
	  for(j=0;j<n;j++)
	     a[i][j]=i+j;
}
void output(int a[][N],int m,int n)
{
	for(i=0;i<m;i++)
      { for(j=0;j<n;j++)
	    printf("%4d",a[i][j]);
	    printf("\n");
      }
      printf("\n");
}
void f1(int a[][N],int b[][N],int m,int n)
{
	for(i=0;i<m;i++)
	  for(j=0;j<n;j++)
	  {
  		b[j][i]=a[i][j];
  	  }
}
int f2(int a[][N],int b[][N],int c[N][N],int m,int n)
{
	for(i=0;i<m;i++)
	  for(j=0;j<m;j++)
	    for(k=0;k<n;k++)
	       c[i][j]=a[i][k]*b[k][j];
	       
}
void f3(int (*p)[N],int m,int n)
{    int (*w)[N]=p+m,i=1,s,*t;
	for(p++;p<w;p++,i++)
	  {
 		t=*p;
        s=*t;          /*分数组指针不能直接交换数值*/ 
  	   	*t=*(t+i);
  		*(t+i)=s;
  	  }
}
