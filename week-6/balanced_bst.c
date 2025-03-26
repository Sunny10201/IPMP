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

int height(struct Node* node) {
    if (node == NULL)
        return 0;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

bool isBalanced(struct Node* root) {
    if (root == NULL)
        return true;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if (abs(leftHeight - rightHeight) > 1)
        return false;
    return isBalanced(root->left) && isBalanced(root->right);
}

int main() {
    struct Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(20);
    root->left->left = newNode(2);
    root->left->right = newNode(8);
    root->right->left = newNode(15);
    root->right->right = newNode(25);
    if (isBalanced(root))
        printf("True\n");
    else
        printf("False\n");
    return 0;
}