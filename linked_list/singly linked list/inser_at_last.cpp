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

Node* insertAtLast(Node* head, int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        return newNode;
    }

    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }

    curr->next = newNode;
    return head;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    // create list
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

    int value;
    cout << "Enter value to insert at last: ";
    cin >> value;

    head = insertAtLast(head, value);

    cout << "After inserting at last: ";
    printList(head);

    return 0;
}
