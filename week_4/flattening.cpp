#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node *next, *bottom;

    Node(int newdata) {
        data = newdata;
        next = bottom = nullptr;
    }
};
Node* flatten(Node* root) {
    vector<int> values;
    while (root != nullptr) {
        values.push_back(root->data);
        Node* temp = root->bottom;
        while (temp != nullptr) {
            values.push_back(temp->data);
            temp = temp->bottom;
        }
        root = root->next;
    }
    sort(values.begin(), values.end());
    Node* tail = nullptr;
    Node* head = nullptr;
    for (int i = 0; i < values.size(); i++) {
        Node* newNode = new Node(values[i]);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            tail->bottom = newNode;
        }
        tail = newNode;
    }
    return head;
}
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->bottom;
    }
    cout << endl;
}
int main() {
    Node* head = new Node(1);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(9);
    head->bottom->bottom->bottom = new Node(30);
    head->next = new Node(10);
    head->next->bottom = new Node(40);
    head->next->next = new Node(19);
    head->next->next->bottom = new Node(25);
    head->next->next->bottom->bottom = new Node(50);
    head->next->next->next = new Node(60);
    head = flatten(head);
    printList(head);
    return 0;
}
