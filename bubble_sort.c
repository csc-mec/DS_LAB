#include <stdio.h>
void main()
{
    int n;
    printf("Enter the size of the array \t");
    scanf("%d",&n);
    int a[n];
    printf("Enter values into the array \t");
    for (int i=0; i< n; i++)
    scanf("%d",&a[i]);

    for (int i=0 ; i<n-1; i++ )
    {
        for (int j= 0 ; j< n-1-i ; j++)
        {
            if (a[j+1]< a[j])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    printf("Sorted array : \n");
    for (int i=0 ; i< n; i++)
    printf("%d \t",a[i]);
}