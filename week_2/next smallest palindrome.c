#include <stdio.h>

int isPalindrome(int num) {
    int n, k, rev = 0;
    n = num;
    while (num != 0) {
        k = num % 10;
        rev = (rev * 10) + k;
        num = num / 10;
    }
    return (n == rev);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    while (!isPalindrome(num))
        num += 1;
    printf("Next palindrome number is %d", num);
    return 0;
}
