#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define Msize 100
//declaring size and setting top 
int top=-1;
int S[Msize];
//to push a number into stack
void push(int x){
    if(top!=Msize-1){
    	top=top+1;
    	S[top]=x;
    }
}
//to pop number from stack during incoming operator
int pop(){
    if(top!=-1){
        top=top-1;
        return S[top+1];
    }
}
//to check for operator
bool isOperator(char ch){
    return (ch=='+' || ch == '-' || ch =='*' || ch=='/' || ch =='^');
}
int main(){
    char C[30];
    int i=0,o1,o2,r;
    printf("Enter expression : ");
    scanf("%s",&C);
    int l= strlen(C);
    while(i!=l){
        if (!isOperator(C[i])){//incoming is number
            int n = C[i]-'0';
            push(n);
        }
        else{
            //obtaining operants from stack 
            o2=pop();
            o1=pop();
            switch (C[i]){
                case '+':r=o1+o2;break;
                case '-':r=o1-o2;break;
                case '*':r=o1*o2;break;
                case '/':r=o1/o2;break;
                case '^':
                r=1;
                for (int k=1;k<=o2;k++){
                    r=r*o1;
                }
                break;
                default:printf("Invalid operators\n");return 0;
            }
            //pushing result back to stack
            push(r);
        }
        i=i+1;
    }
    printf("Result is : %d\n",pop());
}