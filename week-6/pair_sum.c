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

int pair(struct Node* root, int sum, int* set, int* index) {
    if (root == NULL)
        return 0;
    if (pair(root->left, sum, set, index))
        return 1;
    if (*index > 0) {
        for (int i = 0; i < *index; i++) {
            if (set[i] + root->data == sum) {
                printf("Pair found: (%d, %d)\n", set[i], root->data);
                return 1;
            }
        }
    }
    set[(*index)++] = root->data;
    return pair(root->right, sum, set, index);
}

void findPair(struct Node* root, int sum) {
    int set[1000];
    int index = 0;
    if (!pair(root, sum, set, &index))
        printf("No pair found\n");
}

int main() {
    struct Node* root = newNode(15);
    root->left = newNode(10);
    root->right = newNode(20);
    root->left->left = newNode(8);
    root->left->right = newNode(12);
    root->right->left = newNode(16);
    root->right->right = newNode(25);
    int sum = 28;
    findPair(root, sum);
    return 0;
}
