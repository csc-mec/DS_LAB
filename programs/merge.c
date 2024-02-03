#include <stdio.h>

void merge(int a[],int lb,int mid,int ub);//declaration of merge function



void mergeSort(int a[],int lb, int ub){
    if(lb<ub){
        int mid = (lb+ub)/2;
        //recursively sort the two halves
        mergeSort(a,lb,mid);
        mergeSort(a,mid+1,ub);
        //merge the two sorted halves
        merge(a,lb,mid,ub);
    }
}
//merge function
void merge(int a[],int lb,int mid,int ub){
    int i=lb;
    int j=mid+1;
    int k=lb;
    int b[ub];
    //compare the elements of the two halves and put the smaller one in the new array
    while(i<=mid && j<=ub){
        if(a[i] <= a[j]){
            b[k] = a[i];
            i++;
        }else{
            b[k] = a[j];
            j++;
        }
        k++;
    }
    //copy the remaining elements of the first half
    if(i>mid){
        while(j<=ub){
            b[k] = a[j];
            j++;
            k++;
        }
    }
    //copy the remaining elements of the second half
    else{
        while(i<=mid){
            b[k] = a[i];
            i++;
            k++;
        }
    }
    //copy the elements of the new array to the original array
    for(k=lb;k<=ub;k++){
        a[k] = b[k];
    }
}


//function to print the array
void printArray(int a[],int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}

//main function
void main(){
    int i,n;
    printf("Enter length of array:");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        printf("\n");
    }
    printf("Original array:\n");
    printArray(a,n);
    mergeSort(a,0,n);//calling mergeSort function
    printf("Sorted array:\n");
    printArray(a,n);
}