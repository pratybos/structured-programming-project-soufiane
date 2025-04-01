#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct Post {
    int id;
    string content;
    int engagement; // Likes, shares, etc.
    time_t timestamp;
    Post* next;
    Post* prev;

    Post(int id, string content, int engagement) {
        this->id = id;
        this->content = content;
        this->engagement = engagement;
        this->timestamp = time(nullptr);
        next = prev = nullptr;
    }
};

class Feed {
private:
    Post* head;
    Post* tail;
    Post* current;

public:
    Feed() : head(nullptr), tail(nullptr), current(nullptr) {}

    void addPost(int id, string content, int engagement) {
        Post* newPost = new Post(id, content, engagement);
        if (!head) {
            head = tail = current = newPost;
        } else {
            tail->next = newPost;
            newPost->prev = tail;
            tail = newPost;
        }
    }

    void removePost(int id) {
        Post* temp = head;
        while (temp) {
            if (temp->id == id) {
                if (temp->prev) temp->prev->next = temp->next;
                if (temp->next) temp->next->prev = temp->prev;
                if (temp == head) head = temp->next;
                if (temp == tail) tail = temp->prev;
                delete temp;
                return;
            }
            temp = temp->next;
        }
        cout << "Post not found!\n";
    }

    void sortPostsByTime() {
        if (!head) return;
        for (Post* i = head; i->next; i = i->next) {
            for (Post* j = i->next; j; j = j->next) {
                if (i->timestamp < j->timestamp) {
                    swap(i->id, j->id);
                    swap(i->content, j->content);
                    swap(i->engagement, j->engagement);
                    swap(i->timestamp, j->timestamp);
                }
            }
        }
    }

    void sortPostsByEngagement() {
        if (!head) return;
        for (Post* i = head; i->next; i = i->next) {
            for (Post* j = i->next; j; j = j->next) {
                if (i->engagement < j->engagement) {
                    swap(i->id, j->id);
                    swap(i->content, j->content);
                    swap(i->engagement, j->engagement);
                    swap(i->timestamp, j->timestamp);
                }
            }
        }
    }

    void nextPost() {
        if (current && current->next) {
            current = current->next;
            displayCurrentPost();
        } else {
            cout << "No newer post available.\n";
        }
    }

    void previousPost() {
        if (current && current->prev) {
            current = current->prev;
            displayCurrentPost();
        } else {
            cout << "No older post available.\n";
        }
    }

    void displayCurrentPost() {
        if (current) {
            cout << "Post ID: " << current->id << "\nContent: " << current->content
                 << "\nEngagement: " << current->engagement << "\nTime: " << ctime(&current->timestamp) << "\n";
        } else {
            cout << "No posts available.\n";
        }
    }

    void displayFeed() {
        Post* temp = head;
        while (temp) {
            cout << "[ID: " << temp->id << "] " << temp->content << " | Engagement: " << temp->engagement << " | " << ctime(&temp->timestamp);
            temp = temp->next;
        }
    }
};

int main() {
    Feed feed;
    feed.addPost(1, "Hello, world!", 10);
    feed.addPost(2, "C++ is awesome!", 20);
    feed.addPost(3, "Follow for more updates!", 15);

    cout << "\n=== Social Media Feed ===\n";
    feed.displayFeed();

    cout << "\nSorting by engagement...\n";
    feed.sortPostsByEngagement();
    feed.displayFeed();

    cout << "\nNavigating through posts:\n";
    feed.displayCurrentPost();
    feed.nextPost();
    feed.previousPost();

    cout << "\nRemoving a post...\n";
    feed.removePost(2);
    feed.displayFeed();

    return 0;
}
