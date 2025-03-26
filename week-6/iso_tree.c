#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stack>

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

bool isIsomorphic(struct Node* root1, struct Node* root2) {
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
    if (root1->data != root2->data)
        return false;
    
    std::stack<struct Node*> stack1, stack2;
    stack1.push(root1);
    stack2.push(root2);
    
    while (!stack1.empty() && !stack2.empty()) {
        struct Node* n1 = stack1.top(); stack1.pop();
        struct Node* n2 = stack2.top(); stack2.pop();
        
        if (n1->data != n2->data)
            return false;
        
        if ((n1->left && n2->left && n1->left->data == n2->left->data) &&
            (n1->right && n2->right && n1->right->data == n2->right->data)) {
            stack1.push(n1->left);
            stack2.push(n2->left);
            stack1.push(n1->right);
            stack2.push(n2->right);
        } else if ((n1->left && n2->right && n1->left->data == n2->right->data) &&
                   (n1->right && n2->left && n1->right->data == n2->left->data)) {
            stack1.push(n1->left);
            stack2.push(n2->right);
            stack1.push(n1->right);
            stack2.push(n2->left);
        } else {
            return false;
        }
    }
    return stack1.empty() && stack2.empty();
}

int main() {
    struct Node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    root1->right->left = newNode(6);
    root1->left->right->left = newNode(7);
    root1->left->right->right = newNode(8);
    
    struct Node* root2 = newNode(1);
    root2->left = newNode(3);
    root2->right = newNode(2);
    root2->right->left = newNode(4);
    root2->right->right = newNode(5);
    root2->left->right = newNode(6);
    root2->right->right->left = newNode(8);
    root2->right->right->right = newNode(7);
    
    if (isIsomorphic(root1, root2))
        printf("The trees are isomorphic\n");
    else
        printf("The trees are not isomorphic\n");
    
    return 0;
}
