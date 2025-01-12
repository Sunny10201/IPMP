#include <stdio.h>

void sort_seq(int arr[], int n) {
    if (n < 3) {
        printf("Notexists.\n");
        return;
    }

    int smaller[n], greater[n];
    int minIndex = 0, maxIndex = n - 1;

    smaller[0] = -1;
    for (int i = 1; i < n; i++) {
        if (arr[i] <= arr[minIndex]) {
            minIndex = i;
            smaller[i] = -1;
        } else {
            smaller[i] = minIndex;
        }
    }

    greater[n - 1] = -1;
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] >= arr[maxIndex]) {
            maxIndex = i;
            greater[i] = -1;
        } else {
            greater[i] = maxIndex;
        }
    }

    for (int i = 0; i < n; i++) {
        if (smaller[i] != -1 && greater[i] != -1) {
            printf("Triplet: %d, %d, %d\n", arr[smaller[i]], arr[i], arr[greater[i]]);
            return;
        }
    }

    printf("Not exists.\n");
}

int main() {
   int n;
    printf("size of an array:");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",a[i]);
    }
    sort_seq(arr, n);
    return 0;
}
