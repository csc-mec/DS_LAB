#include<stdio.h>
#include<stdbool.h>
#define Msize 50
int f=-1,r=-1;//Declaring max size , rear and front
int A[Msize];//Declaring array
bool isFull(){//Function to check if function is full or not
    if ((r+1)%Msize==f){
        return true;
    }
    return false;
}
bool isEmpty(){//Function to check if function is empty or not
    return (f==-1);
}
void enQueue(){
    if (isEmpty()){//case : when queue is empty
        f=0;
        r=0;
        printf("Enter number : ");
        scanf("%d",&A[r]);
    }
    else if(isFull()){//case : Overflow
        printf("Overflow\n");
    }
    else{
        r=(r+1)%Msize;//changing rear
        printf("Enter number : ");//inputing element
        scanf("%d",&A[r]);
    }
}
void deQueue(){
    if (isEmpty()){//case : Underflow
        printf("Underflow\n");
    }
    else{
        printf("DeQueued element is : %d\n",A[f]);//printing dequeued element 
        f=(f+1)%Msize;//changing front
        if (f==(r+1)%Msize){//reseting front and rear when no more elements is left
            r=-1;
            f=-1;
        }
    }
}
void display(){
    if (isEmpty()){//case : Underflow
        printf("Underflow\n");
    }
    else{
        int i=f;
        //printing each element
        do{
            printf("%d  ",A[i]);
            i=(i+1)%Msize;
        }
        while (i!=(r+1)%Msize);
        printf("\n");
    }
}
int main(){
    int ch;
    while(true){//menu driven
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n\n");
        printf("Enter choice :");
        scanf("%d",&ch);
        //Evaluating choice
        switch (ch){
            case 1 :enQueue();break;
            case 2 :deQueue();break;
            case 3 :display();break;
            case 4 :return 0;break;
            default:printf("Invalid Choice\n");
        }
    }
}