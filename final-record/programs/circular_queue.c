#include<stdio.h>
#include<stdlib.h>

int main() {
    int c, item, front = -1, rear = -1;
    int max;
    printf("enter size of queue : ");
    scanf("%d", &max);
    int queue[max];

    void enqueue(int item) {
        if(front == -1 && rear == -1) {
            front = rear = 0;
            queue[rear] = item;
        } else if((rear + 1) % max == front) {
            printf("Queue is full\n");
        } else {
            rear = (rear + 1) % max;
            queue[rear] = item;
        }
    }

    void dequeue() {
        if(front == -1 && rear == -1) {
            printf("Queue is empty \n");
        } else if(front == rear) {
            printf("Element dequeued is:%d\n", queue[front]);
            front = rear = -1;
        } else {
            printf("Element dequeued is:%d\n", queue[front]);
            front = (front + 1) % max;
        }
    }

    void display() {
        int i = front;
        if(front == -1 && rear == -1) {
            printf("Queue is empty \n");
        }
        else {
            printf("Elements in a queue are: ");
            while(i != rear) {
                printf("%d ", queue[i]);
                i = (i + 1) % max;
            }
            printf("%d\n", queue[rear]);
        }
    }
    int ch;
    printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    while(1){
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("Enter the element to be inserted : ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice \n");
        }
    }
}
