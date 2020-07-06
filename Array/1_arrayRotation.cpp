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

// ROTATE ONE BY ONE 
void leftRotateOne(int arr[], int n) {
    int temp = arr[0], i;
    for (i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1]; // move left by 1
    }
    arr[i] = temp;
}
// Function to left rotate arr[] of size n by d
void leftRotate(int arr[], int d, int n) {
    for (int i = 0; i < d; i++) {
        leftRotateOne(arr, n);
    }
}
//Utility, print function 
void printArray (int arr[], int n) {
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    leftRotate(arr, 2, n);
    printArray(arr, n);

    return 0;
}