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

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) 
        return newNode(data);
    if (data < root->data) 
        root->left = insert(root->left, data);
    else 
        root->right = insert(root->right, data);
    return root;
}

int findMin(struct Node* root) {
    if (root == NULL) 
        return -1;
    while (root->left != NULL) 
        root = root->left;
    return root->data;
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 35);
    printf("Minimum value in BST: %d", findMin(root));
    return 0;
}
