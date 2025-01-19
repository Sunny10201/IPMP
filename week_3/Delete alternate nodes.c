#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void deleteAlternateNodes(struct Node* head) {
    if (head == NULL)
        return;
    struct Node* curr = head;
    struct Node* temp;
    while (curr != NULL && curr->next != NULL) {
        temp = curr->next;
        curr->next = curr->next->next;
        free(temp);
        curr = curr->next;
    }
}
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original List:\n");
    printList(head)
    deleteAlternateNodes(head);
    printf("deleting alternate nodes:\n");
    printList(head);

    return 0;
}
