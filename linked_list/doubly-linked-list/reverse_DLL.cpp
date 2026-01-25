#include <iostream>
using namespace std;

// Doubly Linked List Node
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

// Function to insert node at the end
void insertTail(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to reverse the doubly linked list
Node* reverseList(Node* head) {
    if (!head) return nullptr;

    Node* temp = nullptr;
    Node* curr = head;

    while (curr) {
        // Swap next and prev
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        // Move to next node (which is prev before swap)
        curr = curr->prev;
    }

    // Update head
    if (temp) head = temp->prev;
    return head;
}

int main() {
    Node* head = nullptr;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " node values:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertTail(head, val);
    }

    cout << "Original List: ";
    printList(head);

    head = reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}
