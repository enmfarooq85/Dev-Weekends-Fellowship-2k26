// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

// T.C => O(n * 2^n)
// S.C => O(n)

// class Solution {
// public:
//     bool isDuplicate(string& s1, string& s2) {
//         int arr[26] = {0};

//         for (char& ch : s1) {
//             if (arr[ch - 'a'] > 0)
//                 return true;
//             arr[ch - 'a']++;
//         }

//         for (char& ch : s2) {
//             if (arr[ch - 'a'] > 0)
//                 return true;
//         }

//         return false;
//     }

//     unordered_map<string, int> mp;
//     int solve(int idx, vector<string>& arr, string temp, int n) {
//         if (idx >= n)
//             return temp.length();

//         if (mp.find(temp) != mp.end())
//             return mp[temp];

//         int include = 0;
//         int exclude = 0;
//         if (isDuplicate(arr[idx], temp)) {
//             exclude = solve(idx + 1, arr, temp, n);
//         } else {
//             exclude = solve(idx + 1, arr, temp, n);
//             include = solve(idx + 1, arr, temp + arr[idx], n);
//         }

//         return mp[temp] = max(include, exclude);
//     }

//     int maxLength(vector<string>& arr) {
//         string temp = "";
//         mp.clear();
//         int n = arr.size();

//         return solve(0, arr, temp, n);
//     }
// };

// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

// T.C => O(n * n)
// S.C => O(n * n) 

// class Solution {
// public:
//     int dp[501][501];
//     int solve(int i, int j, string& s) {

//         if (i >= j)
//             return 0;

//         if (dp[i][j] != -1)
//             return dp[i][j];

//         if (s[i] == s[j])
//             return dp[i][j] = solve(i + 1, j - 1, s);
//         else
//             return dp[i][j] = 1 + min(solve(i, j - 1, s), solve(i + 1, j, s));
//     }

//     int minInsertions(string s) {
//         int n = s.length();

//         memset(dp, -1, sizeof(dp));

//         return solve(0, n - 1, s);
//     }
// };

// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule

// T.C => O(n^2 * d)
// S.C => O(1)

// class Solution {
// public:
//     int dp[301][11];
//     int solve(vector<int>& jobDifficulty, int n, int idx, int d) {
//         if (d == 1) {
//             int max = jobDifficulty[idx];

//             for (int i = idx + 1; i < jobDifficulty.size(); i++) {
//                 if (jobDifficulty[i] > max) {
//                     max = jobDifficulty[i];
//                 }
//             }

//             return max;
//         };

//         if (dp[idx][d] != -1)
//             return dp[idx][d];

//         int Max = INT_MIN;
//         int result = INT_MAX;

//         for (int i = idx; i <= n - d; i++) {
//             Max = max(Max, jobDifficulty[i]);
//             result = min(result, Max + solve(jobDifficulty, n, i + 1, d - 1));
//         };

//         return dp[idx][d] = result;
//     }

//     int minDifficulty(vector<int>& jobDifficulty, int d) {
//         int n = jobDifficulty.size();

//         if (n < d)
//             return -1;

//         memset(dp, -1, sizeof(dp));

//         return solve(jobDifficulty, n, 0, d);
//     }
// };

// https://leetcode.com/problems/maximum-profit-in-job-scheduling

// T.C => O(nlogn)
// S.C => O(n)

// class Solution {
// public:
//     int cache[50001];
//     int n;
//     int getNextIndex(vector<vector<int>>& array, int l, int currentJobEnd) {
//         int r = n - 1;

//         int result = n + 1;

//         while (l <= r) {
//             int mid = l + (r - l) / 2;

//             if (array[mid][0] >= currentJobEnd) {
//                 result = mid;
//                 r = mid - 1;
//             } else {
//                 l = mid + 1;
//             }
//         }

//         return result;
//     }

//     int solve(vector<vector<int>>& array, int i) {
//         if (i >= n)
//             return 0;

//         if (cache[i] != -1)
//             return cache[i];

//         int next = getNextIndex(array, i + 1, array[i][1]);

//         int taken = array[i][2] + solve(array, next);
//         int notTaken = solve(array, i + 1);

//         return cache[i] = max(taken, notTaken);
//     }

//     int jobScheduling(vector<int>& startTime, vector<int>& endTime,
//                       vector<int>& profit) {
//         n = startTime.size();
//         vector<vector<int>> array(n, vector<int>(3, 0));

//         for (int i = 0; i < n; i++) {
//             array[i][0] = startTime[i];
//             array[i][1] = endTime[i];
//             array[i][2] = profit[i];
//         }

//         sort(begin(array), end(array));

//         memset(cache, -1, sizeof(cache));
//         return solve(array, 0);
//     }
// };

// https://leetcode.com/problems/arithmetic-slices-ii-subsequence/

// T.C => O(n^2)
// S.C => O(n^2)

// class Solution {
// public:
//     int numberOfArithmeticSlices(vector<int>& nums) {
//         int n = nums.size();
//         int result = 0;
//         unordered_map<long, int> mp[n];

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < i; j++) {
//                 auto diff = (long)nums[i] - nums[j];
//                 auto it = mp[j].find(diff);

//                 int count_at_j = it == end(mp[j]) ? 0 : it->second;

//                 mp[i][diff] += count_at_j + 1;
//                 result += count_at_j;
//             }
//         }
//         return result;
//     }
// };

// https://leetcode.com/problems/longest-common-subsequence/

// T.C => O(n*m)
// S.C => O(n)

// class Solution {
// public:
//     int t[1001][1001];
//     int LCS(string& s1, string& s2, int m, int n) {
//         if(m == 0 || n == 0)
//             return t[m][n] = 0;
        
//         if(t[m][n] != -1)
//             return t[m][n];
        
//         if(s1[m-1] == s2[n-1])
//             return t[m][n] = 1 + LCS(s1, s2, m-1, n-1);
        
//         return t[m][n] = max(LCS(s1, s2, m, n-1), LCS(s1, s2, m-1, n));
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         int m = text1.length();
//         int n = text2.length();
        
//         memset(t, -1, sizeof(t));
        
//         return LCS(text1, text2, m, n);
//     }
// };
