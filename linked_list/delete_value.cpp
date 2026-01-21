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

// Function to delete a node by value
Node* deleteByValue(Node* head, int value) {
    if (head == nullptr) return nullptr; // empty list

    // Case 1: the value is at the head
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* curr = head;
    while (curr->next != nullptr && curr->next->data != value) {
        curr = curr->next;
    }

    if (curr->next == nullptr) {
        cout << "Value " << value << " not found in the list.\n";
        return head;
    }

    Node* temp = curr->next;
    curr->next = curr->next->next;
    delete temp;

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

    int value;
    cout << "Enter value to delete: ";
    cin >> value;

    head = deleteByValue(head, value);

    cout << "List after deleting value " << value << ": ";
    printList(head);

    return 0;
}
