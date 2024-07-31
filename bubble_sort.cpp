/*
In bubble sort, we compare the two value, shift the smaller value to right and store the bigger value in a temp variable; 
After switch we restore the from temp to original data.
Ex: 9,2,5,2,1
First we will take 9 and 2 and compare them. 2 is smaller than 9 so we sotre 9 in a temp variable and shift 2 in place of 9.
then we place 9 from the temp into the place of 2; we get 2,9,5,2,1.
We will do the same for 9,5; we get 2,5,9,2,1. Same for 9,2; we get 2,5,2,9,1; Same for 9,1; we get 2,5,2,1,9;
We have done this one time, we will do this same process till it is sorted.
We will get 1,2,2,5,9 as the final output.

Run time is O(n^2); the larger the data, more time to process
*/

#include <iostream>
using namespace std;

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        // Last i elements are already sorted
        for (int j = 0; j < n-i-1; j++) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {9,7,4,6,0,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Original array: ";
    printArray(arr, n);
    
    bubbleSort(arr, n);
    
    cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}
