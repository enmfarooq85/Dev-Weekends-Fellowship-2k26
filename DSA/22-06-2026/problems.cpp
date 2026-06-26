// https://leetcode.com/problems/two-sum/description/

// T.C => O(n log n)
// S.C => O(n)

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<pair<int, int>> arr;

//         for (int i = 0; i < nums.size(); i++) {
//             arr.push_back({nums[i], i});
//         }

//         sort(arr.begin(), arr.end());

//         int left = 0;
//         int right = arr.size() - 1;

//         while (left < right) {
//             int sum = arr[left].first + arr[right].first;

//             if (sum == target) {
//                 return {arr[left].second, arr[right].second};
//             }
//             else if (sum < target) {
//                 left++;
//             }
//             else {
//                 right--;
//             }
//         }

//         return {};
//     }
// };

// https://leetcode.com/problems/merge-sorted-array/


// T.C => O(m + n)
// S.C => O(m + n)

// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         vector<int> ans;

//         int i = 0, j = 0;

//         while (i < m && j < n) {
//             if (nums1[i] <= nums2[j]) {
//                 ans.push_back(nums1[i++]);
//             } else {
//                 ans.push_back(nums2[j++]);
//             }
//         }

//         while (i < m) {
//             ans.push_back(nums1[i++]);
//         }

//         while (j < n) {
//             ans.push_back(nums2[j++]);
//         }

//         // Copy back to nums1
//         for (int k = 0; k < m + n; k++) {
//             nums1[k] = ans[k];
//         }
//     }
// };

// T.C => O(m + n)
// S.C => O(1)

// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int i = m - 1;              // Last valid element in nums1
//         int j = n - 1;              // Last element in nums2
//         int k = m + n - 1;          // Last position in nums1

//         while (i >= 0 && j >= 0) {
//             if (nums1[i] > nums2[j]) {
//                 nums1[k] = nums1[i];
//                 i--;
//             } else {
//                 nums1[k] = nums2[j];
//                 j--;
//             }
//             k--;
//         }

//         // Copy remaining elements from nums2
//         while (j >= 0) {
//             nums1[k] = nums2[j];
//             j--;
//             k--;
//         }
//     }
// };

// https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/description/

// T.C => O(m + n)
// S.C => O(m + n)

// class Solution {
// public:
//     vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
//                                     vector<vector<int>>& nums2) {

//         vector<vector<int>> ans;

//         int i = 0, j = 0;
//         int m = nums1.size(), n = nums2.size();

//         while (i < m && j < n) {
//             int id1 = nums1[i][0];
//             int id2 = nums2[j][0];

//             if (id1 == id2) {
//                 ans.push_back({id1, nums1[i][1] + nums2[j][1]});
//                 i++;
//                 j++;
//             } else if (id1 < id2) {
//                 ans.push_back(nums1[i]);
//                 i++;
//             } else {
//                 ans.push_back(nums2[j]);
//                 j++;
//             }
//         }

//         while (i < m) {
//             ans.push_back(nums1[i]);
//             i++;
//         }

//         while (j < n) {
//             ans.push_back(nums2[j]);
//             j++;
//         }

//         return ans;
//     }
// };

// T.C => O(m + n + k log k)
// S.C => O(m + n)

// class Solution {
// public:
//     vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
//         unordered_map<int, int> mp;

//         for (auto &v : nums1) {
//             mp[v[0]] = v[1];
//         }

//         for (auto &v : nums2) {
//             mp[v[0]] += v[1];
//         }

//         vector<vector<int>> ans;

//         for (auto &it : mp) {
//             ans.push_back({it.first, it.second});
//         }

//         sort(ans.begin(), ans.end());

//         return ans;
//     }
// };

// T.C => O(m + n + k log k)
// S.C => O(m + n)

// class Solution {
// public:
//     vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
//         map<int, int> mp;

//         for (auto &v : nums1) {
//             mp[v[0]] = v[1];
//         }

//         for (auto &v : nums2) {
//             mp[v[0]] += v[1];
//         }

//         vector<vector<int>> ans;

//         for (auto &it : mp) {
//             ans.push_back({it.first, it.second});
//         }

//         return ans;
//     }
// };

// https://leetcode.com/problems/sort-array-by-parity/description/

// T.C => O(n)
// S.C => O(1)

// class Solution {
// public:
//     vector<int> sortArrayByParity(vector<int>& nums) {
//         int left = 0;
//         int right = nums.size() - 1;

//         while (left < right) {
//             // agr right pe even hy tu left pe le ao aur agr left pe odd hy tu
//             // usko right pe le jao
//             if (nums[right] % 2 == 0 && nums[left] % 2 != 0) {
//                 int temp = nums[left];
//                 nums[left] = nums[right];
//                 nums[right] = temp;
//                 left++;
//                 right--;

//             } else if (nums[left] % 2 == 0 &&
//                        nums[right] % 2 != 0) { // agr already sahi position hy
//                                                // tu just move on kro
//                 left++;
//                 right--;
//             } else if (nums[left] % 2 != 0 &&
//                        nums[right] % 2 != 0) { // ab just one pointer move kro ge agr odd right aur left dono pe hy tu right move kro kyu ke may be left se koi swapping ho jaye
//                 right--;
//             } else if (nums[left] % 2 == 0 && nums[right] % 2 == 0) { // ab just one pointer move kro ge agr even right aur left dono pe hy tu right move kro kyu ke may be left se koi swapping ho jaye
//                 left++;
//             }
//         };

//         return nums;
//     };
// };

// https://leetcode.com/problems/sort-array-by-parity-ii/

// T.C => O(n)
// S.C => O(1)

// class Solution {
// public:
//     vector<int> sortArrayByParityII(vector<int>& nums) {
//         int left = 0;  // even index
//         int right = 1; // odd index

//         while (left < nums.size() && right < nums.size()) {
//             if (nums[left] % 2 == 0) {
//                 left += 2;
//             } else if (nums[right] % 2 == 1) {
//                 right += 2;
//             } else {
//                 swap(nums[left], nums[right]);
//                 left += 2;
//                 right += 2;
//             }
//         }

//         return nums;
//     }
// };

// https://leetcode.com/problems/largest-merge-of-two-strings/

// T.C => O(m + n)
// S.C => O(s)

// class Solution {
// public:
//     string largestMerge(string word1, string word2) {
//         int i = 0, j = 0;
//         string ans = "";

//         while (i < word1.size() && j < word2.size()) {
//             if (word1.substr(i) > word2.substr(j)) {
//                 ans += word1[i++];
//             } else {
//                 ans += word2[j++];
//             }
//         }

//         while (i < word1.size()) {
//             ans += word1[i++];
//         }

//         while (j < word2.size()) {
//             ans += word2[j++];
//         }

//         return ans;
//     }
// };