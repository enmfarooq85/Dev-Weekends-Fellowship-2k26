// https://leetcode.com/problems/pyramid-transition-matrix

// T.C => O(n)
// S.C => O(n)

// class Solution {
// public:
//     unordered_map<string, bool> dp;

//     bool solve(string curr, unordered_map<string, vector<char>>& mp, int idx,
//                string justTop) {
        
//         if (curr.length() == 1) {
//             return true;
//         }

//         string key = curr + "_" + to_string(idx) + "_" + justTop;

//         if (dp.count(key))
//             return dp[key];

//         if (idx ==
//             curr.length() - 1) {
//             return dp[key] = solve(justTop, mp, 0, "");
//         }

//         string pair = curr.substr(idx, 2);
//         if (mp.find(pair) == mp.end()) {
//             return dp[key] = false;
//         }

//         for (char& ch : mp[pair]) {
//             justTop.push_back(ch);

//             if (solve(curr, mp, idx + 1, justTop) == true)
//                 return dp[key] = true;

//             justTop.pop_back();
//         }

//         return dp[key] = false;
//     }

//     bool pyramidTransition(string bottom, vector<string>& allowed) {
//         unordered_map<string, vector<char>> mp;

//         for (auto& pattern : allowed) {
//             mp[pattern.substr(0, 2)].push_back(pattern[2]);
//         }

//         return solve(bottom, mp, 0, "");
//     }
// };

// https://leetcode.com/problems/24-game/

// T.C => O(1)
// S.C => O(1)

// class Solution {
// public:
//     // setting epsilon value to avoid the small comparison error
//     double epsilon = 0.0000001;

//     bool solve(vector<double>& cards) {
//         if (cards.size() == 1) {
//             return abs(cards[0] - 24) <= epsilon;
//         }

//         // picking up every possibility of two numbers either 2, 1 or 1, 2 because it is different in a - b, b - a or a / b or b / a
//         for (int i = 0; i < cards.size(); i++) {
//             for (int j = 0; j < cards.size(); j++) {
//                 // we cannot use same numbers as problems need
//                 if (i == j)
//                     continue;

//                 // storing all other numbers except the i, j
//                 vector<double> temp;
//                 for (int k = 0; k < cards.size(); k++) {
//                     if (k != i && k != j) {
//                         temp.push_back(cards[k]);
//                     }
//                 }

//                 // now, it's time to do possible operation on a and b and see if it any of possible picking evaluate to 24
//                 double a = cards[i];
//                 double b = cards[j];
//                 // total are 8, but possible operations are 6 which will affect the result
//                 vector<double> possibleVal = {a + b, a - b, b - a, a * b};
                
//                 // handling division by zero if b is zero
//                 if (abs(b) > 0.0) {
//                     possibleVal.push_back(a / b);
//                 }

//                 // handling division by zero if a is zero
//                 if (abs(a) > 0.0) {
//                     possibleVal.push_back(b / a);
//                 }

//                 // simple pick the evaluted values of 6 possible operations and chk if any with rest numbers can evaluate to 24
//                 for (double val : possibleVal) {
//                     temp.push_back(val);
//                     if (solve(temp) == true)
//                         return true;
//                     temp.pop_back();
//                 }
//             }
//         }

//         // if nothing return after doing all operation return false
//         return false;
//     }

//     bool judgePoint24(vector<int>& cards) {
//         vector<double> nums;
//         // we are converting it into double because problem requre real division not integer division
//         for (int i = 0; i < cards.size(); i++) {
//             nums.push_back(1.0 * cards[i]);
//         };

//         return solve(nums);
//     }
// };

// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/

// T.C => O(n * 2^n)
// S.C => O(n * 2^n)

// class Solution {
// public:
//     void solve(int n, string temp, vector<string>& result) {
//         if (temp.length() == n) {
//             result.push_back(temp);
//             return;
//         }

//         for (char ch = 'a'; ch <= 'c'; ch++) {
//             if (!temp.empty() && temp.back() == ch) {
//                 continue;
//             };

