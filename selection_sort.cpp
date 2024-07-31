/*
In selection sort, given an array 3,2,5,1,9; here we take two integers value as minimum and temp.
Here we take the minimum value, in this case 3 in the minimum integer and then go for the next value in this case 2.
Now 2 is the smaller one, we change the 3 with the 2 in the minimum integer. now we take 5, which is larger than 2, so ignore.
now we take 1 which is smaller than 2, so change 2 into 1. Now we take 9 which is larger than 1 so ignore,

Now we place 1 in the place of 3; Take the 3 in the temp variable and place it in place of 1 (1,2,5,3,9);
The place of 1 is fixed. now we goto 2 and do all the process same again till it the end value.
*/

#include <iostream>
using namespace std;

// Function to perform selection sort

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        // Find the minimum element in the unsorted part
        int minIdx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        // Swap the found minimum element with the first element
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Original array: ";
    printArray(arr, n);
    
    selectionSort(arr, n);
    
    cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}
