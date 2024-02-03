#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node                                                             
{
    int coefficent;
    int degree;
    struct node *next;
};

struct node* poly1 = NULL;
struct node* poly2 = NULL;
struct node* poly3 = NULL;

struct node* read_Poly(struct node *poly, int coeff, int deg)           
{
    struct node *temp = poly;
    struct node* newnode = malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->coefficent = coeff;
    newnode->degree = deg;
    if (poly == NULL)
    {
        poly  = newnode; 
    }
    else
    {
        while (temp->next!= NULL)
        {
           temp = temp->next;
        }
        temp->next = newnode;
    }
    return poly;
}
void display(struct node *poly)                                                 
{
    while(poly->next!= NULL)
    {
        printf("%dx^%d+ ",poly->coefficent, poly->degree);
        poly = poly->next;
    }
    printf("%dx^%d\n",poly->coefficent, poly->degree);
}

void addPoly()
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->next = NULL;
    struct node *temp1 = poly1;
    struct node *temp2 = poly2;
    struct node *temp3 = poly3;

    while (temp1!= NULL && temp2 != NULL)                                                        
    {
        if (temp1->degree == temp2->degree)
        {
            poly3 = read_Poly(poly3, (temp1->coefficent+temp2->coefficent), temp1->degree);
            temp1 = temp1->next;
            temp2 = temp2->next;
            
        }
        else if (temp1->degree > temp2->degree)
        {
            poly3 = read_Poly(poly3, temp1->coefficent, temp1->degree);
            temp1 = temp1->next;
        }
        else
        {
            poly3 = read_Poly(poly3, temp2->coefficent, temp2->degree);
            temp2 = temp2->next;
        }
    }
    while (temp1!=NULL)                                                                         
    {
        poly3 = read_Poly(poly3, temp1->coefficent, temp1->degree);
        temp1 = temp1->next;
    }
    while (temp2!=NULL)                                                                         
    {
        poly3 = read_Poly(poly3, temp2->coefficent, temp2->degree);
        temp2 = temp2->next;
    }
    display(poly3);
    
}



void main()
{
    int choice, coeff, deg;
    printf("\nSelect an option:\n");
    printf("1. Enter term for polynomial 1\n");
    printf("2. Enter term for polynomial 2\n");
    printf("3. Perform Addition\n");
    printf("4. Exit\n");
    while(1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter coefficient and degree for the term: ");
                scanf("%d%d", &coeff, &deg);
                poly1 = read_Poly(poly1, coeff, deg);
                break;
            case 2:
                printf("Enter coefficient and degree for the term: ");
                scanf("%d%d", &coeff, &deg);
                poly2 = read_Poly(poly2, coeff, deg);
                break;
            case 4:
                exit(0);
                break;
            case 3:
                addPoly();
                break;
                
            default:
                printf("Invalid choice!\n");
        }
    }
}