//             temp.push_back(ch);
//             solve(n, temp, result);
//             temp.pop_back();
//         }
//     }

//     string getHappyString(int n, int k) {
//         vector<string> result;
//         string temp = "";

//         solve(n, temp, result);

//         if (result.size() < k) {
//             return "";
//         }

//         return result[k - 1];
//     }
// };

// T.C => O(n * 2^n)
// S.C => O(n)

// class Solution {
// public:
//     void solve(int& n, int& k, int& count, string curr, string &ans) {
//         if (curr.length() == n) {
//             count++;
//             if (count == k) {
//                 ans = curr;
//             };

//             return;
//         }

//         for (char ch = 'a'; ch <= 'c'; ch++) {
//             if (!curr.empty() && curr.back() == ch) {
//                 continue;
//             };

//             curr.push_back(ch);
            
//             solve(n, k, count, curr, ans);

//             if (!ans.empty()) return;
            
//             curr.pop_back();
//         }
//     }

//     string getHappyString(int n, int k) {
//         int count = 0;
//         string ans = "";
//         string curr = "";

//         solve(n, k, count, curr, ans);

//         return ans;
//     }
// };

// https://leetcode.com/problems/letter-tile-possibilities/description/

// T.C => O(n * n!)
// S.C => O(n * n!) + O(n)

// class Solution {
// public:
//     void solve(int n, string& tiles, vector<bool>& used,
//                unordered_set<string>& result, string& curr) {
//         result.insert(curr);

//         for (int i = 0; i < n; i++) {
//             if (used[i])
//                 continue;

//             curr.push_back(tiles[i]);
//             used[i] = true;

//             solve(n, tiles, used, result, curr);

//             used[i] = false;
//             curr.pop_back();
//         }
//     }

//     int numTilePossibilities(string tiles) {
//         int n = tiles.length();
//         vector<bool> used(n, false);
//         unordered_set<string> result;
//         string curr = "";

//         solve(n, tiles, used, result, curr);

//         return result.size() - 1;
//     }
// };

// T.C => O(n!)
// S.C => O(n)

// class Solution {
// public:
//     int total;

//     void findSequences(vector<int>& count) {
//         total++;

//         for (int charPosition = 0; charPosition < 26; charPosition++) {
//             if (count[charPosition] == 0) {
//                 continue;
//             }

//             count[charPosition]--;
//             findSequences(count);
//             count[charPosition]++;
//         }
//     }

//     int numTilePossibilities(string tiles) {
//         total = 0;

//         vector<int> count(26, 0);

//         for (char c : tiles) {
//             count[c - 'A']++;
//         }

//         findSequences(count);
//         return total - 1;
//     }
// };

// https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/

// T.C => O(n* 2^)
// S.C => O(n)

// class Solution {
// public:
//     void solve(int i, int currCount, int& maxCount, string s,
//                unordered_set<string> sett) {
//         // Pruning:
//         // Even if we split every remaining character individually,
//         // we still cannot beat the current maximum count.
//         if (currCount + (s.length() - i) <= maxCount) {
//             return;
//         }

//         // Reached the end of the string.
//         // Update the maximum number of unique substrings found.
//         if (i >= s.length()) {
//             maxCount = max(currCount, maxCount);
//             return;
//         }

//         // Try every possible substring starting from index i.
//         for (int j = i; j < s.length(); j++) {
//             string splittedString = s.substr(i, j - i + 1);
//             cout << splittedString << endl;
//             // If the substring is unique
//             // choose it, explore recursively, then backtrack.
//             if (sett.find(splittedString) == sett.end()) {
//                 sett.insert(splittedString);
//                 solve(j + 1, currCount + 1, maxCount, s, sett);
//                 sett.erase(splittedString);
//             }
//         }
//     }

//     int maxUniqueSplit(string s) {
//         int currCount = 0;
//         int maxCount = 0;
//         int i = 0;
//         unordered_set<string> sett;

//         solve(i, currCount, maxCount, s, sett);

