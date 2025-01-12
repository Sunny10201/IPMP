#include <stdio.h>
#include <stdlib.h>

void search_matrix(int mat[3][3], int n, int m, int x) {
    int i = 0, j = m - 1;

    while (i < n && j >= 0) {
        if (x > mat[i][j]) {
            i++;
        } else if (x < mat[i][j]) {
            j--;
        } else {
            return true;
        }
    }
    return false;
}

int main() {
    int mat[3][3];
    printf("enter the value of matrix:");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &mat[i][j]);
            printf("%d ", mat[i][j]);
        }
     printf("\n");
    }
    int x;
    printf("number to search in the matrix: ");
    scanf("%d", &x);
    if (search_matrix(mat, 3, 3, x)) {
        printf("true");
    } else {
        printf("false");
    }
    return 0;
}
