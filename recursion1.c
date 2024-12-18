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
printf("%d\n",p);
lmn(p+1);
}
