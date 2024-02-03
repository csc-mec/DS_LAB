#include<stdio.h>
void main(){
    int n,l,sl;
    printf("Enter number of elements ; ");
    scanf("%d",&n);
    int A[n];
    for (int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    l=A[0];
    for (int i=1;i<n;i++){
        if(A[i]>l){
            l=A[i];
        }
    }
    printf("Largest is %d \n",l);
    if (l==A[0]){
        sl=A[1];
    }
    else{
        sl=A[0];
    }
    for (int i=1;i<n;i++){
        if(A[i]>sl && A[i]!=l){
            sl=A[i];
        }
    }
    printf("Second Largest is %d \n",sl);
}