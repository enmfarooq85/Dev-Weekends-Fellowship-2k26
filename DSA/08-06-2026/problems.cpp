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

// https://leetcode.com/problems/top-k-frequent-elements/description/

// T.C => O(n²)
// S.C => O(m)

// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> mp = {};
//         vector<int> ans;

//         for (auto i : nums) {
//             mp[i]++;
//         }

//         while (k > 0) {
//             int mxFreq = -1;
//             int mxNum = -1;

//             for (auto j : mp) {
//                 if (j.second > mxFreq) {
//                     mxFreq = j.second;
//                     mxNum = j.first;
//                 }
//             }
//             cout << "key: " << mxNum << endl;
//             cout << "value: " << mxFreq << endl;
//             mp[mxNum] = -1;
//             ans.push_back(mxNum);

//             k--;
//         }

//         return ans;
//     }
// };

// T.C => O(n + m log m)
// S.C => O(m)

// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> freq;

//         for (int num : nums) {
//             freq[num]++;
//         }

//         vector<pair<int, int>> v;

//         for (auto it : freq) {
//             v.push_back({it.second, it.first});
//         }

//         sort(v.rbegin(), v.rend());

//         vector<int> ans;
//         for (int i = 0; i < k; i++) {
//             ans.push_back(v[i].second);
//         }

//         return ans;
//     }
// };

// // T.C => O(n)
// S.C => O(n)

// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> freq;

//         for (int num : nums) {
//             freq[num]++;
//         }

//         int n = nums.size();
//         vector<vector<int>> bucket(n + 1);

//         for (auto it : freq) {
//             int number = it.first;
//             int frequency = it.second;
//             bucket[frequency].push_back(number);
//         }

//         vector<int> ans;

//         for (int i = n; i > 0 && ans.size() < k; i--) {
//             for (int num : bucket[i]) {
//                 ans.push_back(num);
//                 if (ans.size() == k) {
//                     return ans;
//                 }
//             }
//         }

//         return ans;
//     }
// };
