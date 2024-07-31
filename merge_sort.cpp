/*
In merge sort: follows the divide and conquer paradigm. 
It works by dividing the array into two halves, recursively sorting each half, and then merging the sorted halves.
(4,6,3,6,7,9,4,2)
(4,6,3,6)(7,9,4,2)
(4,6)(3,6)(7,9)(4,2)
Now we will sort the pairs:
(4,6)(3,6)(7,9)(2,4)
Now we will sort by going backwards
(3,4,6,6)(2,4,7,9)
(2,3,4,6,6,7,9)

Merge Function: This function merges two sorted halves of the array. It uses two temporary arrays to store the elements of the 
two halves, and then merges them back into the original array.
MergeSort Function: This function recursively divides the array into two halves and calls the merge function to merge 
the sorted halves.
Main Function: This function initializes an array, calls the mergeSort function, and prints the sorted array.

The merge sort algorithm has a time complexity of 𝑂(𝑛log𝑛)
O(nlogn), which is efficient for large datasets.
It is a stable sort, meaning it preserves the relative order of equal elements.
The space complexity is 𝑂(𝑛)
O(n) due to the temporary arrays used during merging.
*/

#include <iostream>
using namespace std;

// Function to merge two halves of an array
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int* L = new int[n1];
    int* R = new int[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left...right]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Free the memory allocated for temporary arrays
    delete[] L;
    delete[] R;
}

// Function to sort an array using merge sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is: ";
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, 0, arr_size - 1);

    cout << "Sorted array is: ";
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
