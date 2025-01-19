#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct node* createnode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
struct Node *even_odd_list(struct Node *head) {
    struct Node *evenHead = NULL, *evenTail = NULL;
    struct Node *oddHead = NULL, *oddTail = NULL;
    struct Node *current = head;

    while (current != NULL) {
        struct Node *nextNode = current->next;
        if (current->data % 2 == 0) {
            if (evenHead == NULL) {
                evenHead = current;
                evenTail = evenHead;
            } else {
                evenTail->next = current;
                evenTail = evenTail->next;
            }
        } else {
            if (oddHead == NULL) {
                oddHead = current;
                oddTail = oddHead;
            } else {
                oddTail->next = current;
                oddTail = oddTail->next;
            }
        }
        current->next = NULL;
        current = nextNode;
    }

    if (evenHead == NULL) {
        return oddHead;
    }

    evenTail->next = oddHead;
    return evenHead;
}
void displayList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
int main() {
    struct Node *head = createNode(17);
    head->next = createNode(15);
    head->next->next = createNode(8);
    head->next->next->next = createNode(12);
    head->next->next->next->next = createNode(10);
    head->next->next->next->next->next = createNode(5);
    head->next->next->next->next->next->next = createNode(4);
    head->next->next->next->next->next->next->next = createNode(1);
    head->next->next->next->next->next->next->next->next = createNode(7);
    head->next->next->next->next->next->next->next->next->next = createNode(6);
    printf("Original Linked List:\n");
    displayList(head);
    head = even_odd_list(head);
    printf("Modified Linked List (Even followed by Odd):\n");
    displayList(head);
    return 0;
}
