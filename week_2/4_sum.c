#include <stdio.h>
#include <stdlib.h>

void printQuadruplets(int a, int b, int c, int d) {
    printf("[%d, %d, %d, %d]\n", a, b, c, d);
}

void fourSum(int nums[], int n, int target) {
    int i, j, k, l;

    qsort(nums, n, sizeof(int), compare);

    for (i = 0; i < n - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        for (j = i + 1; j < n - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            int left = j + 1, right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];

                if (sum == target) {
                    printQuadruplets(nums[i], nums[j], nums[left], nums[right]);

                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    printf("size of an array:");
    scanf("%d",&n);
    int nums[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",nums[i]);
    }
    printf("enter the target ");
    scanf("%d",target);
    fourSum(nums, n, target);

    return 0;
}
