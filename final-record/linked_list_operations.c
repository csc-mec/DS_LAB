#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*current,*head=NULL,*newnode,*temp,*prev;


void display(){
    if(head==NULL)
        printf("LINKED LIST IS EMPTY");
    else{
        current=head;
        printf("LINKED LIST IS: ");
        while(current!=NULL){
            printf("%d ",current->data);
            current=current->next;
    }
}}
void insert_begin(){
    printf("Enter data:");
    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL){
       head=newnode;
       printf("%d was inserted.",newnode->data);
    }
    else{
        newnode->next=head;
        head=newnode;
        printf("%d was inserted.",newnode->data);
    }
}
void insert_end(){
    printf("Enter data:");
    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL){
       head=newnode;
       printf("%d was inserted.",newnode->data);
    }
    else{
            temp=head;
            while(temp->next!=NULL)
            temp=temp->next;
            temp->next=newnode;
            printf("%d was inserted.",newnode->data);
    }
}
void insert_pos(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter position:");
    int pos;
    scanf("%d",&pos);
    current=head;
    int i=0;
    while(current!=NULL){
        current=current->next;
        i++;
    }
    if(pos>(i+1)||pos<1){
        printf("Invalid Position!");
    }
    else if(pos==1)
        insert_begin();
    else{
        printf("Enter data:");
        scanf("%d",&newnode->data);
        current=head;
        for(int j=1;j<pos-1;j++)
            current=current->next;
        newnode->next=current->next;
        current->next=newnode;
    }
}
void delete_begin(){
    if(head==NULL)
    printf("Linked list is empty. Nothing to delete");
    else if(head->next==NULL){
        temp=head;
        head=NULL;
        printf("%d was deleted",temp->data);
        free(temp);
    }
    else{
        temp=head;
        head=head->next;
        printf("%d was deleted",temp->data);
        free(temp);
    }
}
void delete_end(){
    if(head==NULL)
    printf("Linked list is empty. Nothing to delete");
    else if(head->next==NULL){
        temp=head;
        head=NULL;
        printf("%d was deleted",temp->data);
        free(temp);
    }
    else{
        current=head;
        while(current->next!=NULL){
            prev=current;
            current=current->next;
        }
        prev->next=NULL;
        printf("%d was deleted",current->data);
        free(current);
    }
}
void delete_pos(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter position:");
    int pos;
    scanf("%d",&pos);
    current=head;
    int i=0;
    while(current!=NULL){
        current=current->next;
        i++;
    }
    if(pos>(i)||pos<1){
        printf("Invalid Position!");
    }
    else if(pos==1)
        delete_begin();
    else{
        current=head;
        for(int j=1;j<pos;j++){
            prev=current;
            current=current->next;
        }
        prev->next=current->next;
        free(current);
    }
}
void main(){
    int choice;
    printf("\n1.Display\n2.InsertBegin\n3.InsertEnd\n4.InsertPos\n5.DeleteBegin\n6.DeleteEnd\n7.DeletePos\n8.Exit");
    while(choice!=8){
        printf("\nEnter choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                display();
                break;
            case 2:
                insert_begin();
                break;
            case 3:
                insert_end();
                break;
            case 4:
                insert_pos();
                break;
            case 5:
                delete_begin();
                break;
            case 6:
                delete_end();
                break;
            case 7:
                delete_pos();
                break;
            case 8:
                break;
            default:
                printf("INVALID CHOICE.");
        }
    }
}