#include<stdio.h>
void printArray(int *arr,int size)
{
for(int i=0;i<=size-1;i++)
{
printf("%d ",arr[i]);
}
printf("\n");
}

void bubbleSort(int *arr,int lengthOfArray)
{
int size=lengthOfArray;
for(int i=0;i<size-1;i++)
{
for(int j=0;j<size-i-1;j++)
{
int temp;
if(arr[j]>arr[j+1])
{
temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
}
}
}
}

int bubbleSortAdaptive(int *a,int size)
{
int isSorted=1;
for(int i=0;i<size-1; i++)
{
for(int j=0;j<size-1-i;j++)
{
int temp;
if(a[j]>a[j+1])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
isSorted=0;
}
}
if(isSorted==1) return 1;
}
return 0;

}
int main()
{
int a[]={122,521,6,7,2,90};
int b[]={18,16,11,65,56,5};
int sizeOf_a=sizeof(a)/sizeof(int);
int sizeOf_b=sizeof(b)/sizeof(int);
printf("a[]:");
printArray(a,sizeOf_a);
printf("b[]:");
printArray(b,sizeOf_b);
bubbleSort(a,sizeOf_a);
bubbleSort(b,sizeOf_b);
printf("*****Sorted Array a*****\n");
printArray(a,sizeOf_a);
printf("*****Sorted Array b*****\n");
printArray(b,sizeOf_b);

printf("***********Checking:->Is Bubble Sort Adaptive Or Not*********\n");

//int a2[]={122,521,6,7,2,90};
int a2[]={1,2,3,4,5,6};
int b2[]={18,16,11,65,56,5};
int sizeOf_a2=sizeof(a2)/sizeof(int);
int sizeOf_b2=sizeof(b2)/sizeof(int);
printf("a2[]:");
printArray(a2,sizeOf_a2);
printf("b2[]:");
printArray(b2,sizeOf_b2);
int isAdaptive1=bubbleSortAdaptive(a2,sizeOf_a2);
int isAdaptive2=bubbleSortAdaptive(b2,sizeOf_b2);
if(isAdaptive1) printf("*****Array a2 is Adaptive*****\n");
else printf("**********Array a2 is not Adaptive*******\n"); 
printArray(a2,sizeOf_a2);
if(isAdaptive2) printf("*****Array b2 is Adaptive*****\n");
else printf("**********Array b2 is not Adaptive*******\n"); 
printArray(b2,sizeOf_b2);

return 0;
}