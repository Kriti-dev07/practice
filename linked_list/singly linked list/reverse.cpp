#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

// Insert node at tail
Node* insertTail(Node* head, int data) {
    Node* newNode = new Node(data);

    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Print linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Reverse linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* nextNode = NULL;

    while (curr != NULL) {
        nextNode = curr->next; // store next
        curr->next = prev;     // reverse link
        prev = curr;           // move prev
        curr = nextNode;       // move curr
    }

    return prev; // new head
}

int main() {
    Node* head = NULL;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        head = insertTail(head, value);
    }

    cout << "\nOriginal Linked List:\n";
    printList(head);

    head = reverseList(head);

    cout << "\nReversed Linked List:\n";
    printList(head);

    return 0;
}
