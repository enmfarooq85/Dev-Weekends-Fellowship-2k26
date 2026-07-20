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
