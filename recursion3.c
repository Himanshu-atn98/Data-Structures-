#include<stdio.h>
int lmn(int);
int main()
{
int x,y;
x=5;
y=lmn(x);
printf("%d",y);
return 0;
}
int lmn(int p)
{
int n;
if(p==1) return 1;
n=lmn(p-1)*p;
return n;
}