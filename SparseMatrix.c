  #include <stdio.h>

int main() {
    int r1, c1, k = 0, flag = 0;
    printf("Enter no. of rows: ");
    scanf("%d", &r1);
    printf("Enter no. of columns: ");
    scanf("%d", &c1);
    int A[r1][c1];

    printf("Enter elements: ");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &A[i][j]);
            if (A[i][j] != 0) {
                flag++;
            }
        }
    }

    int sparse[flag + 1][3];  // Increase the size by 1

    sparse[0][0] = r1;
    sparse[0][1] = c1;
    sparse[0][2] = flag;

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            if (A[i][j] != 0) {
                k++;
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = A[i][j];
            }
        }
    }

    printf("Sparse: \n");
    for (int i = 0; i <= flag; i++) {  // Change the loop condition
        for (int j = 0; j < 3; j++) {
            printf("%d\t", sparse[i][j]);
        }
        printf("\n");
    }

    return 0;
}
