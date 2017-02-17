#include <stdio.h>
#include <stdlib.h>

int m=0; //to calculate step numbers
void mergeArrays(int* result, int* left, int leftN, int* right, int rightN)
{
    int i=0,j=0,k=0;
    while(i<leftN && j<rightN)
    {
        if(left[i] > right[j])
        {
            result[k] = right[j];
            j++;
        }
        else{
            result[k] = left[i];
            i++;
        }
        k++;
    }
    while(i<leftN)
    {
        result[k] = left[i];
        k++; i++;
    }
    while(j<rightN)
    {
        result[k] = right[j];
        k++; j++;
    }
}

void mergeSort(int* arr, int n)
{
    int i;

    printf("Step %d: ",m);
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    m++;
    printf("\n");

    if(n < 2) return;

    int mid = n/2;
    int left[mid], right[n-mid];
    for(i=0;i<mid;i++)
        left[i] = arr[i];
    for(i=mid;i<n;i++)
        right[i-mid] = arr[i];
    mergeSort(left,mid);
    mergeSort(right,n-mid);
    mergeArrays(arr,left,mid,right,n-mid);

    printf("Step %d: ",m);
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
    m++;
}

int main()
{
    int a[100],i,j,k,n,pos;
    printf("\t\t\tMerge Sorting\n\n");

    printf("Enter the size of an array\n");
    scanf("%d",&n);
    printf("Enter the elements of an array\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    mergeSort(a,n);

    printf("\nFinal: ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");

    return 0;
}
