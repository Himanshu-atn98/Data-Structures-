#include<stdio.h>
void lmn(int);
int main()
{
lmn(1);
return 0;
}
void lmn(int p)
{
if(p==4)
{
return;
}
lmn(p+1);
printf("%d\n",p);
}
