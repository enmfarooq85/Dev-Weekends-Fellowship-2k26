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

// Note:- This is same approach as above, but with more clearity.

// class Solution {
// public:
//     int numberOfArithmeticSlices(vector<int>& nums) {
//         int n = nums.size();
//         int totalArithmeticSubsequences = 0;

//         // dp[i][diff] = number of arithmetic subsequences
//         // ending at index i with common difference = diff
//         unordered_map<long long, int> dp[n];

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < i; j++) {
//                 long long difference = (long long)nums[i] - nums[j];

//                 // Number of subsequences ending at j
//                 // with the same difference
//                 int existingSequences = 0;

//                 if (dp[j].find(difference) != dp[j].end()) {
//                     existingSequences = dp[j][difference];
//                 }

//                 // +1 represents the new pair
//                 // (nums[j], nums[i])
//                 dp[i][difference] += existingSequences + 1;

//                 // Only extend existing subsequences (length >= 2)
//                 // to form valid arithmetic subsequences (length >= 3)
//                 totalArithmeticSubsequences += existingSequences;
//             }
//         }

//         return totalArithmeticSubsequences;
//     }
// };

// https://leetcode.com/problems/longest-common-subsequence/

// T.C => O(2^n * 2^m) => O(2^m+n)
// S.C => O(m)

// class Solution {
// public:
//     int solve(int i, int j, string text1, string text2) {
//         if (i >= text1.length() || j >= text2.length()) {
//             return 0;
//         }

//         if (text1[i] == text2[j]) {
//             return 1 + solve(i + 1, j + 1, text1, text2);
//         }

//         int excludeFromText1 = solve(i + 1, j, text1, text2);
//         int excludeFromText2 = solve(i, j + 1, text1, text2);

//         return max(excludeFromText1, excludeFromText2);
//     };

//     int longestCommonSubsequence(string text1, string text2) {
//         return solve(0, 0, text1, text2);
//     };
// };

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

// class Solution {
// public:
//     int cache[1001][1001];
//     int solve(int i, int j, string& text1, string& text2) {
//         if (i >= text1.length() || j >= text2.length()) {
//             return 0;
//         }

//         if (cache[i][j] != -1) {
//             return cache[i][j];
//         }

//         if (text1[i] == text2[j]) {
//             return cache[i][j] = 1 + solve(i + 1, j + 1, text1, text2);
//         }

//         int excludeFromText1 = solve(i + 1, j, text1, text2);
//         int excludeFromText2 = solve(i, j + 1, text1, text2);

//         return cache[i][j] = max(excludeFromText1, excludeFromText2);
//     };

//     int longestCommonSubsequence(string text1, string text2) {

//         memset(cache, -1, sizeof(cache));
//         return solve(0, 0, text1, text2);
//     };
// };

// T.C => O(m*n)
// S.C => O(m*n)

// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int m = text1.length();
//         int n = text2.length();

//         vector<vector<int>> t(m + 1, vector<int>(n + 1));

//         for (int i = 0; i < m + 1; i++) {
//             for (int j = 0; j < n + 1; j++) {
//                 if (i == 0 || j == 0)
//                     t[i][j] = 0;
//                 else if (text1[i - 1] == text2[j - 1])
//                     t[i][j] = 1 + t[i - 1][j - 1];
//                 else
//                     t[i][j] = max(t[i][j - 1], t[i - 1][j]);
//             }
//         }

//         return t[m][n];
//     }
// };

// https://leetcode.com/problems/ugly-number/description/

// T.C => O(n * log n)
// S.C => O(1)

// class Solution {
// public:
//     bool isUgly(int n) {
//         if (n < 0)
//             return false;

//         while (n > 1) {
//             if (n % 2 == 0) {
//                 n = n / 2;
//             } else if (n % 3 == 0) {
//                 n = n / 3;
//             } else if (n % 5 == 0) {
//                 n = n / 5;
//             } else {
//                 return false;
//             }
//         }

//         return n == 1;
//     }
// };

// https://leetcode.com/problems/ugly-number-ii/description/

// Note:- This solution will give TLE.

// class Solution {
// public:
//     unordered_map<int, bool> mp;
//     bool isUgly(int n) {
//         if (n <= 0)
//             return false;
//         if (n == 1)
//             return true;

//         if (mp.find(n) != mp.end())
//             return mp[n];

//         if (n % 2 == 0 && isUgly(n / 2))
//             return mp[n] = true;
//         else if (n % 3 == 0 && isUgly(n / 3))
//             return mp[n] = true;
//         else if (n % 5 == 0 && isUgly(n / 5))
//             return mp[n] = true;

//         return mp[n] = false;
//     };

//     int nthUglyNumber(int n) {
//         mp.clear();
//         int num = 1;

//         while (n > 0) {
//             if (isUgly(num)) {
//                 n--;
//             }
//             num++;
//         }

//         return num - 1;
//     }
// };

// T.C => O(n)
// S.C => O(n)

// class Solution {
// public:
//     int nthUglyNumber(int n) {
//         vector<int> ans(n + 1);

//         ans[1] = 1;

//         int i2;
//         int i3;
//         int i5;

//         i2 = i3 = i5 = 1;

//         for (int i = 2; i <= n; i++) {
//             int i2th_ugly = ans[i2] * 2;
//             int i3rd_ugly = ans[i3] * 3;
//             int i5th_ugly = ans[i5] * 5;

//            ans[i] = min({i2th_ugly, i3rd_ugly, i5th_ugly});

//             if (ans[i] == i2th_ugly)
//                 i2++;

//             if (ans[i] == i3rd_ugly)
//                 i3++;

//             if (ans[i] == i5th_ugly)
//                 i5++;
//         }

//         return ans[n];
//     }
// };

// https://leetcode.com/problems/domino-and-tromino-tiling/

// T.C => O(n)
// S.C => O(n)

// class Solution {
// public:
//     int M = 1000000007;
//     int cache[1001];
//     int solve(int n) {
//         if (n == 1 || n == 2)
//             return n;
//         if (n == 3)
//             return 5;

//         if (cache[n] != -1)
//             return cache[n];
        
//         // 2 * (n -1) + (n - 3):
//         return cache[n] = (2 * solve(n - 1) % M + solve(n - 3) % M) % M;
//     }

//     int numTilings(int n) {
//         memset(cache, -1, sizeof(cache));

//         return solve(n);
//     }
// };

// T.C => O(n)
// S.C => O(n)

// class Solution {
// public:
//     int M = 1000000007;
//     int numTilings(int n) {
//         if (n == 1 || n == 2)
//             return n;

//         vector<int> arr(n + 1, 0);

//         arr[1] = 1;
//         arr[2] = 2;
//         arr[3] = 5;

//         for (int i = 4; i <= n; i++) {
//             arr[i] = (2 * arr[i - 1] % M + arr[i - 3] % M) % M;
//         }

//         return arr[n];
//     }
// };

// https://leetcode.com/problems/flip-string-to-monotone-increasing/

// T.C => O(2^n)
// S.C => O(n)

// class Solution {
// public:
//     int solve(int curr, int prev, int n, string& s) {
//         if (curr >= n) {
//             return 0;
//         };

//         int flip = INT_MAX;
//         int noFlip = INT_MAX;

//         if (s[curr] == '1') {
//             if (prev == 0) {
//                 flip = 1 + solve(curr + 1, 0, n, s);
//                 noFlip = solve(curr + 1, 1, n, s);
//             } else {
//                 noFlip = solve(curr + 1, 1, n, s);
//             }
//         } else if (s[curr] == '0') {
//             if (prev == 0) {
//                 flip = 1 + solve(curr + 1, 1, n, s);
//                 noFlip = solve(curr + 1, 0, n, s);
//             } else {
//                flip = 1 + solve(curr + 1, 1, n, s);
//             }
//         }

//         return min(flip, noFlip);
//     }

//     int minFlipsMonoIncr(string s) {
//         int n = s.length();

//         return solve(0, 0, n, s);
//     }
// };

// T.C => O(n)
// S.C => O(n)

// class Solution {
// public:
//     int solve(int curr, int prev, int n, string& s,
//               vector<vector<int>>& cache) {
//         if (curr >= n) {
//             return 0;
//         };

//         int flip = INT_MAX;
//         int noFlip = INT_MAX;

//         if (cache[curr][prev] != -1) {
//             return cache[curr][prev];
//         }

//         if (s[curr] == '1') {
//             if (prev == 0) {
//                 flip = 1 + solve(curr + 1, 0, n, s, cache);
//                 noFlip = solve(curr + 1, 1, n, s, cache);
//             } else {
//                 noFlip = solve(curr + 1, 1, n, s, cache);
//             }
//         } else if (s[curr] == '0') {
//             if (prev == 0) {
//                 flip = 1 + solve(curr + 1, 1, n, s, cache);
//                 noFlip = solve(curr + 1, 0, n, s, cache);
//             } else {
//                 flip = 1 + solve(curr + 1, 1, n, s, cache);
//             }
//         }

//         return cache[curr][prev] = min(flip, noFlip);
//     }

//     int minFlipsMonoIncr(string s) {
//         int n = s.length();
//         vector<vector<int>> cache(n + 1, vector<int>(2, -1));

//         return solve(0, 0, n, s, cache);
//     }
// };

// T.C => O(n)
// S.C => O(1)

// class Solution {
// public:
//     int minFlipsMonoIncr(string s) {
//         int countOfOnes = 0;
//         int totalFlips = 0;

//         for (int i = 0; i < s.length(); i++) {
//             if (s[i] == '1') {
//                 countOfOnes++;
//             } else if (s[i] == '0') {
//                 totalFlips = min(totalFlips + 1, countOfOnes);
//             }
//         }

//         return totalFlips;
//     }
// };

// https://leetcode.com/problems/reducing-dishes/

// T.C => O(2^n)
// S.C => O(n)

// class Solution {
// public:
//     int solve(int i, int t, int n, vector<int>& satisfaction) {
//         if (i == n)
//             return 0;

//         int include =
//             satisfaction[i] * t + solve(i + 1, t + 1, n, satisfaction);
//         int exclude = solve(i + 1, t, n, satisfaction);

//         return max(include, exclude);
//     }

//     int maxSatisfaction(vector<int>& satisfaction) {
//         int n = satisfaction.size();

//         sort(begin(satisfaction), end(satisfaction));
//         return solve(0, 1, n, satisfaction);
//     }
// };

// T.C => O(n)
// S.C => O(n)

// class Solution {
// public:
//     int solve(int i, int t, int n, vector<int>& satisfaction,
//               vector<vector<int>>& cache) {
//         if (i == n)
//             return 0;

//         if (cache[t][i] != -1) {
//             return cache[t][i];
//         }

//         int include =
//             satisfaction[i] * t + solve(i + 1, t + 1, n, satisfaction, cache);
//         int exclude = solve(i + 1, t, n, satisfaction, cache);

//         return cache[t][i] = max(include, exclude);
//     }

//     int maxSatisfaction(vector<int>& satisfaction) {
//         int n = satisfaction.size();
//         vector<vector<int>> cache(n + 1, vector<int>(n + 1, -1));

//         sort(begin(satisfaction), end(satisfaction));
//         return solve(0, 1, n, satisfaction, cache);
//     }
// };

// T.C => O(n)
// S.C => O(n * k)

// class Solution {
// public:
//     int maxSatisfaction(vector<int>& satisfaction) {
//         sort(satisfaction.begin(), satisfaction.end());
//         vector<vector<long long>> arr(501, vector<long long>(501, INT_MIN));

//         int n = satisfaction.size();

//         for (int i = 0; i < 501; i++) {
//             arr[i][0] = 0;
//         }

//         arr[0][1] = satisfaction[0] * 1;
//         for (int i = 1; i < n; i++) {
//             for (int t = 1; t <= n; t++) {
//                 long long include = satisfaction[i] * t + arr[i - 1][t - 1];
//                 long long exclude = 0 + arr[i - 1][t];

//                 arr[i][t] = max(include, exclude);
//             }
//         }

//         long long ans = 0;
//         for (int t = 1; t <= n; t++) {
//             ans = max(ans, arr[n - 1][t]);
//         }

//         return ans;
//     }
// };

// https://leetcode.com/problems/scramble-string

// T.C => O(2^n)
// S.C => O(n)

// class Solution {
// public:
//     bool solve(string s1, string s2) {

//         if (s1 == s2)
//             return true;

//         if (s1.length() != s2.length())
//             return false;

//         bool result = false;
//         int n = s1.length();
//         for (int i = 1; i < n; i++) {

//             bool swapped = solve(s1.substr(0, i), s2.substr(n - i, i)) &&
//                            solve(s1.substr(i, n - i), s2.substr(0, n - i));
//             if (swapped) {
//                 result = true;
//                 break;
//             }

//             bool not_swapped = solve(s1.substr(0, i), s2.substr(0, i)) &&
//                                solve(s1.substr(i, n - i), s2.substr(i, n - i));
//             if (not_swapped) {
//                 result = true;
//                 break;
//             }
//         }

//         return result;
//     }
//     bool isScramble(string& s1, string& s2) {
//         return solve(s1, s2);
//     }
// };

// T.C => O(n)
// S.C => O(n)

// class Solution {
// public:
//     unordered_map<string, bool> mp;
//     bool solve(string s1, string s2) {

//         if (s1 == s2)
//             return true;

//         if (s1.length() != s2.length())
//             return false;

//         string key = s1 + "-" + s2;
//         if (mp.find(key) != mp.end())
//             return mp[key];

//         bool result = false;
//         int n = s1.length();
//         for (int i = 1; i < n; i++) {

//             bool swapped = solve(s1.substr(0, i), s2.substr(n - i, i)) &&
//                            solve(s1.substr(i, n - i), s2.substr(0, n - i));
//             if (swapped) {
//                 result = true;
//                 break;
//             }

//             bool not_swapped = solve(s1.substr(0, i), s2.substr(0, i)) &&
//                                solve(s1.substr(i, n - i), s2.substr(i, n - i));
//             if (not_swapped) {
//                 result = true;
//                 break;
//             }
//         }

//         return mp[key] = result;
//     }
//     bool isScramble(string& s1, string& s2) {
//         mp.clear();
//         return solve(s1, s2);
//     }
// };

// https://leetcode.com/problems/longest-palindromic-subsequence

// T.C => O(2^n)
// S.C => O(n)

// class Solution {
// public:
//     int LPS(string& s, int i, int j) {
//         if (i > j)
//             return 0;
        
//         if (i == j)
//             return 1;

//         if (s[i] == s[j])
//             return 2 + LPS(s, i + 1, j - 1);
//         else
//             return max(LPS(s, i + 1, j), LPS(s, i, j - 1));
//     }

//     int longestPalindromeSubseq(string s) {
//         int m = s.length();
//         return LPS(s, 0, m - 1);
//     }
// };

// T.C => O(n)
// S.C => O(n * k)

// class Solution {
// public:
//     int cache[1001][1001];
//     int LPS(string& s, int i, int j) {
//         if(i > j)
//             return 0;
//         if(i == j)
//             return 1;
        
//         if(cache[i][j] != -1)
//             return cache[i][j];
//         if(s[i] == s[j])
//             return cache[i][j] = 2 + LPS(s, i+1, j-1);
//         else
//             return cache[i][j] = max(LPS(s, i+1, j), LPS(s, i, j-1));
//     }
    
//     int longestPalindromeSubseq(string s) {
//         int m = s.length();
        
//         memset(cache, -1, sizeof(cache));
//         return LPS(s, 0, m-1);
//     }
// };

// T.C => O(n*n)
// S.C => O(n*n)

// class Solution {
// public:
//     int longestPalindromeSubseq(string s) {
//         int n = s.length();
//         vector<vector<int>> dp(n, vector<int>(n, 0));

//         // Every single character is a palindrome of length 1
//         for (int i = 0; i < n; i++) {
//             dp[i][i] = 1;
//         }

//         // Consider all substring lengths from 2 to n
//         for (int length = 2; length <= n; length++) {
//             // Try every possible starting index
//             for (int start = 0; start + length - 1 < n; start++) {
//                 int end = start + length - 1;

//                 // Both characters match
//                 if (s[start] == s[end]) {
//                     dp[start][end] = 2 + dp[start + 1][end - 1];
//                 } else {
//                     // Skip either left or right character
//                     dp[start][end] =
//                         max(dp[start + 1][end], dp[start][end - 1]);
//                 }
//             }
//         }

//         return dp[0][n - 1];
//     }
// };

// https://leetcode.com/problems/maximum-value-of-k-coins-from-piles

// T.C => O(2^n)
// S.C => O(n)

// class Solution {
// public:
//     int n;
//     int solve(int i, vector<vector<int>>& piles, int k) {
//         if(i >= n)
//             return 0;

//         int remove = solve(i+1, piles, k);
//         int add = 0;
        
//         int sum = 0;
//         for(int j = 0; j < min((int)piles[i].size(), k); j++) {
//             sum += piles[i][j];
            
//             if(k - (j+1) >= 0) {
//                 add = max(add, sum + solve(i+1, piles, k-(j+1)));
//             }
//         }
        
//         return max(add, remove);
//     }
    
//     int maxValueOfCoins(vector<vector<int>>& piles, int k) {
//         n = piles.size();

//         return solve(0, piles, k);
        
//     }
// };

// T.C => O(n * k)
// S.C => O(n * k)

// class Solution {
// public:
//     int n;
//     int cache[1001][2001];
    
//     int solve(int i, vector<vector<int>>& piles, int k) {
//         if (i >= n)
//             return 0;

//         if (cache[i][k] != -1) {
//             return cache[i][k];
//         }

//         int remove = solve(i + 1, piles, k);
//         int add = 0;

//         int sum = 0;
//         for (int j = 0; j < min((int)piles[i].size(), k); j++) {
//             sum += piles[i][j];

//             if (k - (j + 1) >= 0) {
//                 add = max(add, sum + solve(i + 1, piles, k - (j + 1)));
//             }
//         }

//         return cache[i][k] = max(add, remove);
//     }

//     int maxValueOfCoins(vector<vector<int>>& piles, int k) {
//         n = piles.size();
//         memset(cache, -1, sizeof(cache));

//         return solve(0, piles, k);
//     }
// };

// T.C => O(n * k)
// S.C => O(n * k)

// class Solution {
// public:
//     int maxValueOfCoins(vector<vector<int>>& piles, int k) {
//         int n = piles.size();
//         vector<vector<int>> t(n + 1, vector<int>(k + 1));

//         for (int i = 1; i <= n; i++) {
//             for (int coins = 0; coins <= k; coins++) {
//                 int sum = 0;
//                 for (int currCoins = 0;
//                      currCoins <= min((int)piles[i - 1].size(), coins);
//                      currCoins++) {
//                     if (currCoins > 0)
//                         sum += piles[i - 1][currCoins - 1];
//                     t[i][coins] =
//                         max(t[i][coins], sum + t[i - 1][coins - currCoins]);
//                 }
//             }
//         }

//         return t[n][k];
//     }
// };

// https://leetcode.com/problems/restore-the-array

// T.C => O(2^n)
// S.C => O(n)

// class Solution {
// public:
//     int n;
//     const int MOD = 1000000007;

//     int solve(int start, string& s, int k) {
//         if (start == n) {
//             return 1;
//         }

//         if (s[start] == '0') {
//             return 0;
//         }

//         long long number = 0;
//         long long ways = 0;

//         for (int end = start; end < n; end++) {
            
//             number = number * 10 + (s[end] - '0');

//             if (number > k) {
//                 break;
//             }

//             ways = (ways + solve(end + 1, s, k)) % MOD;
//         }

//         return ways;
//     }

//     int numberOfArrays(string s, int k) {
//         n = s.length();

//         return solve(0, s, k);
//     }
// };

// T.C => O(n)
// S.C => O(n)

// class Solution {
// public:
//     int n;
//     const int MOD = 1000000007;

//     int solve(int start, string& s, int k, vector<int>& cache) {
//         if (start >= n) {
//             return 1;
//         }

//         if (cache[start] != -1) {
//             return cache[start];
//         }

//         if (s[start] == '0') {
//             return 0;
//         }

//         long long number = 0;
//         long long ways = 0;

//         for (int end = start; end < n; end++) {

//             number = number * 10 + (s[end] - '0');

//             if (number > k) {
//                 break;
//             }

//             ways = (ways + solve(end + 1, s, k, cache)) % MOD;
//         }

//         return cache[start] = ways;
//     }

//     int numberOfArrays(string s, int k) {
//         n = s.length();
//         vector<int> cache(n, -1);

//         return solve(0, s, k, cache);
//     }
// };

// https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary

// T.C => O(2^k)
// S.C => O(k)

// class Solution {
// public:
//     int m;
//     int k;
//     const int MOD = 1000000000 + 7;

//     int solve(
//         int i,
//         int j,
//         vector<vector<long long>>& freq,
//         string& target
//     ) {
//         // Target completely formed
//         if (i == m)
//             return 1;

//         // No more columns available
//         if (j == k)
//             return 0;

//         // Use current column
//         int include =
//             (freq[target[i] - 'a'][j] *
//              solve(i + 1, j + 1, freq, target)) % MOD;

//         // Skip current column
//         int exclude =
//             solve(i, j + 1, freq, target) % MOD;

//         return (include + exclude) % MOD;
//     }

//     int numWays(vector<string>& words, string target) {
//         m = target.length();
//         k = words[0].size();

//         vector<vector<long long>> freq(
//             26,
//             vector<long long>(k)
//         );

//         for (int col = 0; col < k; col++) {
//             for (string& word : words) {
//                 freq[word[col] - 'a'][col]++;
//             }
//         }

//         return solve(0, 0, freq, target);
//     }
// };

// T.C => O(n*k+m*k)
// S.C => O(m * k)

// class Solution {
// public:
//     int m;
//     int k;
//     const int MOD = 1000000000 + 7;
//     int cache[1001][1001];

//     int solve(int i, int j, vector<vector<long long>>& freq, string& target) {
//         // Target completely formed
//         if (i == m)
//             return 1;

//         // No more columns available
//         if (j == k)
//             return 0;

//         if (cache[i][j] != -1){
//             return cache[i][j];
//         }

//         // Use current column
//         int include =
//             (freq[target[i] - 'a'][j] * solve(i + 1, j + 1, freq, target)) %
//             MOD;

//         // Skip current column
//         int exclude = solve(i, j + 1, freq, target) % MOD;

//         return cache[i][j] = (include + exclude) % MOD;
//     }

//     int numWays(vector<string>& words, string target) {
//         m = target.length();
//         k = words[0].size();

//         vector<vector<long long>> freq(26, vector<long long>(k));

//         for (int col = 0; col < k; col++) {
//             for (string& word : words) {
//                 freq[word[col] - 'a'][col]++;
//             }
//         }

//         memset(cache, -1, sizeof(cache));

//         return solve(0, 0, freq, target);
//     }
// };
