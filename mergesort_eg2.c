#include<stdio.h>
void merge(int a[],int low,int high,int mid)
{
int i,j,k,c[50];
i=low;
j=mid+1;
k=low;
while(i<=mid && j<=high)
{
if(a[i]<a[j])
{
c[k]=a[i];
k++;
i++;
}
else
{
c[k]=a[j];
k++;
j++;
}
}
while(i<=mid)
{
c[k]=a[i];
k++;
i++;
}
while(j<=high)
{
c[k]=a[j];
k++;
j++;
}
for(i=low;i<k;i++)
{
a[i]=c[i];
}
}
void mergeSort(int a[],int low,int high)
{
int mid;
if(low<high)
{
mid=(low+high)/2;
mergeSort(a,low,mid);
mergeSort(a,mid+1,high);
merge(a,low,high,mid);
}
}

void printArray(int *arr,int length)
{
for(int i=0;i<length;i++)
{
printf("%d ",arr[i]);
}
printf("\n");
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