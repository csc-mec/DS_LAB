#include <stdio.h>
#include <stdlib.h>

struct node 
{
    struct node *left;
    int data;
    struct node *right;
};

void rightChild(struct node *root, int val)
{
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = val;
    ptr->right = NULL;
    ptr->left = NULL;
    root->right = ptr;
}

void leftChild(struct node *root , int val)
{
        struct node *ptr = malloc(sizeof(struct node));
        ptr->data = val;
        ptr->left= NULL;
        ptr->right= NULL;
        root->left= ptr;
}

// Recursive approach for preorder traversal

void preorderTraversal(struct node *ptr)
{
    if (ptr!= NULL)
    {
        printf("%d",ptr->data);
        preorderTraversal(ptr->left);
        preorderTraversal(ptr->right);
    }
}

//Iterative approach for preorder traversal using stack

void preorderIterative(struct node *root)
{
    struct node* stack[100];
    int top = -1;
    top = 0;
    stack[top] = root;
    while (top !=-1)
    {
        struct node *ptr = stack[top];
        printf("%d",ptr->data);
        top = top-1;
        if (ptr->right)                             //Push right then left child as stack implements LIFO
        {
            top = top+1;
            stack[top] = ptr->right;
        }
        if (ptr->left)
        {
            top = top+1;
            stack[top] = ptr->left;
        }
    }
    printf("\n");
}

void inorderTraversal(struct node *ptr)                 //Inorder traversal using Recursion
{
    if (ptr!= NULL)
    {
        inorderTraversal(ptr->left);
        printf("%d",ptr->data);
        inorderTraversal(ptr->right);
    }
}

void inorderIterative(struct node *root)
{
    if (!root) {
        return;
    }

    struct node* stack[1000];  // Assuming a maximum of 1000 nodes
    int top = -1;

    struct node* current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d", current->data);

        current = current->right;
    }
}

void postorderTraversal(struct node* ptr)               //Postorder traversal recursive approach
{
    if (ptr!=NULL)
    {
        postorderTraversal(ptr->left);
        postorderTraversal(ptr->right);
        printf("%d",ptr->data);
    }
}


  

void postorderIterative(struct node *root)
{
    if (!root) {
        return;
    }

    struct node* stack[1000];  // Assuming a maximum of 1000 nodes
    int top = -1;
    struct node* current = root;
    struct node* prev = NULL;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        if (stack[top]->right == NULL || stack[top]->right == prev) {
            current = stack[top--];
            printf("%d", current->data);
            prev = current;
            current = NULL;
        } else {
            current = stack[top]->right;
        }
    }
}


void main()
{
    struct node *root_node = malloc(sizeof(struct node));
    root_node->data = 1;
    leftChild(root_node,2);
    rightChild(root_node,3);
    leftChild(root_node->left,4);
    rightChild(root_node->left,5);
    leftChild(root_node->right,6);
    rightChild(root_node->right,7);
    printf("Preorder Traversal\n");
    preorderTraversal(root_node);
    printf("\nIterative approach\n");
    preorderIterative(root_node);
    printf("\n\n Inorder Traversal\n");
    inorderTraversal(root_node);
    printf("\n Iterative approach\n");
    inorderIterative(root_node);
    printf("\n\n Postorder Traversal\n");
    postorderTraversal(root_node);
    printf("\nIterative approach\n");
    postorderIterative(root_node);

}