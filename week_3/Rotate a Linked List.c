#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}
struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
struct Node* rotate(struct Node *head, int k) {
    if (k == 0 || head == NULL){
        return head;
    }
    for (int i = 0; i < k; ++i) {
        struct Node *curr = head;
        while (curr->next != NULL){
            curr = curr->next;
        }
        curr->next = head;
        curr = curr->next;
        head = head->next;
        curr->next = NULL;
    }
    return head;
}

void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
int main() {
    struct Node *head = createnode(1);
    head->next = createnode(2);
    head->next->next = createnode(3);
    head->next->next->next = createnode(4);
    head->next->next->next->next = createnode(5);
    head->next->next->next->next->next = createnode(6);
    head->next->next->next->next->next->next = createnode(7);
    head->next->next->next->next->next->next->next = createnode(8);
    head->next->next->next->next->next->next->next->next = createnode(9);
    head->next->next->next->next->next->next->next->next->next = createnode(10);
    printf("linked list \n");
    printList(head);
    head = rotate(head, 4);
    printf("\nRotated Linked list \n");
    printList(head);
    return 0;
}