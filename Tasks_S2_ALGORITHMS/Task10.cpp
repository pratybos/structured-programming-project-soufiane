#include <iostream>
#include <queue>
#include <string>

// Define a structure for messages
struct Message {
    int priority; // Lower value means higher priority
    std::string content;

    // Constructor
    Message(int p, std::string c) : priority(p), content(c) {}

    // Overload operator for priority queue comparison
    bool operator<(const Message& other) const {
        return priority > other.priority; // Min-heap behavior
    }
};

int main() {
    std::priority_queue<Message> messageQueue;

    // Enqueue messages with different priorities
    messageQueue.push(Message(2, "Regular message"));
    messageQueue.push(Message(1, "Urgent message"));
    messageQueue.push(Message(3, "Low priority message"));

    // Dequeue and process messages
    std::cout << "Processing messages in order of priority:\n";
    while (!messageQueue.empty()) {
        Message msg = messageQueue.top();
        std::cout << "[Priority " << msg.priority << "] " << msg.content << std::endl;
        messageQueue.pop();
    }

    return 0;
}
