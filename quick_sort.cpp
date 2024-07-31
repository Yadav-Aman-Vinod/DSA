/*
Quick Sort is a highly efficient sorting algorithm that uses the divide and conquer strategy. 
It selects a "pivot" element from the array and partitions the other elements into two sub-arrays: 
elements less than the pivot and elements greater than the pivot. The sub-arrays are then sorted recursively.
Ex: (4,3,8,2,5) the last element will be pivot which is 5. We will take two index i and j. [i],[4(which will our j),3,8,2,5]
If the j is smaller than pivot(5) we will swap the number(by swapping means stroing the num in temp then change) 

Initial Array: [4, 3, 8, 2, 5] with pivot = 5
Partitioning Steps:
Start with i = -1 (before the first element) and j = 0.
Compare arr[j] (which is 4) with the pivot 5:
Since 4 < 5, increment i to 0 and swap arr[i] with arr[j] (though they are the same in this case).
Move to the next j:
Compare arr[j] (which is 3) with 5:
Since 3 < 5, increment i to 1 and swap arr[i] with arr[j].
Continue with j = 2:
Compare arr[j] (which is 8) with 5:
Since 8 > 5, do nothing.
Continue with j = 3:
Compare arr[j] (which is 2) with 5:
Since 2 < 5, increment i to 2 and swap arr[i] with arr[j].
Final Swap: Swap the pivot 5 with the element at i + 1 (8 in this case).
Partitioned Array: [4, 3, 2, 5, 8]
Now, 5 is in its correct sorted position, and the process is repeated recursively for the sub-arrays [4, 3, 2] and [8].

*/

#include <iostream>
using namespace std;

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function that returns the index of the pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivot element
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[p] is now at the right place
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
