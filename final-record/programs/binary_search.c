#include <stdio.h>

int binary(int a[], int n, int search)
{
    int mid, l =0 , u = n-1 ;
    while(l<=u)
    {
        mid = (l+u)/2;
        if(a[mid]== search)
            return mid;
        else if (a[mid] < search)
            l= mid+1;
        else
            u= mid -1;
    }
    return -1;
}

void main()
{
    int n,search;
    printf("Enter the size of the array : ");
    scanf("%d",&n);

    int a[n];
    printf("Enter elements into the array : ");
    for (int i=0; i<n; i++)
        scanf("%d",&a[i]);

    printf("Enter the search key : ");
    scanf("%d",&search);
    int index = binary(a,n,search);
    if (index != -1)
        printf("Element found at %d\n",index);
    else
        printf("Element not found\n");

}
