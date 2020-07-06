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

// Array distinct numbers sorted in ascending order 
// array has been rotated clockwise k number of times 
// given array, find k

// Number of rotations is equal to index of min element 

// LINEAR SEARCH

// Return count of rotations 
int countRotations(int arr[], int n)
{
    // find index of minimum element 
    int min = arr[0], min_index;
    for (int i = 0; i < n; i++)
    {
        if (min > arr[i]) {
            min = arr[i];
            min_index = i;
        }
    }
    return min_index;
}

int main()
{
    int arr[] = { 15, 18, 2, 3, 6, 12 };
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << countRotations(arr, n);

    return 0;
}