#include <stdio.h>
int front = -1;
int rear = -1; 
int n;
int  loop = 0;

void enqueue(int a[])
{
    if (rear == -1 && front ==-1)
    {
        front = front +1;
        rear = rear +1;
        printf("Enter element \t");
        scanf("%d",&a[rear]);
    }
     else if (rear == n-1)
    {
        printf("Queue overflow");
    }
    else
    {
        rear = rear +1;
        printf("Enter element \t");
        scanf("%d",&a[rear]);
    }
}

void dequeue(int a[])
{
    if (front == -1 && rear == -1)
    {
        printf("Queue underflow");
    }
    else if( front > rear || front > n-1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Element removed is %d", a[front]);
        front ++;
    }
}

void size()
{
    int size = rear-front +1;
    printf("Size of the queue is %d",size);
}

void display(int a[])
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Elements in the queue are: ");
        for(int i = front; i <= rear; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}

void exit_queue()
{
    loop = 1;
}

void main()
{
    printf("Enter size of the queue \t");
    scanf("%d",&n);
    int a[n];
    int choice;
    while (loop == 0)
    {
            printf("\n");
            printf("Menu \n 1.Enqueue \n 2.Dequeue \n 3.Size \n 4.Display \n 5.Exit \n Enter your choice (1-5): \t");
            scanf("%d",&choice);
            switch (choice)
            {
                case (1):
                    enqueue(a);
                    break;
                
                case (2):
                    dequeue(a);
                    break;
                
                case (3):
                    size();
                    break;

                case (4):
                    display(a);
                    break;

                case (5):
                    exit_queue();
                    break;

                default:
                    printf("Invalid choice ");
                    break;
            }
    }
}