//         return maxCount;
//     }
// };

// https://leetcode.com/problems/maximum-score-words-formed-by-letters/description/

// T.C => O(n* 2^n)
// S.C => O(n)

// class Solution {
// public:
//     int maxScore;
//     int n;

//     void solve(int i, int n, int currScore, vector<int>& score,
//                vector<string>& words, vector<int>& lettersMp) {
//         maxScore = max(currScore, maxScore);

//         if (i >= n) {
//             return;
//         }

//         int j = 0;
//         int tempScore = 0;
//         vector<int> tempLettersMp = lettersMp;
//         while (j < words[i].length()) {
//             tempLettersMp[words[i][j] - 'a']--;
//             tempScore += score[words[i][j] - 'a'];

//             if (tempLettersMp[words[i][j] - 'a'] < 0) {
//                 break;
//             }

//             j++;
//         }

//         if (j == words[i].length()) {
//             solve(i + 1, n, currScore + tempScore, score, words, tempLettersMp);
//         };

//         solve(i + 1, n, currScore, score, words, lettersMp);
//     };

//     int maxScoreWords(vector<string>& words, vector<char>& letters,
//                       vector<int>& score) {
//         vector<int> lettersMp(26, 0);

//         for (auto& ch : letters) {
//             lettersMp[ch - 'a']++;
//         };
        
//         n = words.size();
//         maxScore = INT_MIN;
//         int currScore = 0;
//         int i = 0;

//         solve(i, n, currScore, score, words, lettersMp);

//         return maxScore;
//     }
// };

// T.C => O(n* 2^n)
// S.C => O(n)

// class Solution {
// public:
//     int maxScore;
//     int n;

//     void solve(int i, int n, int currScore, vector<int>& score,
//                vector<string>& words, vector<int>& lettersMp) {
//         maxScore = max(currScore, maxScore);

//         if (i >= n) {
//             return;
//         }

//         bool canTake = true;
//         int tempScore = 0;
//         for (char ch : words[i]) {
//             lettersMp[ch - 'a']--;
//             tempScore += score[ch - 'a'];

//             if (lettersMp[ch - 'a'] < 0) {
//                 canTake = false;
//             }
//         }

//         if (canTake) {
//             solve(i + 1, n, currScore + tempScore, score, words, lettersMp);
//         };

//         for (char ch : words[i]) {
//             lettersMp[ch - 'a']++;
//         }

//         solve(i + 1, n, currScore, score, words, lettersMp);
//     };

//     int maxScoreWords(vector<string>& words, vector<char>& letters,
//                       vector<int>& score) {
//         vector<int> lettersMp(26, 0);

//         for (auto& ch : letters) {
//             lettersMp[ch - 'a']++;
//         };

//         n = words.size();
//         maxScore = INT_MIN;
//         int currScore = 0;
//         int i = 0;

//         solve(i, n, currScore, score, words, lettersMp);

//         return maxScore;
//     }
// };

// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

// T.C => O(n* 2^n)
// S.C => O(n)

// class Solution {
// public:
//     void solve(int idx, string digits, unordered_map<char, string>& mp,
//                string& temp, vector<string>& ans) {
//         if (idx == digits.length()) {
//             ans.push_back(temp);
//             return;
//         }

//         char chDigit = digits[idx];
//         string chToLetterMp = mp[chDigit];

//         for (int i = 0; i < chToLetterMp.length(); i++) {
//             temp.push_back(chToLetterMp[i]);
//             solve(idx + 1, digits, mp, temp, ans);
//             temp.pop_back();
//         }
//     };

//     vector<string> letterCombinations(string digits) {
//         unordered_map<char, string> mp;

//         mp['2'] = "abc";
//         mp['3'] = "def";
//         mp['4'] = "ghi";
//         mp['5'] = "jkl";
//         mp['6'] = "mno";
//         mp['7'] = "pqrs";
//         mp['8'] = "tuv";
//         mp['9'] = "wxyz";

//         vector<string> ans;
//         string temp = "";
//         int idx = 0;

