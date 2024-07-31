/*
First we take the 1 index in a dataset: (2,5,1,7,3); here in this case is 5 and store it in temp variable;
then we compare it with the zero index that is 2 which is smaller; then we keep the element as it is. Now we take 1 in the 
temp variable and compare it with 5 and 2 which is smaller. we shift 5 and two to make (1,2,5,7,3).
Now we will take 7 in a temp variable and compare it will 1,2,5 which are smaller, so no changes. now we take 3 in the 
temp variable and compare it with 1,2,5,7; Here 3 is smaller than 5 and 7 so we shift 5 and 7; to make 1,2,3,5,7.

*/

#include <iostream>
using namespace std;

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        
        // Move elements of arr[0..i-1] that are greater than temp
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    printArray(arr, n);
    
    insertionSort(arr, n);
    
    cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}
