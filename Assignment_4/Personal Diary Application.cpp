#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#include <vector>

using namespace std;

// Function to get the current date as a string
string getCurrentDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    stringstream date;
    date << 1900 + ltm->tm_year << "-"
         << 1 + ltm->tm_mon << "-"
         << ltm->tm_mday;
    return date.str();
}

// Function to add a new diary entry
void addEntry() {
    ofstream file("diary.txt", ios::app); // Open file in append mode
    if (!file) {
        cerr << "Error opening file!" << endl;
        return;
    }

    string content;
    cout << "Enter your diary entry: ";
    cin.ignore(); // Ignore any leftover newlines
    getline(cin, content);

    string date = getCurrentDate();
    file << date << "\n" << content << "\n---\n"; // Each entry ends with '---' for separation
    file.close();
    cout << "Entry added successfully.\n";
}

// Function to view all entries
void viewEntries() {
    ifstream file("diary.txt");
    if (!file) {
        cerr << "Error opening file or no entries found!" << endl;
        return;
    }

    string line;
    cout << "DIARY ENTRIES:\n";
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

// Function to delete entries by date
void deleteEntry() {
    string targetDate;
    cout << "Enter the date of the entry you want to delete (YYYY-MM-DD): ";
    cin >> targetDate;

    ifstream file("diary.txt");
    if (!file) {
        cerr << "Error opening file or no entries found!" << endl;
        return;
    }

    ofstream temp("temp.txt");
    string line;
    bool isEntryToDelete = false;
    bool entryDeleted = false;

    while (getline(file, line)) {
        if (line == targetDate) {
            isEntryToDelete = true; // Mark this entry to be deleted
            entryDeleted = true;
        } else if (line == "---") {
            if (isEntryToDelete) {
                isEntryToDelete = false; // End deletion of current entry
            } else {
                temp << "---\n"; // Write the separator for the kept entry
            }
        } else if (!isEntryToDelete) {
            temp << line << "\n"; // Copy line to temp if not deleting
        }
    }

    file.close();
    temp.close();
    remove("diary.txt");
    rename("temp.txt", "diary.txt");

    if (entryDeleted)
        cout << "Entry deleted successfully.\n";
    else
        cout << "No entry found for the given date.\n";
}

// Main menu
int main() {
    int choice;
    do {
        cout << "\nPERSONAL DIARY APPLICATION\n";
        cout << "1. Add New Entry\n";
        cout << "2. View Past Entries\n";
        cout << "3. Delete Entry by Date\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                deleteEntry();
                break;
            case 4:
                cout << "Exiting the application.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
