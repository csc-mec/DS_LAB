#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 5

int Q[SIZE];
int F = -1 ;
int R = -1 ;


void addRear();
void addFront();
void rmRear();
void rmFront();

void display();
void size();

bool isEmpty(){
	return F == -1;
}

bool isFull(){
	return (R+1)%SIZE == F;
}

void main(){
	int option;
	printf("\n\nQueue operations\n");	
	printf("1.Display\n");
	printf("2.Add to rear\n");
	printf("3.Add to front\n");
	printf("4.Remove from rear\n");
	printf("5.Remove from front\n");
	printf("6.Size\n");
	printf("7.Exit\n");
	while(true){
		printf("Select an option : ");
		scanf("%d",&option);
		printf("\n");
		switch(option){
			case 1	:display();break;
			case 2	:addRear();break;
			case 3	:addFront();break;
			case 4	:rmRear();break;
			case 5	:rmFront();break;
			case 6	:size();break;
			case 7	:exit(0);break;
			default	:printf("Invalid option entered\n");
		}
	}
}

void addRear(){
	if(isFull()){
		printf("Queue overflow\n");
	}
	else{
		if(isEmpty()){
			F = 0;
			R = 0;
		}
		else{
			R = (R+1)%SIZE;
		}
		printf("Enter element : ");
		scanf("%d" , &Q[R]);
	}
}

void addFront(){
	if(isFull()){
		printf("Queue overflow\n");
	}
	else{
		if(isEmpty()){
			F = 0;
			R = 0;
		}
		else if(F == 0){
			F = SIZE -1;
		}
		else{
			F--;
		}
		printf("Enter element : ");
		scanf("%d" , &Q[F]);
	}
}

void rmRear(){
	if(isEmpty()){
		printf("Queue underflow\n");
	}
	else{
		printf("Removing %d\n" , Q[R]);
		if(F == R){
			F = -1;
			R = -1;
		}
		else if(R == 0){
			R = SIZE - 1;
		}
		else{
			R--;
		}
	}
}

void rmFront(){
	if(isEmpty()){
		printf("Queue underflow\n");
	}
	else{
		printf("Removing %d\n" , Q[F]);
		if (F == R){
			F = -1;
			R = -1;
		}
		else{
			F = (F+1)%SIZE;
		}
	}
}

void display(){
	if(isEmpty()){
		printf("Queue is Empty ! \n");
		return;
	}
	printf("Queue : ");
	int i = F;
	while(i != R){
		printf("%d\t",Q[i]);
		i = (i+1)%SIZE;
	}
	
	printf("%d\n",Q[R]);
}

void size(){
	int size_v;
	if(isEmpty())
		size_v = 0;
	else if(isFull())
		size_v = SIZE;
	else if(F > R)
		size_v = SIZE - (F - R) + 1;
	else
		size_v = F - R + 1;
		
	printf("Size is %d\n" , size_v);
}
