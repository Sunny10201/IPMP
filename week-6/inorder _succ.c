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

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct Node* inorderSuccessor(struct Node* root, struct Node* node) {
    if (node->right != NULL)
        return minValueNode(node->right);
    struct Node* successor = NULL;
    while (root != NULL) {
        if (node->data < root->data) {
            successor = root;
            root = root->left;
        } else if (node->data > root->data)
            root = root->right;
        else
            break;
    }
    return successor;
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
    struct Node* node = root->left;
    struct Node* successor = inorderSuccessor(root, node);
    if (successor != NULL)
        printf("Inorder Successor of %d is %d", node->data, successor->data);
    else
        printf("No inorder successor found for %d", node->data);
    return 0;
}