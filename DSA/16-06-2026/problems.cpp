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