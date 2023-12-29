#include<stdio.h>
void main(){
    int n,i,j;
    printf("Enter the size of array :");
    scanf("%d",&n);
    int a[n];
    printf("Enter the %d elements :",n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            int temp=0;
            if(a[j]<a[i]){
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
    }
    printf("Sorted array is\n");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
    printf("\n");
}
