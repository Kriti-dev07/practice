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

// Convert array to DLL
Node* arrayToDLL(vector<int>& arr) {
    if (arr.size() == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* curr = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        curr->next = temp;
        temp->prev = curr;
        curr = temp;
    }

    return head;
}

// Delete head of DLL
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

// Delete tail of DLL
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

// Print DLL
void printDLL(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};

    Node* head = arrayToDLL(arr);
    cout << "Original DLL: ";
    printDLL(head);

    head = deleteHead(head);
    cout << "After deleting head: ";
    printDLL(head);

    head = deleteTail(head);
    cout << "After deleting tail: ";
    printDLL(head);

    return 0;
}
