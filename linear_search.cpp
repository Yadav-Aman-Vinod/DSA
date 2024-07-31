/*
In linear search, it iterate element one at a time.
Run time complexity: O(n) - Linear Time: The time required grows linearly with the input size. 
                            This is straightforward and usually manageable for moderate-sized inputs.
                            Example: Linear search in an array.
It is slow for large dataset and fast for small and mid dataset.
Do not need to be sort.
Used in DSA where random memory is not need as in linkedList.

1. Start from the First Element: Begin with the first element of the array or list.
2. Compare with the Target: Check if the current element matches the target value you are searching for.
3. Element Found: If the current element is equal to the target, the search is successful. Return the index of the element.
4. Element Not Found: If the current element is not equal to the target, move to the next element and repeat the comparison.
5. Continue Until End: Continue this process until you either find the target element or reach the end of the array.
6. Return Not Found: If the end of the array is reached without finding the target, 
return a special value (often -1 or null) to indicate that the target is not in the array.
*/

#include <iostream>
using namespace std;

int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; // Return -1 if the target is not found
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target;
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Enter the number you want to search: ";
    cin >> target;

    int result = linear_search(arr, size, target);

    if (result != -1) {
        cout << "Your number is at index: " << result << endl;
    } else {
        cout << "Number not found" << endl;
    }

    return 0;
}
