#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void range(struct Node* root, int low, int high) {
    if (root == NULL)
        return;
    if (low < root->data)
        range(root->left, low, high);
    if (low <= root->data && high >= root->data)
        printf("%d ", root->data);
    if (high > root->data)
        range(root->right, low, high);
}

int main() {
    struct Node* root = newNode(15);
    root->left = newNode(10);
    root->right = newNode(20);
    root->left->left = newNode(8);
    root->left->right = newNode(12);
    root->right->left = newNode(16);
    root->right->right = newNode(25);
    int low = 10, high = 20;
    range(root, low, high);
    return 0;
}
