#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node *skipMdeleteN(struct Node *head, int m, int n) {
    struct Node *curr = head;
    struct Node *t;
    int count;
    while (curr != NULL) {
        for (count = 1; count < m && curr != NULL; count++)
            curr = curr->next;
        if (curr == NULL)
            return head;
        t = curr->next;
        for (count = 1; count <= n && t != NULL; count++) {
            struct Node *temp = t;
            t = t->next;
            free(temp);
        }
        curr->next = t;
        curr = t;
    }
    return head;
}
void printList(struct Node *head) {
    struct Node *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}
struct Node *createNode(int data) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
int main() {
    struct Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(6);
    head->next->next->next = createNode(11);
    head->next->next->next->next = createNode(2);
    head->next->next->next->next->next = createNode(1);
    int m = 1, n = 2;
    head = skipMdeleteN(head, m, n);
    printList(head);
    return 0;
}
