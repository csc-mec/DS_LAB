#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define Msize 20
int top = -1;
int S[Msize];
void push(int x){
    top = top + 1;
    S[top] = x;
}
int pop(){
    top = top - 1;
    return S[top + 1];
}
bool isOperator(char ch){
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}
int main(){
    char C[30];
    int i = 0, o1, o2, r;
    printf("Enter expression : ");
    scanf("%s", &C);
    int l = strlen(C);
    while (i != l){
        if (!isOperator(C[i])){
            int n = C[i] - '0';
            push(n);
        }
        else{
            o2 = pop();
            o1 = pop();
            switch (C[i]){
            case '+':
                r = o1 + o2;
                break;
            case '-':
                r = o1 - o2;
                break;
            case '*':
                r = o1 * o2;
                break;
            case '/':
                r = o1 / o2;
                break;
            case '^':
                r = 1;
                for (int k = 1; k <= o2; k++){
                    r = r * o1;
                }
                break;
            default:
                printf("Invalid operators\n");
                return 0;
            }
            push(r);
        }
        i = i + 1;
    }
    int result = pop(); 
    printf("Result is : %d\n", result);
}
