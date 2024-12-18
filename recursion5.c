#include<stdio.h>
void lmn(int);
void pqr(int);
int main()
{
pqr(1);
}
void pqr(int p)
{
if(p==6) return ;
lmn(p);
}
void lmn(int e)
{
printf("%d\n",e*e);
pqr(e+1);
}