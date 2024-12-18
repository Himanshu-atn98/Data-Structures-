#include<stdio.h>
void printArray(int *arr,int lengthOfArray)
{
for(int i=0;i<lengthOfArray;i++)
{
printf("%d ",arr[i]);
}
printf("\n");
}

// Partition Code
int partition(int *arr,int low,int high)
{
int pivot=arr[low];
int temp;
int i=low+1;
int j=high;
while(i<=j)
{
while(arr[i]<=pivot)
{
i++;
}
while(arr[j]>pivot)
{
j--;
}
if(i<j)
{
temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
}
else
{
temp=arr[low];// Or-> temp=pivot;
arr[low]=arr[j];
arr[j]=temp;
return j;
}
}
}

//Quic Sort Code
void quickSort(int *arr,int low,int high)
{
int partitionIndex;
if(low<high)
{
partitionIndex=partition(arr,low,high);
quickSort(arr,low,partitionIndex-1);
quickSort(arr,partitionIndex+1,high);
}
}


int main()
{
int arr[]={21,9,5,8,4,6,13,2,17};
//int arr[]={21,9};
//int arr[]={21,2,3s};
int lengthOfArray=sizeof(arr)/sizeof(int);
int low=0;
int high=lengthOfArray-1;
printf("Unsorted arr[]:");
printArray(arr,lengthOfArray);
quickSort(arr,low,high);
printf("Sorted arr[]:");
printArray(arr,lengthOfArray);
return 0;
}