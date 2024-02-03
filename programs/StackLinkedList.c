#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

// Function to push an element onto the stack
void push(int x)
{
    struct node *t;
    t = (struct node*)malloc(sizeof(struct node));

    // Check if memory allocation is successful
    if (t == NULL)
        printf("Stack is full\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

// Function to pop an element from the stack
int pop()
{
    struct node *t;
    int x = -1;

    // Check if the stack is empty
    if (top == NULL)
        printf("Stack is Empty\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }

    return x;
}

// Function to display the elements of the stack
void display()
{
    struct node *p;
    p = top;

    // Traverse the stack and print each element
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
}

int main()
{
    int ch;

    do
    {
        // Display menu options
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
            {
                int x;
                // Get the element to be pushed from the user
                printf("Enter the element to be pushed: ");
                scanf("%d", &x);
                push(x);
                break;
            }
            case 2:
            {
                int x;
                // Pop an element and display it
                x = pop();
                printf("Popped element is: %d\n", x);
                break;
            }
            case 3:
            {
                // Display the elements in the stack
                display();
                break;
            }
            case 4:
            {
                printf("Exiting...\n");
                break;
            }
            default:
            {
                printf("Invalid choice\n");
                break;
            }
        }
    }
    while (ch != 4);

    return 0;
}
