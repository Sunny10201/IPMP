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
void sort_list_0_1_2(struct Node *start) {
    int count[3] = {0, 0, 0};
    struct Node *current = start;
    while (current != NULL) {
        count[current->data] += 1;
        current = current->next;
    }
    int index = 0;
    current = start;

    while (current != NULL) {
        if (count[index] == 0) {
            index += 1;
        } else {
            current->data = index;
            count[index] -= 1;
            current = current->next;
        }
    }
}
void displayList(struct Node *node) {
    while (node != NULL) {
        printf(" %d", node->data);
        node = node->next;
    }
    printf("\n");
}
int main() {
    struct Node *head = createNode(1);
    head->next = createNode(1);
    head->next->next = createNode(2);
    head->next->next->next = createNode(1);
    head->next->next->next->next = createNode(0);
    printf("before Sorting:");
    displayList(head);
    sort_list_0_1_2(head);
    printf("after Sorting:");
    displayList(head);
    return 0;
}
