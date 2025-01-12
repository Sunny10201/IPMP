#include <stdio.h>
#define R 100
#define C 100

void diag_traversal(int arr[R][C], int n, int m) {
    int maxDiagonals = n + m - 1;
    for (int d = 0; d < maxDiagonals; d++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i + j == d) {
                    printf("%d ", arr[i][j]);
                }
            }
        }
        printf("\n");
    }
}

int main() {
    int arr[R][C], n, m;
    printf("number of rows: ");
    scanf("%d", &n);
    printf("number of columns: ");
    scanf("%d", &m);
    printf("elements of the matrix :");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    diag_traversal(arr, n, m);
    return 0;
}
