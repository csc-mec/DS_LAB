#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Define a structure for a doubly linked list node
struct node {
    int data;            // Data stored in the node
    struct node* prev;   // Pointer to the previous node in the list
    struct node* next;   // Pointer to the next node in the list
} *current, *head, *tail, *newnode, *temp;

// Function to add a new node at the front of the list
void addFront(int x) {
    // Allocate memory for a new node
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = NULL;

    // If the list is empty, set both head and tail to the new node
    if (head == NULL) {
        tail = newnode;
        head = newnode;
    } else {
        // Otherwise, update pointers to insert the new node at the front
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

// Function to delete the node at the front of the list
void deleteFront() {
    if (head == NULL) {
        // If the list is empty, print a message
        printf("Nothing to delete\n");
    } else {
        // Otherwise, update pointers and free the memory of the node being deleted
        temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL;
        free(temp);
    }
}

// Function to insert a new node at the end of the list
void insertEnd(int x) {
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (tail == NULL) {
        // If the list is empty, set both head and tail to the new node
        head = newnode;
        tail = newnode;
    } else {
        // Otherwise, update pointers to insert the new node at the end
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

// Function to delete the node at the end of the list
void deleteEnd() {
    if (tail == NULL) {
        // If the list is empty, print a message
        printf("Nothing to delete\n");
    } else {
        // Otherwise, update pointers and free the memory of the node being deleted
        temp = tail;
        tail = tail->prev;
        if (tail != NULL)
            tail->next = NULL;
        else
            head = NULL;
        free(temp);
    }
}

// Function to insert a new node after a specific value in the list
void insertSpecific(int x, int search) {
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (head == NULL) {
        // If the list is empty, set both head and tail to the new node
        head = newnode;
        tail = newnode;
    } else {
        // Search for the specified value in the list
        current = head;
        while (current != NULL) {
            if (current->data == search) {
                // Update pointers to insert the new node after the found value
                newnode->next = current->next;
                newnode->prev = current;
                if (current->next != NULL)
                    current->next->prev = newnode;
                else
                    tail = newnode;
                current->next = newnode;
                return;
            }
            current = current->next;
        }
        // If the specified value is not found, print a message
        printf("Element not found\n");
    }
}

// Function to delete the node with a specific value in the list
void deleteSpecific(int search) {
    if (head == NULL) {
        // If the list is empty, print a message
        printf("Nothing to delete\n");
    } else {
        // Search for the specified value in the list
        current = head;
        while (current != NULL) {
            if (current->data == search) {
                // Update pointers to remove the node with the specified value
                if (current->prev != NULL)
                    current->prev->next = current->next;
                else
                    head = current->next;
                if (current->next != NULL)
                    current->next->prev = current->prev;
                else
                    tail = current->prev;
                // Free the memory of the node being deleted
                free(current);
                return;
            }
            current = current->next;
        }
        // If the specified value is not found, print a message
        printf("Element not found\n");
    }
}

// Function to display the elements of the list
void display() {
    if (head == NULL) {
        // If the list is empty, print a message
        printf("Nothing to display\n");
    } else {
        // Otherwise, traverse the list and print each element
        current = head;
        while (current != NULL) {
            printf("<-%d->", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    int ch, data, search;

    // Menu-driven loop for interacting with the doubly linked list
    while (true) {
        printf("1.Insert at front\n2.Delete at Front\n3.Insert at rear\n4.Delete at rear\n5.Insert at position\n6.Delete at position\n7.Display\n8.Exit\n");
        printf("Enter choice:");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter data:");
                scanf("%d", &data);
                addFront(data);
                break;
            case 2:
                deleteFront();
                break;
            case 3:
                printf("Enter data:");
                scanf("%d", &data);
                insertEnd(data);
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                printf("Enter data:");
                scanf("%d", &data);
                printf("Enter search:");
                scanf("%d", &search);
                insertSpecific(data, search);
                break;
            case 6:
                printf("Enter search:");
                scanf("%d", &search);
                deleteSpecific(search);
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid\n");
        }
    }
    return 0;
}
