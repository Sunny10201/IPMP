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

void populateinorderSuccessor(struct Node* root, struct Node** next) {
    if (root == NULL)
        return;
    populateinorderSuccessor(root->right, next);
    root->next = *next;
    *next = root;
    populateinorderSuccessor(root->left, next);
}

void printinorderSuccessor(struct Node* root) {
    while (root->left)
        root = root->left;
    while (root) {
        printf("%d -> %d\n", root->data, root->next ? root->next->data : -1);
        root = root->next;
    }
}

int main() {
    struct Node* root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(12);
    root->left->left = newNode(3);
    struct Node* next = NULL;
    populateinorderSuccessor(root, &next);
    printinorderSuccessor(root);
    return 0;
}
