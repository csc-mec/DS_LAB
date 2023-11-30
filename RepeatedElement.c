#include <stdio.h>
int main(){
    int n,f,c;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    int A[n];
    for (int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    for (int i=0;i<n;i++){
        c=0;
        f=0;
        for(int j=0;j<n;j++){
            if (A[i]==A[j]){
                if(j<i){
                    f=1;
                    break;
                }
                c=c+1;
            }
        }
        if (f==0 && c>0){
            printf("Count of %d is %d \n",A[i],c);
        }
    }
}