#include <stdio.h>
int linear(int a[], int search, int n)
{
    for (int i=0; i<n; i++){
        if (a[i] == search){
            return  i;
        }
    }
    return -1;
}

void main()
{
    int search,n;
    printf("Enter the number of elements in the array : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements into the array : ");
    for (int i= 0 ; i< n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the element to search for : ");
    scanf("%d",&search);
    int index = linear(a,search,n);
    if (index == -1)
        printf("Element not found\n");
    else
        printf("Element found at index %d \n",index);

}
