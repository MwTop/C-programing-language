#include <stdio.h>

int mark[10];  //全局变量数组默认赋值为0
int n;

void Divid(int now,int k,int prio)
{
   int i;
   if(now > n) return ;
   if(n == 1) printf("1最小不能被划分！\n");
   if(now == n)
   {
     for(i = 0;i < k-1; i++)
       printf("%d+",mark[i]);
	 printf("%d\n",mark[i]);
   }
   else
   {
     for(i=prio;i>0;i--)
	 {
	    if(i<=prio)
		{
		 mark[k]=i;
		 now+=i;
		 Divid(now,k+1,i);
	     now-=i;
		}
	 }
   }
}
int main()
{
   printf("请输入一个正整数：\n");
   scanf("%d",&n);
   Divid(0,0,n-1);
   return 0;
}

