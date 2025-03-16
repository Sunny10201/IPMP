#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
void printList(struct Node *head) {
    struct Node *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}
struct Node *merge(struct Node *head1, struct Node *head2) {
    struct Node *curr1 = head1;
    struct Node *curr2 = head2;
    struct Node *next1, *next2;

    while (curr1 != NULL && curr2 != NULL) {
        next1 = curr1->next;
        next2 = curr2->next;
        curr2->next = curr1->next;
        curr1->next = curr2;
        curr1 = next1;
        curr2 = next2;
    }
    return curr2;
}
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
int main() {
    struct Node *head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(20);
    struct Node *head2 = createNode(10);
    head2->next = createNode(1);
    head2->next->next = createNode(6);
    head2->next->next->next = createNode(9);
    head2->next->next->next->next = createNode(2);
    struct Node *remaining = merge(head1, head2);
    printList(head1);
    return 0;
}
