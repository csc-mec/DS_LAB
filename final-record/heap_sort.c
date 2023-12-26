#include<stdio.h>
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void maxheapify(int a[],int n,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n&&a[l]>a[largest])
      largest=l;
    if(r<n&&a[r]>a[largest]) 
      largest=r;
    if(largest!=i){
        swap(&a[i],&a[largest]);
        maxheapify(a,n,largest);
    }
}
void heapsort(int a[],int n){
    
    for(int i=n/2-1;i>=0;i--){
       maxheapify(a,n,i);
    }
    for(int i=n-1;i>0;i--){
        swap(&a[0],&a[i]);
        maxheapify(a,i,0);

    }
}
int main(){
    int n,a[20],i;
    printf("Enter size of array : ");
    scanf("%d",&n);
    printf("Enter array : ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    heapsort(a,n);

    printf("Sorted array is\n");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}
