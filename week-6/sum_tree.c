#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node(int x) {
            data = x;
            left = right = nullptr;
        }
};

int sum(Node *root) {
    if (root == NULL)
        return 0;
    return sum(root->left) + root->data + sum(root->right);
}

bool isSumTree(Node* root) {
    int ls, rs;
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        return true;
    ls = sum(root->left);
    rs = sum(root->right);
    if ((root->data == ls + rs) && isSumTree(root->left) && isSumTree(root->right))
        return true;
    return false;
}

int main() {
    Node* root = new Node(26);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);
    if (isSumTree(root))
        cout << "True";
    else
        cout << "False";
    return 0;
}