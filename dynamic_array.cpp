/*
A dynamic array can grow or shrink in size during runtime, unlike a static array, whose size is fixed at compile-time. 
The dynamic array typically uses a pointer to allocate memory dynamically on the heap, allowing for flexible array resizing.

Static Array: Given a data, lets say 1,2,4,5,6,7,8,9; they have a continuous memory. To insert a data in it, say (3), 
1,2,3,4,5,6,7,8,9; we have to shift the memory address of the 4,5,6,7,8,9; to add 3 in-between. 
Same for delete the value, say (4), 1,2,3,5,6,7,8,9; we have to shift the memory address of the 5,6,7,8,9. 
(Which is possible but takes more time and has limited storage assigned to it).
If the storage value is 10, starting from 0-9, we cannot add more value to it as the storage is full.

so we use dynamic array.

where: new_list = 2 * old_list.(here 2 depend on the language we use as in python or java, etc)
Now the value is 20 of the storage, hence we can store more (ex: 1,2,3,4,5,6,7,8,9, empty, empty, empty..... so on).

disadvantage is that, it uses more storage.
*/

#include <iostream>
#include <stdexcept> // For std::out_of_range

using namespace std;

class DynamicArray {
private:
    int* arr;          // Pointer to the dynamically allocated array
    int capacity;      // Total capacity of the array
    int size;          // Current number of elements in the array

    // Private method to resize the array when it is full
    void resize() {
        capacity *= 2;                       // Double the capacity
        int* newArr = new int[capacity];     // Allocate new array with larger capacity
        for (int i = 0; i < size; i++) {     // Copy elements to new array
            newArr[i] = arr[i];
        }
        delete[] arr;                        // Free old array memory
        arr = newArr;                        // Update pointer to new array
    }

public:
    // Constructor to initialize the dynamic array
    DynamicArray(int initialCapacity = 2) {
        capacity = initialCapacity;          // Set initial capacity
        size = 0;                            // Start with an empty array
        arr = new int[capacity];             // Allocate memory for the array
    }

    // Destructor to free dynamically allocated memory
    ~DynamicArray() {
        delete[] arr;                        // Free memory when object is destroyed
    }

    // Method to add an element to the end of the array
    void add(int value) {
        if (size == capacity) {              // Resize if array is full
            resize();
        }
        arr[size++] = value;                 // Add value and increment size
    }

    // Method to get an element at a specific index
    int get(int index) const {
        if (index < 0 || index >= size) {    // Check for out-of-bounds access
            throw out_of_range("Index out of range");
        }
        return arr[index];                   // Return element at index
    }

    // Method to get the current size of the array
    int getSize() const {
        return size;
    }

    // Method to get the current capacity of the array
    int getCapacity() const {
        return capacity;
    }
};

int main() {
    DynamicArray dynamicArray;

    dynamicArray.add(10);
    dynamicArray.add(20);
    dynamicArray.add(30); // This will trigger resizing
    dynamicArray.add(40);
    dynamicArray.add(50);

    cout << "Array elements: ";
    for (int i = 0; i < dynamicArray.getSize(); i++) {
        cout << dynamicArray.get(i) << " ";
    }
    cout << endl; // Output: 10 20 30 40

    cout << "Array size: " << dynamicArray.getSize() << endl;         // Output: 4
    cout << "Array capacity: " << dynamicArray.getCapacity() << endl; // Output: 4

    return 0;
}
