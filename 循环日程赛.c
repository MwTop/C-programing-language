#include <stdio.h>
#include "math.h"
#define M 100
#define N 100

 //void Table(int k,int n,int **a);
//void input(int &k);
//void output(int **a,int n);
void gametable(int k);

int main(void)
{
	int k;
//	input(k);
//	int n=1;
//	int p[M][N];
	printf("Please input the number: \n ");
	scanf("%d",&k);
    if(k!=0)
    gametable(k);
    
	return 0;   	
}


	void gametable(int k)
	{
		int a[M][N];
		int n,temp,i,j,t;
		n=2;
		a[1][1]=1;
		a[1][2]=2;
		a[2][1]=2;
		a[2][2]=1;
		 for(t=1;t< k;t++)
		 {
		 	temp=n;n=n*2;
		 	for(i = temp+1; i<=n;i++)
		 	  for(j = 1; j<=temp;j++)
		 	  a[i][j]=a[i-temp][j]+temp;
		 	  
			   for(i = 1; i<=temp;i++)
			   	for(j = temp+1; j<=n;j++)
			   	 a[i][j]=a[i+temp][(j+temp)%n];
			   	 
			   	  for(i =temp+1 ; i<=n ; i++)
			     	for(j = temp+1; j<=n;j++)
			     	a[i][j]=a[i-temp][j-temp];
	    	}
			   printf("the number of athlete: %d\n",n);	 
			   	 for(i=1;i<=n;i++)
			   	   for(j=1;j<=n;j++)
			   	   {  
			   	   	   printf("%d ",a[i][j]);
			   	   	   if(j == n)
			   	   	   printf("\n");
			   	   }
	 }
	
	
	

