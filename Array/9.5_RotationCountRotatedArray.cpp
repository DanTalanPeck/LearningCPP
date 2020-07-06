#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <regex>
#include <iterator>
#include <unordered_set>
#include <cmath>
#include <queue>

using namespace std;

// BINARY SEARCH
// min element, only element whose previous is greater than it
// no previous, no rotation (first element is min)
// check condition for mid element, compare with mid-1 AND mid+1
// If min element is NOT at middle (neither mid or mid+1)
// then min lies in either left half or right half 
// mid element is smaller than last element, min element lies in left half
// else min lies in right half 

int countRotations(int arr[], int low, int high)
{
    // array is NOT rotated at all
    if (high < low)
        return 0;
    // only one element left
    if (high == low)
        return low;

    // find mid
    int mid = (low + high) / 2;

    // check if mid+1 element is min
    if (mid < high && arr[mid + 1] < arr[mid])
        return (mid + 1);
    
    // check if mid itself is minimum element 
    if (mid > low && arr[mid] < arr[mid - 1])
        return mid;

    // Decide, need to go to left or right half 
    if (arr[high] > arr[mid])
        return countRotations(arr, low, mid - 1);
    
    return countRotations(arr, mid + 1, high);
}

int main()
{
    int arr[] = { 15, 18, 2, 3, 6, 12 };
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << countRotations(arr, n);

    return 0;
}