//         solve(idx, digits, mp, temp, ans);

//         return ans;
//     }
// };

// https://leetcode.com/problems/the-number-of-beautiful-subsets/

// T.C => O(n)
// S.C => O(n)

// class Solution {
// public:
//     int solve(vector<int>& nums, int idx, unordered_map<int, int>& mp, int k,
//               int& count) {
//         if (idx == nums.size()) {
//             count++;
//             return count;
//         }

//         if (!mp[nums[idx] - k] && !mp[nums[idx] + k]) {
//             mp[nums[idx]]++;
//             solve(nums, idx + 1, mp, k, count);
//             mp[nums[idx]]--;
//         };

//         solve(nums, idx + 1, mp, k, count);

//         return count;
//     };

//     int beautifulSubsets(vector<int>& nums, int k) {
//         unordered_map<int, int> mp;
//         int count = 0;

//         return solve(nums, 0, mp, k, count) - 1;
//     }
// };

// https://leetcode.com/problems/word-search/

// T.C => O(n)
// S.C => O(n)

// class Solution {
// public:
//     bool backtrack(int i, int j, int k, int rows, int cols, string word,
//                    vector<vector<char>>& board) {
//         if (k == word.length())
//             return true;

//         if (i < 0 || i >= rows || j < 0 || j >= cols ||
//             board[i][j] != word[k]) {
//             return false;
//         }

//         // it means valid
//         char temp = board[i][j];
//         // mark as visited
//         board[i][j] = '#';

//         // bottom // top // right // left
//         bool bottom = backtrack(i + 1, j, k + 1, rows, cols, word, board);
//         bool top = backtrack(i - 1, j, k + 1, rows, cols, word, board);
//         bool right = backtrack(i, j + 1, k + 1, rows, cols, word, board);
//         bool left = backtrack(i, j - 1, k + 1, rows, cols, word, board);

//         board[i][j] = temp;
//         return bottom || top || right || left;
//     }
//     bool exist(vector<vector<char>>& board, string word) {
//         int rows = board.size();
//         int cols = board[0].size();

//         for (int i = 0; i < rows; i++) {
//             for (int j = 0; j < cols; j++) {
//                 if (backtrack(i, j, 0, rows, cols, word, board))
//                     return true;
//             }
//         }

//         return false;
//     }
// };

// Note: There is a slight difference in this approach from previous. Now, we are calling the backtrack function when we are finding the first letter of word in board. Other part of code is same as above.

// class Solution {
// public:
//     bool backtrack(int i, int j, int k, int rows, int cols, string word,
//                    vector<vector<char>>& board) {
//         if (k == word.length())
//             return true;

//         if (i < 0 || i >= rows || j < 0 || j >= cols ||
//             board[i][j] != word[k]) {
//             return false;
//         }

//         // it means valid
//         char temp = board[i][j];
//         // mark as visited
//         board[i][j] = '#';

//         // bottom // top // right // left
//         bool bottom = backtrack(i + 1, j, k + 1, rows, cols, word, board);
//         bool top = backtrack(i - 1, j, k + 1, rows, cols, word, board);
//         bool right = backtrack(i, j + 1, k + 1, rows, cols, word, board);
//         bool left = backtrack(i, j - 1, k + 1, rows, cols, word, board);

//         board[i][j] = temp;
//         return bottom || top || right || left;
//     }
//     bool exist(vector<vector<char>>& board, string word) {
//         int rows = board.size();
//         int cols = board[0].size();

//         for (int i = 0; i < rows; i++) {
//             for (int j = 0; j < cols; j++) {
//                 if (board[i][j] == word[0] &&
//                     backtrack(i, j, 0, rows, cols, word, board))
//                     return true;
//             }
//         }

//         return false;
//     }
// };

// https://leetcode.com/problems/non-decreasing-subsequences/

// T.C => O(n * 2^n)
// S.C => O(n) 

