#include<stdio.h>
#include<stdbool.h>
int Msize=30,f=-1,r=-1; //Settting max size and front and rear
int A[30]; //Declaring array for queue
bool isEmpty(){  //Function to check if queue is empty
    return (f==-1 || f>r);
}
bool isFull(){ //Function to checek if queue is full
    return (r==Msize-1);
}
void deQueue(){ 
    if(isEmpty()){ //Underflow condition
        printf("Queue Underflow\n");
    }
    else{ 
        printf("Dequeued element is %d",A[f++]);//printing dequeued element and incrimenting front
    }
}
void enQueue(){
    int key;
    if(isEmpty()){ //First element case
        printf("Enter elements :");
        scanf("%d",&A[++r]);
        f++;
    }
    else if(isFull()){ //Overflow condition
        printf("Queue Overflow\n");
    }
    else{
        printf("Enter elements : ");
        scanf("%d",&A[++r]);//incrimenting rear and adding element into rear position
        key = A[r];
        for (int i=r-1;i>=f;i--){//inserting to correct position
            if (key<A[i]){
                A[i+1]=A[i];
                A[i]=key;
            }
            else{
                break;
            }
        }
    }
}
void size(){//Function to return size
    if(isEmpty()){
        printf("Size is %d\n",0);
        }
    else{
        printf("Size is %d\n",r-f+1);
    }
}
void display(){//To display
    if(isEmpty()){//Underflow condition
        printf("Queue Underflow\n");
    }
    else{
        printf("The queue is :\n");
        for (int i=f;i<=r;i++){//printing each element one by one in correct order
             printf("%d  ",A[i]);
        }
        printf("\n");
    }
}
int main(){
    int ch,c=0;
    printf("ASCENDING ORDER PRIORITY QUEUE\n");
    while (true){//menu driven 
        printf("1. Display\n");
        printf("2. Enqueue\n");
        printf("3. Dequeue\n");
        printf("4. Size\n");
        printf("5. Exit\n\n");
        printf("Enter choice :");//Inputing choice
        scanf("%d",&ch);
        //Evaluating choice
        switch (ch){
            case 1 :display();break;
            case 2 :enQueue();break;
            case 3 :deQueue();break;
            case 4 :size();break;
            case 5 :return 0;break;
            default:printf("Invalid Choice\n");
            }
        printf("\n");
        if(f==Msize){//Queue ending function i.e, disadvantage of normal queue
            printf("Queue Ended \n");
            return 0 ;
        }
        c=c+1;
        if(c==200){//Condition to prevent loop from running till infinity
            printf("Limit reached\n");
            return 0 ;
        }
    }
    }