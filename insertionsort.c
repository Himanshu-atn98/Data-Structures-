#include<stdio.h>
void printArray(int *arr,int size)
{
for(int i=0;i<size;i++)
{
printf("%d ",arr[i]);
}
printf("\n");
}

void insertionSort(int *arr,int size)
{
for(int i=1;i<size;i++)
{
int key=arr[i];
int j=i-1;
while(j>=0 && arr[j]>key)
{
arr[j+1]=arr[j];
j--;
}
arr[j+1]=key;
}
}

int main()
{
int arr[]={12,54,7,65,48,2,23};
int sizeOf_arr=sizeof(arr)/sizeof(int);
printf("Unsorted arr[]:");
printArray(arr,sizeOf_arr);
insertionSort(arr,sizeOf_arr);
printf("Sorted arr[]:");
printArray(arr,sizeOf_arr);
return 0;
}