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

bool isComplete(struct Node* root) {
    if (root == NULL)
        return true;
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    bool flag = false;
    while (front < rear) {
        struct Node* temp = queue[front++];
        if (temp->left) {
            if (flag)
                return false;
            queue[rear++] = temp->left;
        } else {
            flag = true;
        }
        if (temp->right) {
            if (flag)
                return false;
            queue[rear++] = temp->right;
        } else {
            flag = true;
        }
    }
    return true;
}

int main() {
    struct Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(20);
    root->left->left = newNode(2);
    root->left->right = newNode(8);
    root->right->left = newNode(15);
    root->right->right = newNode(25);
    if (isComplete(root))
        printf("True\n");
    else
        printf("False\n");
    return 0;
}
