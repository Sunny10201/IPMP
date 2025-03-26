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

int getWidth(struct Node* root, int level) {
    if (root == NULL)
        return 0;
    if (level == 1)
        return 1;
    return getWidth(root->left, level - 1) + getWidth(root->right, level - 1);
}

int maxWidth(struct Node* root) {
    int maxWidth = 0, width, h, i;
    h = maxDepth(root);
    for (i = 1; i <= h; i++) {
        width = getWidth(root, i);
        if (width > maxWidth)
            maxWidth = width;
    }
    return maxWidth;
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
    root->right->right = newNode(6);
    root->right->left = newNode(7);
    printf("%d", maxWidth(root));
    return 0;
}
