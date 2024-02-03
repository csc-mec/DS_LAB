#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node * rmfirst(struct node *head){
    if (head==NULL){
        printf("Undedflow\n");
    }
    else if (head->next==head){
        printf("Popped data is : %d",head->data);
        free(head);
        head=NULL;
    }
    else{
        struct node *temp,*current;
        printf("Popped data is : %d",head->data);
        temp = head;
        current=head;
        do{
            current =  current->next;
        }while (current->next != head);
        current->next=head->next;
        head=temp->next;
        free(temp);
    }
    return head;
}
struct node * addlast(struct node *head){
    struct node *newnode;
    newnode = malloc(sizeof(struct node));
    printf("Enter data : ");
    int e;
    scanf("%d",&e);
    newnode->data = e;
    newnode->next=head;
    if (head==NULL){
        head=newnode;
        newnode->next=head;
    }
    else{
        struct node *current;
        current = head;
        do{
            current =  current->next;
        }while (current->next != head);
        current->next=newnode;
    }
    return head;
}
struct node * addfirst(struct node *head){
    struct node *newnode;
    newnode = malloc(sizeof(struct node));
    printf("Enter data : ");
    int e;
    scanf("%d",&e);
    newnode->data = e;
    if (head == NULL){
        head =  newnode;
        newnode->next = head;
    }
    else if(head->next==head) {
        newnode->next=head;
        head->next=newnode;
        head=newnode;
    }
    else{
        newnode->next=head;
        struct node *current;
        current=head;
        do{
            current =  current->next;
        }while (current->next != head);
        current->next=newnode;
        head=newnode;
    }
    return head;
}
struct node * rmlast(struct node *head){
    if (head==NULL){
        printf("Underflow\n");
    }
    else if (head->next == head){
        printf("Popped data is : %d",head->data);
        free(head);
        head=NULL;
    }
    else{
        struct node *current;
        current=head;
        while(current->next->next!=head){
            current=current->next;
        }
        struct node *temp;
        temp=current->next;
        printf("Popped element is : %d",temp->data);
        free(temp);
        current->next=head;
    }
    return head;
}
bool search(struct node *head,int data){
    if (head==NULL){
        return false;
    }
    else{
        struct node *current;
        current=head;
        do{
            if (head->data = data){
                return true;
            }
            current=current->next; 
        }while(current!=head);
        return false;
    }
}
bool addmid(struct node *head,int a , int b){
    if(head==NULL){
        return false;
    }
    struct node *newnode;
    newnode= malloc(sizeof(struct node));
    struct node *current;
    current=head;
    do{
       if (current->data ==a && current->next->data==b){
           printf("Enter data : ");
           int e;
           scanf("%d",&e);
           newnode->data=e;
           newnode->next=head->next;
           current->next=newnode;
           return true;
       }
       current=current->next;
    }while(current!=head);
    return false;
     }
void display(struct node *head){
    struct node *current;
    current=head;
    if (head==NULL){
        printf("Underflow\n");
    }
    else{
        do{
            printf("%d\n",head->data);
            head=head->next;
        }while(current!=head);
    }
}
int main(){
    int ch,y,x;
    struct node *head;
    head=NULL;
    while (true){
        printf("1. Display\n");
        printf("2. ADD FIRST\n");
        printf("3. REMOVE FIRST\n");
        printf("4. ADD LAST\n");
        printf("5. REMOVE LAST\n");
        printf("6. SEARCH\n");
        printf("7. ADD MID\n");
        printf("8. Exit\n\n");
        printf("Enter choice :");
        scanf("%d",&ch);
        switch (ch){
            case 1 :display(head);break;
            case 2 :head= addfirst(head);break;
            case 3 :head=rmfirst(head);break;
            case 4 :head=addlast(head);break;
            case 5 :head=rmlast(head);break;
            case 6 :
                printf("Enter search key : ");
                scanf("%d",&x);
                if (search(head,x)){
                    printf("Element found\n");
                }
                else{
                    printf("Element not found\n");
                }
                break;
            case 7 :
                printf("Enter the elements : ");
                scanf("%d %d",&x,&y);
                if(!addmid(head,x,y)){
                    printf("Not Possible\n");
                }
                break;
            case 8 :return 0;break;
            default:printf("Invalid Choice\n");
       }
       printf("\n");
   }
}
