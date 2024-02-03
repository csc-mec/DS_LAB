// Program that adds a node to the end of a linked list.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void main()
{
    // Creating 3 nodes.
    struct node *head =malloc(sizeof(struct node));
    head ->data = 35;
    head ->next = NULL;

    struct node *current = malloc(sizeof(struct node));
    current ->data = 45;
    current ->next = NULL;
    head ->next = current;

    current = malloc(sizeof(struct node));
    current ->data = 80;
    current ->next = NULL;

    head ->next ->next = current;


    // Creating temporary node

    struct node *temp = malloc(sizeof(struct node));
    temp ->data = 10;
    temp ->next = NULL;
    current ->next = temp;

    // Printing all the nodes

    struct node *ptr =head;
    while (ptr != NULL)
    {
        printf("%d \n",ptr->data);
        ptr = ptr->next;
    }
    
}