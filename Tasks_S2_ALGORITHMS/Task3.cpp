#include <iostream>
#include <string>
using namespace std;

struct File {
    string name;
    int size; // Size in KB
    string type; // File type (e.g., txt, jpg, cpp)
};

struct Folder {
    string name;
    File* file; // Each folder can store a single file (simplified for demonstration)
    Folder* left; // Left child folder
    Folder* right; // Right child folder

    Folder(string folderName) {
        name = folderName;
        file = nullptr;
        left = right = nullptr;
    }
};

// Insert a folder into the tree
Folder* insertFolder(Folder* root, string folderName) {
    if (root == nullptr) {
        return new Folder(folderName);
    }
    if (folderName < root->name) {
        root->left = insertFolder(root->left, folderName);
    } else {
        root->right = insertFolder(root->right, folderName);
    }
    return root;
}

// Add a file to a folder
void addFile(Folder* folder, string fileName, int fileSize, string fileType) {
    if (folder) {
        folder->file = new File{fileName, fileSize, fileType};
    }
}

// Search for a file by name (recursive)
File* searchFile(Folder* root, string fileName) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->file && root->file->name == fileName) {
        return root->file;
    }
    File* leftSearch = searchFile(root->left, fileName);
    if (leftSearch) return leftSearch;
    return searchFile(root->right, fileName);
}

// Display the file system
void displayFileSystem(Folder* root, int depth = 0) {
    if (root == nullptr) return;
    displayFileSystem(root->right, depth + 1);

    for (int i = 0; i < depth; i++) cout << "   ";
    cout << root->name;
    if (root->file) {
        cout << " [File: " << root->file->name << ", " << root->file->size << "KB, " << root->file->type << "]";
    }
    cout << endl;

    displayFileSystem(root->left, depth + 1);
}

int main() {
    Folder* root = nullptr;
    root = insertFolder(root, "Documents");
    root = insertFolder(root, "Downloads");
    root = insertFolder(root, "Pictures");
    root = insertFolder(root, "Music");

    addFile(root, "report.txt", 120, "txt");
    addFile(root->left, "song.mp3", 5000, "mp3");
    addFile(root->right, "photo.jpg", 2048, "jpg");

    cout << "File System Structure:\n";
    displayFileSystem(root);

    string searchName = "photo.jpg";
    File* foundFile = searchFile(root, searchName);
    if (foundFile) {
        cout << "\nFile Found: " << foundFile->name << " (" << foundFile->size << "KB, " << foundFile->type << ")\n";
    } else {
        cout << "\nFile not found.\n";
    }
    return 0;
}
