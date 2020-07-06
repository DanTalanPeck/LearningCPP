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

// STEPS:
// 1. store last element in a variable x
// 2. shift all elements one position ahead 
// 3. replace first element of array with x

void rotate(int arr[], int n) {
    int x = arr[n - 1], i;
    for (i = n - 1; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[0] = x;
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 5 }, i; // declaring i as an integer, weird
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Given array is: \n";
    for (i = 0; i < n; i++)
        std::cout << arr[i];

    rotate(arr, n);

    std::cout << "\nRotate array is: \n";
    for (i = 0; i < n; i++)
        std::cout << arr[i];

    return 0;
}