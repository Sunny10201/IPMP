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

int maxDepth(struct Node* node) {
    if (node == NULL)
        return 0;
    int leftDepth = maxDepth(node->left);
    int rightDepth = maxDepth(node->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    printf("%d", maxDepth(root));
    return 0;
}