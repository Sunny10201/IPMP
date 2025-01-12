#include<stdlib.h>
#include <stdio.h>
void booleanMatrix(int mat[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == 1) {
                mat[0][j] = 1;
                mat[i][0] = 1;
            }
        }
    }
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (mat[i][0] == 1 || mat[0][j] == 1) {
                mat[i][j] = 1;
            }
        }
    }
    if (mat[0][0] == 1) {
        for (int j = 0; j < cols; j++) {
            mat[0][j] = 1;
        }
    }
    if (mat[0][0] == 1) {
        for (int i = 0; i < rows; i++) {
            mat[i][0] = 1;
        }
    }
}
int main() {
    int mat[10][10], rows, cols;

    printf("number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    booleanMatrix(mat, rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
