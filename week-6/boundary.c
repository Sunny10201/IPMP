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

void printLeaves(struct Node* root) {
    if (root == NULL)
        return;
    printLeaves(root->left);
    if (root->left == NULL && root->right == NULL)
        printf("%d ", root->data);
    printLeaves(root->right);
}

void printBoundaryLeft(struct Node* root) {
    if (root == NULL)
        return;
    if (root->left) {
        printf("%d ", root->data);
        printBoundaryLeft(root->left);
    } else if (root->right) {
        printf("%d ", root->data);
        printBoundaryLeft(root->right);
    }
}

void printBoundaryRight(struct Node* root) {
    if (root == NULL)
        return;
    if (root->right) {
        printBoundaryRight(root->right);
        printf("%d ", root->data);
    } else if (root->left) {
        printBoundaryRight(root->left);
        printf("%d ", root->data);
    }
}

void printBoundary(struct Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    printBoundaryLeft(root->left);
    printLeaves(root->left);
    printLeaves(root->right);
    printBoundaryRight(root->right);
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    printBoundary(root);
    return 0;
}
