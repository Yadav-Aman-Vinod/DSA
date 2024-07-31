/*
Priority Queue is a FIFO (first in first out) with the elements with hightest priporty first and the less priority last.
Ex: input value is 1,3,7,2,3 or A,H,I,B; it will become 7,3,3,2,1 or I,H,B,A.
(The value with the highest will be first and the value with the lowest will be last).
(Then the same as Queue for input and outout)

3 Common Uses of Priority Queues:

Task Scheduling:
Prioritizing tasks based on importance or deadlines.
Real-time systems often use priority queues to handle time-critical events.

Event-Driven Simulations:
Simulating events with different priorities, such as in network simulations or game engines.

Dijkstra's Algorithm:
Finding the shortest path between nodes in a graph by prioritizing nodes based on their tentative distance.
*/

/*
(Basic function)

#include <iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int> pq;
       // Insert elements
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);

    cout << "Top element: " << pq.top() << std::endl; // Output: 30

    // Remove the top element
    pq.pop();
    std::cout << "Top element after pop: " << pq.top() << std::endl; // Output: 20

    cout << "Size of priority queue: " << pq.size() << std::endl; // Output: 3

}

*/
#include<iostream>
#include<queue>
using namespace std;

int main() {
    priority_queue<int> pq;
int number;
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
                cout << "Enter a number to push: ";
                cin >> number;
                pq.push(number);
                cout << number << " pushed onto the queue.\n";
                break;
            case 2:
                if (!pq.empty()) {
                    cout << pq.top() << " popped from the queue.\n";
                    pq.pop();
                } else {
                    cout << "Queue is empty. Cannot pop.\n";
                }
                break;
            case 3:
                if (!pq.empty()) {
                    cout << "Top element is: " << pq.top() << endl;
                } else {
                    cout << "Queue is empty.\n";
                }
                break;
            case 4:
                cout << "Queue size is: " << pq.size() << endl;
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