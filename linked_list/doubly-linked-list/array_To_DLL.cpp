#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int d) {
        data = d;
        prev = nullptr;
        next = nullptr;
    }
};

Node* arrayToDLL(vector<int>& arr) {
    if (arr.size() == 0) return nullptr;

    // Create head
    Node* head = new Node(arr[0]);
    Node* curr = head;

    // Create rest of the nodes
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        curr->next = temp;
        temp->prev = curr;
        curr = temp;
    }

    return head;
}
