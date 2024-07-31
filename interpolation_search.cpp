/*
Interpolation search is like guessing where something might be based on what you know about its position in a range. 
If the chapters are spread out evenly, you make an educated guess where to start looking, 
which saves time compared to checking every single chapter one by one.

Imagine the Book is Spread Out: Think of your book laid out on a table with chapters spaced out evenly from start to end. 
You know the chapters are in order from 1 to 100.
Estimate Where to Look: If you're looking for chapter 25, you can guess that it's roughly one-fourth of the way through the book, 
not at the very start or end.
Make a Guess: Instead of starting at the beginning and flipping through each chapter, 
you guess that chapter 25 is somewhere around the one-fourth point of the book. 
You don't flip through every single chapter, but you go directly to where you think chapter 25 should be.
Check and Adjust: When you find where you guessed, you check if it's chapter 25. 
If it’s not, you adjust your guess. If chapter 25 is actually closer to the start, you move your guess closer to the beginning; 
if it's closer to the end, you move your guess further.
Repeat: You keep adjusting your guess and checking until you find the chapter or figure out that it’s not in the book.

Advantages:
Efficiency: Faster than binary search for uniformly distributed data because it skips over large segments of the array.

Limitations:
Non-uniform Data: If the data isn’t uniformly distributed, interpolation search may perform poorly or not work at all.
Overhead: More complex than binary search, especially in handling edge cases and ensuring proper calculations.

Interpolation search is ideal when you have large datasets with values that are fairly evenly distributed and 
you want to leverage the distribution to speed up the search process.

*/

#include<iostream>
using namespace std;

int interpolation(int arr[], int size, int target){

    int left = 0;
    int right = size - 1;

    while (left <= right && target >= arr[left] && target <= arr[right]) {
        int pos = left + ((target - arr[left]) * (right - left)) / (arr[right] - arr[left]);
        if (arr[pos] == target) {
            return pos; // Found the target
        }
        if (arr[pos] < target) {
            left = pos + 1;
        } else {
            right = pos - 1;
        }
    }
    return -1; // Target not found
}

int main()
{
        int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Enter the number you want to search: ";
    cin >> target;

    int result = interpolation(arr, size, target);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array" << endl;
    }

    return 0;

}