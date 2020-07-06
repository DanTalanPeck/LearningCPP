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

//Hamming distance between two strings 
//of equal length is the number of positions 
//at which the corresponding symbols are different.

// given array of n elements
// create new array which is a rotation of given array
// hamming distance between both the arrays is a maximum 

// create array of double size, elements repeated twice
// iterate through copy array, find hamming distance with every shift (rotation)

// return maximum hamming distance of a rotation 

int maxHamming(int arr[], int n) {
    //arr[] to brr[] two times
    int brr[9];
    for (int i = 0; i < n; i++) 
        brr[i] = arr[i];
    for (int i = 0; i < n; i++)
        brr[n + i] = arr[i];

    // hamming distance with 0 rotation
    // would be  zero
    int maxHam = 0;

    // try other rotations one by one 
    // compute hamming distance of every rotation 
    for (int i = 1; i < n; i++) {
        int currHam = 0;
        for (int j = i, k = 0; j < (i + n); j++, k++)
            if (brr[j] != arr[k])
                currHam++;
        // can never get more than n
        if (currHam == n)
            return n;

        maxHam = max(maxHam,currHam);
    }
    return maxHam;
}

int main()
{
    int arr[] = { 2, 4, 6, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << maxHamming(arr, n);
    return 0;
}