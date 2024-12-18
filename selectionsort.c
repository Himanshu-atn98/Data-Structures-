#include<stdio.h>
void printArray(int *arr,int lengthOfArray)
{
for(int i=0;i<lengthOfArray;i++)
{
printf("%d ",arr[i]);
}
printf("\n");
}

void selectionSort(int *arr,int lengthOfArray)
{
int temp;
for(int i=0;i<lengthOfArray;i++)
{
for(int j=i+1;j<lengthOfArray;j++)
{
if(arr[i]>arr[j])
{
temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
}
}
}
}
int main()

{
int arr1[]={54,12,89,121,7,2,165,39,72,63};
int arr2[100];
int used_SizeOf_arr2=0;
printf("Enter the new array arr2\n");
for(int i=0;i<21;i++)
{
scanf("%d",&arr2[i]);
used_SizeOf_arr2++;
}

int lengthOf_arr1=sizeof(arr1)/sizeof(int);

printf("Unsorted arr1[]:");
printArray(arr1,lengthOf_arr1);
selectionSort(arr1,lengthOf_arr1);
printf("Sorted arr1[]:");
printArray(arr1,lengthOf_arr1);

printf("***** Size Of arr2 is %d*****\n",used_SizeOf_arr2);
printf("Sorted arr2[]:");
selectionSort(arr2,used_SizeOf_arr2);
printArray(arr2,used_SizeOf_arr2);
return 0;
}