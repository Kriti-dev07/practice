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

// Function to delete k-th node (1-based index)
Node* deleteKth(Node* head, int k) {
    if (head == nullptr || k <= 0) return head; // empty list or invalid k

    // Case 1: delete the first node
    if (k == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* curr = head;
    // move to (k-1)-th node (node before the one we want to delete)
    for (int i = 1; i < k - 1 && curr->next != nullptr; i++) {
        curr = curr->next;
    }

    if (curr->next == nullptr) {
        cout << "Position " << k << " does not exist in the list.\n";
        return head; // k is larger than list size
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

    int k;
    cout << "Enter position k to delete: ";
    cin >> k;

    head = deleteKth(head, k);

    cout << "List after deleting " << k << "-th element: ";
    printList(head);

    return 0;
}
