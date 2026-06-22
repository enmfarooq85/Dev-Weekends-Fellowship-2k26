// return the index of 103 element using linear search
// int collogeID[4] = {101, 102, 103, 104};
// for (int i = 0; i < sizeof(collogeID) / sizeof(int); i++)
// {
//     if (collogeID[i] == 1003)
//     {
//         cout << i << endl;
//         return;
//     }
// };

// LEETCODE PROBLEM:
// https://leetcode.com/problems/running-sum-of-1d-array/

// Understand the problem first:

// hme aik array dia gia hy nums name ka. aur uno ne running sum ko is trah define kia hy ke at the current position hum log zero se le kr us current position tk ja skte hy aur elements ko plus kr skte hy. hume running sum return krna hy nums array ka.

// vector<int> nums = {1, 2, 3, 4};

// looping over the vector array nums
// vector<int> result = nums; // copy original array

// O(N)^2
// for (int i = 0; i < nums.size(); i++)
// {
//     int runningSum = 0;

//     for (int j = 0; j <= i; j++)
//     {
//         runningSum += nums[j];
//     }

//     result[i] = runningSum;
// }

// // O(N):
// for (int i = 1; i < nums.size(); i++)
// {
//     // yaha pe hum log just carrying sum ko le ke current me plus kr rahe jis se hmara solution linear me a raha hy. aur start bi one se kr rahe hy kyu ke agr one se krte tu pir us se pehle koi sum hy nahi that's why zero se start kr rahe hy.
//     nums[i] += nums[i - 1];
// }

// https://leetcode.com/problems/product-of-array-except-self/description/

// T.C => O(n)
// S.C => O(n)

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> prefix(n,1);
//         vector<int> suffix(n,1);
//         vector<int> result(n);

//         // build prefix:
//         for (int i = 1; i < n; i++){
//             prefix[i] = prefix[i - 1] * nums[i - 1];
//         }

//         // build suffix:
//         for (int j = n - 2; j >= 0; j--){
//             suffix[j] = suffix[j + 1] * nums[j + 1];
//         }

//         for (int k = 0; k < n; k++){
//             result[k] = suffix[k] * prefix[k];
//         }

//         return result;
//     }
// };

// T.C => O(n)
// S.C => O(1)

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> result(n, 1);

//         // build prefix:
//         for (int i = 1; i < n; i++){
//             result[i] = result[i - 1] * nums[i - 1];
//         }

//         int suffix = 1;
//         for (int j = n - 2; j >= 0; j--){
//             // building ith suffix going on and at same time multiplying with prefix at same time
//             suffix *= nums[j + 1];
//             result[j] *= suffix;
//         }

//         return result;
//     }
// };
