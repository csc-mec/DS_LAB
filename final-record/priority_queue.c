#include<stdio.h>
#include<stdbool.h>
int Msize=30,f=-1,r=-1;  
int A[30];  
bool isEmpty(){  
    return (f==-1 || f>r);
}
bool isFull(){ 
    return (r==Msize-1);
}
void deQueue(){ 
    if(isEmpty()){ 
        printf("Queue Underflow\n");
    }
    else{ 
        printf("Dequeued element is %d",A[f++]);
    }
}
void enQueue(){
    int key;
    if(isEmpty()){  
        printf("Enter elements :");
        scanf("%d",&A[++r]);
        f++;
    }
    else if(isFull()){ 
        printf("Queue Overflow\n");
    }
    else{
        printf("Enter elements : ");
        scanf("%d",&A[++r]);
        key = A[r];
        for (int i=r-1;i>=f;i--){
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
void size(){
    if(isEmpty()){
        printf("Size is %d\n",0);
        }
    else{
        printf("Size is %d\n",r-f+1);
    }
}
void display(){ 
    if(isEmpty()){ 
        printf("Queue Underflow\n");
    }
    else{
        printf("The queue is :\n");
        for (int i=f;i<=r;i++){ 
             printf("%d  ",A[i]);
        }
        printf("\n");
    }
}
int main(){
    int ch,c=0;
    printf("ASCENDING ORDER PRIORITY QUEUE\n");
    while (true){
        printf("1. Display\n");
        printf("2. Enqueue\n");
        printf("3. Dequeue\n");
        printf("4. Size\n");
        printf("5. Exit\n\n");
        printf("Enter choice :");
        scanf("%d",&ch);
        switch (ch){
            case 1 :display();break;
            case 2 :enQueue();break;
            case 3 :deQueue();break;
            case 4 :size();break;
            case 5 :return 0;break;
            default:printf("Invalid Choice\n");
            }
        printf("\n");
        if(f==Msize){
            printf("Queue Ended \n");
            return 0 ;
        }
        c=c+1;
        if(c==200){
            printf("Limit reached\n");
            return 0 ;
        }
    }
    }
