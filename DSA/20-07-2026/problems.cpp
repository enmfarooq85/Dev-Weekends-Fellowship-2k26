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
