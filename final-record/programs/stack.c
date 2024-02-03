#include <stdio.h>
#include <stdbool.h>

#define SIZE 20

int stack[SIZE];
int top = -1;

bool isEmpty() {
   	return top == -1;
}

bool isFull() {
    return top == SIZE - 1;
}

void push(int element) {
    if (!isFull()) {
        top++;
        stack[top] = element;
    } else {
        printf("Stack overflow\n");
    }
}

void pop() {
    if (!isEmpty()) {
        printf("%d is popped\n", stack[top]);
        top--;
    } else {
        printf("Stack underflow\n");
    }
}

void peek() {
    if (!isEmpty()) {
        printf("%d\n", stack[top]);
    } else {
        printf("Stack underflow\n");
    }
}

void display() {
  if (!isEmpty())
    for (int i = top; i >= 0; i--)
        printf("%d\n", stack[i]);
  else
   	printf("Stack underflow\n");
}
int main() {
 	int choice, element;
    printf("1. Display\n");
    printf("2. Push\n");
	printf("3. Pop\n");
    printf("4. Peek\n");
    printf("5. Exit\n");
 	while (1) {
    	printf("Enter your choice: ");
    	scanf("%d", &choice);
    	switch (choice) {
		case 1:
            display();
            break;
       	case 2:
            printf("Enter element to push: ");
            scanf("%d", &element);
            push(element);
            break;
       	case 3:
            pop();
            break;
    	case 4:
            peek();
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice\n");
     	}
	}

 	return 0;
}
