/*
Queue is (FIFO) first in first out.
Meaning: 1,2,3,4 (is in line where 1 is the head and 4 is the tail)
To remove (pop) the head we use dequeue(): 2,3,4 (where now 2 is the head and 4 is the tail)
To add (push) value, we use enqueue(): 2,3,4,5 (where 2 is the head and now 5 is the tail)
Basically it is to queue in a line (to wait until the first one is done (first come first serve) )
To see the first value we use (front).


3 Common Uses of Queues:

Task Scheduling:
Operating systems use queues to manage processes and threads.
Print jobs are often queued before being processed.
Network requests and responses can be queued for efficient handling.

Buffering:
Data can be temporarily stored in a queue before processing.
Input/output operations can use queues to handle data flow.
Queues can smooth out data rate variations.

Breadth-First Search (BFS):
Graph algorithms like BFS use queues to explore neighboring nodes level by level.
This is useful for finding shortest paths or solving puzzles.
Uses of Priority Queues
Priority queues prioritize elements based on their values, ensuring high-priority items are processed first.

*/
#include<iostream>
#include<queue>
using namespace std;

int main() {
    queue<string> myqueue;
string name;
int choice;

while(true){
cout << "\nQueue Operations Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Size\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a name to push: ";
                cin >> name;
                myqueue.push(name);
                cout << name << " pushed onto the queue.\n";
                break;
            case 2:
                if (!myqueue.empty()) {
                    cout << myqueue.front() << " popped from the queue.\n";
                    myqueue.pop();
                } else {
                    cout << "Queue is empty. Cannot pop.\n";
                }
                break;
            case 3:
                if (!myqueue.empty()) {
                    cout << "Top element is: " << myqueue.front() << endl;
                } else {
                    cout << "Queue is empty.\n";
                }
                break;
            case 4:
                cout << "Queue size is: " << myqueue.size() << endl;
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}