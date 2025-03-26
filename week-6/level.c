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

bool checkLeavesLevelUtil(struct Node* root, int level, int* leafLevel) {
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL) {
        if (*leafLevel == 0) {
            *leafLevel = level;
            return true;
        }
        return (level == *leafLevel);
    }
    return checkLeavesLevelUtil(root->left, level + 1, leafLevel) &&
           checkLeavesLevelUtil(root->right, level + 1, leafLevel);
}

bool checkLeavesLevel(struct Node* root) {
    int leafLevel = 0;
    return checkLeavesLevelUtil(root, 0, &leafLevel);
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    if (checkLeavesLevel(root))
        printf("All leaves are at the same level");
    else
        printf("Leaves are not at the same level");
    return 0;
}
