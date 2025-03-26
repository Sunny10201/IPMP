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

bool ChildrenSumProperty(struct Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return true;
    int leftData = root->left ? root->left->data : 0;
    int rightData = root->right ? root->right->data : 0;
    if (root->data == leftData + rightData &&
        ChildrenSumProperty(root->left) &&
        ChildrenSumProperty(root->right))
        return true;
    return false;
}

int main() {
    struct Node* root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->right = newNode(2);
    if (ChildrenSumProperty(root))
        printf("True\n");
    else
        printf("False\n");
    return 0;
}
