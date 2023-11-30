#include<stdio.h>
#include<stdbool.h>
#define Msize 30
int A[Msize];
int r=-1,f=-1;
bool isFull(){//Function to check if function is full or not
    if ((r+1)%Msize==f){
        return true;
    }
    return false;
}
bool isEmpty(){//Function to check if function is empty or not
    return (f==-1);
}
void addLast(){
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
void rmFirst(){
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
void addFirst(){
    if (isEmpty()){
        f=0;
        r=0;
        printf("Enter number : ");
        scanf("%d",&A[f]);
    }
    else if(isFull()){
        printf("Overflow\n");
    }
    else{
        (f==0)?(f=Msize-1):(f=f-1);
        printf("Enter number : ");//inputing element
        scanf("%d",&A[f]);
    }
}
void rmLast(){
    if (isEmpty()){//case : Underflow
        printf("Underflow\n");
    }
    else{
        printf("DeQueued element is : %d\n",A[r]);//printing dequeued element 
        (r==0)?(r=Msize-1):(r=r-1);
        if (f==(r+1)%Msize){//reseting front and rear when no more elements is left
            r=-1;
            f=-1;
        }
    }
}
void first(){
    if (isEmpty()){//case : Underflow
        printf("Underflow\n");
    }
    else{
        printf("First element is %d\n",A[f]);
    }
}
void last(){
    if (isEmpty()){//case : Underflow
        printf("Underflow\n");
    }
    else{
        printf("Last element is %d\n",A[r]);
    }
}
void size(){
    if (isEmpty()){//case : Underflow
        printf("Underflow\n");
    }
    else{
        int i=f,c=0;
        do{
            i=(i+1)%Msize;
            c=c+1;
        }
        while(i!=(r+1)%Msize);
        printf("Size is %d\n",c);
    }
}
void display(){
    if (isEmpty()){//case : Underflow
        printf("Underflow\n");
    }
    else{
        int i=f;
        do{
            printf("%d  ",A[i]);
            i=(i+1)%Msize;
        }
        while(i!=(r+1)%Msize);
        printf("\n");
    }
}
int main(){
    while (true){
        int ch;
        printf("\n1 . Add Last\n");
        printf("2 . Add First\n");
        printf("3 . Remove Last\n");
        printf("4 . Remove First\n");
        printf("5 . Print Last\n");
        printf("6 . Print First\n");
        printf("7 . Size\n");
        printf("8 . Display\n");
        printf("9 . Exit\n\n");
        printf("Enter choice : ");
        scanf("%d",&ch);
        switch (ch){
            case 1:addLast();break;
            case 2:addFirst();break;
            case 3:rmLast();break;
            case 4:rmFirst();break;
            case 5:last();break;
            case 6:first();break;
            case 7:size();break;
            case 8:display();break;
            case 9:return 0;break;
            default:printf("Enter valid choice\n");
        }
    }
}