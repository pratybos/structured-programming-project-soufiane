#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to insert a new node at the end of the linked list
void insertNode(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a node with a specific value from the linked list
void deleteNode(Node*& head, int value) {
    if (head == nullptr) return;

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Value " << value << " not found in the list." << endl;
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

// Main function
int main() {
    Node* head = nullptr;
    int numElements, value, deleteValue;

    // Input the number of elements in the linked list
    cout << "Enter number of elements: ";
    cin >> numElements;

    // Input each element and insert it into the linked list
    cout << "Enter elements: ";
    for (int i = 0; i < numElements; i++) {
        cin >> value;
        insertNode(head, value);
    }

    // Display the linked list
    cout << "Linked List: ";
    printList(head);

    // Input the value to delete from the linked list
    cout << "Enter value to delete: ";
    cin >> deleteValue;

    // Delete the node with the specified value
    deleteNode(head, deleteValue);

    // Display the linked list after deletion
    cout << "After deleting " << deleteValue << ":" << endl;
    cout << "Linked List: ";
    printList(head);

    // Free memory by deleting all nodes
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
