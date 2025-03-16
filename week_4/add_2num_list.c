#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
struct Node* addTwoNumbers(struct Node* num1, struct Node* num2, int carry) {
    if (num1 == NULL && num2 == NULL && carry == 0) {
        return NULL;
    }
    int sum = carry;
    if (num1) {
        sum += num1->data;
        num1 = num1->next;
    }
    if (num2) {
        sum += num2->data;
        num2 = num2->next;
    }
    struct Node* result = createNode(sum % 10);
    result->next = addTwoNumbers(num1, num2, sum / 10);
    return result;
}
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
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
    int n1, n2;
    scanf("%d", &n1);
    struct Node* num1 = createList(n1);
    scanf("%d", &n2);
    struct Node* num2 = createList(n2);
    struct Node* result = addTwoNumbers(num1, num2, 0);
    printList(result);
    return 0;
}
