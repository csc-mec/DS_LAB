#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



struct node {
	int data ;
	struct node* next;
};

struct node * addFront(struct node *);
struct node * addRear(struct node *);
struct node * rmFront(struct node *);
struct node * rmRear(struct node *);
struct node * rmKey(struct node *);
void addAfter(struct node *);
void display(struct node *);

void main(){
	struct node * head = NULL;
	int o;
    printf("Linked list operations\n");
    printf("\t1. Display\n");
    printf("\t2. Add front\n");
    printf("\t3. Add rear\n");
    printf("\t4. Add after\n");
    printf("\t5. Remove front\n");  
    printf("\t6. Remove rear\n");
    printf("\t7. Remove key\n");
    printf("\t8. Exit\n");
	while(true){
		printf("Enter option : ");
		scanf("%d" , &o);
		switch(o){
			case 1	: display(head)		;break;
			case 2	: head = addFront(head)	;break;
			case 3	: head = addRear(head)	;break;
			case 4	: addAfter(head)	;break;
			case 5	: head = rmFront(head)	;break;
			case 6	: head = rmRear(head)	;break;
			case 7	: head = rmKey(head)		;break;
			case 8	: exit(0)		;break;
			default	: printf("Invalid option\n");
		}
	}
}

struct node * addFront(struct node * head){
	struct node * newNode = malloc(sizeof(struct node));
	printf("Enter data : ");
	scanf("%d" , &newNode->data);
	newNode->next = head;
	head = newNode;
	return head;
}

struct node * addRear(struct node * head){
	struct node * current = head;
	struct node * newNode = malloc(sizeof(struct node));
	printf("Enter data : ");
	scanf("%d" , &newNode->data);
	newNode->next = NULL;
	if(current == NULL){
		head = newNode;
	}
	else{
		while(current->next != NULL){
			current = current->next;	
		}
		current->next = newNode;	
	}
	return head;
}

struct node * rmFront(struct node * head){
	struct node * temp = head;
	if(head == NULL){
		printf("List empty\n");
	}
	else{
		head = head->next;
		free(temp);
	}
	return head;
}

struct node * rmRear(struct node * head){
	if(head == NULL){
		printf("List empty\n");
	}
	else{
		struct node * current = head;
		while(true){
			if(current->next == NULL){
				struct node * temp = current;
				head = NULL;
				free(temp);
				break;
			}
			if(current->next->next == NULL){
				struct node * temp = current->next;
				current->next = NULL;
				free(temp);
				break;
			}
			current = current->next;
		}
	}
	return head;
}

void addAfter(struct node * head){
	int key;
	struct node * newNode = malloc(sizeof(struct node));
	printf("Enter element to search : ");
	scanf("%d" , &key);
	printf("Enter element to add after : ");
	scanf("%d" , &newNode->data);
	struct node * current = head;
	if( current == NULL){
		printf("List empty\n");
		return;
	}
	else{
		while(true){
			if(current->data == key){
				newNode->next = current->next;
				current->next = newNode;
				return;
			}
			if(current->next == NULL){
				break;
			}
			current = current->next;
		}
	}
	printf("Cannot find %d in List\n" , &key);
}

void display(struct node * head){
	printf("\n");
	if(head == NULL){
		printf("List empty\n");
		return;
	}
	while(head != NULL){
			printf("%d ",head->data);
			head = head->next;
	}
	printf("\n");
}

struct node * rmKey (struct node * head){
	int key;
	printf("Enter element to delete : ");
	scanf("%d" , &key);
	struct node * current = head;
	struct node * temp = head;
	if( current == NULL){
		printf("List empty\n");
	}
	else if(current->data == key){
		head = current->next;
		free(temp);
	}
	else{
		while(true){
			if(current->next->data == key){
				temp = current->next;
				current->next = current->next->next;
				free(temp);
				break;
			}
			if(current->next == NULL){
				break;
			}
			current = current->next;
		}
	}
	printf("Cannot find %d in List\n" , key);
	return head;
}