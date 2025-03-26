#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int x){
         data = x;
          left = right = nullptr;
    }
};

void verticalSumUtil(Node *node, int hd, map<int, int> &mp) {
    if (node == nullptr) return;
    verticalSumUtil(node->left, hd-1, mp);
    mp[hd] += node->data;
    verticalSumUtil(node->right, hd+1, mp);
}

vector<int> verticalSum(Node *root) {
    map <int, int> mp;
    verticalSumUtil(root, 0, mp);
    vector<int> result;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
          result.push_back(it->second);
    }
      return result;
}

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> res = verticalSum(root);
    for(int i : res) {
          cout << i << " ";
    }
    return 0;
}