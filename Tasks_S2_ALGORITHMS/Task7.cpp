#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Job structure
struct Job {
    int id;
    int priority;
    int executionTime;

    Job(int i, int p, int e) : id(i), priority(p), executionTime(e) {}
};

// Comparator for min-heap
struct CompareJob {
    bool operator()(Job const& j1, Job const& j2) {
        if (j1.priority == j2.priority)
            return j1.executionTime > j2.executionTime;
        return j1.priority > j2.priority;
    }
};

class JobScheduler {
private:
    priority_queue<Job, vector<Job>, CompareJob> minHeap;

public:
    void addJob(int id, int priority, int executionTime) {
        minHeap.push(Job(id, priority, executionTime));
    }

    void executeJobs() {
        while (!minHeap.empty()) {
            Job job = minHeap.top();
            minHeap.pop();
            cout << "Executing Job ID: " << job.id << " | Priority: " << job.priority << " | Execution Time: " << job.executionTime << "\n";
        }
    }
};

int main() {
    JobScheduler scheduler;

    scheduler.addJob(1, 2, 10);
    scheduler.addJob(2, 1, 5);
    scheduler.addJob(3, 3, 2);
    scheduler.addJob(4, 1, 8);
    scheduler.addJob(5, 2, 4);

    cout << "Job Execution Order:\n";
    scheduler.executeJobs();

    return 0;
}
