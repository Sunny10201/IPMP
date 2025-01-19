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
int findTriplet(struct Node *list1, struct Node *list2, struct Node *list3, int target) {
    struct Node *a = list1;
    while (a != NULL) {
        struct Node *b = list2;
        struct Node *c = list3;
        while (b != NULL && c != NULL) {
            int sum = a->data + b->data + c->data;
            if (sum == target) {
                printf("Triplet found: %d, %d, %d\n", a->data, b->data, c->data);
                return 1;
            } else if (sum < target) {
                b = b->next;
            } else {
                c = c->next;
            }
        }
        a = a->next;
    }
    printf("No triplet found\n");
    return 0;
}
void displayList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
int main() {
    struct Node *list1 = createNode(12);
    list1->next = createNode(6);
    list1->next->next = createNode(29);

    struct Node *list2 = createNode(23);
    list2->next = createNode(5);
    list2->next->next = createNode(8);

    struct Node *list3 = createNode(90);
    list3->next = createNode(20);
    list3->next->next = createNode(59);

    printf("List 1: ");
    displayList(list1);

    printf("List 2: ");
    displayList(list2);

    printf("List 3: ");
    displayList(list3);

    int target = 101;
    printf("Target Sum: %d\n", target);

    findTriplet(list1, list2, list3, target);

    return 0;
}
