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

// https://leetcode.com/problems/rotate-array/

// T.C => O(n)
// S.C => O(1)

// class Solution {
// public:
//     void reverseArray(vector<int>& nums, int left, int right) {
//         while (left < right) {
//             int temp = nums[left];
//             nums[left] = nums[right];
//             nums[right] = temp;

//             left++;
//             right--;
//         }
//     }

//     void rotate(vector<int>& nums, int k) {
//         int n = nums.size();
//         k %= n;

//         // Reverse the entire array
//         reverseArray(nums, 0, n - 1);

//         // Reverse first k elements
//         reverseArray(nums, 0, k - 1);

//         // Reverse remaining elements
//         reverseArray(nums, k, n - 1);
//     }
// };

// T.C => O(n * k)
// S.C => O(1)

// Note:- TLE Soluttion...

// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n = nums.size();
//         k %= n;

//         while (k--) {
//             int last = nums[n - 1];

//             for (int i = n - 1; i > 0; i--) {
//                 nums[i] = nums[i - 1];
//             }

//             nums[0] = last;
//         }
//     }
// };

// https://leetcode.com/problems/compare-version-numbers/

// T.C => O(n + m)
// S.C => O(n + m)

// class Solution {
// public:
//     int compareVersion(string version1, string version2) {
//         vector<string> tokens1, tokens2;
//         string token;

//         stringstream ss1(version1);
//         while (getline(ss1, token, '.')) {
//             tokens1.push_back(token);
//         }

//         stringstream ss2(version2);
//         while (getline(ss2, token, '.')) {
//             tokens2.push_back(token);
//         }

//         int maxLength = max(tokens1.size(), tokens2.size());

//         for (int i = 0; i < maxLength; i++) {
//             int v1 = (i < tokens1.size()) ? stoi(tokens1[i]) : 0;
//             int v2 = (i < tokens2.size()) ? stoi(tokens2[i]) : 0;

//             if (v1 < v2)
//                 return -1;
//             if (v1 > v2)
//                 return 1;
//         }

//         return 0;
//     }
// };

// T.C => O(n + m)
// S.C => O(1)

// class Solution {
// public:
//     int compareVersion(string version1, string version2) {
//         int i = 0, j = 0;
//         int n = version1.size();
//         int m = version2.size();

//         while (i < n || j < m) {
//             int num1 = 0;
//             int num2 = 0;

//             // Reading untill dot comes in
//             while (i < n && version1[i] != '.') {
//                 num1 = num1 * 10 + (version1[i] - '0');
//                 i++;
//             }

//             // Reading untill dot comes in
//             while (j < m && version2[j] != '.') {
//                 num2 = num2 * 10 + (version2[j] - '0');
//                 j++;
//             }

//             // now we have token from v1 and v2, we should compare them.
//             if (num1 < num2)
//                 return -1;
//             if (num1 > num2)
//                 return 1;
            
//             // now after token we have character so skip it.
//             i++;
//             j++;
//         }

//         return 0;
//     }
// };

// https://leetcode.com/problems/reverse-prefix-of-word/

// T.C => O(n)
// S.C => O(1)

// class Solution {
// public:
//     string reversePrefix(string word, char ch) {
//         if(word.length() == 1) return word;

//         int end = -1;
//         for (int i = 0; i < word.length(); i++) {
//             if (word[i] == ch) {
//                 end = i;
//                 break;
//             }
//         }

//         if (end == -1) {
//             return word;
//         } else if (end == 0) {
//             return word;
//         }

//         int start = 0;
//         while (start < end) {
//             swap(word[start], word[end]);
//             start++;
//             end--;
//         }

//         return word;
//     }
// };

// T.C => O(n)
// S.C => O(n)

// class Solution {
// public:
//     string reversePrefix(string word, char ch) {
//         stack<char> st;
//         int index = -1;

//         for (int i = 0; i < word.size(); i++) {
//             st.push(word[i]);

//             if (word[i] == ch) {
//                 index = i;
//                 break;
//             }
//         }

//         if (index == -1)
//             return word;

//         int i = 0;
//         while (!st.empty()) {
//             word[i++] = st.top();
//             st.pop();
//         }

//         return word;
//     }
// };


// https://leetcode.com/problems/partition-array-according-to-given-pivot/

// T.C => O(n)
// S.C => O(s + m + e)

// class Solution {
// public:
//     vector<int> pivotArray(vector<int>& nums, int pivot) {
//         int n = nums.size();
//         vector<int> small;
//         vector<int> large;
//         vector<int> equal;

//         for (int i = 0; i < n; i++) {
//             if (nums[i] < pivot) {
//                 small.push_back(nums[i]);
//             } else if (nums[i] > pivot) {
//                 large.push_back(nums[i]);
//             } else {
//                 equal.push_back(nums[i]);
//             }
//         }

//         vector<int> ans;

//         for (int i = 0; i < small.size(); i++) {
//             ans.push_back(small[i]);
//         }

//         for (int i = 0; i < equal.size(); i++) {
//             ans.push_back(equal[i]);
//         }

//         for (int i = 0; i < large.size(); i++) {
//             ans.push_back(large[i]);
//         }

//         return ans;
//     }
// };

// T.C => O(n)
// S.C => O(n)

// class Solution {
// public:
//     vector<int> pivotArray(vector<int>& nums, int pivot) {
//         int n = nums.size();
//         vector<int> ans(n);

//         int j = 0;

//         for (int i = 0; i < n; i++) {
//             if (nums[i] < pivot) {
//                 ans[j++] = nums[i];
//             }
//         }

//         for (int i = 0; i < n; i++) {
//             if (nums[i] == pivot) {
//                 ans[j++] = nums[i];
//             }
//         }

//         for (int i = 0; i < n; i++) {
//             if (nums[i] > pivot) {
//                 ans[j++] = nums[i];
//             }
//         }

//         return ans;
//     }
// };