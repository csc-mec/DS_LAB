#include <stdio.h>
#define SIZE 20

void merge(int arr[] , int l , int m , int h){
	int i=l;
	int j=m+1;
	int k=0;
	
	int tempa[h-l+1];
	
	while(i<=m && j<=h){
		if(arr[i] < arr[j]){
			tempa[k] = arr[i];
			i++;
		}
		else{
			tempa[k] = arr[j];
			j++;
		}
		k++;
	}
	while(i<=m){
		tempa[k] = arr[i];
		i++;
		k++;
	}
	while(j<=h){
		tempa[k] = arr[j];
		j++;
		k++;
	}
	
	for(int i=l ; i<=h ;i++){
		arr[i] = tempa[i-l];
	}
}

void mergeSort(int arr[] , int l , int h){
	if(l<h){
		int m = (l+h)/2;
		
		mergeSort(arr , l , m);
		mergeSort(arr , m+1 , h);
		
		merge(arr , l , m , h);
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
	mergeSort(array , 0 , n-1);
	for(int i=0 ; i<n ;i++){
		printf("%d " , array[i]);
	}
	printf("\n");
}
