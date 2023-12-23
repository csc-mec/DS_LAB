#include <stdio.h>
#define SIZE 20

int partition(int arr[] , int l , int h){
    if(l<h){
        int pivot = arr[h];
        int i=l-1;
        for(int j=l ; j<h ; j++){
            if(arr[j] < pivot){
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i+1];
        arr[i+1] = arr[h];
        arr[h] = temp;
        return i+1;
    }
}

void quickSort(int arr[] , int l , int h){
    if(l<h){
        int p = partition(arr , l , h);
        quickSort(arr , l , p-1);
        quickSort(arr , p+1 , h);
    }
}

void main(){
    int array[SIZE] , n;
    printf("Enter size of array : ");
    scanf("%d" , &n);
    printf("Enter the erray : ");
    for(int i=0 ; i<n ;i++){
        scanf("%d" , &array[i]);
    }
    quickSort(array , 0 , n-1);
    for(int i=0 ; i<n ;i++){
        printf("%d " , array[i]);
    }
    printf("\n");
}