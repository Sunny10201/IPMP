#include<bits/stdc++.h>
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

void KdistanceUill(Node *root, int k, vector<int> &result) {
    if(root == NULL|| k < 0 )
        return;
    if( k == 0 ) {
        result.push_back(root->data);
        return;
    }
    KdistanceUill(root->left, k - 1, result);
    KdistanceUill(root->right, k - 1, result);
}

vector<int> Kdistance(struct Node *root, int k) {
    vector<int> result;
    KdistanceUill(root, k, result);
    return result;
}

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(8);
    vector<int> result = Kdistance(root, 2);
    for(int i : result) {
        cout << i << " ";
    }
    return 0;
}