// class Solution {
// public:
//     void backtrack(int n, int idx, vector<int>& nums, vector<int>& curr,
//                    vector<vector<int>>& result) {
//         // subset min length should be 2 and maximum nums length
//         if (curr.size() > 1 && curr.size() <= nums.size())
//             result.push_back(curr);

//         // using set to avoid duplicates in the curr recursive call
//         unordered_set<int> st;
//         // trying each possibility
//         for (int i = idx; i < n; i++) {
//             // if vector of int is empty so try to add if not empty then
//             // chk if we can add or not because curr number
//             // should be greater than last of vector of integer and move on
//             if ((curr.empty() || nums[i] >= curr.back()) &&
//                 st.find(nums[i]) == st.end()) {

//                 curr.push_back(nums[i]);
//                 backtrack(n, i + 1, nums, curr, result);
//                 curr.pop_back();

//                 st.insert(nums[i]);
//             }
//         }
//     }

//     vector<vector<int>> findSubsequences(vector<int>& nums) {
//         int n = nums.size();
//         // result to store final result of vector of vector of int
//         vector<vector<int>> result;
//         // temp vector of int to store a single subsequence
//         vector<int> curr;

//         backtrack(n, 0, nums, curr, result);
//         return result;
//     }
// };

// https://leetcode.com/problems/palindrome-partitioning

// T.C => O(n * 2^n)
// S.C => O(n * 2^n) 

// class Solution {
// public:
//     bool isPalindrome(string& s, int l, int r) {
//         while (l < r) {
//             if (s[l] != s[r])
//                 return false;
//             l++;
//             r--;
//         }

//         return true;
//     }

//     void backtrack(int idx, int n, string& s, vector<string> curr,
//                    vector<vector<string>>& result) {

//         if (idx == n) {
//             result.push_back(curr);
//             return;
//         }

//         for (int i = idx; i < n; i++) {
//             if (isPalindrome(s, idx, i)) {
//                 curr.push_back(s.substr(idx, i - idx + 1));
//                 backtrack(i + 1, n, s, curr, result);
//                 curr.pop_back();
//             }
//         }
//     }

//     vector<vector<string>> partition(string s) {
//         int n = s.length();
//         vector<vector<string>> result;
//         vector<string> curr;
//         int idx = 0;

//         backtrack(idx, n, s, curr, result);
//         return result;
//     }
// };

// https://leetcode.com/problems/count-numbers-with-unique-digits/description/

// T.C => O(n)
// S.C => O(1)

// class Solution {
// public:
//     int countNumbersWithUniqueDigits(int n) {
//         if (n == 0)
//             return 1;

//         int ans = 10;
//         int start = 9;
//         int curr = 9;
//         while (n > 1 && start) {
//             curr *= start;
//             ans += curr;
//             start--;
//             n--;
//         }

//         return ans;
//     }
// };

// T.C => O(n)
// S.C => O(1)

// class Solution {
// public:
//     int count = 1;

//     void backtrack(int n, int length, vector<bool>& used) {
//         if (length == n) {
//             return;
//         }

//         for (int digit = 0; digit <= 9; digit++) {
//             if (length == 0 && digit == 0)
//                 continue;

//             if (used[digit])
//                 continue;

//             used[digit] = true;
//             count++;

//             backtrack(n, length + 1, used);
//             used[digit] = false;
//         }
//     }

//     int countNumbersWithUniqueDigits(int n) {

//         if (n == 0)
//             return 1;

//         vector<bool> used(10, false);
//         backtrack(n, 0, used);

//         return count;
//     }
// };

// https://leetcode.com/problems/combination-sum-iv/

// T.C => O(n^target)
// S.C => O(target)

// Note:- This solution will give us TLE.

// class Solution {
// public:
//     int solve(int idx, int n, vector<int>& nums, int target) {
//         if (target == 0) {
//             return 1;
//         }

//         if (idx >= n || target < 0) {
//             return 0;
//         }

//         return solve(0, n, nums, target - nums[idx]) +
//                solve(idx + 1, n, nums, target);
//     };
    
