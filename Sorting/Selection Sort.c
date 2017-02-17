#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[100],i,j,k,n,pos,swap;
    printf("\t\t\tSelection Sorting\n\n");

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
        pos = i;
        for(j=i+1;j<n;j++)
            if(a[pos]>a[j])
                pos = j;
        swap = a[i];
        a[i] = a[pos];
        a[pos] = swap;
        printf("Step %d: ",i+1);
        for(k=0;k<n;k++)
            printf("%d ",a[k]);
        printf("\n");
    }





    return 0;
}
