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

// Insert at tail (for user input)
Node* insertAtTail(Node* head, int data) {
    Node* newNode = new Node(data);

    if (head == nullptr) {
        return newNode;
    }

    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }

    curr->next = newNode;
    newNode->prev = curr;

    return head;
}

// Delete head
Node* deleteHead(Node* head) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete.\n";
        return nullptr;
    }

    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* newHead = head->next;
    newHead->prev = nullptr;
    delete head;

    return newHead;
}

// Print DLL
void printDLL(Node* head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    Node* head = nullptr;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        head = insertAtTail(head, x);
    }

    cout << "Original Doubly Linked List: ";
    printDLL(head);

    // Delete head
    head = deleteHead(head);

    cout << "After deleting head: ";
    printDLL(head);

    return 0;
}
