#include <iostream>
#include <unordered_set>
#include <vector>
#include <regex>
using namespace std;

// Weak password database
unordered_set<string> weakPasswords = {
    "123456", "password", "123456789", "qwerty", "abc123", "password1", "admin", "welcome", "syfsyyf"
};

// Function to check if password is weak
bool isWeakPassword(const string& password) {
    return weakPasswords.find(password) != weakPasswords.end();
}

// Function to calculate password strength score
int passwordStrength(const string& password) {
    int score = 0;

    if (password.length() >= 8) score += 2;
    if (password.length() >= 12) score += 3;

    regex upperCase("[A-Z]");
    regex lowerCase("[a-z]");
    regex digit("[0-9]");
    regex specialChar("[!@#$%^&*()_+\\-=\\[\\]{};':\",.<>?/|]");

    if (regex_search(password, upperCase)) score += 2;
    if (regex_search(password, lowerCase)) score += 2;
    if (regex_search(password, digit)) score += 2;
    if (regex_search(password, specialChar)) score += 3;

    return score;
}

// Merge Sort to rank passwords by strength
void merge(vector<pair<string, int>>& passwords, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<pair<string, int>> leftArr(n1);
    vector<pair<string, int>> rightArr(n2);

    for (int i = 0; i < n1; i++)
        leftArr[i] = passwords[left + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = passwords[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i].second >= rightArr[j].second) {
            passwords[k] = leftArr[i];
            i++;
        } else {
            passwords[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        passwords[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        passwords[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(vector<pair<string, int>>& passwords, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(passwords, left, mid);
        mergeSort(passwords, mid + 1, right);
        merge(passwords, left, mid, right);
    }
}

// Main function
int main() {
    vector<string> testPasswords = {
        "admin", "Secure123!", "password", "HelloWorld1", "Str0ngP@ss!", "syfsyyf", "My_SuperPassword99!"
    };

    vector<pair<string, int>> passwordRanks;

    for (const string& pwd : testPasswords) {
        if (isWeakPassword(pwd)) {
            cout << "❌ Password '" << pwd << "' is weak!\n";
        } else {
            int score = passwordStrength(pwd);
            cout << "🔒 Password '" << pwd << "' has strength score: " << score << "\n";
            passwordRanks.push_back({pwd, score});
        }
    }

    // Sorting passwords based on strength using Merge Sort
    mergeSort(passwordRanks, 0, passwordRanks.size() - 1);

    cout << "\n🔹 Password Strength Ranking:\n";
    for (const auto& p : passwordRanks) {
        cout << p.first << " -> Strength: " << p.second << "\n";
    }

    return 0;
}
