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

int height(struct Node* root) {
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void printLevel(struct Node* root, int level, int ltr) {
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) {
        if (ltr) {
            printLevel(root->left, level - 1, ltr);
            printLevel(root->right, level - 1, ltr);
        } else {
            printLevel(root->right, level - 1, ltr);
            printLevel(root->left, level - 1, ltr);
        }
    }
}

void printSpiral(struct Node* root) {
    int h = height(root);
    int i;
    int ltr = 0;
    for (i = 1; i <= h; i++) {
        printLevel(root, i, ltr);
        ltr = !ltr;
    }
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    printSpiral(root);
    return 0;
}
