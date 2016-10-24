#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int JM(int M,int e,int n){
    int C=M;
	int i;
	for(i=1;i<e;i++)
	{	C*=M; C%=n;}
//	C=pow(M,e);
//	printf("%ld",C);
//	C=C%n;
	return C;
}
int XM(long P,int d,int n){
    int Ming=P,i;
	for(i=1;i<d;i++){
	  Ming*=P; Ming%=n;
	}
	return Ming;
}

void RSA(int a,int b){
	int e,d,M;
	int k=1;   //标志位
	long P,Q;
    int n=a*b;
    int N=(a-1)*(b-1);  //使用N表示failn
	printf("N=(p-1)*(q-1)=%d\n",N);
    printf("输入一个整数e与N互素且小于N的数:");
    scanf("%d",&e);
   do{
	  if(N%e==0){ 
		  k=0;
		  printf("N与e不互素，请重新输入整数e的值："); //判断N与e是否互素
		  scanf("%d",&e);
	  }
	  else k=1;
   }while(k<1);
   for(d=1;d < N;d++){
	   if((d*e)%N == 1){
		  printf("d=%d\n",d);
		  break;
	   }
   }
   printf("公钥KU={%d,%d},私钥KR={%d,%d}\n",e,n,d,n);
   printf("输入需要传输的数字M(M<n)的值：");
   scanf("%d",&M);
    P=JM(M,e,n);
   printf("经过加密后密文为：%ld\n",P);
   Q=XM(P,d,n);
   printf("经过解密后明文为：%ld\n",Q);
}

int Issushu(int m,int n){
   int flag1=1,flag2=1;
   int i;
   for(i=2;i<m;i++)
     if(m%i==0){
		 flag1=0;i=m;
   }
    for(i=2;i<n;i++)
     if(n%i==0){
		 flag2=0;i=n;
   }
	 if(flag1==1 && flag2==1)
	 { printf("p和q都为素数！\n"); return 1;}
	 else {printf("抱歉，p和q不满足互为素数!请重新输入：\n");
	      return 0;
	     //  exit(0);    
	 }
}

int main(){
   int p,q,t;
   char ch;
   printf("\t*******以下是RSA加密算法的模拟过程：********\n");
   do{
       printf("请输入两个素数p,q：");
   	do{
     	scanf("%d %d",&p,&q);
    	t=Issushu(p,q);
	}while(t==0);
     RSA(p,q);
     printf("\n是否继续?y or n:");
     fflush(stdin);
     ch=getchar();
   }while(ch!='n');
   return 0;
}
