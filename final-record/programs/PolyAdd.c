#include <stdio.h>

void main(){
    int a, b, max;
    struct poly{
        int coeff;
        int expo;
    };
    
    struct poly p1[20], p2[20];
    
    printf("Enter Degree of First Polynomial: ");
    scanf("%d", &a);
    printf("Enter Degree of Second Polynomial: ");
    scanf("%d", &b);
    
    printf("\nPolynomial 1\n");
    for(int i = a; i >= 0; i --){
        printf("Enter Coefficient of x^%d: ", i);
        scanf("%d", &p1[i].coeff);
        p1[i].expo = i;
    }
    printf("\nPolynomial 2\n");
    for(int i = b; i >= 0; i --){
        printf("Enter Coefficient of x^%d: ", i);
        scanf("%d", &p2[i].coeff);
        p2[i].expo = i;
    }
    
    if(a > b){
        max = a;
    }
    else{
        max = b;
    }
    
    
    printf("The Sum Is: ");
    for(int i = max; i > 0; i--){
        if(p1[i].expo == p2[i].expo){
            printf("%d(x^%d) + ", p1[i].coeff + p2[i].coeff, p1[i].expo);
        }
        else if(max == a){
            printf("%d(x^%d) + ", p1[i].coeff, p1[i].expo);
        }
        else if(max == b){
            printf("%d(x^%d) + ", p2[i].coeff, p2[i].expo);
        }
    }
    if(p1[0].expo == p2[0].expo){
            printf("%d(x^%d) ", p1[0].coeff + p2[0].coeff, p1[0].expo);
    }
    else if(max == a){
        printf("%d(x^%d) ", p1[0].coeff, p1[0].expo);
    }
    else if(max == b){
        printf("%d(x^%d) ", p2[0].coeff, p2[0].expo);
    }
    printf("\n");
}
    