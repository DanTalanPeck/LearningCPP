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

// find pivot element of sorted and rotated array
// pivot element is largest element in array
// smallest element, adjacent to it

// left pointer, pointing to smallest element 
// right pointer, pointing to largest element 

// find sum of elements pointed by both pointers 

// if sum is equal to x, then increment the count 

// if sum is less than x, to increase sum move left pointer 
// to next position by incrementing in a rotational manner

// if sum is greater than x, to decrease sume move right pointer
// to next position by decrementing it in rotational manner 

// repeat unti left pointer is NOT equal to right pointer 
// OR until left pointer is NOT equal to right pointer -1

// function returns count of number of pairs with 
// sum equal to x

int pairsInSortedRotated(int arr[], int n, int x) {

    // Find pivot element (largest element of array)
    int i;
    for (i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1])
            break;

    // l is index of smallest element 
    int l = (i + 1) % n;
    // r is index of largest element 
    int r = i;
    // variable to store count of number of pairs 
    int count = 0;

    // find sum of pair formed by arr[l] and arr[r]
    // update l, r and count accordingly
    while (l != r) {

        // if find pair with sum x,
        // then increment count,
        // move l and r to next element 
        if (arr[l] + arr[r] == x) {
            count++;

            // check l and r do NOT cross each other
            // (otherwise loop will terminate)
            if (l == (r - 1 + n) % n) {
                return count;
            }
            l = (l + 1) % n;
            r = (r - 1 + n) % n;
        }

        // if current pair sum is less
        // move to higher sum side 
        else if (arr[l] + arr[r] < x)
            l = (l + 1) % n;

        // if current pair sum is greater,
        // move to lower sum side
        else
            r = (n + r - 1) % n;
    }
    return count;
}

int main()
{
    int arr[] = { 11, 15, 6, 7, 9, 10 };
    int sum = 16;
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << pairsInSortedRotated(arr, n, sum);

    return 0;
}