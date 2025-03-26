#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = node->next = NULL;
    return node;
}

void connect(struct Node* root) {
    if (root == NULL)
        return;
    struct Node* start = root;
    while (start) {
        struct Node* curr = start;
        while (curr) {
            if (curr->left)
                curr->left->next = curr->right;
            if (curr->right && curr->next)
                curr->right->next = curr->next->left;
            curr = curr->next;
        }
        start = start->left;
    }
}

void printNextPointers(struct Node* root) {
    while (root) {
        struct Node* temp = root;
        while (temp) {
            printf("%d -> %d  ", temp->data, temp->next ? temp->next->data : -1);
            temp = temp->next;
        }
        printf("\n");
        root = root->left;
    }
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    connect(root);
    printNextPointers(root);
    return 0;
}
