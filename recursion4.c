#include<stdio.h>
void lmn(int,int);
int main()
{
lmn(0,1);
return 0;
}
void lmn(int p1,int p2)
{
int sum;
if(p2==55 || p2>55) return ;
if(p1==0) printf("p2: %d\n",p2);
sum=p1+p2;
printf("Sum: %d\n",sum);
lmn(p2,sum);
//printf("Sum: %d\n",sum);
}
