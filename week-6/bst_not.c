#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool isBSTUtil(struct Node* node, struct Node* min, struct Node* max) {
    if (node == NULL)
        return true;
    if ((min != NULL && node->data <= min->data) || (max != NULL && node->data >= max->data))
        return false;
    return isBSTUtil(node->left, min, node) && isBSTUtil(node->right, node, max);
}

bool isBST(struct Node* root) {
    return isBSTUtil(root, NULL, NULL);
}

int main() {
    struct Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(20);
    root->left->left = newNode(2);
    root->left->right = newNode(8);
    root->right->left = newNode(15);
    root->right->right = newNode(25);
    if (isBST(root))
        printf("True\n");
    else
        printf("False\n");
    return 0;
}