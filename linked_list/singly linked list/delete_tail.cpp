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

// Function to delete the tail node
Node* deleteTail(Node* head) {
    if (head == nullptr) return nullptr; // empty list
    if (head->next == nullptr) {         // only one node
        delete head;
        return nullptr;
    }

    Node* curr = head;
    while (curr->next->next != nullptr) { // go to second last node
        curr = curr->next;
    }

    delete curr->next;   // delete last node
    curr->next = nullptr; 
    return head;
}

// Function to print the linked list
void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

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

    // Delete tail
    head = deleteTail(head);

    // Print list
    cout << "List after deleting tail: ";
    printList(head);

    return 0;
}
