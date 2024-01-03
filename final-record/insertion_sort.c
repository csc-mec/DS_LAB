#include <stdio.h>
void main()
{
    int n, i, j, key;
    printf("Enter Size : ");
    scanf("%d", &n);
    int a[n];
    printf("Enter Array Elements : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (a[j] > key && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    printf("Sorted array : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}
