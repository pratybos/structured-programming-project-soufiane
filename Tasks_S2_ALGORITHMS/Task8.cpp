#include <iostream>
#include <string>

using namespace std;

// Structure for a tree node
struct Node {
    string question;
    Node* yes;
    Node* no;
};

// Function to create a new node
Node* createNode(string question) {
    Node* newNode = new Node();
    newNode->question = question;
    newNode->yes = nullptr;
    newNode->no = nullptr;
    return newNode;
}

// Function to traverse the decision tree
void diagnose(Node* root) {
    if (!root) return;

    string response;
    cout << root->question << " (yes/no): ";
    cin >> response;

    if (response == "yes") {
        if (root->yes) {
            diagnose(root->yes);
        } else {
            cout << "Diagnosis: You may have a cold or flu." << endl;
        }
    } else if (response == "no") {
        if (root->no) {
            diagnose(root->no);
        } else {
            cout << "Diagnosis: You may have allergies or another condition." << endl;
        }
    } else {
        cout << "Invalid input, please respond with 'yes' or 'no'." << endl;
        diagnose(root);
    }
}

int main() {
    // Building a simple decision tree
    Node* root = createNode("Do you have a fever?");
    root->yes = createNode("Do you have a cough?");
    root->no = createNode("Do you have sneezing?");

    root->yes->yes = createNode("Do you have body aches?");
    root->yes->no = createNode("Do you have a sore throat?");

    root->no->yes = createNode("Diagnosis: You may have allergies.");
    root->no->no = createNode("Diagnosis: You may be healthy or have a mild issue.");

    root->yes->yes->yes = createNode("Diagnosis: You may have the flu.");
    root->yes->yes->no = createNode("Diagnosis: You may have a cold.");
    root->yes->no->yes = createNode("Diagnosis: You may have a viral infection.");
    root->yes->no->no = createNode("Diagnosis: You may have mild irritation.");

    // Start diagnosis
    diagnose(root);

    return 0;
}
