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

// left rotate an array k times
void leftRotate(int arr[], int n, int k) {

    // print array after k rotations 
    for (int i = k; i < k + n; i++)
        std::cout << arr[i % n] << " ";
}

int main()
{
    int arr[] = { 1, 3, 5, 7, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 2;
    leftRotate(arr, n, k);
    std::cout << '\n';

    k = 3;
    leftRotate(arr, n, k);
    std::cout << '\n';
    k = 4;
    leftRotate(arr, n, k);
    std::cout << '\n';


    /*
    //BEAUTIFUL 
    int arr[] = { 1,2,3,4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << arr[4 % n] << '\n';
    std::cout << arr[5 % n] << '\n';
    std::cout << arr[6 % n] << '\n';
    std::cout << arr[7 % n] << '\n';
    */
    return 0;
}