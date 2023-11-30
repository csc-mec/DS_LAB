#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
//setting maxsize of stack and array initializing index and creating stack and array
int top=-1,i=-1;
#define Asize 30
#define Bsize 60
char A[Asize];
char B[Bsize];
int prio(char c){//function to return priority and checek for operator
    switch (c){
        case '(':return 0;break;
        case '+':return 1;break;
        case '-':return 1;break;
        case '*':return 2;break;
        case '/':return 2;break;
        case '^':return 3;break;
        default :return -1;
    }
}
bool isEmptyA(){//check if stack is empty
    return (top==-1);
}
bool isFullA(){//checek stack is full
    return (top==Asize-1);
}
bool isFullB(){//check array is full
    return (i==Bsize-1);
}
//to push Operator  into stack
void push(char c){
    if (isFullA()){
        printf("Stack Overflow\n");
    }
    else{
        A[++top]=c;
    }
}
//to pop operator from stack
char pop(){
    if (isEmptyA()){
        printf("Underflow\n");
        return '@';
    }
    else {
        top--;
        return A[top+1];
    }
}
//to add operator or operant into postfix expression
void add(char c){
     if (isFullB()){
        printf("Expression Limit\n");
        exit(0);
    }
    else{
        B[++i]=c;
    }
}
void main(){
    char x;
    char C[30];
    printf("Enter expression : ");
    scanf("%s",&C);
    int l= strlen(C);
    for(int j=0;j<l;j++){
        if(C[j]==')'){//bracket close case
            while(A[top]!='('){
                x=pop();
                add(x);
            }
            x=pop();
        }
        else if(C[j]=='^' && A[top]=='^'){//double exponent 
            push(C[j]);
        }
        else if(prio(C[j])==-1){//operant case
            add(C[j]);
        }
        else{//operator case
            if(isEmptyA() || C[j]=='('){//empty stack or bracket open case
                push(C[j]);
            }
            else if(prio(C[j])>prio(A[top])){//comparing stack top and incoming element
                push(C[j]);
            }
            else{
                //poping element till lower priority operator is at stack top or stack is empty
                while(!isEmptyA() && prio(C[j])<=prio(A[top])){
                    x=pop();
                    add(x);
                }
                push(C[j]);
            }
        }
    }
    //adding rest of operators into postfix expression
    while(!isEmptyA()){
        x=pop();
        add(x);
    }
    for (int j=0;j<i+1;j++){
        printf("%c",B[j]);
    }
    printf("\n");
}