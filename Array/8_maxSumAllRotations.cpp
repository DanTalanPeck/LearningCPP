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

// Efficient solution 
int maxSum(int arr[], int n)
{
    int cum_sum = 0;
    for (int i = 0; i < n; i++)
        cum_sum += arr[i];

    // computer sum of i*arr[i]
    // for initial configuration 
    int curr_val = 0;
    for (int i = 0; i < n; i++)
        curr_val += i * arr[i];

    // Initialize result 
    int res = curr_val;

    // compute values for other iterations 
    for (int i = 1; i < n; i++) {
        // compute next value using previous value, O(1) time
        int next_val = curr_val - (cum_sum - arr[i - 1]) + arr[i-1] * (n - 1);

        // update current value 
        curr_val = next_val;

        // update result if required
        res = max(res, next_val);
    }
    return res;
}

int main()
{
    int arr[] = { 8, 3, 1, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << maxSum(arr, n) << '\n';

    return 0;
}