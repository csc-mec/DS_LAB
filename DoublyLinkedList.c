/*Notes:
 *%p is used to print pointer value but in lab computer %d works as well
 *While inserting an element into a specified location,if value is not found in list,segmentation  fault occurs
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
	struct node*prev;
};
struct node*head=NULL;
void pushfront(int k){
	struct node*temp=head;
	struct node*new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=k;
	new_node->prev = NULL;
	if(head == NULL){
       new_node->next = NULL;
       head = new_node;
       return;
    }
    new_node->next=head;
    temp->prev=new_node;
    head=new_node;
}
void pushrear(int k){
	struct node*temp=head;
	struct node*new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=k;
	new_node->next=NULL;
	if(head == NULL){
       new_node->prev = NULL;
       head = new_node;
       return;
	}
    while(temp->next!=NULL){
        temp=temp->next;
    }
    //Here value of new_node is NULL
    temp->next=new_node;
    new_node->prev=temp;
}
void insert(int value,int k){
	struct node*temp=head;
    struct node*new_node=malloc(sizeof(struct node));
    while(temp->data!=value){
        temp=temp->next;
    }
    new_node->data=k;
    new_node->next=temp->next;
    temp->next=new_node;
    new_node->prev=temp;
    //Assigning value of prev in next node to that of the address of new_node
    temp=new_node->next;
    temp->prev=new_node;
}
void display(){
	struct node*temp=head;
    if(temp==NULL){
        printf("No elements in list! \n");
        return;
	}
	else{
        while(temp!=NULL){
            //printing value of head
            printf(" %d \n",temp->data);
            temp=temp->next;
        }
	}
}
void deletefront(){
	struct node*temp=head;
	if(head==NULL){
		printf("List is empty");
	}
	else if(temp->next==NULL&&temp->prev==NULL){
        printf("The deleted element is: %d \n",temp->data);
        free(head);
        //You need to assign value of head as NULL so that display does not loop endlessly
        head=NULL;
        return;
	}
	else{
		printf("The deleted element is: %d \n",temp->data);
		temp=temp->next;
		head=temp;
		temp->prev=NULL;
		free(temp->prev);
		return;
	}
}
void deleterear(){
    struct node*temp=head;
	if(head==NULL){
		printf("List is empty");
		return;
	}
	else if(temp->next==NULL&&temp->prev==NULL){
        printf("The deleted element is: %d \n",temp->data);
        free(head);
        head=NULL;
        return;
	}
	else{
		struct node*temp=head;
		while(temp->next->next!=NULL){
			temp=temp->next;
		}
		struct node*current=temp;
		temp=temp->next;
		printf("The deleted element is: %d \n",temp->data);
		current->next=NULL;
		free(temp);
		return;
	}
}

void main(){
	int choice;
	do{
		printf("\n ----Doubly Linked List implementation in C---- \n");
		printf("1.Insert elements at front \n");
		printf("2.Insert elements at rear \n");
		printf("3.Insert element at specified location \n");
		printf("4.Delete elements at front \n");
		printf("5.Delete elements at rear \n");
		printf("6.Display all elements \n");
		printf("7.Exit \n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:{
				int k;
				printf("Insert value: ");
				scanf("%d",&k);
				pushfront(k);
				printf("Element inserted successfully! \n");
				break;
			}
			case 2:{
				int k;
				printf("Insert value: ");
				scanf("%d",&k);
				pushrear(k);
				printf("Element inserted successfully! \n");
				break;
			}
			case 3:{
				int v,k;
				struct node*temp=head;
				if(temp==NULL){
                    printf("List is empty \n");
                    break;
				}
				else{
                    printf("Enter value after which data is to be entered: ");
                    scanf("%d",&v);
                    printf("Insert value: ");
                    scanf("%d",&k);
                    insert(v,k);
                    printf("Element inserted successfully! \n");
                    break;
				}
			}
			case 4:{
				deletefront();
				break;
			}
			case 5:{
				deleterear();
				break;
			}
			case 6:{
				display();
				break;
			}
			case 7:{
				choice=7;
				break;
			}
			default:{
				printf("Invalid choice! \n");
			}
		}
	}while(choice!=7);
}
