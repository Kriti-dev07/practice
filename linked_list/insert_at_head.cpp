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

// Function to print the linked list
void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

// Function to insert a node at head
Node* insertAtHead(Node* head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    return head;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    // Step 1: Create the list
    cout << "Enter elements of the list (-1 to end): ";
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

    // Step 2: Insert a new node at head
    int value;
    cout << "Enter value to insert at head: ";
    cin >> value;
    head = insertAtHead(head, value);

    cout << "List after inserting at head: ";
    printList(head);

    return 0;
}