//     int combinationSum4(vector<int>& nums, int target) {
//         int n = nums.size();

//         return solve(0, n, nums, target);
//     }
// };

// T.C => O(n * target)
// S.C => O(target)

// class Solution {
// public:
//     int dp[201][1001];
//     int solve(int idx, int n, vector<int>& nums, int target) {
//         if (target == 0) {
//             return 1;
//         }

//         if (idx >= n || target < 0) {
//             return 0;
//         }

//         if (dp[idx][target] != -1){
//             return dp[idx][target];
//         }

//         return dp[idx][target] = solve(0, n, nums, target - nums[idx]) +
//                solve(idx + 1, n, nums, target);
//     };

//     int combinationSum4(vector<int>& nums, int target) {
//         int n = nums.size();
//         memset(dp, -1, sizeof(dp));
//         return solve(0, n, nums, target);
//     }
// };

// https://leetcode.com/problems/permutations/

// T.C => O(n * n!)
// S.C => O(n)

// class Solution {
// public:
//     vector<vector<int>> ans;
//     vector<int> temp;
//     vector<bool> visited;
//     int n;

//     void solve(vector<int>& nums) {
//         if (temp.size() == n) {
//             ans.push_back(temp);
//             return;
//         }

//         for (int i = 0; i < n; i++) {
//             if (visited[i] == true){
//                 continue;
//             };

//             visited[i] = true;
//             temp.push_back(nums[i]);
            
//             solve(nums);

//             temp.pop_back();
//             visited[i] = false;
//         }
//     }

//     vector<vector<int>> permute(vector<int>& nums) {
//         n = nums.size();
        
//         visited.assign(n, false);
//         solve(nums);

//         return ans;
//     }
// };

// https://leetcode.com/problems/beautiful-arrangement

// T.C => O(n * n!)
// S.C => O(n)

// Note:- This solution is giving TLE.

// class Solution {
// public:
//     vector<int> nums;
//     vector<int> perm;
//     vector<bool> visited;
//     int ans = 0;
//     int nn;

//     void solve(vector<int>& nums) {
//         if (perm.size() == nn) {
//             int isAdded = false;
//             for (int i = 0; i < perm.size(); i++) {
//                 if (perm[i] % (i + 1) == 0 || (i + 1) % perm[i] == 0) {
//                     isAdded = true;
//                 } else {
//                     isAdded = false;
//                     break;
//                 }
//             };

//             if (isAdded == true) {
//                 ans += 1;
//             };

//             return;
//         }

//         for (int i = 0; i < nn; i++) {
//             if (visited[i] == true) {
//                 continue;
//             };

//             visited[i] = true;
//             perm.push_back(nums[i]);

//             solve(nums);

//             perm.pop_back();
//             visited[i] = false;
//         }
//     }

//     int countArrangement(int n) {
//         for (int i = 1; i <= n; i++) {
//             nums.push_back(i);
//         };

//         nn = nums.size();
//         visited.assign(nn, false);

//         solve(nums);
//         return ans;
//     }
// };

// T.C => O(n!)
// S.C => O(n)

// class Solution {
// public:
//     vector<int> nums;
//     vector<int> perm;
//     vector<bool> visited;
//     int ans = 0;
//     int nn;

//     void solve(vector<int>& nums) {
//         if (perm.size() == nn) {
//             ans++;
//             return;
//         }

//         int pos = perm.size() + 1;
//         for (int i = 0; i < nn; i++) {
//             if (visited[i]) {
//                 continue;
//             }

//             if (nums[i] % pos != 0 && pos % nums[i] != 0) {
//                 continue;
//             }

//             visited[i] = true;
//             perm.push_back(nums[i]);

//             solve(nums);

//             perm.pop_back();
//             visited[i] = false;
//         }
//     }

//     int countArrangement(int n) {
//         for (int i = 1; i <= n; i++) {
//             nums.push_back(i);
//         }

//         nn = n;
//         visited.assign(nn, false);

//         solve(nums);
//         return ans;
//     }
// };

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
