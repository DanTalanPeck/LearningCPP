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

// sorted/rotated
// Find largest element in the array, 
// which is the pivot point also 

// element just after the largest is the smallest elment 
// have largest/smallest element index, 
// use similiar meet in middle algo to find if there is a pair 
// indexes incremented/decremented in rotational manner, using modular arithmetic

// returns true if arr[0...n-1] has a pair with sum=x
bool pairInSortedRotated(int arr[], int n, int x) {
    // find pivot element 
    int i;
    for (i = 0; i < n - 1; i++)
        if (arr[i] > arr[i+1]) // decreasing 
            break;
    int l = (i + 1) % n; // l is the index of the smallest element 
    int r = i; // r is the index of largest element 

    // keep moving l or r till they meet
    while (l != r) {
        // if find a pair with sum x, return true 
        if (arr[l] + arr[r] == x)
            return true;
        // if current pair sum is less, move to higher sum 
        if (arr[l] + arr[r] < x)
            l = (l + 1) % n; // increase smallest index
        else // move to lower sum side
            r = (n + r - 1) % n; // reduce highest index
    }
    return false;
}

int main()
{
    int arr[] = { 11, 15, 6, 8, 9, 10 };
    int sum = 16;
    int n = sizeof(arr) / sizeof(arr[0]);

    if (pairInSortedRotated(arr, n, sum))
        std::cout << "Array has two elements with sum 16";
    else
        std::cout << "Array doesn't have two elements with sum 16";


    return 0;
}