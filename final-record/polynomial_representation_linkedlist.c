#include<stdio.h>
#include<stdlib.h>
struct node{
    int coeff;
    int exp;
    struct node *next;
};
struct node *newnode,*current,*head=NULL,*tail=NULL;
void create(){
    int n,i;
    printf("Enter number of terms: ");
    scanf("%d",&n);
    printf("Enter terms in decreasing order of coefficients\n");
    for(i=0;i<n;i++){
        newnode=malloc(sizeof(struct node));
        printf("Enter coefficient and exponent: ");
        scanf("%d %d",&newnode->coeff,&newnode->exp);
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }
}
void display(){
    current=head;
    while(current!=NULL){
        printf("%dx^%d",current->coeff,current->exp);
        if(current!=tail){
            printf("+");
        }
        current=current->next;
    }
    printf("\n");
}
void main(){
    create();
    display();
}
