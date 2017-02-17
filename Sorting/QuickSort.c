#include <stdio.h>
#include <stdlib.h>

int partition(int* arr, int start, int end)
{
    int pIndex, pivot, temp,i;
    pIndex = start;
    pivot = arr[end];
    for(i=start;i<end;i++)
    {
        if(arr[i]<pivot)
        {
            temp = arr[i];
            arr[i]=arr[pIndex];
            arr[pIndex] = temp;
            pIndex++;
        }
    }
    temp = arr[end];
    arr[end]=arr[pIndex];
    arr[pIndex] = temp;
    return pIndex;
}

void QuickSort(int* arr, int start, int end)
{
    int pivot;
    if(start >= end) return;
    pivot = partition(arr,start,end);
    QuickSort(arr,start,pivot-1);
    QuickSort(arr,pivot+1,end);
}


int main()
{
    int a[100],i,j,k,n,pos;
    printf("\t\t\t Quick Sorting\n\n");

    printf("Enter the size of an array\n");
    scanf("%d",&n);
    printf("Enter the elements of an array\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    QuickSort(a,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");

    return 0;
}
