#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = nullptr;
    }
};

void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

Node* insertAtK(Node* head, int k, int value) {
    if (k <= 0) return head;

    Node* newNode = new Node(value);

    if (k == 1) {
        newNode->next = head;
        return newNode;
    }

    Node* curr = head;
    for (int i = 1; i < k - 1 && curr != nullptr; i++) {
        curr = curr->next;
    }

    if (curr == nullptr) {
        cout << "Position out of range\n";
        delete newNode;
        return head;
    }

    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    cout << "Enter elements (-1 to end): ";
    int x;
    while (cin >> x && x != -1) {
        Node* newNode = new Node(x);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Original list: ";
    printList(head);

    int k, value;
    cout << "Enter position k and value: ";
    cin >> k >> value;

    head = insertAtK(head, k, value);

    cout << "After insertion: ";
    printList(head);

    return 0;
}
