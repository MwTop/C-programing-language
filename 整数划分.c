#include <stdio.h>

int mark[10];  //ȫ�ֱ�������Ĭ�ϸ�ֵΪ0
int n;

void Divid(int now,int k,int prio)
{
   int i;
   if(now > n) return ;
   if(n == 1) printf("1��С���ܱ����֣�\n");
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
   printf("������һ����������\n");
   scanf("%d",&n);
   Divid(0,0,n-1);
   return 0;
}

