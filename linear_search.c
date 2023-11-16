#include <stdio.h>
int linear(int a[], int search, int n)
{
    int flag = 0, index;
    for (int i=0; i<n; i++)
    {
        if (a[i] == search)
        {
            flag =1;
            index =i;
            break;
        }
    }
    if (flag == 1)
    return index;

    else
    return -1;
}

void main()
{
    int search,n;
    printf("Enter the number of elements in the array \t");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements into the array \t");
    for (int i= 0 ; i< n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the element to search for :\t");
    scanf("%d",&search);
    int index = linear(a,search,n);
    if (index == -1)
    printf("Element not found.");
    else
    printf("Element found at index %d \t",index+1);

}