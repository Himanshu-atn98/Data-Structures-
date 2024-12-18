#include<stdio.h>
#include<string.h>
void linearSort(int *,int);
int main()
{
int a[]={151,147,63,52,23,111,251,89,14,20};
int b[]={45,80,32,35,11,90,121,42,248,21};
int length1=0;
int length2=0;

length1=sizeof(a)/sizeof(int) ;
length2=sizeof(b)/sizeof(int) ;
printf("Length2:%d\n",length2);

/*
for(int e=0;e<length1;e++)
{
printf("Enter the number:");
scanf("%d",&a[e]);
}
//printf("Sorted Data\n");
*/
linearSort(a,length1);
printf("larg1:%d\n",a[length1-1]);

linearSort(b,length2);
printf("larg2:%d\n",b[length2-1]);

if(a[length1-1]>b[length2-1]) printf("Large Number:%d\n",a[length1-1]);
else printf("Large Number:%d\n",b[length2-1]);
 
return 0;
}

void linearSort(int *p,int size)
{
int f,g;
for(int e=0;e<=size-2;e++)
{
f=e+1;

while(f<=size-1)
{
if(p[e]>p[f])
{
g=p[e];
p[e]=p[f];
p[f]=g;
}
f++;
}

}
}