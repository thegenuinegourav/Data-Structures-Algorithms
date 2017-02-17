#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[100],i,j,k,n,pos;
    printf("\t\t\tInsertion Sorting\n\n");

    printf("Enter the size of an array\n");
    scanf("%d",&n);
    printf("Enter the elements of an array\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Step 0: ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");

    for(i=1;i<n;i++)
    {
        pos = i;
        for(j=i-1;j>=0;j--)
        {
            if(a[j]>a[pos])
            {
                a[j]+=a[pos];
                a[pos]=a[j]-a[pos];
                a[j]-=a[pos];
            }
            else break;
        }
        printf("Step %d: ",i+1);
        for(k=0;k<n;k++)
            printf("%d ",a[k]);
        printf("\n");
    }





    return 0;
}
