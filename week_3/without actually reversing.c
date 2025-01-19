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
void printReverse(struct Node* curr) {
    if (curr == NULL){
        return; 
    }
    printReverse(curr->next);
    printf("%d ", curr->data);
}
int main()
{
    struct Node *head = createnode(1);
    head->next = createnode(2);
    head->next->next = createnode(3);
    head->next->next->next = createnode(4);
    head->next->next->next->next = createnode(5);
    printReverse(head);
    return 0;
}