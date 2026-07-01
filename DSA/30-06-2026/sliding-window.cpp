#include "iostream"
#include "vector"
#include <climits>
using namespace std;

// One approach will be to solve with brute force technique, it will give you O(n*k) complexity.
int findMaxSum(vector<int> &arr1, int k1)
{
    int n = arr1.size();
    int maxSum = INT_MIN;

    for (int i = 0; i <= n - k1; i++)
    {
        int currentSum = 0;

        // Calculate sum of current subarray of size k
        for (int j = 0; j < k1; j++)
            currentSum += arr1[i + j];

        // Update result if required
        maxSum = max(currentSum, maxSum);
    }

    return maxSum;
};

// using sliding window, it will give us O(n) time complexity.
int findMaxSumUsingSlidingWindow(vector<int> &arr1, int k)
{
    int n = arr1.size();

    // n must be greater
    if (n <= k)
    {
        cout << "Invalid";
        return -1;
    }

    // Compute sum of first window of size k
    int maxSum = 0;
    for (int i = 0; i < k; i++)
        maxSum += arr1[i];

    // Compute sums of remaining windows by removing first element of previous window and adding last element of current window.
    int windowSum = maxSum;
    for (int i = k; i < n; i++)
    {
        windowSum += arr1[i] - arr1[i - k];
        
    }

    return maxSum;
};

int main()
{

    // Sliding Window:

    // Sliding Window Technique is a method used to solve problems that involve subarray or substring or window.

    // Instead of repeatedly iterating over the same elements, the sliding window maintains a range (or “window”) that moves step-by-step through the data, updating results incrementally.
    // The main idea is to use the results of previous window to do computations for the next window.
    // Commonly used for problems like finding subarrays with a specific sum, finding the longest substring with unique characters, or solving problems that require a fixed-size window to process elements efficiently.

    // In order to understand it better, we can move on with an example:

    // consider you have an array:
    vector<int> arr = {2, 6, 1, 2, 3, 9, 10};
    // you have to find maxmimum sum of the exactly three elements:
    int k = 3;

    cout << "Using Brute Force: " << findMaxSum(arr, k) << endl;
    cout << "Using Sliding Window: " << findMaxSumUsingSlidingWindow(arr, k) << endl;

    // There are basically two types of sliding window:

    // 1. Fixed Size Sliding Window:
    // 2. Variable Size Sliding Window:

    // How to Identify Sliding Window Problems?

    // These problems generally require Finding Maximum/Minimum Subarray, Substrings which satisfy some specific condition.
    // The size of the subarray or substring ‘k’ will be given in some of the problems.
    // These problems can easily be solved in O(n^2) time complexity using nested loops, using sliding window we can solve these in O(n) Time Complexity.
    // Required Time Complexity: O(n) or O(n log n)
    // Constraints: n <= 10^6

    return 0;
}