#include<stdio.h>
void printArray(int *arr,int length)
{
for(int i=0;i<length;i++)
{
printf("%d ",arr[i]);
}
printf("\n");
}

// Merging Elements
void merge(int *arr,int low,int high,int mid)
{
int i=low; 
int j=mid+1;
int k=low;
//int a1[101];  
int a1[high+1];
while(i<=mid && j<=high)
{
if(arr[i]<arr[j])
{
a1[k]=arr[i];
i++;
k++;
}
else
{
a1[k]=arr[j];
j++;
k++;
}
}
while(i<=mid)
{
a1[k]=arr[i];
i++;
k++;
}
while(j<=high)
{
a1[k]=arr[j];
j++;
k++;
}
for(i=low;i<k;i++)
{
arr[i]=a1[i];
}
}

// Merge Sort Code
void mergeSort(int *arr,int low,int high)
{
int mid;
if(low<high)
{
mid=(low+high)/2;
mergeSort(arr,low,mid);
mergeSort(arr,mid+1,high);
merge(arr,low,high,mid);
}
}
int main()
{
int arr[]={9,14,4,8,7,6,11,5};
int lengthOfArray=sizeof(arr)/sizeof(int);
int low=0;
int high=lengthOfArray-1;

printf("Unsorted arr[]:");
printArray(arr,lengthOfArray);

mergeSort(arr,low,high);
printf("Sorted arr[]:");
printArray(arr,lengthOfArray);
return 0;
}