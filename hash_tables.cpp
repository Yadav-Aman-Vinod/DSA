/*
A hash table (also known as a hash map) is a data structure that implements an associative array, 
a structure that can map keys to values. It uses a hash function to compute an index (or hash code) into 
an array of buckets or slots, from which the desired value can be found.

Hash Function: Converts the key into a unique index within the bounds of the array. 
The quality of the hash function determines the efficiency of the hash table.
Collisions: Occur when two keys hash to the same index. Common ways to handle collisions include:
Chaining: Each bucket points to a list of entries that share the same hash code.
Open Addressing: All elements are stored in the array itself. When a collision occurs, 
the hash function finds another open slot within the array.

Example Walkthrough:
Inserting 1, 2, 12, 14:
1 goes to bucket 1 % 5 = 1
2 goes to bucket 2 % 5 = 2
12 also goes to bucket 12 % 5 = 2 (collision with 2)
14 goes to bucket 14 % 5 = 4
The hash table handles collisions by storing colliding elements in the same bucket's list. 
This simple example demonstrates the basic principles of hash tables, 
including how they store and retrieve data based on keys and manage collisions.

Using Chaining (Separate Chaining)
Insert Key 3
Hash Calculation: 3 % 3 = 0
Action: Insert 3 into bucket 0.
Hash Table: [ [3], [], [] ]
Insert Key 6
Hash Calculation: 6 % 3 = 0
Action: Collision! Bucket 0 already has 3. Add 6 to the list in bucket 0.
Hash Table: [ [3, 6], [], [] ]
Insert Key 9
Hash Calculation: 9 % 3 = 0
Action: Collision! Bucket 0 already has 3 and 6. Add 9 to the list in bucket 0.
Hash Table: [ [3, 6, 9], [], [] ]
Using Linear Probing
Insert Key 3
Hash Calculation: 3 % 3 = 0
Action: Insert 3 into bucket 0.
Hash Table: [ [3], [], [] ]
Insert Key 6
Hash Calculation: 6 % 3 = 0
Action: Collision! Bucket 0 is occupied. Try bucket 1.
Action: Bucket 1 is empty. Insert 6 into bucket 1.
Hash Table: [ [3], [6], [] ]
Insert Key 9
Hash Calculation: 9 % 3 = 0
Action: Collision! Buckets 0 and 1 are occupied. Try bucket 2.
Action: Bucket 2 is empty. Insert 9 into bucket 2.
Hash Table: [ [3], [6], [9] ]
*/

#include <iostream>
#include <list>
#include <vector>
#include <string>

class HashTable {
private:
    std::vector<std::list<std::pair<int, std::string>>> table;
    int size;

    // Hash function
    int hashFunction(int key) {
        return key % size;
    }

public:
    // Constructor to initialize hash table with a given size
    HashTable(int size) {
        this->size = size;
        table.resize(size);
    }

    // Function to insert a key-value pair
    void insert(int key, const std::string& value) {
        int index = hashFunction(key);
        table[index].emplace_back(key, value);
    }

    // Function to search for a value by key
    std::string search(int key) {
        int index = hashFunction(key);
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        return "Not Found";
    }

    // Function to remove a key-value pair
    void remove(int key) {
        int index = hashFunction(key);
        auto& cell = table[index];
        for (auto it = cell.begin(); it != cell.end(); ++it) {
            if (it->first == key) {
                cell.erase(it);
                return;
            }
        }
    }

    // Function to display the hash table
    void display() {
        for (int i = 0; i < size; ++i) {
            std::cout << "Bucket " << i << ": ";
            for (const auto& pair : table[i]) {
                std::cout << "[" << pair.first << ": " << pair.second << "] ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    HashTable hashTable(10); // Create a hash table of size 10

    hashTable.insert(1, "Value1");
    hashTable.insert(2, "Value2");
    hashTable.insert(42, "Value42"); // Collision with key 2
    hashTable.insert(4, "Value4");

    hashTable.display();

    std::cout << "Searching for key 2: " << hashTable.search(2) << std::endl;
    std::cout << "Searching for key 42: " << hashTable.search(42) << std::endl;
    std::cout << "Searching for key 3: " << hashTable.search(3) << std::endl;

    hashTable.remove(2);
    hashTable.display();

    return 0;
}
