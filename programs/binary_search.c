#include <stdio.h>

int binary(int a[], int n, int search)
{
    int mid, l =0 , u = n-1 ,  index = -1;
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
    return index;
}

void main()
{
    int n,search;
    printf("Enter the size of the array \t");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements into the array \t");
    for (int i=0; i<n; i++)
    scanf("%d",&a[i]);

    printf("Enter the search key \t");
    scanf("%d",&search);
    int index = binary(a,n,search);
    if (index == -1)
    printf("Element not found in the array  \t");
    else
    printf("Element found at index %d \t",index);

}