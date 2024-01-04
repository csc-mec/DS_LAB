#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

int queue[SIZE];
int front = -1;
int rear = -1;

bool isEmpty() {
    return front == -1 && rear == -1;
}
bool isFull() {
    return rear == SIZE - 1;
}
void enqueue(int element) {
    if (isEmpty()) {
        front = 0;
        rear = 0;
        queue[rear] = element;
    } else if (isFull()) {
        printf("Queue overflow\n");
    } else {
        rear++;
        queue[rear] = element;
    }
}
void dequeue() {
    if (isEmpty()) {
        printf("Queue underflow\n");
    } else if (front > rear) {
        printf("Cannot dequeue\n");
    } else {
        printf("%d is dequeued\n", queue[front]);
        front++;
    }
}
void queueSize() {
    if (isEmpty()) {
        printf("Queue underflow\n");
    } else {
        printf("%d\n", rear - front + 1);
    }
}
void display() {
    if (!isEmpty()) {
        for (int i = front; i <= rear; i++) {
            printf("%d\n", queue[i]);
        }
    } else {
        printf("Queue underflow\n");
    }
}
int main() {
    int choice, element;
    printf("1. Display\n");
    printf("2. Enqueue\n");
    printf("3. Dequeue\n");
    printf("4. Size\n");
    printf("5. Exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display();
                break;
            case 2:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 3:
                dequeue();
                break;
            case 4:
                queueSize();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
