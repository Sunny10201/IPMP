#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
int mul_2num_lists(struct Node *first, struct Node *second) {
    int num1 = 0, num2 = 0;
    while (first != NULL) {
        num1 = (num1 * 10 + first->data) % MOD;
        first = first->next;
    }
    while (second != NULL) {
        num2 = (num2 * 10 + second->data) % MOD;
        second = second->next;
    }
    return (num1 * num2) % MOD;
}
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
int main() {
    struct Node *head1 = createNode(9);
    head1->next = createNode(4);
    head1->next->next = createNode(6);
    struct Node *head2 = createNode(8);
    head2->next = createNode(4);
    printf("%d\n", mul_2num_lists(head1, head2));
    return 0;
}
