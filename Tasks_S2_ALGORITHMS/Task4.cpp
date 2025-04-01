#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Employee {
    int id;
    string name;

    // ✅ Default Constructor (Fix for compilation issue)
    Employee() : id(0), name("") {}

    // ✅ Parameterized Constructor
    Employee(int i, string n) : id(i), name(n) {}
};

// Define B-tree Node structure (simplified for indexing)
class BTreeNode {
public:
    vector<Employee> employees;
    vector<BTreeNode*> children;
    bool isLeaf;

    BTreeNode(bool leaf) : isLeaf(leaf) {}
};

class BTree {
public:
    BTreeNode* root;
    int degree;

    BTree(int t) : degree(t) {
        root = new BTreeNode(true);
    }

    // Function to insert an Employee into the B-tree
    void insert(Employee emp) {
        // Simplified insert (Full implementation requires splitting nodes)
        root->employees.push_back(emp);
    }

    // Function to search for an Employee by ID
    Employee* search(int id) {
        for (auto& emp : root->employees) {
            if (emp.id == id)
                return &emp;
        }
        return nullptr;
    }
};

int main() {
    BTree tree(3);

    // Insert some employees
    tree.insert(Employee(1, "ASH"));
    tree.insert(Employee(2, "SOUFIANE"));
    tree.insert(Employee(3, "MOHO"));

    // Search for an employee
    int searchID = 2;
    Employee* result = tree.search(searchID);
    if (result) {
        cout << "Employee found: " << result->id << ", " << result->name << endl;
    } else {
        cout << "Employee not found" << endl;
    }

    return 0;
}
