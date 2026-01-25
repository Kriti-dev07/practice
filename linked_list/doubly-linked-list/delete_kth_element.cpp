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

// Insert at tail (used for user input)
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
    if (head == nullptr) return nullptr;

    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* newHead = head->next;
    newHead->prev = nullptr;
    delete head;
    return newHead;
}

// Delete tail
Node* deleteTail(Node* head) {
    if (head == nullptr) return nullptr;

    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }

    curr->prev->next = nullptr;
    delete curr;
    return head;
}

// Delete k-th node (1-indexed)
Node* deleteKth(Node* head, int k) {
    if (head == nullptr || k <= 0) return head;

    if (k == 1) {
        return deleteHead(head);
    }

    Node* curr = head;
    int count = 1;

    while (curr != nullptr && count < k) {
        curr = curr->next;
        count++;
    }

    if (curr == nullptr) {
        cout << "Invalid position! No deletion done.\n";
        return head;
    }

    if (curr->next == nullptr) {
        return deleteTail(head);
    }

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    delete curr;

    return head;
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

    cout << "Doubly Linked List: ";
    printDLL(head);

    int k;
    cout << "Enter position (1-indexed) to delete: ";
    cin >> k;

    head = deleteKth(head, k);

    cout << "After deletion: ";
    printDLL(head);

    return 0;
}
