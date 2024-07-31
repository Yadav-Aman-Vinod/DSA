/*
Binary search is to find the position of the element within the sorted array.
First it will check the middle value; if not same then check it the value the greater or less than the middle value.
Eliminate (do no consider) the greater or less if not there.
do the same again till the number is found. (First it will check the middle value...)

Ex: Target = 7; 
(1,2,3,4,[5],6,7,8,9,10) (middle value) (Check if the target value is greater or less than the middle value)
(6,7,[8],9,10) (again take the middle value and check if target is less or more than the middle value)
(6,[7]) (target found.)

Array Must Be Sorted: Binary search only works on sorted arrays.
Time Complexity: O(log n), where n is the number of elements in the array.
Space Complexity: O(1) for the iterative approach, as it uses a constant amount of additional space.

It is great to search when you have large dataset as it eliminates half the values to find the target)
*/
#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // To prevent overflow

        // Check if the target is present at mid
        if (arr[mid] == target) {
            return mid;
        }

        // If target is greater, ignore the left half
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }

    // Target is not present in the array
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Enter the number you want to search: ";
    cin >> target;

    int result = binarySearch(arr, size, target);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array" << endl;
    }

    return 0;
}
