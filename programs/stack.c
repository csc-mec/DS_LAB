#include <stdio.h>
#include <stdbool.h>

int top =-1, n;
bool loop = false;
// stack push

void push(int a[])
{
    if (top == n-1)
    {
      printf("Stack Overflow");
    }
    else
    {
      top =top+1;
      printf("Enter value into the stack \t");
      scanf("%d",&a[top]);
    }

} 

void pop(int a[])
{
  if (top == -1)
  printf("Stack empty");

  else
  {
    printf("Element removed is %d",a[top]);
    top = top-1;
  }

}

void peek(int a[])
{
  if (top == -1)
  printf("Stack underflow");
  
  else
  printf("Element at the top of the stack is %d",a[top]);
}

void isFull(int a[])
{
  if (top == n-1)
  printf("Stack is full");
  
  else
  printf("Stack is not full");
}

void isEmpty(int a[])
{
  if (top == -1)
  printf("Stack is empty");
  
  else
  printf("Stack is not empty");
}

void exit_stack()
{
	loop = true;
}

void main()
{
  printf("Enter the size of the stack .");
  scanf("%d",&n);
  int a[n]; 
  int choice;
  while (loop == false)
  {
    printf("\n Menu \n 1.Push \n 2.Pop \n 3.Peek \n 4.isFull \n 5.isEmpty \n 6. Exit \n Enter your choice (1-5) \t");
    scanf("%d",&choice);
    switch (choice)
    {
    case  (1):
				push(a);
				break;
    case (2):
				pop(a);
				break;
	case (3):
				peek(a);
				break;
	case(4):
				isFull(a);
				break;
	case(5):
				isEmpty(a);
				break;
	case (6):
				exit_stack();
				break;
    default:
				printf("Invalid choice");
      			break;
    }

  }
  

}