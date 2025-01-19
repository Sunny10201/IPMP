#include<stdio.h>
#include<stdlib.h>

struct Node
{
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
int findNthFromLast(struct Node* head, int N) {
    int len = 0, i;
    struct Node* temp = head;
    while (temp != NULL) {
        temp = temp->next;
        len++;
    }
    if (len < N)
        return -1;

    temp = head;
    for (i = 1; i < len - N + 1; i++)
        temp = temp->next;

    return temp->data;
}
int main()
{
    struct Node* head = createnode(1);
    head->next = createnode(2);
    head->next->next = createnode(3);
    head->next->next->next = createnode(4);
    head->next->next->next->next = createnode(5);
    printf("%d", findNthFromLast(head, 2));
    return 0;
}