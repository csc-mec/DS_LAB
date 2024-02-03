#include <stdio.h>
struct poly
{
    int coeff;
    int deg;
};

struct poly p1[10];
struct poly p2[10];
struct poly p3[10];

void main()
{
    int t1,t2;
    printf("Enter the number of terms for the first polynomial");
    scanf("%d",&t1);
    printf("Enter the number terms for the second polynomial");
    scanf("%d",&t2);
    printf("Enter the coefficient and the degree for the first polynomial \n");
    for (int i=0; i< t1; i++)
    {
        printf("Enter the degree \t");
        scanf("%d",&p1[i].deg);
        printf("Enter the coefficient \t");
        scanf("%d",&p1[i].coeff);
    }

    printf("Enter the coefficient and the degree for the second polynomial \n");
    for (int i=0; i< t2; i++)
    {
        
        printf("Enter the degree \t");
        scanf("%d",&p2[i].deg);
        printf("Enter the coefficient \t");
        scanf("%d",&p2[i].coeff);
    }

    int i= 0, j= 0, k=0;
    while(i<t1 && j< t2) // Common terms
    {
        if (p1[i].deg == p2[j].deg)
        {
            p3[k].deg = p1[i].deg;
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            i++;
            j++;
            k++;
        }
        else if (p1[i].deg > p2[j].deg)
        {
            p3[k].deg = p1[i].deg;
            p3[k].coeff = p1[i].coeff;
            i++;
            k++;
        }
        else
        {
            p3[k].deg = p2[j].deg;
            p3[k].coeff = p2[j].coeff;
            j++;
            k++;
        }
    }

    while (i<t1)    // Remaining termas
    {
        p3[k].deg = p1[i].deg;
        p3[k].coeff = p1[i].coeff;
        i++;
        k++;
    }
    
    while (j<t2)
    {
        p3[k].deg = p2[j].deg;
        p3[k].coeff = p2[j].coeff;
        j++;
        k++;
    }
    printf("The resulting polynomial is \n");
    for (int i=0; i< k; i++)
    {
        printf(" %dx^%d +\t",p3[i].coeff, p3[i].deg);
    }
}