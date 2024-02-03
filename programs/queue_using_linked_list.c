#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *front,*rear;

void enqueue();
void dequeue();
void display();

void main() {
    int choice;
    while(1){
    printf("\nQUEUE\n");
    printf("OPTIONS\n");
    printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return;
        default:
            printf("Invalid option!\n");
    }
    }
}

void enqueue(){
    struct node *newnode;
    newnode = malloc(sizeof(struct node));
    printf("Enter element:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(front == NULL && rear == NULL){
        front=newnode;
        rear=newnode;
    }else{
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue(){
    if(front==NULL && rear==NULL){
        printf("List empty");
    }else{
        struct node *temp;
        temp = front;
        printf("dequeued %d",temp->data);
        front = front->next;
        free(temp);
    }
}

void display(){
    struct node *temp;
    temp = front;
    if(front==NULL && rear==NULL){
        printf("List empty");
    }else{
        while(temp != NULL){
            printf("%d\t",temp->data);
            temp = temp->next;
        }
        
    }
}
