#include <iostream>
#include <stack>
#include <string>

class TextEditor {
private:
    std::string text;
    std::stack<std::string> undoStack;
    std::stack<std::string> redoStack;

public:
    void type(const std::string& newText) {
        undoStack.push(text);  // Save current state for undo
        text += newText;
        while (!redoStack.empty()) redoStack.pop(); // Clear redo stack
    }

    void deleteText(size_t count) {
        if (count > text.length()) count = text.length();
        undoStack.push(text); // Save current state for undo
        text.erase(text.length() - count, count);
        while (!redoStack.empty()) redoStack.pop(); // Clear redo stack
    }

    void undo() {
        if (!undoStack.empty()) {
            redoStack.push(text); // Save current state for redo
            text = undoStack.top();
            undoStack.pop();
        } else {
            std::cout << "Nothing to undo!" << std::endl;
        }
    }

    void redo() {
        if (!redoStack.empty()) {
            undoStack.push(text); // Save current state for undo
            text = redoStack.top();
            redoStack.pop();
        } else {
            std::cout << "Nothing to redo!" << std::endl;
        }
    }

    void display() {
        std::cout << "Current Text: " << text << std::endl;
    }
};

int main() {
    TextEditor editor;
    editor.type("Hello");
    editor.display();

    editor.type(" World");
    editor.display();

    editor.deleteText(5);
    editor.display();

    editor.undo();
    editor.display();

    editor.redo();
    editor.display();

    editor.undo();
    editor.undo();
    editor.display();

    editor.redo();
    editor.display();

    return 0;
}
