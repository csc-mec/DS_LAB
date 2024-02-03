#include<stdio.h>
int create(int n,int m,int T[][3]){//function to create a tuple
    int k=0,e;
    //assigning values of column num and row num
    T[0][0]=n;
    T[0][1]=m;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            scanf("%d",&e);
            if (e!=0){//checking if non zero
                //adding element into tuple
                k=k+1;
                T[k][0]=i;
                T[k][1]=j;
                T[k][2]=e;
            }
        }
    }
    T[0][2]=k;
    return k;
}
void display(int k,int T[][3]){//displaying a tuple
    for (int i=0;i<=k;i++){
        printf ("%d  %d  %d\n",T[i][0],T[i][1],T[i][2]);
    }
}
int add(int n,int m,int k1,int k2, int T1[][3],int T2[][3],int T3[][3]){//to add tuples
    int i=1,j=1,k=0;//declaring i,j,k for traversing
    //assigning values of column num and row num
    T3[0][0]=n;
    T3[0][1]=m;
    while (i<=k1 && j<=k2){
        if (T1[i][0]==T2[j][0]){
            if(T1[i][1]==T2[j][1]){//when both column no and row no are equal of both tuples
                //adding and puting in result tuple
                k=k+1;
                T3[k][0]=T1[i][0];
                T3[k][1]=T1[i][1];
                T3[k][2]=T1[i][2] + T2[j][2];
                i=i+1;
                j=j+1;
            }
            else if (T1[i][1]<T2[j][1]){
                //putting in result tuple
                k=k+1;
                T3[k][0]=T1[i][0];
                T3[k][1]=T1[i][1];
                T3[k][2]=T1[i][2];
                i=i+1;
            }
            else{
            //putting in result tuple
            k=k+1;
            T3[k][0]=T2[j][0];
            T3[k][1]=T2[j][1];
            T3[k][2]=T2[j][2];
            j=j+1;
            }
        }
        else if (T1[i][0]<T2[j][0]){
            //putting in result tuple
            k=k+1;
            T3[k][0]=T1[i][0];
            T3[k][1]=T1[i][1];
            T3[k][2]=T1[i][2];
            i=i+1;
        }
        else{
            //putting in result tuple
            k=k+1;
            T3[k][0]=T2[j][0];
            T3[k][1]=T2[j][1];
            T3[k][2]=T2[j][2];
            j=j+1;
        }
    }
    while (i<=k1){
        //putting the remaining in result tuple
        k=k+1;
        T3[k][0]=T1[i][0];
        T3[k][1]=T1[i][1];
        T3[k][2]=T1[i][2];
        i=i+1;
    }
    while (j<=k2){
    //putting the remaining in result tuple
        k=k+1;
        T3[k][0]=T2[j][0];
        T3[k][1]=T2[j][1];
        T3[k][2]=T2[j][2];
        j=j+1;
    }
    return k;
}
int main(){
    int n1,m1,n2,m2,k1,k2,k3;//declaring order and size of tuples
    //inputing orders
    printf("Enter order of matrix 1 : ");
    scanf("%d%d",&n1,&m1);
    printf("Enter order of matrix 2 : ");
    scanf("%d%d",&n2,&m2);
    int T1[50][3],T2[50][3],T3[50][3];//declaring tuples
    if (n1!=n2 || m1!=m2){//checking if addition is possible
        printf("Addition not possible\n");
        return 0;
    }
    //entering matrices
    printf("Enter Matrix 1 : \n");
    k1=create(n1,m1,T1);
    printf("The Tuple is : \n");
    display(k1,T1);
    printf("Enter Matrix 2 : \n");
    k2=create(n2,m2,T2);
    printf("The Tuple is : \n");
    display(k2,T2);
    //printing output tuple
    printf("The Sum Tuple is : \n");
    k3=add(n1,m1,k1,k2,T1,T2,T3);
    T3[0][2]=k3;
    display(k3,T3);
    return 0;
}