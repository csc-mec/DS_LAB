#include <stdio.h>
void main()
{
    int n;
    printf("Enter the size of the array \t");
    scanf("%d",&n);
    int a[n];
    printf("Enter values into the array \t");
    for(int i=0; i<n; i++)
    scanf("%d",&a[i]);

    int min;
    for (int i=0 ; i< n-1; i++)
    {
        min =i;
        for (int  j =i+1; j<n; j++)
        {
            if (a[min]> a[j])
            min =j;
        } 
        if (min != i)
        {int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
        }
        
    }

    for(int i=0; i<n; i++)
    printf("%d \t",a[i]);


}