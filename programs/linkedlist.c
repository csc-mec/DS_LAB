#include <stdio.h>
#include <malloc.h>
struct node {
    int data ;
    struct node * next;
};


void print_linked(struct node *p){
    if(p==NULL){
        printf("NULL");
        return;
    }
    printf("%d->",p->data);
    print_linked(p->next);
}
void main(){
    int n ;
    struct node* ptr,*head;
    printf("enter the number of nodes you want to enter");
    scanf("%d",&n);
    head=malloc(sizeof(struct node));
    ptr=head;
    for(int i =0 ;i<n-1;i++){
        printf("enter the data you want in this node");
        scanf("%d",&(ptr->data));
        ptr->next=malloc(sizeof(struct node));
        ptr=ptr->next;
    }
    printf("enter the data you want in this node");
    scanf("%d",&(ptr->data));
    ptr->next=NULL;

    print_linked(head);


}