#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node*prev;
    int data;
    struct node*next;
};
struct node *head=NULL,*tail,*newnode,*temp,*current,*back,*ptr;

void create()
{
    int n;
    printf("ENTER NO OF NODES: ");
    scanf("%d",&n);
    printf("ENTER ELEMENTS: ");
    for(int i=0;i<n;i++)
    {
    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL && tail==NULL)
    {
        head=tail=newnode;
    }
    else
    {
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}
}
void display()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void addfront()
{
    int data;
    printf("ENTER ELEMENT TO BE ADDED IN THE FRONT: ");
    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    if (head==NULL)
    {
        head=tail=newnode;
    
    }
    else
    {
        head->prev=newnode;
        newnode->next=head;
        head=newnode;
    }
}

void addrear()
{
    int data;
    printf("ENTER ELEMENT TO BE ADDED AT THE END: ");
    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL && tail==NULL)
    {
        head=tail=newnode;
    }
    else
    {
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
    
}

void addbetween()
{
    int c;
    temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        c++;
    }
    int pos;
    printf("ENTER POSITION WHERE ELEMENT IS TO BE ADDED: ");
    scanf("%d",&pos);
    int data;
    printf("ENTER ELEMENT: ");
    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    if (pos>c)
    {
        printf("invalid pos\n");
        
    }
    else
    {
        int i=1;
        temp=head;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        if(newnode->next!=NULL){
            newnode->next->prev=newnode;
        }
    }
    
}

void delfront()
{
    temp=head;
    printf("Deleted Element: %d\n",temp -> data);
    head=head->next;
    head->prev=NULL;
    free(temp);
}

void delrear()
{
    temp=head;
    while(temp->next!=NULL)
    {
        back=temp;
        temp=temp->next;
        
    }
    back->next=NULL;
    printf("Deleted Element: %d\n",temp -> data);
    free(temp);
}

void delbetween()
{
    int pos;
    printf("ENTER POSITION: ");
    scanf("%d",&pos);
    int i=1;
    temp=head;
    while(i<pos-1)
    {
       temp=temp->next;
       i++;
    }
    ptr=temp->next;
    temp->next=ptr->next;
    printf("Deleted Element: %d\n",ptr -> data);
    free(ptr);
    
}

void main()
{
    int ch;
    int flag=1;
    printf("1.CREATE N NODES\n2.DISPLAY\n3.INSERTION AT FRONT\n4.INSERTION AT REAR\n5.INSERTION IN BETWEEN\n6.DELETION AT FRONT\n7.DELETION AT REAR\n8.DELETION IN BETWEEN\n9.EXIT\n");
    while(flag==1)
    {
        printf("ENTER CHOICE: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:create();break;
            case 2:display();break;
            case 3:addfront();break;
            case 4:addrear();break;
            case 5:addbetween();break;
            case 6:delfront();break;
            case 7:delrear();break;
            case 8:delbetween();break;
            case 9:flag=0;break;
            default:printf("invalid ch");break;  
        }
    }
}
