// https://leetcode.com/problems/two-sum/

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> prevMap;

//         for (int i = 0; i < nums.size(); i++) {
//             int diff = target - nums[i];

//             if (prevMap.find(diff) != prevMap.end()) {
//                 return {prevMap[diff], i};
//             } else {
//                 prevMap[nums[i]] = i;
//             }
//         }
//         return {};
//     }
// };

// https://leetcode.com/problems/next-greater-element-i/description/

// T.C => O(N)^2
// S.C => O(m) + O(n)

// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         unordered_map<int, int> nge;
//         int n = nums2.size();

//         for (int i = 0; i < n; i++) {
//             int curr = nums2[i];
//             int nextGreater = -1;

//             for (int j = i + 1; j < n; j++) {
//                 if (nums2[j] > curr) {
//                     nextGreater = nums2[j];
//                     break;
//                 }
//             }

//             nge[curr] = nextGreater;
//         }

//         vector<int> result;

//         for (int x : nums1) {
//             result.push_back(nge[x]);
//         }

//         return result;
//     }
// };

// T.C => O(n + m) + O(1)
// S.C => O(m)

// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         unordered_map<int, int> nge;
//         stack<int> st;

//         for (int i = 0; i < nums2.size(); i++) {
//             int curr = nums2[i];

//             while (!st.empty() && curr > st.top()) {
//                 nge[st.top()] = curr;
//                 st.pop();
//             }

//             st.push(curr);
//         }
        
//         while (!st.empty()) {
//             nge[st.top()] = -1;
//             st.pop();
//         }

//         vector<int> result;

//         for (int x : nums1) {
//             result.push_back(nge[x]);
//         }

//         return result;
//     }
// };

// https://leetcode.com/problems/find-the-difference-of-two-arrays/

// T.C => O(n + m)
// S.C => O(n + m)

// class Solution {
// public:
//     vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
//         unordered_set<int> s1(nums1.begin(), nums1.end());
//         unordered_set<int> s2(nums2.begin(), nums2.end());

//         vector<vector<int>> result(2);

//         for (int x : s1) {
//             if (s2.find(x) == s2.end()) {
//                 result[0].push_back(x);
//             }
//         }

//         for (int x : s2) {
//             if (s1.find(x) == s1.end()) {
//                 result[1].push_back(x);
//             }
//         }

//         return result;
//     }
// };

// T.C => O((n + m) log(n + m))
// S.C => O(n + m)

// class Solution {
// public:
//     vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
//         vector<vector<int>> ans;
//         map<int, int> mp1, mp2;
//         // value: freqquency
//         for (auto i : nums1) mp1[i]++;
//         for (auto j : nums2) mp2[j]++;

//         // nums1 - nums2 
//         set<int> set1;
//         vector<int> temp1;
//         for (auto i : nums1){
//             if (mp1[i] > 0 && mp2.count(i) == 0){
//                 set1.insert(i);
//             }
//         }

//         set<int> set2;
//         vector<int> temp2;
//         for (auto i : nums2){
//             if (mp2[i] > 0 && mp1.count(i) == 0){
//                 set2.insert(i);
//             }
//         }

//         for (auto i : set1) temp1.push_back(i);
//         for (auto j : set2) temp2.push_back(j);
        

//         ans.push_back(temp1);
//         ans.push_back(temp2);
//         return ans;
//     }
// };
