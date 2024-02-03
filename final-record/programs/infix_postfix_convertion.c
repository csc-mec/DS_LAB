#include <stdio.h>
#include <stdbool.h>
#define SIZE 20

char stack[SIZE];
char array[SIZE];

int TOP = -1;
int INDEX = -1;

void addToArray(char c){
	INDEX++;
	array[INDEX] = c;
}

void push(char c){
	TOP++;
	stack[TOP] = c;
}
char pop(){
	TOP--;
	return stack[TOP+1];
}


bool isOperator(char c){
	switch(c){
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
		case '(':
		case ')': return 1;
		default : return 0;
	}
}

int prior(char c){
	switch(c){
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 2;
		case '^': return 3;
		case '(': return 0;
	}
}



void assign(char c){
	if(!isOperator(c)){
		addToArray(c);
	}
	else{
		if(TOP == -1){
			push(c);
		}
		else if(c == ')'){
			while(stack[TOP] != '('){
				addToArray(pop());
			}
			pop();
		}
		
		else if(c == '(' || c == '^'){
			push(c);
		}
		
		else{
			while(prior(c) <= prior(stack[TOP])){
				addToArray(pop(c));
			}
			push(c);
		}
	}
	
}

void main(){
	char infix[SIZE];
	printf("Enter the infix operation :");
	scanf("%s" , &infix);
	for(int i=0 ; infix[i] != '\0' ; i++){
		assign(infix[i]);
	}
	while (TOP > -1){
		addToArray(pop());
	}
	for(int i=0 ; i<=INDEX ; i++){
		printf("%c" ,array[i] );
	}
	printf("\n");	
}