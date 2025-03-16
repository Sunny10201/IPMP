#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void pairwiseSwap(struct Node* head) {
    struct Node* curr = head;
    while (curr != NULL && curr->next != NULL) {
        int temp = curr->data;
        curr->data = curr->next->data;
        curr->next->data = temp;
        curr = curr->next->next;
    }
}
void printList(struct Node* head) {
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
struct Node* createList(int n) {
    if (n <= 0) return NULL;
    int val;
    scanf("%d", &val);
    struct Node* head = createNode(val);
    struct Node* temp = head;
    for (int i = 1; i < n; i++) {
        scanf("%d", &val);
        temp->next = createNode(val);
        temp = temp->next;
    }
    return head;
}
int main() {
    int n;
    scanf("%d", &n);
    struct Node* head = createList(n);
    pairwiseSwap(head);
    printList(head);
    return 0;
}
