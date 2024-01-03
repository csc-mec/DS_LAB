#include <stdio.h>
#include <stdlib.h>

int degree = 0; 

struct node{
    int coeff;
    int pow;
    struct node *next;
}*poly1 = NULL , *poly2 = NULL , *poly3 = NULL; 

struct node *createPoly(struct node *head){
    int n , i , m = 0; 
    struct node *ptr, *temp = head;
    printf("ENTER NUMBER OF TERMS IN POLYNOMIAL : ");
    scanf("%d", &n);
    for(i = 0 ; i < n ; i++){
        ptr = malloc(sizeof(struct node));
        printf("ENTER COEFFICIENT AND POWER : ");
        scanf("%d %d", &ptr->coeff, &ptr->pow);
        if(i == 0){
            head = ptr;  
            ptr->next = NULL;
            temp = ptr;
        }
        else{
            temp->next = ptr;
            ptr->next = NULL;
            temp = ptr;
        }
        if(ptr->pow > m){
            m = ptr->pow;
        }       
    }
    degree += m;
    return head;
}
void createPolyFromHash(int hash[] , int m){
    struct node *ptr , *temp = poly3 ;

    for(int i = 0 ; i<m+1 ; i++){
        if(hash[i] != 0){
            ptr = malloc(sizeof(struct node));
            ptr->coeff = hash[i];
            ptr->pow = i;
            ptr->next = NULL;

            if(temp == NULL){
                poly3 = ptr;
                temp = ptr;
            }
            else{
                temp->next = ptr;
                temp = ptr;
            }
        }
    }
}

void displayPoly(struct node *head){
    struct node *ptr = head;
    while(ptr != NULL){
        if(ptr->next == NULL){
            printf("%dx^%d", ptr->coeff, ptr->pow);
            break;
        }
        printf("%dx^%d + ", ptr->coeff, ptr->pow);
        ptr = ptr->next;
    }
    printf("\n");
}

void multiplyPoly(struct node *head1 , struct node *head2, int m){
    struct node *ptr1 , *ptr2 ; 

    int hash[m+1] ; 
    for(int i = 0 ; i<m+1 ; i++){
        hash[i] = 0;
    }

    for (ptr1 = head1; ptr1 != NULL; ptr1 = ptr1->next) {
        for (ptr2 = head2; ptr2 != NULL; ptr2 = ptr2->next) {
            int c = ptr1->coeff * ptr2->coeff;
            int p = ptr1->pow + ptr2->pow;
            hash[p] += c;
        }
    }
    createPolyFromHash(hash , m);
}

int main(){
    poly1 = createPoly(poly1);
    poly2 = createPoly(poly2);
    
    printf("POLYNOMIAL 1 : ");
    displayPoly(poly1);
    printf("POLYNOMIAL 2 : ");
    displayPoly(poly2);

    multiplyPoly(poly1 , poly2, degree);

    printf("MULTIPLIED POLYNOMIAL : ");
    displayPoly(poly3);
}
