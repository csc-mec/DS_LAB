#include<stdio.h>
void main()
{
    int n,i,j;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the %d elements : ",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    
    int temp=0;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j+1]<a[j]){
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("Sorted array is \n");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
}
