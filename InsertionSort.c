// Insertion Sort
#include <stdio.h>

void main(){
    // Declare variables
    int n, i, j, key;

    // Get the size of the array from the user
    printf("Enter Size: ");
    scanf("%d", &n);

    // Declare an array of size 'n' to store elements
    int a[n];

    // Get array elements from the user
    printf("Enter Array Elements: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    // Perform insertion sort
    for(i = 1; i < n; i++){
        key = a[i];
        j = i - 1;

        // Move elements greater than 'key' to one position ahead of their current position
        while(a[j] > key && j >= 0){
            a[j + 1] = a[j];
            j--;
        }

        // Place 'key' in its correct position
        a[j + 1] = key;
    }

    // Display the sorted array
    printf("Sorted array: ");
    for(int i = 0; i < n; i++){
        printf("%d\t", a[i]);
    }
}
