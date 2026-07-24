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