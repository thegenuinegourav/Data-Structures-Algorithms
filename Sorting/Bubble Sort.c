#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[100],i,j,k,n,pos;
    printf("\t\t\tBubble Sorting\n\n");

    printf("Enter the size of an array\n");
    scanf("%d",&n);
    printf("Enter the elements of an array\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Step 0: ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                a[j]+=a[j+1];
                a[j+1]=a[j]-a[j+1];
                a[j]-=a[j+1];
            }
        }
        printf("Step %d: ",i+1);
        for(k=0;k<n;k++)
            printf("%d ",a[k]);
        printf("\n");
    }





    return 0;
}
