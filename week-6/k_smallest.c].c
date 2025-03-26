#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

int kthSmallestRecur(Node* root, int &cnt, int k) {
    if (root == nullptr) return -1;
    int left = kthSmallestRecur(root->left, cnt, k);
    if (left != -1) return left;
    cnt++;
    if (cnt == k) return root->data;
    int right = kthSmallestRecur(root->right, cnt, k);
    return right;
}

int kthSmallest(Node* root, int k) {
    int cnt = 0;
    return kthSmallestRecur(root, cnt, k);
}

int main() {
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    int k = 3;
    cout << kthSmallest(root, k) << endl;
    return 0;
}
