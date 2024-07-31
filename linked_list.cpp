/*
To understand linked list, first we will understand array list.

Arraylist: Given a data, lets say 1,2,4,5,6,7,8,9; they have a continuous memory. To insert a data in it, say (3), 
1,2,3,4,5,6,7,8,9; we have to shift the memory address of the 4,5,6,7,8,9; to add 3 in-between. 
Same for delete the value, say (4), 1,2,3,5,6,7,8,9; we have to shift the memory address of the 5,6,7,8,9. 
(Which is possible but takes more time, so we use linked list).

Single Linked List: Given a data 1,2,4,5,6,7,8,9; they add memory address but stored at random places and not continuous.
To insert a value (3), we dont have to shift the memory, we just assign the memory and add the data in the list.
The last value of the list donest have an address and is represented by a null stating that it is the tail (or last) value of the list.
For delete is also simple, you can delete the data with its address and it dont matter because it is not continuous.
It is tracked from Head(1) to Tail(9).
[Data | Address] -> [Data | Address]

Double Linked List: Is same as single linked list and have address in the front and back. 
(ex: (A00001) 1 (A09728), (B32122) 2 (C43636))
It is tracked from Head(1) to Tail(9) and back from Tail(9) to Head(1) as it has address both front and back.
It requires more memory than single linked list.
[Address | Data | Address] <-> [Address | Data | Address]

(Searching is complex in linked list has the memory is spread out througout the storage. Requires more storage)

(Can be used the musiic player.)

*/

#include <iostream>

using namespace std;

// Define the structure of a node in a singly linked list
struct Node {
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node

    // Constructor to initialize a node with data
    Node(int value) : data(value), next(nullptr) {}
};

// Define the linked list class
class LinkedList {
public:
    Node* head;     // Pointer to the first node in the list

    // Constructor to initialize the linked list with the head pointer set to nullptr
    LinkedList() : head(nullptr) {}

    // Method to insert a new node at the end of the list
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Method to insert a new node at a specific position
    void insertAtPosition(int value, int position) {
        Node* newNode = new Node(value);
        if (position == 0) { // Insert at the beginning
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            for (int i = 0; temp != nullptr && i < position - 1; i++) {
                temp = temp->next;
            }
            if (temp == nullptr) {
                cout << "Position out of bounds" << endl;
                delete newNode;
                return;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Method to delete a node with a specific value
    void deleteValue(int value) {
        if (head == nullptr) return;

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) return; // Value not found

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    // Method to display the list elements
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free memory when the list is destroyed
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    LinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(40);
    cout << "Initial list: ";
    list.display(); // Output: 10 20 40

    list.insertAtPosition(30, 2);
    cout << "After inserting 30 at position 2: ";
    list.display(); // Output: 10 20 30 40

    list.deleteValue(20);
    cout << "After deleting value 20: ";
    list.display(); // Output: 10 30 40

    return 0;
}

