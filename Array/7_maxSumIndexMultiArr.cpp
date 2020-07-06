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

// given array, only rotation operation is allowed on array
// can rotate array as many times as we want 
// return maximum possible of summation of i*arr[i]

// simple solution: find all rotations one by one,
// check sum of every rotation, return maximum sum
// Time complexity: O(n^2)

// Efficient solution, O(n) times 
// Rj be a value of i*arr[i] with j rotations 
// Calculate next roation value from previous rotation
// e.g. calculate Rj from Rj-1
// can calculate initial value result as R0, then keep calculating 

// Returns max possible value of i*arr[i]
int maxSum(int arr[], int n)
{
    // Find array sum and i*arr[i] with no rotation 
    int arrSum = 0; // stores sum or arr[i]
    int currVal = 0; // stores sum of i*arr[i]

    for (int i = 0; i < n; i++)
    {
        arrSum = arrSum + arr[i];
        currVal = currVal + (i * arr[i]);
    }

    // Initialize result as 0 rotation sum 
    int maxVal = currVal;

    // Try all rotations, one by one, find max rotation sum
    for (int j = 1; j < n; j++)
    {
        currVal = currVal + arrSum - n * arr[n - j];
        if (currVal > maxVal)
            maxVal = currVal;
    }
    return maxVal;
}

int main()
{
    int arr[] = { 10, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << "\nMax sum is " << maxSum(arr, n);

    return 0;
}